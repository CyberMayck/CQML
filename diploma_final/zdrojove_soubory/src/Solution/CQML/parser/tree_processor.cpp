#include "tree_processor.h"
#include <unordered_map>

#include "parser_tree.h"
#include "elements.h"
#include "parameter_handling.h"
#include "src_processor.h"


void recursionCount(ParserGUIElement * element);
GUIElement * recursionConstructGUIStructures(ParserGUIElement * element);
std::string expressionToStr(SrcNode * node);

int id=0;
int elementCount=0;
GUIElement * elements;


extern int totalClassCnt;
extern GUIElement * elementGroups[100];
extern int elementGroupSizes[100];
extern int customClassCnt;


extern vector<ClassContainer*> defaultClasses;
extern unordered_map<string, int> defaultClassMap;
extern vector<ClassContainer*> classes[100];
extern unordered_map<string, int> classMaps[100];
extern vector<PrimitiveType*> primitiveTypes;
extern unordered_map<string, int> primitiveTypeMap;

extern std::unordered_map<std::string, int> idMaps[100];

extern std::vector<GUIImport> imports;
// path to fileIndex
extern std::unordered_map<std::string, int> importMap;
extern std::vector<GraphNode*> importGraph;

// import to import index in array
extern std::unordered_map<std::string, int> importToKeyMaps[100];

// import to name of the class in output
extern std::unordered_map<std::string, std::string> importPathToName;

/**
 * Function which process the syntax tree and creates gui structures from it
 * 
 *
 * @param syntax tree node
 * @param current file index
 * @param output number of elements
 * @param output array of elements
 */
void processTree(ParserList* elementTree, int treeInd, int& elementCountOut, GUIElement * &elementsOut)
{
	// count elements
	id=0;
	elementCount=0;
	for(int i=0;i<elementTree->memberCount;i++)
	{
		if(elementTree->members[i]->type==TYPE_IMPORT || elementTree->members[i]->type==TYPE_INCLUDE)
		{
			continue;
		}
		recursionCount((ParserGUIElement*)elementTree->members[i]);
	}
	elements=new GUIElement[elementCount];
	
	// process the tree itself (create guielement structures)
	for(int i=0;i<elementTree->memberCount;i++)
	{
		if(elementTree->members[i]->type==TYPE_IMPORT || elementTree->members[i]->type==TYPE_INCLUDE)
		{
			continue;
		}

		// just one element as root
		//rootElements[rootElementCount]=id;
		recursionConstructGUIStructures((ParserGUIElement*)elementTree->members[i]);
		//rootElementCount++;
	}
	elements[0].parentId=-1;

	
	// create ids
	id=0;
	for(int i=0;i<elementCount;i++)
	{
		for(int j=0;j<elements[i].attributeCount;j++)
		{
			GUIElementAttribute * att=&elements[i].attributes[j];
			if(strcmp(att->name,"id")==0)
			{
				std::string idName=expressionToStr(att->expression);
				
				// should check for duplicities !!!
				if(idMaps[treeInd].count(idName)>0)
				{
					//assert(false);
					printf("same id multiple times: %s\n",att->name);
					exit(0);
				}
				idMaps[treeInd][idName]=i;
				break;
			}
		}
	}

	int customClassCount=0;


	
	// create custom classes for elements with new properties
	for(int i=0;i<elementCount;i++)
	{
		bool imported=false;
		int importInd;
		int importFileInd;
		std::unordered_map<string, int>  * stuff= &importToKeyMaps[0];
		if(importToKeyMaps[treeInd].count(elements[i].name)>0)
		{
			imported=true;
			importInd=importToKeyMaps[treeInd][elements[i].name];

			importFileInd=importMap[imports[importInd].path];

		}

		if(imported)
		{
			if(elements[i].propertiesCount>0)
			{
				//[0]
				std::string parName=elementGroups[importFileInd][0].classContainer->className;
				//std::string className=std::string(elements[i].name)+std::string("Custom")+std::to_string(static_cast<long long>(customClassCnt));
				std::string className=parName+std::string("Custom")+std::to_string(static_cast<long long>(customClassCnt));
				
				customClassCnt++;
				ClassContainer * cont=new ClassContainer(className,treeInd,totalClassCnt++);
				cont->SetAncestor(elementGroups[importFileInd][0].classContainer);

				elements[i].classContainer=cont;
			}
			else
			{
				elements[i].classContainer=elementGroups[importFileInd][0].classContainer;
			}
		}
		else
		{
			if(elements[i].propertiesCount>0)
			{
				std::string className=std::string("")+std::string(elements[i].name)+std::string("Custom")+std::to_string(static_cast<long long>(customClassCnt));
				customClassCnt++;
				ClassContainer * cont=new ClassContainer(className, treeInd,totalClassCnt++);
				cont->SetAncestor(defaultClasses[defaultClassMap[string("")+string(elements[i].name)]]);
				
				elements[i].classContainer=cont;
			}
			else
			{
				elements[i].classContainer=defaultClasses[defaultClassMap[string("")+string(elements[i].name)]];
			}
		}
		if(elements[i].propertiesCount>0)
		{
			ClassContainer * cont = elements[i].classContainer;
			classes[treeInd].push_back(cont);

			for(int j=0;j<elements[i].propertiesCount;j++)
			{
				GUIElementProperty * prop= &elements[i].properties[j];

				PropertyAndType temp;
				temp.name=prop->name;
				temp.type=prop->typeName;
				temp.value=string();
				temp.isDefault=0;

				cont->AddProp(temp);
			}
			ClassContainer* ancestor=cont->GetAncestor();
			while(ancestor!=0)
			{
				cont->isReferencable=ancestor->isReferencable;

				ancestor=ancestor->GetAncestor();
			}
		}

	}

	// process expressions in elements
	for(int i=0;i<elementCount;i++)
	{
		for(int j=0;j<elements[i].attributeCount;j++)
		{
			GUIElementAttribute * att=&elements[i].attributes[j];
			
			
			if(strcmp(att->name,"id")==0)
				continue;

			// should check for duplicities !!!
			PropertyAndType* t=  elements[i].classContainer->CheckExistence(std::string(att->name));
			
			if(t==0)
			{
				printf("nonexistent atribute %s in %s\n",att->name,elements[i].name);
				exit(0);
			}

			// check for existence after '.'
			if(att->name2!=0)
			{
				// todo? maybe check non-default too?
				PropertyAndType* oldT=t;
				t=defaultClasses[defaultClassMap[t->type]]->CheckExistence(std::string(att->name2));
				if(t==0)
				{
					printf("nonexistent attribute: %s \nin %s\n",att->name2,oldT->type.c_str());
					exit(0);
				}
			}
			
			if(att->source!=0)
				att->source->Process(treeInd,i);
			else
				att->handler->Process(treeInd,i);
		}

		for(int j=0;j<elements[i].handlerCount;j++)
		{
			GUIElementHandler * handler=&elements[i].handlers[j];

			PropertyAndType* t= elements[i].classContainer->CheckExistence(std::string(handler->name));
			HandlerAndType* h= elements[i].classContainer->CheckHExistence(std::string("Custom")+std::string(handler->name));
			///here
			if(t==0 && h==0)
			{
				printf("nonexistent attribute or handler: %s \nin %s\n",handler->name,elements[i].name);
				exit(0);
			}

			if(t!=0 && h!=0)
			{
				printf("handler and property has same name\n");
				exit(0);
			}
			
			if(t!=0)
			{
				// just property handler
				handler->isProperty=true;
			}
			else
			{
				// actual handler
				handler->isProperty=false;
			}
			string alp;

			handler->source->Process(treeInd,i);
		}
	}
	elementsOut=elements;
	elementCountOut=elementCount;
}



/**
 * Recursive function for calculating total number of elements.
 * 
 *
 * @param number of elements
 */
void recursionCount(ParserGUIElement * element)
{
	elementCount++;
	if((*element).list!=0)
	{
		for(int i=0;i<(*(*element).list).memberCount;i++)
		{
			if((*(*(*element).list).members[i]).type==TYPE_GUI_ELEMENT)
				recursionCount((ParserGUIElement *)(*(*element).list).members[i]);
		}
	}
}



/**
 * function for creating gui structures from parser tree
 * 
 *
 * @param syntax tree node
 *
 * @return intialized element
 */
GUIElement * recursionConstructGUIStructures(ParserGUIElement * element)
{
	int i;
	elements[id]=GUIElement();
	GUIElement * instance=&elements[id];

	int childCnt=0;
	int attribCnt=0;
	int handlerCnt=0;
	int propertyCnt=0;

	// count stuff first
	if(element->list!=0)
	{
		for(i=0;i<element->list->memberCount;i++)
		{
			if(element->list->members[i]->type==TYPE_GUI_ELEMENT)
			{
				childCnt++;
			}
			else if(element->list->members[i]->type==TYPE_ATTRIBUTE)
			{
				attribCnt++;
			}
			else if(element->list->members[i]->type==TYPE_ATTRIBUTE_HANDLER)
			{
				attribCnt++;
			}
			else if(element->list->members[i]->type==TYPE_HANDLER)
			{
				handlerCnt++;
			}
			else if(element->list->members[i]->type==TYPE_PROPERTY)
			{
				if(((ParserProperty*)element->list->members[i])->attribute!=0)
					attribCnt++;
				propertyCnt++;
			}
			
		}
	}

	//alocate
	instance->attributeCount=attribCnt;
	instance->attributes=new GUIElementAttribute[attribCnt];
	instance->handlerCount=handlerCnt;
	instance->handlers=new GUIElementHandler[handlerCnt];
	instance->childrenCount=childCnt;
	instance->children=new GUIElement*[childCnt];
	instance->propertiesCount=propertyCnt;
	instance->hasCustomClass=propertyCnt>0;
	instance->properties=new GUIElementProperty[propertyCnt];
	instance->id=id;
	instance->name=element->name;



	// and init in the end
	id++;
	childCnt=0;
	attribCnt=0;
	propertyCnt=0;
	handlerCnt=0;
	if(element->list!=0)
	{
		for(i=0;i<element->list->memberCount;i++)
		{
			if(element->list->members[i]->type==TYPE_GUI_ELEMENT)
			{
				instance->children[childCnt]=recursionConstructGUIStructures((ParserGUIElement *)element->list->members[i]);
				instance->children[childCnt]->parentId=instance->id;
				childCnt++;
			}
			else if(element->list->members[i]->type==TYPE_ATTRIBUTE)
			{
				instance->attributes[attribCnt]=GUIElementAttribute();
				instance->attributes[attribCnt].name=((ParserAttribute *)element->list->members[i])->name;
				instance->attributes[attribCnt].name2=((ParserAttribute *)element->list->members[i])->name2;
				instance->attributes[attribCnt].expression=((ParserAttribute *)element->list->members[i])->expression;
				instance->attributes[attribCnt].source=ExprToHandler(((ParserAttribute *)element->list->members[i])->expression);
				instance->attributes[attribCnt].handler=0;//new GUIElementHandler();
				attribCnt++;
			}
			else if(element->list->members[i]->type==TYPE_ATTRIBUTE_HANDLER)
			{
				instance->attributes[attribCnt]=GUIElementAttribute();
				instance->attributes[attribCnt].name=((ParserAttribute *)element->list->members[i])->name;
				instance->attributes[attribCnt].name2=((ParserAttribute *)element->list->members[i])->name2;
				instance->attributes[attribCnt].expression=((ParserAttribute *)element->list->members[i])->expression;
				instance->attributes[attribCnt].source=0;//ExprToHandler(((ParserAttribute *)element->list->members[i])->expression);
				
				instance->attributes[attribCnt].handler=SourceToHandler(((ParserAttribute *)element->list->members[i])->expression);
				//instance->attributes[attribCnt].handler=SourceToHandler(((ParserHandler *)element->list->members[i])->code);
				attribCnt++;
			}
			else if(element->list->members[i]->type==TYPE_HANDLER)
			{
				instance->handlers[handlerCnt]=GUIElementHandler();
				instance->handlers[handlerCnt].name=((ParserHandler *)element->list->members[i])->name;
				instance->handlers[handlerCnt].code=((ParserHandler *)element->list->members[i])->code;
				instance->handlers[handlerCnt].source=SourceToHandler(((ParserHandler *)element->list->members[i])->code);
				handlerCnt++;
			}
			else if(element->list->members[i]->type==TYPE_PROPERTY)
			{
				ParserProperty * prop=(ParserProperty *)element->list->members[i];
				instance->properties[propertyCnt]=GUIElementProperty();
				instance->properties[propertyCnt].name=prop->attName;
				instance->properties[propertyCnt].typeName=prop->typeName;
				instance->properties[propertyCnt].hasUpdater=0;
				if(prop->attribute!=0)
				{
					instance->attributes[attribCnt]=GUIElementAttribute();
					instance->attributes[attribCnt].name=prop->attribute->name;
					instance->attributes[attribCnt].name2=0;
					instance->attributes[attribCnt].expression=prop->attribute->expression;
					instance->attributes[attribCnt].source=ExprToHandler(prop->attribute->expression);

					instance->attributes[attribCnt].handler=0;//new GUIElementHandler();
					instance->properties[propertyCnt].hasUpdater=1;

					attribCnt++;
				}
				propertyCnt++;
			}
			else if(element->list->members[i]->type==TYPE_PROPERTY_HANDLER)
			{
				ParserProperty * prop=(ParserProperty *)element->list->members[i];
				instance->properties[propertyCnt]=GUIElementProperty();
				instance->properties[propertyCnt].name=prop->attName;
				instance->properties[propertyCnt].typeName=prop->typeName;
				
				if(prop->attribute!=0)
				{
					instance->attributes[attribCnt]=GUIElementAttribute();
					instance->attributes[attribCnt].name=prop->attribute->name;
					instance->attributes[attribCnt].name2=0;
					instance->attributes[attribCnt].expression=prop->attribute->expression;
					
					if(prop->attribute->base.type==TYPE_ATTRIBUTE)
					{
						instance->attributes[attribCnt].source=ExprToHandler(prop->attribute->expression);
						instance->attributes[attribCnt].handler=0;
					}
					else
					{
						instance->attributes[attribCnt].source=0;
						instance->attributes[attribCnt].handler=SourceToHandler(prop->attribute->expression);
					}

					attribCnt++;
				}
				propertyCnt++;
			}
		}
	}

	return instance;
}


/**
 * Writes expression to string
 * 
 *
 * @param root node of expression
 *
 * @return expression in string form
 */
std::string expressionToStr(SrcNode * node)
{
	if(node->text!=0)
	{
		if(node->text)
			return std::string(node->text);
	}
	std::string str("");
	for(int i=0;i<node->childrenCount;i++)
	{
		str+=expressionToStr(node->children[i]);
	}
	return str;
}