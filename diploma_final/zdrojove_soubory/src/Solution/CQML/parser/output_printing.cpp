#include "output_printing.h"
#include "elements.h"
#include "parameter_handling.h"
#include "src_processor.h"
#include <unordered_map>
#include <stdio.h>

extern int compCnt;
extern int * compInds;

extern int importCnt;
extern std::vector<GUIImport> imports;
extern std::unordered_map<std::string, std::string> importPathToName;
extern std::unordered_map<std::string, int> importToKeyMaps[100];
extern std::vector<GUIInclude> includes;

extern int totalClassCnt;
extern vector<ClassContainer*> defaultClasses;
extern unordered_map<string, int> defaultClassMap;
extern vector<ClassContainer*> classes[100];
extern unordered_map<string, int> classMaps[100];
extern vector<PrimitiveType*> primitiveTypes;
extern unordered_map<string, int> primitiveTypeMap;

void printClassDeclarations(const char* rootName, int treeInd, GUIElement * elements, int elementCount, FILE * file_class_header, FILE * file_class_source);
void rootElementDeclaration(const char * rootName, GUIElement * elements, int elementCount, FILE * file_class_header);
void printHandlers(GUIElement * elements, int elementCount, FILE * file_class_source);
void printRootElementAllocation(const char * rootName, int treeInd, GUIElement * rootElement, FILE* file_class_source);
void printAttributeUpdatersHeaders(GUIElement * elements, int elementCount, FILE * file_class_source);
void printElementUpdatersHeaders(int elementCount, FILE* file_class_source);
void printRootElementConstructor(const char * rootName, int treeInd, GUIElement * elements, int elementCount, FILE * file_class_source);
void printRootElementUpdater(const char * rootName, int treeInd, FILE * file_class_source);
void printAttributeUpdaters(GUIElement * elements, int elementCount, FILE * file_class_source);
void printHandlerAssignment(GUIElement * elements, int elementCount, FILE * file_class_source);
void printAttributesBodies(GUIElement * elements, int elementCount, FILE * file_class_source);
void printElementUpdaters(GUIElement * elements, int elementCount, FILE * file_class_source);

/**
 * Prints output file that lists all other output files.
 *
 * @param number of files processed.
 */
void printOutputListFile(int cnt)
{
	FILE * hFile;
	fopen_s(&hFile,"outputfiles.txt","w");
	if(hFile)
	{
		fprintf(hFile, "parser_output.cpp\n");
		for(int i=0;i<cnt;i++)
		{
			fprintf(hFile, "output%d.cpp\n",i);
		}
		fclose(hFile);
	}
	
	fopen_s(&hFile,"outputheaders.txt","w");
	if(hFile)
	{
		fprintf(hFile, "parser_output.h\n");
		for(int i=0;i<cnt;i++)
		{
			fprintf(hFile, "output%d.h\n",i);
		}
		fclose(hFile);
	}
}



/**
 * Prints command line help.
 * 
 */
void PrintHelp()
{
	printf("First parameter of is filename in cqml format of top level component of GUI hierarchy.");
}


/**
 * Creates source files for a component.
 * 
 *
 * @param nName of output file.
 * @param index of component tree.
 * @param array of elements.
 * @param number of elements.
 */
void makeSource(std::string name, int treeInd, GUIElement* elements, int elementCount)
{
	FILE * file_class_header;
	FILE * file_class_source;

	std::string name1 = name+std::string(".h");
	std::string name2 = name+std::string(".cpp");
	
	fopen_s(&file_class_header,(string("cqml_output/")+name1).c_str(),"w");
	fopen_s(&file_class_source,(string("cqml_output/")+name2).c_str(),"w");

	fprintf(file_class_header,"#pragma once\n");

	fprintf(file_class_header,"#include \"qml_includes.h\"\n");
	fprintf(file_class_source,"#include \"%s\"\n\n#include \"qml_includes.h\"\n",name1.c_str());
	for(int i=0;i<importCnt;i++)
	{
		if(imports[i].treeInd==treeInd)
		{
			fprintf(file_class_header,"#include \"%s.h\"\n",importPathToName[imports[i].path].c_str());
		}
	}
	
	fprintf(file_class_header,"namespace CQMLGUI{\n");
	for(unsigned int i=0;i<includes.size();i++)
	{
		if(includes[i].treeInd==treeInd)
		{
			fprintf(file_class_source,"#include %s\n",includes[i].path.c_str());
		}
	}

	printClassDeclarations(name.c_str(), treeInd, elements, elementCount, file_class_header, file_class_source);

	
	rootElementDeclaration(name.c_str(),elements, elementCount, file_class_header);

	
	fprintf(file_class_source,"static void _CQML_Update(CQMLGUI::Element *s);\n\n");

	printHandlers(elements, elementCount, file_class_source);
	

	printRootElementAllocation(name.c_str(), treeInd, &elements[0], file_class_source);
	
	printAttributeUpdatersHeaders(elements, elementCount, file_class_source);
	printElementUpdatersHeaders(elementCount,file_class_source);

	printRootElementConstructor(name.c_str(), treeInd,elements, elementCount, file_class_source);


	printRootElementUpdater(name.c_str(), treeInd, file_class_source);

	printAttributesBodies(elements, elementCount, file_class_source);

	printElementUpdaters(elements, elementCount, file_class_source);

	
	fprintf(file_class_header,"};");

	fclose(file_class_header);
	fclose(file_class_source);
}


/**
 * Prints declarations of classes
 * 
 *
 * @param Name of root element.
 * @param index of component tree.
 * @param array of elements.
 * @param number of elements.
 * @param output file
 */
void printClassDeclarations(const char* rootName, int treeInd, GUIElement * elements, int elementCount, FILE * file_class_header, FILE * file_class_source)
{
	int customClassCount=0;

	// header
	fprintf(file_class_header,"struct Root%s;\n\n",rootName);

	for(int i=0;i<elementCount;i++)
	{
		elements[i].importName=elements[i].name;
		if(!elements[i].hasCustomClass)
			continue;

		
		char * customClassName= new char[256];
		sprintf_s(customClassName,256,"%s",elements[i].classContainer->className.c_str());
		char * originalClassName= new char[256];
		sprintf_s(originalClassName,256,"%s",elements[i].classContainer->GetAncestor()->className.c_str());
		
		
		customClassCount++;

		elements[i].origClassName=originalClassName;
		elements[i].name=customClassName;
		
		fprintf(file_class_header,"struct %s;\n\n",elements[i].name);
	}

	// custom classes
	for(int i=0;i<elementCount;i++)
	{
		if(!elements[i].hasCustomClass)
			continue;
		fprintf(file_class_header,"struct %s\n",elements[i].name);

		fprintf(file_class_header,"\t: %s\n{\n",elements[i].origClassName,elements[i].name);

		for(int j=0;j<elements[i].propertiesCount;j++)
		{
			GUIElementProperty * prop= &elements[i].properties[j];
			ClassContainer * cont= GetClassContainer(prop->typeName,treeInd);
			if(cont && cont->isReferencable)
				fprintf(file_class_header,"\t%s * %s;\n",prop->typeName,prop->name);
			else
				fprintf(file_class_header,"\t%s %s;\n",prop->typeName,prop->name);
			fprintf(file_class_header,"\tCQML_Context * %s_context;\n",prop->name);
			fprintf(file_class_header,"\tvoid (* %s_Update)(CQML_Context*);\n",prop->name);
		}
		fprintf(file_class_header,"\tvirtual void Update();\n");
		fprintf(file_class_header,"VariantRef Get(const char* s);\n");
		fprintf(file_class_header,"%s();\n",elements[i].name);
		fprintf(file_class_header,"};\n");

		fprintf(file_class_header,"%s* ac%s();\n\n",elements[i].name,elements[i].name);
	}
	
	// source
	fprintf(file_class_source,"//classDeclaration\n");
	for(int i=0;i<elementCount;i++)
	{
		if(!elements[i].hasCustomClass)
			continue;

		fprintf(file_class_source,"CQMLGUI::%s* CQMLGUI::ac%s()\n{\n",elements[i].name,elements[i].name);
		
		fprintf(file_class_source,"\tCQMLGUI::%s * pointer;\n\tpointer=new CQMLGUI::%s();\n",elements[i].name,elements[i].name);

		fprintf(file_class_source,"\treturn pointer;\n");

		fprintf(file_class_source,"}\n");
	}

	for(unsigned int i=0;i<classes[treeInd].size();i++)
	{
		fprintf(file_class_source,"CQMLGUI::%s::%s()\n{\n",classes[treeInd][i]->className.c_str(),classes[treeInd][i]->className.c_str());
		
		fprintf(file_class_source,"\tclassID=%d;\n",classes[treeInd][i]->classID);
		for(unsigned int j=0;j<classes[treeInd][i]->props.size();j++)
		{
			if(!classes[treeInd][i]->props[j].isDefault)
			{
				fprintf(file_class_source,"\t%s_Update=0;\n",classes[treeInd][i]->props[j].name.c_str());
				fprintf(file_class_source,"\t%s_context=0;\n",classes[treeInd][i]->props[j].name.c_str());
			}
			PropertyAndType* prop= &classes[treeInd][i]->props[j];
			ClassContainer * cont= GetClassContainer(prop->type,treeInd);
			if(cont && cont->isReferencable)
			{
				fprintf(file_class_source,"\t%s=0;\n",classes[treeInd][i]->props[j].name.c_str());
			}
		}

		fprintf(file_class_source,"}\n");
	}

	
	for(unsigned int i=0;i<classes[treeInd].size();i++)
	{
		fprintf(file_class_source,"VariantRef CQMLGUI::%s::Get(const char* s)\n{\n",classes[treeInd][i]->className.c_str());
		
		fprintf(file_class_source,"\tint hash=GetHash(classID,s);\n");
		fprintf(file_class_source,"\tif(hash<0) \n\t{\n\t\tthrow(0); \n\t\treturn VariantRef();\n\t}\n");
		fprintf(file_class_source,"\tswitch(hash)\n\t{\n");
		PerfectHashData * hashData = classes[treeInd][i]->hashData;
		for(int j=0;j<hashData->m;j++)
		{
			PropertyAndType * prop= classes[treeInd][i]->CheckExistence(hashData->keys[j]);

			fprintf(file_class_source,"\tcase %d:\n",j);
			if(prop->IsPrimitive())
				fprintf(file_class_source,"\t\treturn VariantRef(%s,&%s_Update);\n",hashData->keys[j].c_str(),hashData->keys[j].c_str());
			else
			{
				ClassContainer * tCont=GetDefaultClassContainer(prop->type);
				if(tCont->isReferencable)
				{
					fprintf(file_class_source,"\t\treturn VariantRef((CQMLObject**)&%s,&%s_Update);\n",hashData->keys[j].c_str(),hashData->keys[j].c_str());
				}
				else
				{
					fprintf(file_class_source,"\t\treturn VariantRef((CQMLObject*)&%s,&%s_Update);\n",hashData->keys[j].c_str(),hashData->keys[j].c_str());
				}
			}
		}
		
		fprintf(file_class_source,"\tdefault: break;\n");
		fprintf(file_class_source,"\t}\n");
		
		fprintf(file_class_source,"\treturn VariantRef();\n");

		fprintf(file_class_source,"}\n");
	}

}


/**
 * Prints declaration of root element
 * 
 *
 * @param Name of root element.
 * @param index of component tree.
 * @param array of elements.
 * @param number of elements.
 * @param output file
 */
void rootElementDeclaration(const char * rootName, GUIElement * elements, int elementCount, FILE * file_class_header)
{
	fprintf(file_class_header,"struct Root%s\n\t:Component\n{\n\tRoot%s();\n",rootName,rootName);

	for(int i=0;i<elementCount;i++)
	{
		fprintf(file_class_header, "\t%s* _CQML_element%d;\n",elements[i].classContainer->className.c_str(),i);
	}
	fprintf(file_class_header,"};\n");


	fprintf(file_class_header,"%s* acGUI_Root%s();\n",elements[0].classContainer->className.c_str(),rootName);

	fprintf(file_class_header,"Root%s cGUI_Root%s();\n",rootName,rootName);
}


/**
 * Prints handler functions for handling events and calculating attributes
 * 
 *
 * @param array of elements.
 * @param number of elements.
 * @param output file
 */
void printHandlers(GUIElement * elements, int elementCount, FILE * file_class_source)
{
	int currentId;
	currentId=0;

	fprintf(file_class_source, "\n//printHandlers()\nusing namespace CQMLGUI;\n");

	for(int k=compCnt-1;k>=0;k--)
	{
		for(int i=0;i<elementCount;i++)
		{
			for(int j=0;j<elements[i].handlerCount;j++)
			{
				GUIElementHandler* handler=&elements[i].handlers[j];
				if(compInds[handler->graphInd]!=k)
				{
					continue;
				}

				HandlerAndType * ht=  elements[i].classContainer->CheckHExistence(string("Custom")+handler->name);
				if(ht!=0)
				{
					string str="";
					for(unsigned int l=1;l<ht->paramNames.size();l++)
					{
						str+=ht->paramTypes[l]+string(" ")+ht->paramNames[l];
						if(l!=ht->paramNames.size()-1)
						{
							str+=", ";
						}
					}
					
					fprintf(file_class_source, "static %s _CQML_element%d_%s(CQMLGUI::CQML_Context * context, %s)\n{\n",ht->returnType.c_str(),i,handler->name,str.c_str());
				
					string hSrc;
					handler->source->Print(hSrc);
					
					fprintf(file_class_source, "%s\n",hSrc.c_str());
					fprintf(file_class_source, "\n}\n");
				}
				else
				{
					if(handler->isProperty)
					{
						PropertyAndType * prop=	elements[i].classContainer->CheckExistence(handler->name);
						if(prop!=0)
						{
							fprintf(file_class_source, "static void Update_E%d_%s(CQMLGUI::CQML_Context *);\n",i,handler->name);
							fprintf(file_class_source, "static %s Handler_E%d_%s(CQMLGUI::CQML_Context *);\n",prop->type.c_str(),i,handler->name);
						
							fprintf(file_class_source, "static void Update_E%d_%s(CQMLGUI::CQML_Context *context)\n",i,handler->name);
							fprintf(file_class_source, "{\n");


						
							fprintf(file_class_source,"\t((CQMLGUI::%s*)context->self)->%s=",prop->cont->className.c_str(),handler->name);
							fprintf(file_class_source, "Handler_E%d_%s(context)",i,handler->name);
							fprintf(file_class_source, ";\n");
						
							fprintf(file_class_source, "}\n");


							fprintf(file_class_source, "static %s Handler_E%d_%s(CQMLGUI::CQML_Context *context)\n",prop->type.c_str(),i,handler->name);
							fprintf(file_class_source, "{\n");
							string str="";
							handler->source->Print(str);
						
							fprintf(file_class_source, "%s",str.c_str());
							fprintf(file_class_source, "\n}\n");

						}
					}
				}
			}
		}
	}
}


/**
 * Prints allocation function for root element of a component.
 * 
 *
 * @param name of root element.
 * @param index of component tree.
 * @param pointer to root element
 * @param output file
 */
void printRootElementAllocation(const char * rootName, int treeInd, GUIElement * rootElement, FILE* file_class_source)
{
	
	fprintf(file_class_source, "\n //rootElementAllocation() \n");
	fprintf(file_class_source,"CQMLGUI::%s* CQMLGUI::acGUI_Root%s()\n{\n",rootElement->classContainer->className.c_str(),rootName);
	

	fprintf(file_class_source,"\tCQMLGUI::Root%s * pointer;\n\tpointer=new CQMLGUI::Root%s();\n",rootName,rootName);

	fprintf(file_class_source,"\treturn pointer->_CQML_element0;\n",rootName);
			

	fprintf(file_class_source,"}\n");
}


/**
 * Prints heads of atribute updating functions
 * 
 *
 * @param array of elements.
 * @param number of elements.
 * @param output file
 */
void printAttributeUpdatersHeaders(GUIElement * elements, int elementCount, FILE * file_class_source)
{
	fprintf(file_class_source, "\n //printAttributeUpdatersHeaders() \n");

	int currentId;
	currentId=0;

		for(int i=0;i<elementCount;i++)
		{
			for(int j=0;j<elements[i].attributeCount;j++)
			{
				GUIElementAttribute* att=&elements[i].attributes[j];

				if(strcmp("id",att->name)==0)
				{
					continue;
				}

				
				ClassContainer * cont=elements[i].classContainer;
				PropertyAndType * prop=cont->CheckExistence(std::string(att->name));
				if(prop!=0)
				{
					if(prop->cont)
					{
						if(att->name2==0)
						{
							fprintf(file_class_source, "static void Update_E%d_%s(CQMLGUI::CQML_Context *);\n",i,att->name);
							if(att->handler!=0) fprintf(file_class_source, "static %s Handler_E%d_%s(CQMLGUI::CQML_Context *);\n",prop->type.c_str(),i,att->name);
						}
						else
						{
							PropertyAndType * prop2=0;
							if(defaultClassMap.count(prop->type)>0)
							{
								prop2=defaultClasses[defaultClassMap[prop->type]]->CheckExistence(std::string(att->name2));
							}
							if(prop2!=0)
							{
								fprintf(file_class_source, "static void Update_E%d_%s_%s(CQMLGUI::CQML_Context *);\n",i,att->name,att->name2);
								if(att->handler!=0) fprintf(file_class_source, "static %s Handler_E%d_%s_%s(CQMLGUI::CQML_Context *);\n",prop2->type.c_str(),i,att->name,att->name2);
							}
						}
					}
				}
				else
				{
					printf("nonexistent attribute: %s \nin %s\n",att->name,elements[i].name);
					exit(0);
				}
			}
		}
	
}


/**
 * Prints headers of updaters for whole elements.
 * 
 *
 * @param number of elements.
 * @param output file
 */
void printElementUpdatersHeaders(int elementCount, FILE* file_class_source)
{
	fprintf(file_class_source, "\n //printElementUpdatersHeaders() \n");

	int currentId;
	currentId=0;
		for(int i=0;i<elementCount;i++)
		{

			fprintf(file_class_source, "static void Update_E%d(CQMLGUI::Element *self);\n",i);
		}
	
}


/**
 * Prints constructor for root element.
 * 
 *
 * @param Name of root element.
 * @param index of component tree.
 * @param array of elements.
 * @param number of elements.
 * @param output file
 */
void printRootElementConstructor(const char * rootName, int treeInd, GUIElement * elements, int elementCount, FILE * file_class_source)
{
	fprintf(file_class_source, "\n //rootElementConstructor() \n");

	fprintf(file_class_source,"CQMLGUI::Root%s::Root%s()\n{\n\tCQMLGUI::Element*tmp=0;\n",rootName,rootName);

	for(int i=0;i<elementCount;i++)
	{
		bool isImportName=importToKeyMaps[treeInd].count(std::string(elements[i].importName))!=0;
		if(isImportName)
		{
			if(elements[i].hasCustomClass)
			{
				const char *nam= importPathToName[imports[importToKeyMaps[treeInd][std::string(elements[i].importName)]].path].c_str();
				
				fprintf(file_class_source, "\t_CQML_element%d = CQMLGUI::ac%s();\n",i,elements[i].name);
				fprintf(file_class_source, "\ttmp=CQMLGUI::acGUI_Root%s();\n",nam);
				fprintf(file_class_source, "\tCopyChildren(_CQML_element%d,tmp);\n",i);
				fprintf(file_class_source, "\ttmp=tmp->root;\n",i);

				//copy intrails
				ClassContainer * parCont=elements[i].classContainer->GetAncestor();
				if(parCont!=0)
				{
					for(unsigned int j=0;j<parCont->props.size();j++)
					{
						fprintf(file_class_source, "\t_CQML_element%d->%s=((CQMLGUI::Root%s*)tmp)->_CQML_element0->%s;\n",i,parCont->props[j].name.c_str(),nam,parCont->props[j].name.c_str());
						fprintf(file_class_source, "\t_CQML_element%d->%s_Update=((CQMLGUI::Root%s*)tmp)->_CQML_element0->%s_Update;\n",i,parCont->props[j].name.c_str(),nam,parCont->props[j].name.c_str());
						fprintf(file_class_source, "\t_CQML_element%d->%s_context=((CQMLGUI::Root%s*)tmp)->_CQML_element0->%s_context;\n",i,parCont->props[j].name.c_str(),nam,parCont->props[j].name.c_str());
						fprintf(file_class_source, "\tif(_CQML_element%d->%s_context)\n",i,parCont->props[j].name.c_str());
						fprintf(file_class_source, "\t\t_CQML_element%d->%s_context->self=_CQML_element%d;\n",i,parCont->props[j].name.c_str(),i);
					}
				}
				while(parCont!=0)
				{
					for(unsigned int j=0;j<parCont->handlers.size();j++)
					{

						HandlerAndType* handler=&parCont->handlers[j];
						//if(!handler->isProperty)
						{
							fprintf(file_class_source, "\t_CQML_element%d->%s=((CQMLGUI::Root%s*)tmp)->_CQML_element0->%s;\n",i,handler->name.c_str(),nam,handler->name.c_str());
							
							fprintf(file_class_source, "\t_CQML_element%d->%s_context=((CQMLGUI::Root%s*)tmp)->_CQML_element0->%s_context;\n",i,handler->name.c_str(),nam,handler->name.c_str());
							fprintf(file_class_source, "\tif(_CQML_element%d->%s_context)\n",i,handler->name.c_str());
						
							fprintf(file_class_source, "\t\t_CQML_element%d->%s_context->self=_CQML_element%d;\n",i,handler->name.c_str(),i);
						
						}
					}
					parCont=parCont->GetAncestor();
				}

				fprintf(file_class_source, "\tdelete ((CQMLGUI::Root%s*)tmp)->_CQML_element0;\n",nam);
				fprintf(file_class_source, "\t((CQMLGUI::Root%s*)tmp)->_CQML_element0=_CQML_element%d;\n",nam,i);
			}
			else
			{
				const char *nam= importPathToName[imports[importToKeyMaps[treeInd][std::string(elements[i].importName)]].path].c_str();
				
				fprintf(file_class_source, "\t_CQML_element%d = CQMLGUI::acGUI_Root%s();\n",i,nam);
			}
		}
		else
			fprintf(file_class_source, "\t_CQML_element%d = CQMLGUI::ac%s();\n",i,elements[i].name);
		fprintf(file_class_source, "\t_CQML_element%d->root=(CQMLGUI::Element*)this;\n",i);
	}
	for(int i=0;i<elementCount;i++)
	{
		for(int j=0;j<elements[i].childrenCount;j++)
		{
			fprintf(file_class_source, "\tmGUI_Element_InsertChild((CQMLGUI::Element*)_CQML_element%d, (CQMLGUI::Element*)_CQML_element%d);\n",i,elements[i].children[j]->id);
		}
	}

	
	printAttributeUpdaters(elements, elementCount, file_class_source);

	printHandlerAssignment(elements, elementCount, file_class_source);

	fprintf(file_class_source,"\t_CQML_Update((CQMLGUI::Element *)_CQML_element0);\n");

	

	fprintf(file_class_source,"\n}\n");
}


/**
 * Prints updater of root element of a component
 * 
 *
 * @param Name of root element.
 * @param index of component tree.
 * @param output file
 */
void printRootElementUpdater(const char * rootName, int treeInd, FILE * file_class_source)
{
	fprintf(file_class_source, "\n //rootElementUpdater() \n");

	fprintf(file_class_source,"static void _CQML_Update(CQMLGUI::Element *s)\n{\n\tCQMLGUI::Root%s * self=(CQMLGUI::Root%s *)s;\n",rootName,rootName);

	fprintf(file_class_source,"\ts->Update();\n");

	fprintf(file_class_source,"\n}\n");
}


/**
 * Prints updater functions for attributes.
 * 
 *
 * @param array of elements.
 * @param number of elements.
 * @param output file
 */
void printAttributeUpdaters(GUIElement * elements, int elementCount, FILE * file_class_source)
{
	fprintf(file_class_source, "\n //printAttributeUpdaters() \n");

	int currentId;
	currentId=0;

	{
		for(int i=0;i<elementCount;i++)
		{
			for(int j=0;j<elements[i].attributeCount;j++)
			{
				GUIElementAttribute* att=&elements[i].attributes[j];

				if(strcmp("id",att->name)==0)
				{
					continue;
				}

				
				ClassContainer * cont=elements[i].classContainer;
				PropertyAndType * prop=cont->CheckExistence(std::string(att->name));
				if(prop!=0)
				{
					if(prop->cont)
					{
						if(att->name2==0)
						{
							fprintf(file_class_source, "\t((%s*)_CQML_element%d)->%s_context",prop->cont->className.c_str(),i,att->name);
							fprintf(file_class_source, "  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element%d);\n",i);
							fprintf(file_class_source, "\t((%s*)_CQML_element%d)->%s_Update",prop->cont->className.c_str(),i,att->name);
							fprintf(file_class_source, "  = Update_E%d_%s;\n",i,att->name);
						}
						else
						{
							fprintf(file_class_source, "\t((%s*)_CQML_element%d)->%s.%s_context",prop->cont->className.c_str(),i,att->name,att->name2);
							fprintf(file_class_source, "  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_CQML_element%d));\n",i);
							fprintf(file_class_source, "\t((%s*)_CQML_element%d)->%s.%s_Update",prop->cont->className.c_str(),i,att->name,att->name2);
							fprintf(file_class_source, "  = Update_E%d_%s_%s;\n",i,att->name,att->name2);
						}
					}
				}
				else
				{
					printf("nonexistent attribute: %s \nin %s\n",att->name,elements[i].name);
					exit(0);
				}
			}
		}
	}
}


/**
 * Prints assignment of handler functions to coresponding attributes or events.
 * 
 *
 * @param array of elements.
 * @param number of elements.
 * @param output file
 */
void printHandlerAssignment(GUIElement * elements, int elementCount, FILE * file_class_source)
{
	fprintf(file_class_source, "//printHandlerAssignment()\n");

	int currentId;
	currentId=0;

	for(int k=compCnt-1;k>=0;k--)
	{
		for(int i=0;i<elementCount;i++)
		{
			for(int j=0;j<elements[i].handlerCount;j++)
			{
				GUIElementHandler* handler=&elements[i].handlers[j];
				if(compInds[handler->graphInd]!=k)
				{
					continue;
				}
				if(!handler->isProperty)
				{
					fprintf(file_class_source, "\t_CQML_element%d->Custom%s=_CQML_element%d_%s;\n",i,handler->name,i,handler->name);
					fprintf(file_class_source, "\t_CQML_element%d->Custom%s_context=acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element%d);\n",i,handler->name,i);
				}
				else
				{
					PropertyAndType * prop=	elements[i].classContainer->CheckExistence(handler->name);
					if(prop!=0)
					{
							fprintf(file_class_source, "\t((%s*)_CQML_element%d)->%s_context",prop->cont->className.c_str(),i,handler->name);
							fprintf(file_class_source, "  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element%d);\n",i);
							fprintf(file_class_source, "\t((%s*)_CQML_element%d)->%s_Update",prop->cont->className.c_str(),i,handler->name);
							fprintf(file_class_source, "  = Update_E%d_%s;\n",i,handler->name);
					}
				}
			}
		}
	}
}



/**
 * Prints bodies of functions for updating attributes.
 * 
 *
 * @param array of elements.
 * @param number of elements.
 * @param output file
 */
void printAttributesBodies(GUIElement * elements, int elementCount, FILE * file_class_source)
{
	fprintf(file_class_source, "\n //printAttributesBodies()\n");

	int currentId;
	currentId=0;

	for(int k=compCnt-1;k>=0;k--)
	{
		for(int i=0;i<elementCount;i++)
		{
			for(int j=0;j<elements[i].attributeCount;j++)
			{
				GUIElementAttribute* att=&elements[i].attributes[j];
				if(compInds[att->graphInd]!=k)
				{
					continue;
				}
				if(strcmp("id",att->name)==0)
				{
					continue;
				}
				
				ClassContainer * cont=elements[i].classContainer;
				PropertyAndType * prop=cont->CheckExistence(std::string(att->name));
				if(prop!=0)
				{
					if(att->name2==0)
					{
						fprintf(file_class_source, "static void Update_E%d_%s(CQMLGUI::CQML_Context *context)\n",i,att->name);
						fprintf(file_class_source, "{\n");

						
						fprintf(file_class_source,"\t((CQMLGUI::%s*)context->self)->%s=",prop->cont->className.c_str(),att->name);
						if(att->source!=0)
						{
							string str="";
							att->source->Print(str);
						
							fprintf(file_class_source, "%s",str.c_str());
						}
						else
						{
							fprintf(file_class_source, "Handler_E%d_%s(context)",i,att->name);
						}
						fprintf(file_class_source, ";\n");
						
						fprintf(file_class_source, "}\n");

						if(att->handler!=0)
						{
							fprintf(file_class_source, "static %s Handler_E%d_%s(CQMLGUI::CQML_Context *context)\n",prop->type.c_str(),i,att->name);
							fprintf(file_class_source, "{\n");
							string str="";
							att->handler->Print(str);
						
							fprintf(file_class_source, "%s",str.c_str());
							fprintf(file_class_source, "\n}\n");
						}
					}
					else
					{
						fprintf(file_class_source, "static void Update_E%d_%s_%s(CQMLGUI::CQML_Context *context)\n",i,att->name,att->name2);
						fprintf(file_class_source, "{\n");

						fprintf(file_class_source,"\t((CQMLGUI::%s*)context->self)->%s.%s=",prop->cont->className.c_str(),att->name,att->name2);
						if(att->source!=0)
						{
							string str="";
							att->source->Print(str);
						
							fprintf(file_class_source, "%s",str.c_str());
						}
						else
						{
							fprintf(file_class_source, "Handler_E%d_%s_%s(context)",i,att->name,att->name2);
						}
						
						fprintf(file_class_source, ";\n");
						fprintf(file_class_source, "}\n");
						
						if(att->handler!=0)
						{
							PropertyAndType * prop2=0;
							if(defaultClassMap.count(prop->type)>0)
							{
								prop2=defaultClasses[defaultClassMap[prop->type]]->CheckExistence(std::string(att->name2));
							}
							
							if(prop2!=0)
							{

								fprintf(file_class_source, "static %s Handler_E%d_%s_%s(CQMLGUI::CQML_Context *context)\n",prop2->type.c_str(),i,att->name,att->name2);
								fprintf(file_class_source, "{\n");
								string str="";
								att->handler->Print(str);
						
								fprintf(file_class_source, "%s",str.c_str());
								fprintf(file_class_source, "\n}\n");
							}
							else
							{

								printf("nonexistent attribute: %s.%s \nin %s\n",att->name,att->name2,elements[i].name);
								exit(0);
							}
						}
					}
				}
				else
				{
					printf("nonexistent attribute: %s \nin %s\n",att->name,elements[i].name);
					exit(0);
				}
				
			}
		}
	}
}


/**
 * Prints updater functions for elements.
 * 
 *
 * @param array of elements.
 * @param number of elements.
 * @param output file
 */
void printElementUpdaters(GUIElement * elements, int elementCount, FILE * file_class_source)
{
	fprintf(file_class_source, "\n //printElementUpdaters() \nusing namespace CQMLGUI;\n");

	int currentId;
	currentId=0;

	{
		for(int i=0;i<elementCount;i++)
		{
			if(!elements[i].hasCustomClass)
				continue;
			ClassContainer * cont=elements[i].classContainer;
			ClassContainer * parentCont=cont->GetAncestor();

			fprintf(file_class_source, "void %s::Update()\n{\n",cont->className.c_str());
			
				
			fprintf(file_class_source, "\tif(!enabled)\n\t\treturn;\n");
			for(int j=0;j<elements[i].propertiesCount;j++)
			{
				GUIElementProperty* att=&elements[i].properties[j];

				PropertyAndType * prop=cont->CheckExistence(std::string(att->name));
				if(prop!=0)
				{
					if(prop->IsPrimitive())
					{
						fprintf(file_class_source, "\tif(%s_Update)%s_Update",att->name,att->name);
						fprintf(file_class_source, "(%s_context);\n",att->name); 
					}
					else
					{
						ClassContainer * tCont=GetDefaultClassContainer(prop->type);
						if(tCont->isReferencable)
						{
							fprintf(file_class_source, "\tif(%s_Update)%s_Update",att->name,att->name);
							fprintf(file_class_source, "(%s_context);\n",att->name); 
						}
						else
						{
							// non referencable struct
							fprintf(file_class_source, "\tif(%s_Update)%s_Update",att->name,att->name);
							fprintf(file_class_source, "(%s_context);\n",att->name); 
							fprintf(file_class_source, "\telse\n\t{\n");

							for(unsigned int k=0;k<tCont->props.size();k++)
							{
								const char * tName=tCont->props[k].name.c_str();
								fprintf(file_class_source, "\t\tif(%s.%s_Update)%s.%s_Update",att->name,tName,att->name,tName);
								fprintf(file_class_source, "(%s.%s_context);\n",att->name,tName); 
							}

							fprintf(file_class_source, "\t}\n");
				
						}
					}
				}
				else
				{
					printf("nonexistent attribute: %s \nin %s\n",att->name,elements[i].name);
					exit(0);
				}
				
			}
			fprintf(file_class_source, "\t %s::Update();\n",parentCont->className.c_str());
			fprintf(file_class_source, "}\n",i);
		}
		
		
	}
}


/**
 * Generates main output sourcefile.
 * 
 *
 * @param count of processed components.
 */
void makeMainSource(int elementTreeCnt)
{
	FILE * file;
	fopen_s(&file,"cqml_output/parser_output.h","w");
	if(file)
	{
		fprintf(file,"#include \"qml_includes.h\"\n");
		fprintf(file,"struct ClassHashTable;\n");
		fprintf(file,"void _CQML_Start();\n");

		fprintf(file,"void InitHashTabs(ClassHashTable *& hashTabs);\n");
		fclose(file);
	}
	
	fopen_s(&file,"cqml_output/parser_output.cpp","w");
	fprintf(file,"#include \"output0.h\"\n#include\"parser_output.h\"\n#include \"qml_includes.h\"\n");
	fprintf(file,"void _CQML_ClassTabsInit();\n");
	fprintf(file,"CQMLGUI::Element* root;\n");

	fprintf(file,"\nvoid _CQML_Start()\n{\n\tSetInitHashTabs(&InitHashTabs);\n\tCQMLInitHashes();\n\troot = (CQMLGUI::Element*) CQMLGUI::acGUI_Rootoutput0();\n\tCQMLGUI::SetRoot(root);\n\t_CQML_Update();\n}\n");
	

	
	fprintf(file,"// print default constructors;\n");

	
	fprintf(file, "using namespace CQMLGUI;\n");
	
	PrintClassHashTabs(file,elementTreeCnt);

	fclose(file);
}