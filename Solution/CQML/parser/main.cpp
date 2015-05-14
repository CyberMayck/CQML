#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <assert.h>

//#include "lex.yy.c"
//#include "cqml_grammar.tab.c"
//#include "cqml_grammar.tab.h"
#include "cqml_grammar.tab.h"

#include "checker.h"

#include "parser_tree.h"
#include "parameter_handling.h"
#include "src_processor.h"
#include "elements.h"
extern vector<ClassContainer*> defaultClasses;
extern unordered_map<string, int> defaultClassMap;
extern vector<ClassContainer*> classes[100];
extern unordered_map<string, int> classMaps[100];
extern vector<PrimitiveType*> primitiveTypes;
extern unordered_map<string, int> primitiveTypeMap;

extern int totalClassCnt;

typedef struct yy_buffer_state *YY_BUFFER_STATE;

void PrintNodeToFile(FILE* file, SrcNode* node);


std::unordered_map<std::string, int> keyMap;
std::vector<GraphNode*> graphNodes;

std::unordered_map<std::string, bool> importsProcessed;
std::vector<GUIImport> imports;

std::vector<GUIInclude> includes;

int importCnt=0;

// path to fileIndex
std::unordered_map<std::string, int> importMap;
std::vector<GraphNode*> importGraph;


// import to import index in array
std::unordered_map<std::string, int> importToKeyMaps[100];

// import to name of the class in output
std::unordered_map<std::string, std::string> importPathToName;


GUIElement * elements;
int elementCount;

GUIElement * elementGroups[100];
int elementGroupSizes[100];

int customClassCnt=0;

ParserList* elementTree;
std::unordered_map<std::string, int> idMaps[100];

extern "C"
{
YY_BUFFER_STATE yy_scan_string(char *);
YY_BUFFER_STATE yyrestart(FILE * file);
YY_BUFFER_STATE yyparse();
}

FILE *file;
FILE *file_class_header;
FILE *file_class_source;
int id;

int * identifiersIds;
char ** identifiers;
int identifiersCount;
int identifiersMax;

int rootElements[100];
int rootElementCount;




#include <stack>
std::stack<int> tStack;
int tInd=0;
int compInd=0;

int* gIndex;
int* gLink;
int* stackCnts;
int* compInds;
void tarjanRecursion(std::vector<GraphNode*> &graphNodes,int ind);

void PrintTypesUnion(FILE* f);


ParserList * elementTrees[100];
int elementTreeGInds[100];
int elementTreeCnt=0;


void GUIElementHandler::CheckerPrint(FILE * f)
{
	//for(int i=0;i<checkers.size();i++)
	{
	//	checkers[i].Print(f);
	}
}

char * firstIDrec(SrcNode* node)
{
	int i;
	char * txt;
	if((*node).text!=0)
	{
		return (*node).text;
	}
	
	for(i=0;i<(*node).childrenCount;i++)
	{
		txt=firstIDrec((*node).children[i]);
		if(txt!=0)
			return txt;
	}
	return 0;
}


void PrintNode(SrcNode* node)
{
	int i;
	if((*node).text!=0)// && (*node).type==NODE_TYPE_ID)
	{
		printf("id: %s",(*node).text);
	}
	for(i=0;i<(*node).childrenCount;i++)
	{
		PrintNode((*node).children[i]);
	}
}

void printHandlerAssignment()
{
	fprintf(file_class_source, "//printHandlerAssignment()\n");
//	int i;

	int currentId;
	currentId=id;

	for(int k=compInd-1;k>=0;k--)
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

void printHandlers()
{
//	int i;

	int currentId;
	currentId=id;

	fprintf(file_class_source, "\n//printHandlers()\nusing namespace CQMLGUI;\n");

	for(int k=compInd-1;k>=0;k--)
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
					//fprintf(file_class_source, "static %s _CQML_element%d_%s(CQMLGUI::CQML_Context * context, CQMLGUI::CQMLEvent Event)\n{\n",i,handler->name,str.c_str());
					fprintf(file_class_source, "static %s _CQML_element%d_%s(CQMLGUI::CQML_Context * context, %s)\n{\n",ht->returnType.c_str(),i,handler->name,str.c_str());
				
					string hSrc;
					handler->source->Print(hSrc);
					//PrintNodeToFile(file_class_source,handler->code);
					fprintf(file_class_source, "%s\n",hSrc.c_str());
					fprintf(file_class_source, "\n}\n");
				}
				else
				{
					if(handler->isProperty)
					{ ///duh
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


void printAttributes()
{
//	int i;
	//ParserAttribute* att;
	int currentId;
	currentId=id;

	for(int k=compInd-1;k>=0;k--)
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
					if(prop->cont)
					{
						if(att->name2==0)
							fprintf(file_class_source, "\t((CQMLGUI::%s*)self->_CQML_element%d)->%s=",prop->cont->className.c_str(),i,att->name);
						else
							fprintf(file_class_source, "\t((CQMLGUI::%s*)self->_CQML_element%d)->%s.%s=",prop->cont->className.c_str(),i,att->name,att->name2);
					}
				}
				else
				{
					//assert(false);
					printf("nonexistent attribute: %s \nin %s\n",att->name,elements[i].name);
					exit(-1);
				}
				
				//PrintNodeToFile(file_class_source,att->expression);
				string hSrc;
				att->source->Print(hSrc);
				fprintf(file_class_source, "%s\n",hSrc.c_str());
				fprintf(file_class_source, ";\n");
			}
		}
	}
}

void classDeclaration(const char* rootName, int treeInd)
{
	int customClassCount=0;

	//fprintf(file_class_header,"typedef struct GUI_Root%s GUI_Root%s;\n\n",rootName,rootName);
	fprintf(file_class_header,"struct Root%s;\n\n",rootName);

	// header
	for(int i=0;i<elementCount;i++)
	{
		elements[i].importName=elements[i].name;
		if(!elements[i].hasCustomClass)
			continue;

		
		char * customClassName= new char[256];
		sprintf_s(customClassName,256,"%s",elements[i].classContainer->className.c_str());
		char * originalClassName= new char[256];
		sprintf_s(originalClassName,256,"%s",elements[i].classContainer->GetAncestor()->className.c_str());
		
		//sprintf_s(customClassName,100,"%sCustom%d",elements[i].name,elements[i].classContainer->classID);//customClassCount);
		customClassCount++;
		//clear?
		//elements[i].origClassName=elements[i].name;
		//elements[i].name=customClassName;
		elements[i].origClassName=originalClassName;
		elements[i].name=customClassName;
		
		//fprintf(file_class_header,"typedef struct GUI_%s GUI_%s;\n\n",elements[i].name,elements[i].name);
		fprintf(file_class_header,"struct %s;\n\n",elements[i].name);
	}

	// header
	for(int i=0;i<elementCount;i++)
	{
		if(!elements[i].hasCustomClass)
			continue;
		fprintf(file_class_header,"struct %s\n",elements[i].name);
	//	fprintf(file_class_header,"\t: %s\n{\n\t%s();",elements[i].origClassName,elements[i].name);
		fprintf(file_class_header,"\t: %s\n{\n",elements[i].origClassName,elements[i].name);
		//fprintf(file_class_header,"\t%s();\n",elements[i].name);

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
		//fprintf(file_class_source,"\tCQMLGUI::%s * pointer;\n\tpointer=(CQMLGUI::%s*)malloc(sizeof(CQMLGUI::%s));\n",elements[i].name,elements[i].name,elements[i].name);
		fprintf(file_class_source,"\tCQMLGUI::%s * pointer;\n\tpointer=new CQMLGUI::%s();\n",elements[i].name,elements[i].name);

//		fprintf(file_class_source,"\tpointer->original=cGUI_%s();\n",elements[i].origClassName);
		fprintf(file_class_source,"\treturn pointer;\n");

		fprintf(file_class_source,"}\n");
	}

	// constructors
	/*for(int i=0;i<elementCount;i++)
	{
		if(!elements[i].hasCustomClass)
			continue;

		fprintf(file_class_source,"CQMLGUI::%s::%s()\n{\n",elements[i].name,elements[i].name);
		
		fprintf(file_class_source,"\tclassID=%d;\n",elements[i].classContainer->classID);
		

		fprintf(file_class_source,"}\n");
	}*/
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
		//jep
		

		fprintf(file_class_source,"}\n");
	}

	
	/*for(int i=0;i<classes[treeInd].size();i++)
	{
		fprintf(file,"CQMLObject* CQMLGUI::%s::Copy()\n",classes[treeInd][i]->className.c_str());
		
		fprintf(file,"{\n");
		fprintf(file,"\treturn new CQMLGUI::%s(*this);\n",classes[treeInd][i]->className.c_str());
		fprintf(file,"}\n\n");
	}*/
	
	for(unsigned int i=0;i<classes[treeInd].size();i++)
	{
		fprintf(file_class_source,"VariantRef CQMLGUI::%s::Get(const char* s)\n{\n",classes[treeInd][i]->className.c_str());
		//fprintf(file_class_source,"Variant CQMLGUI::%s::Get(const char* s)\n{\n",classes[treeInd][i]->className.c_str());
		

		fprintf(file_class_source,"\tint hash=GetHash(classID,s);\n");
		fprintf(file_class_source,"\tif(hash<0) \n\t{\n\t\tthrow(0); \n\t\treturn VariantRef();\n\t}\n");
		fprintf(file_class_source,"\tswitch(hash)\n\t{\n");
		PerfectHashData * hashData = classes[treeInd][i]->hashData;
		for(int j=0;j<hashData->m;j++) ///ok
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

void rootElementDeclaration(const char * rootName)
{
	fprintf(file_class_header,"struct Root%s\n\t:Component\n{\n\tRoot%s();\n",rootName,rootName);
	//fprintf(file_class_header,"GUI_Element base;\n"); //no base
	for(int i=0;i<elementCount;i++)
	{
		fprintf(file_class_header, "\t%s* _CQML_element%d;\n",elements[i].classContainer->className.c_str(),i);
	}
	fprintf(file_class_header,"};\n");
	//fprintf(file_class_header,"Root%s* acGUI_Root%s();\n",rootName,rootName);

	fprintf(file_class_header,"%s* acGUI_Root%s();\n",elements[0].classContainer->className.c_str(),rootName);
	//fprintf(file_class_header,"%s* acGUI_Root%s();\n",elements[0].name,rootName);
	fprintf(file_class_header,"Root%s cGUI_Root%s();\n",rootName,rootName);
}

void printAttributeUpdaters();
void printAttributeUpdatersHeaders();
void printElementUpdatersHeaders();
void printElementUpdaterAssignments();

void rootElementAllocation(const char * rootName, int treeInd)
{
	
	fprintf(file_class_source, "\n //rootElementAllocation() \n");
	fprintf(file_class_source,"CQMLGUI::%s* CQMLGUI::acGUI_Root%s()\n{\n",elements[0].classContainer->className.c_str(),rootName);
	//fprintf(file_class_source,"CQMLGUI::%s* CQMLGUI::acGUI_Root%s()\n{\n",elements[0].name,rootName);

		//fprintf(file_class_source,"CQMLGUI::Root%s* CQMLGUI::acGUI_Root%s()\n{\n",rootName,rootName);
		fprintf(file_class_source,"\tCQMLGUI::Root%s * pointer;\n\tpointer=new CQMLGUI::Root%s();\n",rootName,rootName);

		////fprintf(file_class_source,"pointer->original=cGUI_Root();\n",elements[i].origClassName);
		//fprintf(file_class_source,"\t*pointer=cGUI_Root%s((CQMLGUI::Element *)pointer);\n",rootName);
		
		//fprintf(file_class_source, "mGUI_Element_InsertChild((GUI_Element*)pointer, (GUI_Element*)pointer->_CQML_element0);\n");
		//fprintf(file_class_source,"return pointer;\n");

		//fprintf(file_class_source,"\treturn (CQMLGUI::Root%s*)pointer->_CQML_element0;\n",rootName);
		fprintf(file_class_source,"\treturn pointer->_CQML_element0;\n",rootName);
			

		fprintf(file_class_source,"}\n");
}

void rootElementConstructor(const char * rootName, int treeInd)
{
	fprintf(file_class_source, "\n //rootElementConstructor() \n");

	fprintf(file_class_source,"CQMLGUI::Root%s::Root%s()\n{\n\tCQMLGUI::Element*tmp=0;\n",rootName,rootName);
	//fprintf(file_class_source,"\tCQMLGUI::Root%s s;\n",rootName);
	//fprintf(file_class_source,"\tCQMLGUI::Root%s * self=&s;\n",rootName);

	//fprintf(file_class_source,"self->base=cGUI_Element();\n"); //no base
	//fprintf(file_class_source,"self->base.root=(GUI_Element*)self;\n");

	for(int i=0;i<elementCount;i++)
	{
		bool isImportName=importToKeyMaps[treeInd].count(std::string(elements[i].importName))!=0;
		if(isImportName)
		{
			if(elements[i].hasCustomClass)
			{
				const char *nam= importPathToName[imports[importToKeyMaps[treeInd][std::string(elements[i].importName)]].path].c_str();
				//fprintf(file_class_source, "\t_CQML_element%d = (CQMLGUI::Element*)CQMLGUI::acGUI_Root%s();\n",i,nam);
				
				//fprintf(file_class_source, "\t%s;\n",elements[i].name);

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
					//parCont->handlers
				}
				while(parCont!=0)
				{
					for(unsigned int j=0;j<parCont->handlers.size();j++)
					{
						//GUIElementHandler
						HandlerAndType* handler=&parCont->handlers[j];
						//if(!handler->isProperty)
						
						{
							fprintf(file_class_source, "\t_CQML_element%d->%s=((CQMLGUI::Root%s*)tmp)->_CQML_element0->%s;\n",i,handler->name.c_str(),nam,handler->name.c_str());
							
							fprintf(file_class_source, "\t_CQML_element%d->%s_context=((CQMLGUI::Root%s*)tmp)->_CQML_element0->%s_context;\n",i,handler->name.c_str(),nam,handler->name.c_str());
							fprintf(file_class_source, "\tif(_CQML_element%d->%s_context)\n",i,handler->name.c_str());
						
							fprintf(file_class_source, "\t\t_CQML_element%d->%s_context->self=_CQML_element%d;\n",i,handler->name.c_str(),i);
						
							//fprintf(file_class_source, "\t_CQML_element%d->Custom%s=_CQML_element%d_%s;\n",i,handler->name,i,handler->name);
							//fprintf(file_class_source, "\t_CQML_element%d->Custom%s_context=acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element%d);\n",i,handler->name,i);
						}
					}
					parCont=parCont->GetAncestor();
				}
				//

				fprintf(file_class_source, "\tdelete ((CQMLGUI::Root%s*)tmp)->_CQML_element0;\n",nam);
				fprintf(file_class_source, "\t((CQMLGUI::Root%s*)tmp)->_CQML_element0=_CQML_element%d;\n",nam,i);
			}
			else
			{
				const char *nam= importPathToName[imports[importToKeyMaps[treeInd][std::string(elements[i].importName)]].path].c_str();
				//fprintf(file_class_source, "\t_CQML_element%d = (CQMLGUI::Element*)CQMLGUI::acGUI_Root%s();\n",i,nam);
				fprintf(file_class_source, "\t_CQML_element%d = CQMLGUI::acGUI_Root%s();\n",i,nam);
			}
		}
		else
			fprintf(file_class_source, "\t_CQML_element%d = CQMLGUI::ac%s();\n",i,elements[i].name);
		fprintf(file_class_source, "\t_CQML_element%d->root=(CQMLGUI::Element*)this;\n",i);
	}
	for(int i=0;i<elementCount;i++)
	{
	//	fprintf(file, "_CQML_element%d = (GUI_Element*)acGUI_%s();\n",i,elements[i].name);
		for(int j=0;j<elements[i].childrenCount;j++)
		{
			fprintf(file_class_source, "\tmGUI_Element_InsertChild((CQMLGUI::Element*)_CQML_element%d, (CQMLGUI::Element*)_CQML_element%d);\n",i,elements[i].children[j]->id);
		}
	}

	
	printAttributeUpdaters();


	for(int i=0;i<rootElementCount;i++)
	{
		//fprintf(file, "mGUI_Element_InsertChild((GUI_Element*)root, (GUI_Element*)_CQML_element%d);\n",rootElements[i]);
	}

	printHandlerAssignment();

	//fprintf(file,"_CQML_Update();\n}\n");
	//fprintf(file,"void _CQML_Update()\n{\n");
	//printAttributes();

	//fprintf(file_class_source,"self->base.Update=_CQML_Update;\n"); //
	printElementUpdaterAssignments();
	fprintf(file_class_source,"\t_CQML_Update((CQMLGUI::Element *)_CQML_element0);\n");

	
	//fprintf(file_class_source,"self->base.root=pointer;\n");

	fprintf(file_class_source,"\n}\n");
	//fprintf(file_class_source,"\treturn *self;\n}\n");
}


void rootElementUpdater(const char * rootName, int treeInd)
{
	fprintf(file_class_source, "\n //rootElementUpdater() \n");

	fprintf(file_class_source,"static void _CQML_Update(CQMLGUI::Element *s)\n{\n\tCQMLGUI::Root%s * self=(CQMLGUI::Root%s *)s;\n",rootName,rootName);
	//fprintf(file_class_source,"\tmGUI_Element_Update((CQMLGUI::Element *)self);\n");
	fprintf(file_class_source,"\ts->Update();\n");
	//printAttributes(); // original
	fprintf(file_class_source,"\n}\n");
}

void printElementUpdatersHeaders()
{
	fprintf(file_class_source, "\n //printElementUpdatersHeaders() \n");
//	int i;
	//ParserAttribute* att;
	int currentId;
	currentId=id;

	//for(int k=compInd-1;k>=0;k--)
	{
		for(int i=0;i<elementCount;i++)
		{

			fprintf(file_class_source, "static void Update_E%d(CQMLGUI::Element *self);\n",i);
		}
	}
}

void printAttributeUpdatersHeaders()
{
	fprintf(file_class_source, "\n //printAttributeUpdatersHeaders() \n");
//	int i;
	//ParserAttribute* att;
	int currentId;
	currentId=id;

	//for(int k=compInd-1;k>=0;k--)
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
					exit(-1);
					//assert(false);
				}
			}
		}
	}
}

void printAttributeUpdaters()
{
	fprintf(file_class_source, "\n //printAttributeUpdaters() \n");
//	int i;
	//ParserAttribute* att;
	int currentId;
	currentId=id;

	//for(int k=compInd-1;k>=0;k--)
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
					//perror("nonexistent attribute \n");
					printf("nonexistent attribute: %s \nin %s\n",att->name,elements[i].name);
					exit(-1);
					//assert(false);
				}
			}
		}
	}
}



bool * visited;
bool * processed;

bool recursionDetectCycle(std::vector<GraphNode*> &graphNodes,GraphNode * node, int ind)
{
	if(visited[ind])
		return true;
	processed[ind]=true;
	visited[ind]=true;
	for(unsigned int i=0;i<node->nextNodes.size();i++)
	{
		if(recursionDetectCycle(graphNodes,graphNodes[node->nextNodes[i]],node->nextNodes[i]))
			return true;
	}
	visited[ind]=false;
	return false;
}

void sortTopologically(std::vector<GraphNode*> &graphNodes)
{
	tInd=0;
	compInd=0;
	gIndex=new int[graphNodes.size()];
	gLink=new int[graphNodes.size()];
	stackCnts=new int[graphNodes.size()];
	compInds=new int[graphNodes.size()];
	for(unsigned int i=0;i<graphNodes.size();i++)
	{
		gIndex[i]=-1;
		stackCnts[i]=0;
	}
	for(unsigned int i=0;i<graphNodes.size();i++)
	{
		if(gIndex[i]==-1)
		{
			tarjanRecursion(graphNodes, i);
		}
	}
}

void tarjanRecursion(std::vector<GraphNode*> &graphNodes,int ind)
{
	gIndex[ind]=tInd;
	gLink[ind]=tInd;
	tInd++;
	tStack.push(ind);
	stackCnts[ind]++;

	for(unsigned int i=0;i<graphNodes[ind]->nextNodes.size();i++)
	{
		int ind2=graphNodes[ind]->nextNodes[i];
		if(gIndex[ind2]==-1)
		{
			tarjanRecursion(graphNodes,ind2);
			if(gLink[ind]>gLink[ind2])
				gLink[ind]=gLink[ind2];
		}
		else if(stackCnts[ind2]>0)
		{
			if(gLink[ind]>gIndex[ind2])
				gLink[ind]=gIndex[ind2];
		}
	}

	if(gLink[ind]==gIndex[ind])
	{
		while(true)
		{
			int ind2=tStack.top();
			tStack.pop();
			stackCnts[ind2]--;
			compInds[ind2]=compInd;
			
			if(ind==ind2)
				break;
		}
		compInd++;
	}
}

bool detectCycle(std::vector<GraphNode*> &graphNodes)
{
	visited=new bool[graphNodes.size()];
	processed=new bool[graphNodes.size()];
	for(int i=0,j=graphNodes.size();i<j;i++)
	{
		visited[i]=false;
		processed[i]=false;
	}
	for(unsigned int i=0;i<graphNodes.size();i++)
	{
		if(!processed[i])
		{
			if(recursionDetectCycle(graphNodes,graphNodes[i],i))
				return true;
		}
	}
	return false;
}


FILE **files;


void makeMainSource()
{
	fopen_s(&file,"cqml_output/parser_output.h","w");
	if(file)
	{
		fprintf(file,"#include \"qml_includes.h\"\n");
		fprintf(file,"struct ClassHashTable;\n");
		fprintf(file,"void _CQML_Start();\n");
		fprintf(file,"void _CQML_Update();\n");
		fprintf(file,"void _CQML_Draw();\n");

		fprintf(file,"void InitHashTabs(ClassHashTable *& hashTabs);\n");
		fclose(file);
	}
	
	fopen_s(&file,"cqml_output/parser_output.cpp","w");
	fprintf(file,"#include \"output0.h\"\n#include\"parser_output.h\"\n#include \"qml_includes.h\"\n");
	fprintf(file,"void _CQML_Update();\n");
	fprintf(file,"void _CQML_ClassTabsInit();\n");
	fprintf(file,"void _CQML_Draw();\n");
	fprintf(file,"CQMLGUI::Element* root;\n");

	fprintf(file,"\nvoid _CQML_Start()\n{\n\tSetInitHashTabs(&InitHashTabs);\n\tCQMLInitHashes();\n\troot = (CQMLGUI::Element*) CQMLGUI::acGUI_Rootoutput0();\n\tCQMLGUI::SetRoot(root);\n\t_CQML_Update();\n}\n");
	//fprintf(file,"\nvoid _CQML_Update()\n{\n\troot->Update();\n}\n");
	fprintf(file,"\nvoid _CQML_Update()\n{\n\tCQMLGUI::PreUpdate();\n\troot->Update();\n\tCQMLGUI::PostUpdate();\n}\n");
	fprintf(file,"\nvoid _CQML_Draw()\n{\n\tCQMLGUI::PreDraw();\n\troot->Draw();\n\tCQMLGUI::PostDraw();\n}\n");

	
	fprintf(file,"// print default constructors;\n");
	/*for(int i=0;i<defaultClasses.size();i++)
	{
		ClassContainer * cont =defaultClasses[i];
		fprintf(file,"CQMLGUI::%s::%s()\n{\n",cont->className.c_str(),cont->className.c_str());
		
		fprintf(file,"\tclassID=%d;\n",cont->classID);

		ClassContainer * parCont=cont;
		//while(parCont!=0)
		{
			for(int j=0;j<parCont->props.size();j++)
			{
				if(parCont->props[j].IsPrimitive())
				{
					fprintf(file,"\t%s=%s;\n",parCont->props[j].name.c_str(), parCont->props[j].value.c_str());
				}
				else if(parCont->props[j].IsReference())
				{
					fprintf(file,"\t%s=%s;\n",parCont->props[j].name.c_str(), parCont->props[j].value.c_str());
					//fprintf(file,"\t%s_Update=0;\n",parCont->props[j].name.c_str());
				}
				if(!parCont->props[j].isDefault)
					fprintf(file,"\t%s_Update=0;\n",parCont->props[j].name.c_str());
			}
			for(int j=0;j<parCont->handlers.size();j++)
			{
					fprintf(file,"\t%s=0;\n",parCont->handlers[j].name.c_str());
			}
			//parCont=parCont->GetAncestor();
		}
		fprintf(file,"\tInit();\n");
		
		fprintf(file,"}\n");
	}
	*/
	
	/*
	for(int i=0;i<defaultClasses.size();i++)
	{
		fprintf(file,"Variant CQMLGUI::%s::Get(const char* s)\n{\n",defaultClasses[i]->className.c_str());
		
		fprintf(file,"\tint hash=GetHash(classID,s);\n");
		fprintf(file,"\tif(hash<0) return Variant(0);\n");
		fprintf(file,"\tswitch(hash)\n\t{\n");
		PerfectHashData * hashData = defaultClasses[i]->hashData;
		for(int j=0;j<hashData->m;j++) ///ok
		{
			//fprintf(file,"\tcase %d:\n",j);
			//fprintf(file,"\t\treturn Variant(%s);\n",hashData->keys[j].c_str());
			PropertyAndType * prop=defaultClasses[i]->CheckExistence(hashData->keys[j]);

			fprintf(file,"\tcase %d:\n",j);
			if(prop->IsPrimitive())
				fprintf(file,"\t\treturn Variant(%s);\n",hashData->keys[j].c_str());
			else
				fprintf(file,"\t\treturn Variant(&%s);\n",hashData->keys[j].c_str());
		}
		
		fprintf(file,"\tdefault: break;\n");
		fprintf(file,"\t}\n");
		
		fprintf(file,"\treturn Variant(0);\n");

		fprintf(file,"}\n");
	}
	*/
	
	fprintf(file, "using namespace CQMLGUI;\n");
	/*
	for(int i=0;i<defaultClasses.size();i++)
		{
			ClassContainer * cont=defaultClasses[i];
			ClassContainer * parentCont=cont->GetAncestor();
			if(defaultClasses[i]->isReferencable && parentCont)
			{
				fprintf(file, "void %s::Update()\n{\n",cont->className.c_str());
				
				for(int j=0;j<cont->props.size();j++)
				{
					PropertyAndType * prop = &cont->props[j];
					if(prop->IsPrimitive())
					{
						fprintf(file, "\tif(%s_Update)%s_Update",prop->name.c_str(),prop->name.c_str());
						fprintf(file, "(%s_context);\n",prop->name.c_str()); 
					}
					else
					{
						ClassContainer * tCont=GetDefaultClassContainer(prop->type);
						if(tCont->isReferencable)
						{
							fprintf(file, "\tif(%s_Update)%s_Update",prop->name.c_str(),prop->name.c_str());
							fprintf(file, "(%s_context);\n",prop->name.c_str()); 
						}
						else
						{
							// non referencable struct
							fprintf(file, "\tif(%s_Update)%s_Update",prop->name.c_str(),prop->name.c_str());
							fprintf(file, "(%s_context);\n",prop->name.c_str()); 
							fprintf(file, "\telse\n\t{\n");

							for(int k=0;k<tCont->props.size();k++)
							{
								const char * tName=tCont->props[k].name.c_str();
								fprintf(file, "\t\tif(%s.%s_Update)%s.%s_Update",prop->name.c_str(),tName,prop->name.c_str(),tName);
								fprintf(file, "(%s.%s_context);\n",prop->name.c_str(),tName); 
							}

							fprintf(file, "\t}\n");
				
						}
					}
				}


				fprintf(file, "\t %s::Update();\nDefaultUpdate();\n",parentCont->className.c_str());
				fprintf(file, "}\n");
				//fprintf(file_class_source, "void %s::Update()\n{\n",cont->className.c_str());
			}
		}
*/
	
	PrintClassHashTabs(file,elementTreeCnt);
	
	//PrintClassInfos(file,elementTreeCnt);
	
	/*fprintf(file,"void _CQML_ClassTabsInit()\n");
	fprintf(file,"{\n");
	PrintClassTabs(file,elementTreeCnt);
	fprintf(file,"}\n");*/

	fclose(file);
}

void printElementUpdaters()
{
	fprintf(file_class_source, "\n //printElementUpdaters() \nusing namespace CQMLGUI;\n");
//	int i;
	//ParserAttribute* att;
	int currentId;
	currentId=id;

	//for(int k=compInd-1;k>=0;k--)
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
					//perror("nonexistent attribute \n");
					printf("nonexistent attribute: %s \nin %s\n",att->name,elements[i].name);
					exit(-1);
					//assert(false);
				}
				
			}
			fprintf(file_class_source, "\t %s::Update();\n",parentCont->className.c_str());
			fprintf(file_class_source, "}\n",i);
		}
		
		
	}
}


void printAttributesBodies()
{
	fprintf(file_class_source, "\n //printAttributesBodies()\n");

//	int i;
	//ParserAttribute* att;
	int currentId;
	currentId=id;

	for(int k=compInd-1;k>=0;k--)
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
				
				///here
				ClassContainer * cont=elements[i].classContainer;
				PropertyAndType * prop=cont->CheckExistence(std::string(att->name));
				if(prop!=0)
				{
					if(att->name2==0)
					{
						fprintf(file_class_source, "static void Update_E%d_%s(CQMLGUI::CQML_Context *context)\n",i,att->name);
						fprintf(file_class_source, "{\n");
						// add dynamic check //todo

						//att->handler->CheckerPrint(file_class_source);
						
						fprintf(file_class_source,"\t((CQMLGUI::%s*)context->self)->%s=",prop->cont->className.c_str(),att->name);
						if(att->source!=0)
						{
							string str="";
							att->source->Print(str);
						//PrintNodeToFile(file_class_source,att->expression);
						
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
						// add dynamic check
						//att->handler->CheckerPrint(file_class_source);

						fprintf(file_class_source,"\t((CQMLGUI::%s*)context->self)->%s.%s=",prop->cont->className.c_str(),att->name,att->name2);
						if(att->source!=0)
						{
							string str="";
							att->source->Print(str);
							//PrintNodeToFile(file_class_source,att->expression);
						
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
							//PropertyAndType * prop2= prop->cont->CheckExistence(std::string(att->name2));
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
								exit(-1);
							}
						}
					}
				}
				else
				{
					//printf("nonexistent attribute: %s \n",att->name);
					printf("nonexistent attribute: %s \nin %s\n",att->name,elements[i].name);
					exit(-1);
					//assert(false);
				}
				
			}
		}
	}
}

void printElementUpdaterAssignments();
//

void printElementUpdaterAssignments()
{
	fprintf(file_class_source, "\n //printElementUpdaterAssignments() \n");
//	int i;
	//ParserAttribute* att;
	int currentId;
	currentId=id;

	//for(int k=compInd-1;k>=0;k--)
	{
		for(int i=0;i<elementCount;i++)
		{
			//fprintf(file_class_source,"\t((CQMLGUI::Element *)_CQML_element%d)->CustomUpdate=Update_E%d;\n",i,i);
		}
	}
}

void PrintTypesUnion(FILE* f)
{
	for(unsigned int i=0;i<primitiveTypes.size();i++)
	{
		fprintf(f,"%s ut_%s;\n",primitiveTypes[i]->name.c_str(),primitiveTypes[i]->name.c_str());
	}
	fprintf(f,"void* ut_ref;\n");
	for(unsigned int i=0;i<defaultClasses.size();i++)
	{
		fprintf(f,"%s ut_%s;\n",defaultClasses[i]->className.c_str(),defaultClasses[i]->className.c_str());
	}
}

void makeSource(std::string name, int treeInd)
{
	std::string name1 = name+std::string(".h");
	std::string name2 = name+std::string(".cpp");
	
	fopen_s(&file_class_header,(string("cqml_output/")+name1).c_str(),"w");
	fopen_s(&file_class_source,(string("cqml_output/")+name2).c_str(),"w");

	fprintf(file_class_header,"#pragma once\n");
//	fprintf(file,"#pragma once\n");

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

	id=0;

	classDeclaration(name.c_str(), treeInd);

	
	//fprintf(file,"namespace CQMLGUI{\n");
	//fprintf(file,"struct %s;\n\n",elements[0].name);
	
	//fprintf(file,"%s* acGUI_Root%s();\n",elements[0].name,name.c_str());
	//here

	//fprintf(file, "\n}\n");
	rootElementDeclaration(name.c_str());
	
	bool cycle=detectCycle(graphNodes);
	sortTopologically(graphNodes);
	
	
	fprintf(file_class_source,"static void _CQML_Update(CQMLGUI::Element *s);\n\n");

	printHandlers();
	

	id=0;
	rootElementAllocation(name.c_str(), treeInd);
	
	printAttributeUpdatersHeaders();
	printElementUpdatersHeaders();

	rootElementConstructor(name.c_str(), treeInd);


	if(cycle)
	{
		printf("Cycle Detected\n");
	}

	rootElementUpdater(name.c_str(), treeInd);

	printAttributesBodies();

	printElementUpdaters();

	
	fprintf(file_class_header,"};");

	//fclose(file);
	fclose(file_class_header);
	fclose(file_class_source);
}


// recursion function from creating gui structures from parser tree
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

bool processSrcDots(SrcNode * node, int treeInd, int currentElementId, int graphInd, GUIElementHandler* h);

int countDotIds(SrcNode * node);
int fillIds(SrcNode * node, std::string* identifiers, int ind);

bool processDots(SrcNode * node, int treeInd,int currentElementId, int graphInd, GUIElementHandler* h, int& varId, bool isRight, SrcApendix& ap, int & lastVar)
{
	char str[256];
	// count Identifiers
	int cnt=countDotIds(node);
	if(cnt<1)
		return false;

	// save identifiers
	std::string* identifiers = new std::string[cnt];
	fillIds(node,identifiers,0);

	bool isOtherId=idMaps[treeInd].count(identifiers[0])!=0;
	int curId=currentElementId;
	
	std::string prevTypeName;
	ClassContainer * prevClassCont=0;
	int prevVarId=varId;

	
	if(isOtherId)
	{
		curId=idMaps[treeInd][identifiers[0]];
		
		sprintf_s(str,256,"(*((GUI_Rootoutput%d*)context->root)->_CQML_element%d)",treeInd,curId);
		// start from ID
		for(int i=1;i<cnt;i++)
		{
			if(isRight || i<cnt-1)
			{
				if(i==1)
					ap.addGetter(std::string(str),std::string(node->text),varId);
				else
					ap.addGetter(prevVarId,std::string(node->text),varId);
				prevVarId=varId;
				varId++;
			}
			else
			{
				if(i==1)
					ap.addSetter(std::string(str),std::string(node->text),lastVar);
				else
					ap.addSetter(prevVarId,std::string(node->text),lastVar);
			}
		}
	}
	else
	{
		PropertyAndType * prop=elements[curId].classContainer->CheckExistence(identifiers[0]);
		sprintf_s(str,256,"(*((CQMLGUI::Rootoutput%d*)context->root)->_CQML_element%d)",treeInd,curId);
		if(prop!=0)
		{
			//start from this
			// if this
			for(int i=0;i<cnt;i++)
			{
				if(isRight || i<cnt-1)
				{
					if(i==1)
						ap.addGetter(std::string(str),std::string(node->text),varId);
					else
						ap.addGetter(prevVarId,std::string(node->text),varId);
					prevVarId=varId;
					varId++;
				}
				else
				{
					if(i==1)
						ap.addSetter(std::string(str),std::string(node->text),lastVar);
					else
						ap.addSetter(prevVarId,std::string(node->text),lastVar);
				}
			}
		}
		else
		{
			return true;
			// leave it alone
		}
	}
	if(isRight)
	{
		free(node->text);
		sprintf_s(str,256,"var%d",(varId-1));

		node->text=new char[strlen(str)+1];
		strcpy_s(node->text,strlen(str)+1,str);
	}


	return true;
}

void processRefs(SrcNode * node, int treeInd, int currentElementId, int graphInd, GUIElementHandler* h, int& varId, bool isRight, SrcApendix& ap, int & lastVar)
{
	char str[256];
	if(node->type==NODE_TYPE_ID)
	{
		bool isOtherId=idMaps[treeInd].count(std::string(node->text))!=0;
		int curId=currentElementId;

		if(isOtherId)
		{
			curId=idMaps[treeInd][std::string(node->text)];
			
			free(node->text);
			//sprintf_s(str,256,"(*((CQMLGUI::Rootoutput%d *)context->root)->_CQML_element%d)",treeInd,curId);
			sprintf_s(str,256,"(*((CQMLGUI::Rootoutput%d*)context->root)->_CQML_element%d)",treeInd,curId);
			//sprintf(str,"(*self->localGroup->members[%d])",otherId);
			node->text=new char[strlen(str)+1];
			strcpy_s(node->text,strlen(str)+1,str);
		}
		else
		{
			curId=currentElementId;
			ClassContainer * cont=elements[currentElementId].classContainer;
			PropertyAndType * prop=cont->CheckExistence(std::string(node->text));
			
			sprintf_s(str,256,"(*((CQMLGUI::Rootoutput%d*)context->root)->_CQML_element%d)",treeInd,curId);
			if(prop!=0)
			{
				// ap
				if(isRight)
				{
					ap.addGetter(std::string(str),std::string(node->text),varId);
					varId++;
				// add getter
				}
				else
				{
					ap.addSetter(std::string(str),std::string(node->text),lastVar);
				// add setter
				}
				
				if(isRight)
				{
					free(node->text);
					sprintf_s(str,256,"var%d",(varId-1));

					node->text=new char[strlen(str)+1];
					strcpy_s(node->text,strlen(str)+1,str);
				}
			}
			else
			{
				// leave it alone might be local
			}
		}
	}
	else
	{
		if(node->type==NODE_TYPE_DOT)
		{
			if(processDots(node, treeInd,currentElementId, graphInd,h,varId, isRight,ap,lastVar))
			{
				node->type=NODE_TYPE_DOT_PROCESSED;
			}
		}
		else
		{
			for(int i=0;i<node->childrenCount;i++)
			{
				processRefs(node->children[i],treeInd,currentElementId, graphInd,h,varId,isRight,ap, lastVar);
			}
		}
	}
}

void printSubnodesToStr(SrcNode * node, string & str)
{
	if((*node).text!=0)
	{
		str=str+string(node->text);
	}
	if(node->type!=NODE_TYPE_DOT_PROCESSED)
	{
		for(int i=0;i<node->childrenCount;i++)
		{
			printSubnodesToStr(node->children[i],str);
		}
	}
}

void processApendi(SrcNode * node, int treeInd, int currentElementId, int graphInd, GUIElementHandler* h, int & varId)
{
	SrcApendix * ap=node->apendix;
	for(unsigned int l=0;l<ap->sentences.size();l++)
	{
		SrcNode* node= ap->sentences[l].nodes[ap->sentences[l].nodes.size()-1];
			int lastVar=0;

		processRefs(node,treeInd,currentElementId,graphInd,h,varId,true,*ap,lastVar);

		string expStr="";
		printSubnodesToStr(node,expStr);
		ap->addExpr(varId,expStr);
		varId++;
		lastVar=varId;

		for(int i=ap->sentences[l].nodes.size()-2;i>=0;i--)
		{
			processRefs(node,treeInd,currentElementId,graphInd,h,varId,false,*ap,lastVar);


		}
		
		//ap->sentences[l].nodes.size()
	}
}

void processSrcAssign(SrcNode * node, int treeInd, int currentElementId, SrcNode * lastStatementNode, int graphInd, GUIElementHandler* h)
{
	AssignSentence * sent=&lastStatementNode->apendix->sentences[lastStatementNode->apendix->sentences.size()-1];
	if(node->childrenCount==3)
	{
		// left side of current right side of previous
		sent->nodes.push_back(node->children[0]);
		AssignmentOperator op;
		op.str=string(node->children[1]->text);
		sent->ops.push_back(op);

		// go right
		processSrcAssign(node->children[2],treeInd, currentElementId,lastStatementNode,graphInd,h);

		// getters to apendix - replace dots and ids by the vars
	}
	else
	{
		sent->nodes.push_back(node->children[0]);
		//just left side - right side of previous
		// getters to apendix - replace dots and ids by the vars
	}
}

void processSrc(SrcNode * node, int treeInd, int currentElementId, SrcNode * lastStatementNode, int graphInd, GUIElementHandler* h, int & varId)
{
	if(node->type==NODE_TYPE_STATM)
	{
		lastStatementNode=node;
		node->apendix=0;
	}
	bool processKids=false;
	if(node->type==NODE_TYPE_DOT)
	{
		if(lastStatementNode->apendix==0)
			lastStatementNode->apendix= new SrcApendix();
		lastStatementNode->apendix->sentences.push_back(AssignSentence());
		AssignSentence * sent=&lastStatementNode->apendix->sentences[lastStatementNode->apendix->sentences.size()-1];
		sent->nodes.push_back(node);
		// append getter to statement
		// and
		// write here
	}
	else if(node->type==NODE_TYPE_ID)
	{
		if(lastStatementNode->apendix==0)
			lastStatementNode->apendix= new SrcApendix();
		lastStatementNode->apendix->sentences.push_back(AssignSentence());
		AssignSentence * sent=&lastStatementNode->apendix->sentences[lastStatementNode->apendix->sentences.size()-1];
		sent->nodes.push_back(node);
		// append getter to statement
		// and
		// write here
	}
	else if(node->type==NODE_TYPE_ASSIGN)
	{
		if(lastStatementNode->apendix==0)
			lastStatementNode->apendix= new SrcApendix();
		lastStatementNode->apendix->sentences.push_back(AssignSentence());
		processSrcAssign(node,treeInd,currentElementId, lastStatementNode, graphInd,h);
	}
	else processKids=true;

	if(processKids)
	{
		for(int i=0;i<node->childrenCount;i++)
		{
			processSrc(node->children[i],treeInd,currentElementId, lastStatementNode, graphInd,h,varId);
		}
	}
	if(lastStatementNode==node)
	{
		processApendi(node,treeInd,currentElementId, graphInd,h,varId);
	}
}

void processSrcReferences(SrcNode * node, int treeInd, int currentId, bool leftMostFound, bool dotNodePassed, int graphInd, GUIElementHandler* h)
{
	char str[256];
	if(node->type==NODE_TYPE_DOT)
	{
		dotNodePassed=true;
	}
	else if(node->type==NODE_TYPE_ID)
	{
		bool isOtherId=idMaps[treeInd].count(std::string(node->text))!=0;
		bool isImportName=importToKeyMaps[treeInd].count(std::string(node->text))!=0;
		//if(leftMostFound)
		{
			if(isOtherId)
			{
				int otherId=idMaps[treeInd][std::string(node->text)];
				free(node->text);
				sprintf_s(str,256,"(*((CQMLGUI::Rootoutput%d*)context->root)->_CQML_element%d)",treeInd,otherId);
				//sprintf_s(str,256,"(*((CQMLGUI::Rootoutput%d *)context->root)->_CQML_element%d)",treeInd,otherId);
				//sprintf(str,"(*self->localGroup->members[%d])",otherId);
				node->text=new char[strlen(str)+1];
				strcpy_s(node->text,strlen(str)+1,str);
			}
			else if(isImportName)
			{
				int otherId=importToKeyMaps[treeInd][std::string(node->text)];
				
				free(node->text);
				sprintf_s(str,256,"CQMLGUI::Root%s",importPathToName[imports[otherId].path].c_str());
				//sprintf(str,"(*self->localGroup->members[%d])",otherId);
				node->text=new char[strlen(str)+1];
				strcpy_s(node->text,strlen(str)+1,str);
			}
			else
			{
				if(strcmp("parent",node->text)==0)
				{
					free(node->text);
					sprintf_s(str,256,"(*((CQMLGUI::Rootoutput%d*)context->root)->_CQML_element%d->parent)",treeInd,currentId);
					//sprintf(str,"(*self->localGroup->members[%d]->parent)",currentId);
					node->text=new char[strlen(str)+1];
					strcpy_s(node->text,strlen(str)+1,str);
				}
				else
				{
					ClassContainer * cont=elements[currentId].classContainer;
					PropertyAndType * prop=cont->CheckExistence(std::string(node->text));
					if(prop!=0)
					{
						//
						sprintf_s(str,256,"((%s*)((CQMLGUI::Rootoutput%d *)context->root)->_CQML_element%d)->%s",prop->cont->className.c_str(),treeInd,currentId,node->text);
							string checkStr=string("((CQMLGUI::Rootoutput")
							+std::to_string(static_cast<long long>(treeInd))
							+string(" *)context->root)->_CQML_element")
							+std::to_string(static_cast<long long>(currentId));
						Checker checker;//(checkStr,string(node->text));
						checker.SetStartName(checkStr);
						checker.PushCheck(prop);//string(node->text));
						h->checkers.push_back(checker);
						
						std::string key=std::to_string(static_cast<long long>(currentId))+std::string(".")+std::string(node->text);

						free(node->text);
						node->text=new char[strlen(str)+1];
						strcpy_s(node->text,strlen(str)+1,str);

						if(keyMap.count(key)!=0)
						{
							graphNodes[keyMap[key]]->nextNodes.push_back(graphInd);
						}
						else
						{
							GraphNode* graphNode=new GraphNode();
							graphNode->key=key;
							graphNode->nextNodes.push_back(graphInd);
							keyMap[key]=graphNodes.size();
							graphNodes.push_back(graphNode);
							//graphNodespush_back();
						}

					}
					else
					{
						// no id nor valid att - might be local - do nothing
					}
				}
				////
				/*else if(strcmp("MakeNewThing",node->text)==0) // temporary - because of missing valid att
				{
				}
				else// if(is valid att?) //complete
				{
				}*/
				//else //nothing
			}
		}
	}
	if(!dotNodePassed)
	{
		for(int i=0;i<node->childrenCount;i++)
		{
			processSrcReferences(node->children[i],treeInd,currentId,leftMostFound,dotNodePassed, graphInd,h);
		}
	}
	else
	{
		if(processSrcDots(node, treeInd,currentId, graphInd,h))
		{
			node->type=NODE_TYPE_DOT_PROCESSED;
		}
	}
}

//class 
int countDotIds(SrcNode * node)
{
	if(node->type==NODE_TYPE_LEAF)
		return -1;
	if(node->type==NODE_TYPE_ID)
		return 1;

	int cnt=0;
	int val=0;
	for(int i=0;i<node->childrenCount;i++)
	{
		if(node->type==NODE_TYPE_DOT && i==1)
			continue;
		
		val=countDotIds(node->children[i]);
		if(val<0)
			return -1;
		cnt+=val;
	}
	return cnt;
}

int fillIds(SrcNode * node, std::string* identifiers, int ind)
{
	if(node->type==NODE_TYPE_ID)
	{
		identifiers[ind]=std::string(node->text);
		ind++;
	}
	else
	{
		for(int i=0;i<node->childrenCount;i++)
		{		
			ind=fillIds(node->children[i],identifiers, ind);
		}
	}
	return ind;
}

bool processSrcDots(SrcNode * node, int treeInd,int currentElementId, int graphInd, GUIElementHandler* h)
{
	// count Identifiers
	int cnt=countDotIds(node);
	if(cnt<1)
		return false;

	// save identifiers
	std::string* identifiers = new std::string[cnt];
	fillIds(node,identifiers,0);

	//bool prevParam=false;
	bool prevElement=false;
	bool isOtherId=idMaps[treeInd].count(identifiers[0])!=0;
	int curId=currentElementId;
	int startInd=1;

	
	std::string completeStr("");

	std::string prevTypeName;
	ClassContainer * prevClassCont=0;

	
								
	//string checkStr=string("((GUI_Rootoutput")
	//		+std::to_string(static_cast<long long>(treeInd))
	//		+string(" *)context->root)->_CQML_element");
	
			
	Checker checker;//(checkStr,string(node->text));


	///
	startInd=0;
	prevElement=true;
	if(isOtherId)
	{
		curId=idMaps[treeInd][identifiers[0]];
		startInd=1;
	}
	GUIElement el=elements[curId];
	prevTypeName=elements[curId].classContainer->className;
	prevClassCont=elements[curId].classContainer;

	string preStr("");  // output
	string postStr(""); // output
	string attribs(""); // graph purposes

	string completeName;

	bool previousIsReference=true;
	bool passedReference=false;
	for(int i=startInd;i<cnt;i++)
	{
		string nam = identifiers[i];
		PropertyAndType * prop=prevClassCont->CheckExistence(identifiers[i]);
		/// waaat
		if(prop!=0)
		{
			if(identifiers[i]==std::string("parent"))
			{
				curId=elements[curId].parentId;
				prevTypeName=elements[curId].classContainer->className;
				prevClassCont=elements[curId].classContainer;
				continue;
			}
			// id.parent.parent end
			if(prevElement)
			{
				completeName=string("((CQMLGUI::Rootoutput")
					+std::to_string(static_cast<long long>(treeInd))
					+string(" *)context->root)->_CQML_element")
					+std::to_string(static_cast<long long>(treeInd));

				prevElement=false;
			}
			prevTypeName=prop->type;


			/// should check if reference or value
			//            ?GUI_?
			if(previousIsReference)
				preStr=std::string("*)") +preStr;
			else
				preStr=std::string("*)&") +preStr;
				//preStr=std::string(")") +preStr;

			preStr=std::string("((")+prop->cont->className+preStr;
			//	+completeStr+

			if(previousIsReference)
				postStr=postStr+ std::string(")->")+identifiers[i];
			else
				postStr=postStr+ std::string(")->")+identifiers[i];
				//postStr=postStr+ std::string(").")+identifiers[i];
			
			checker.PushCheck(prop);//identifiers[i]);
			attribs+="."+identifiers[i];

			
			previousIsReference=prop->IsReference();
			if(previousIsReference)
				passedReference=true;


			// is type a class defined in same file
			if(prop->cont->fileId!=-1 && classMaps[prop->cont->fileId].count(prop->type)>0)
			{
				prevClassCont=classes[prop->cont->fileId][classMaps[prop->cont->fileId][prop->type]];
			}
			else
			{
				// is default class
				if(defaultClassMap.count(prop->type)>0)
				{
					prevClassCont=defaultClasses[defaultClassMap[prop->type]];
				}
				else
				{
					prevClassCont=0;
				}
			}
		}
		else
		{
			//assert(false);
			//perror("unknown att error\n");
			printf("nonexistent attribute: %s \nin %s\n",nam.c_str(),elements[i].name);
			exit(-1);
		}
			//completeStr= std::string("((GUI_")+prop->cont->className+std::string("*)")+completeStr+std::string(")->")+identifiers[i];
			//attribs+="."+identifiers[i];

			//		check.AddCheck(identifiers[i]);
					// to do> element might be stored in attribute
					// + proptype might be from different file
			//		prevElement=false;
		
	}
	completeStr=preStr+completeName+postStr;
	node->text=new char[completeStr.length()+1];
	strcpy_s(node->text,completeStr.length()+1,completeStr.c_str());

	checker.SetStartName(completeName);
	h->checkers.push_back(checker);
								
	////
	/*if(isOtherId)
	{
		prevElement=true;
		curId=idMaps[treeInd][identifiers[0]];
		prevTypeName=elements[curId].classContainer->className;
		prevClassCont=elements[curId].classContainer;

		checkStr=checkStr+std::to_string(static_cast<long long>(curId))
				+string(")");
	}
	else
	{
		if(identifiers[0]==std::string("parent"))
		{
			prevElement=true;
			curId=elements[curId].parentId;
			prevTypeName=elements[curId].classContainer->className;
			prevClassCont=elements[curId].classContainer;

			checkStr=checkStr+std::to_string(static_cast<long long>(curId))
					+string(")");
		}
		else //if(is valid param identifiers[0])
		{
			ClassContainer * cont=elements[currentElementId].classContainer;
			
			prevTypeName=elements[curId].classContainer->className;
			if(cont->CheckExistence(identifiers[0])!=0)
			{
				prevClassCont=elements[curId].classContainer;
			}
			prevElement=false;
			startInd=0; //

			//
			check.AddCheck(identifiers[0]);

			completeStr=std::string("(((GUI_Rootoutput")+std::to_string(static_cast<long long>(treeInd))+std::string(" *)((GUI_Element*)self)->root)->_CQML_element")+std::to_string(static_cast<long long>(curId))+std::string(")");

		}
	}*/

	/*std::string attribs("");
	for(int i=startInd;i<cnt;i++)
	{
		if(prevElement)
		{
			if(identifiers[i]==std::string("parent"))
			{
				prevElement=true;
				curId=elements[curId].parentId;
				prevTypeName=elements[curId].classContainer->className;
				prevClassCont=elements[curId].classContainer;
				
			}
			else
			{
				PropertyAndType * prop=prevClassCont->CheckExistence(identifiers[i]);
				if(prop!=0)
				{
					//
					completeStr=std::string("(((GUI_Rootoutput")+std::to_string(static_cast<long long>(treeInd))+std::string(" *)((GUI_Element*)self)->root)->_CQML_element")+std::to_string(static_cast<long long>(curId))+std::string(")");
					//
					prevElement=false;
					prevTypeName=prop->type;
					if(prop->cont->fileId!=-1 && classMaps[prop->cont->fileId].count(prop->type)>0)
					{
						prevClassCont=classes[prop->cont->fileId][classMaps[prop->cont->fileId][prop->type]];
					}
					else
					{
						if(defaultClassMap.count(prop->type)>0)
							prevClassCont=defaultClasses[defaultClassMap[prop->type]];
						else
							prevClassCont=0;
					}
					completeStr= std::string("((GUI_")+prop->cont->className+std::string("*)")+completeStr+std::string(")->")+identifiers[i];
					attribs+="."+identifiers[i];

					check.AddCheck(identifiers[i]);
					// to do> element might be stored in attribute
					// + proptype might be from different file
					prevElement=false;
				}
				else
				{
					//assert(false);
					perror("unknown att error\n");
					exit(-1);
					//unknown att error
				}
			}
		}
		else
		{
			if(prevClassCont!=0)
			{
				if(identifiers[i]==std::string("parent"))
				{
					// to do> element might be stored in attribute
					return false;
				}
				PropertyAndType * prop=prevClassCont->CheckExistence(identifiers[i]);
				if(prop!=0)
				{
					prevElement=false;
					prevTypeName=prop->type;
					if(prop->cont->fileId!=-1 && classMaps[prop->cont->fileId].count(prop->type)>0)
					{
						prevClassCont=classes[prop->cont->fileId][classMaps[prop->cont->fileId][prop->type]];
					}
					else
					{
						if(defaultClassMap.count(prop->type)>0)
							prevClassCont=defaultClasses[defaultClassMap[prop->type]];
						else
							prevClassCont=0;
					}
					prevElement=false;
					attribs+="."+identifiers[i];
					
					check.AddCheck(identifiers[i]);

					completeStr= std::string("((GUI_")+prop->cont->className+std::string("*)")+completeStr+std::string(")->")+identifiers[i];
				}
				else
				{
					//assert(false);
			perror("unknown att error\n");
			exit(-1);
					//unkown att error
				}
			}
			else
			{
				// nor id nor anything else
				attribs+="."+identifiers[i];

				check.AddCheck(identifiers[i]);
			}
		}
	}*/

	//checkStr=checkStr+std::to_string(static_cast<long long>(curId))
	//				+string(")");
	//check.ElementStr(checkStr);
	//h->checks.push_back(check);
	


	std::string key=std::to_string(static_cast<long long>(curId))+attribs;
	//std::unordered_map<std::string, int> keyMap;
	//std::vector<GraphNode*> graphNodes;
	
	if(keyMap.count(key)!=0)
	{
		graphNodes[keyMap[key]]->nextNodes.push_back(graphInd);
	}
	else
	{
		GraphNode* graphNode=new GraphNode();
		graphNode->key=key;
		graphNode->nextNodes.push_back(graphInd);
		keyMap[key]=graphNodes.size();
		graphNodes.push_back(graphNode);
		//graphNodespush_back();
	}
	//attribs;
	//curId ///vex

	//
	//if(startInd==1)
	//	attribs=std::string("(*((GUI_Rootoutput")+std::to_string(static_cast<long long>(treeInd))+std::string(" *)((GUI_Element*)self)->root)->_CQML_element")+std::to_string(static_cast<long long>(curId))+std::string(")")+attribs;
	//else
	//	attribs=std::string("(*(GUI_")+std::string(elements[curId].name)+std::string("*)((GUI_Rootoutput")+std::to_string(static_cast<long long>(treeInd))+std::string(" *)((GUI_Element*)self)->root)->_CQML_element")+std::to_string(static_cast<long long>(curId))+std::string(")")+attribs;
		
	//attribs
	//node->text=new char[attribs.length()+1];
	//std::strcpy(node->text,attribs.c_str());
	
	//
	//node->text=new char[completeStr.length()+1];
	//std::strcpy(node->text,completeStr.c_str());

	return true;
}




void PrintNodeToFile(FILE* file, SrcNode* node)
{
	int i;
	if((*node).text!=0)
	{
		fprintf(file, "%s",node->text);
	}
	if(node->type!=NODE_TYPE_DOT_PROCESSED)
	{
		for(i=0;i<(*node).childrenCount;i++)
		{
			PrintNodeToFile(file, node->children[i]);
		}
	}
	else
	{
		printf("");
	}
}

std::string expressionToStr(SrcNode * node)
{
	if(node->text!=0)// && (*node).type==NODE_TYPE_ID)
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

void processTreeImports(ParserList* elementTree, int importGInd)
{
	for(int i=0;i<elementTree->memberCount;i++)
	{
		if(elementTree->members[i]->type==TYPE_INCLUDE)
		{
			GUIInclude include;
			include.path=std::string(((ParserInclude*)elementTree->members[i])->path);
			include.treeInd=elementTreeCnt;
			includes.push_back(include);
		}
		if(elementTree->members[i]->type==TYPE_IMPORT)
		{
			GUIImport import;
			import.name=std::string(((ParserImport*)elementTree->members[i])->name);
			import.path=std::string(((ParserImport*)elementTree->members[i])->path);
			import.path=import.path.substr(1,import.path.length()-2);
			import.treeInd=elementTreeCnt;
			imports.push_back(import);
			if(importsProcessed.count(import.path)<1)
				importsProcessed[import.path]=false;
			
			if(importMap.count(import.path)!=0)
			{
				importGraph[importMap[import.path]]->nextNodes.push_back(importGInd);
			}
			else
			{
				GraphNode* graphNode=new GraphNode();
				graphNode->key=import.path;
				graphNode->nextNodes.push_back(importGInd);
				importMap[import.path]=importGraph.size();
				importGraph.push_back(graphNode);
				//graphNodespush_back();
			}
			importToKeyMaps[elementTreeCnt][import.name]=importCnt;

			importCnt++;
			continue;
			//((ParserImport*)element->list->members[i])->name;
			//((ParserImport*)element->list->members[i])->path;
		}

		// just one element
		/*rootElements[rootElementCount]=id;
		recursionConstructGUIStructures((ParserGUIElement*)elementTree->members[i]);
		elements[rootElements[rootElementCount]].parentId=-1;
		rootElementCount++;*/
	}
}


// process parse tree and create gui structures
void processTree(ParserList* elementTree, int treeInd)
{
	// count elements
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
	id=0;
	for(int i=0;i<elementTree->memberCount;i++)
	{
		if(elementTree->members[i]->type==TYPE_IMPORT || elementTree->members[i]->type==TYPE_INCLUDE)
		{
			continue;
		}

		// just one element as root
		rootElements[rootElementCount]=id;
		recursionConstructGUIStructures((ParserGUIElement*)elementTree->members[i]);
		elements[rootElements[rootElementCount]].parentId=-1;
		rootElementCount++;
	}

	

	//ddd
/*	for(int i=0;i<elementCount;i++)
	{
		if(!elements[i].hasCustomClass)
			continue;
		
		string nameC=string(elements[i].name)+string("Custom")+std::to_string(static_cast<long long>(customClassCnt));
		
		ClassContainer * cont = new ClassContainer(nameC, treeInd, totalClassCnt+customClassCnt);
		
		string sp =elements[i].name;

		cont->SetAncestor(defaultClasses[defaultClassMap[sp]]);

		ClassContainer * ancestor= cont->GetAncestor();
		while(ancestor!=0)
		{
			cont->isReferencable=ancestor->isReferencable;

			ancestor=ancestor->GetAncestor();
		}
		elements[i].classContainer=cont;

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
		customClassCnt++;
	}*/
	//ddd
	
	// create ids
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
					exit(-1);
				}
				idMaps[treeInd][idName]=i;
				break;
			}
		}
	}

	int customClassCount=0;


	
	// create existence checkers
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
			//importFileInd=imports[importInd].treeInd;
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

		/*for(int j=0;j<elements[i].propertiesCount;j++)
		{
			PropertyAndType temp;
			temp.name=elements[i].properties[j].name;
			// todo check default type
			if(strcmp(elements[i].properties[j].typeName,"int")!=0)
			{
				temp.type=(string("")+string(elements[i].properties[j].typeName));
			}
			else
			{
				temp.type=elements[i].properties[j].typeName;//+string("*");
				temp.name=temp.name;
			}

			elements[i].classContainer->AddProp(temp);
		}*/
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
			///here
			if(t==0)
			{
					//assert(false);
				printf("nonexistent atribute %s in %s\n",att->name,elements[i].name);
				exit(-1);
			}

			// check for existence after '.'
			if(att->name2!=0)
			{
				// todo? maybe check non-default too?
				PropertyAndType* oldT=t;
				t=defaultClasses[defaultClassMap[t->type]]->CheckExistence(std::string(att->name2));
				if(t==0)
				{
						//assert(false);
					printf("nonexistent attribute: %s \nin %s\n",att->name2,oldT->type.c_str());
					exit(-1);
				}
			}


			std::string key=std::to_string(static_cast<long long>(i))+"."+std::string(att->name);
			if(att->name2!=0)
				key=key+"."+std::string(att->name2);
			int graphInd;
			
			if(keyMap.count(key)!=0)
			{
				graphInd=keyMap[key];//->nextNodes.push_back(graphInd);
			}
			else
			{
				GraphNode* graphNode=new GraphNode();
				graphNode->key=key;
				graphInd=graphNodes.size();
				keyMap[key]=graphInd;
				graphNodes.push_back(graphNode);
				//graphNodespush_back();
			}
			att->graphInd=graphInd;
			
			if(att->source!=0)
				att->source->Process(treeInd,i);
			else
				att->handler->Process(treeInd,i);
			//processSrcReferences(att->expression,treeInd,i,false,false,graphInd,att->handler);
		}

		for(int j=0;j<elements[i].handlerCount;j++)
		{
			GUIElementHandler * handler=&elements[i].handlers[j];

			PropertyAndType* t= elements[i].classContainer->CheckExistence(std::string(handler->name));
			HandlerAndType* h= elements[i].classContainer->CheckHExistence(std::string("Custom")+std::string(handler->name));
			///here
			if(t==0 && h==0)
			{
					//assert(false);
				printf("nonexistent attribute or handler: %s \nin %s\n",handler->name,elements[i].name);
				exit(-1);
			}

			if(t!=0 && h!=0)
			{
					//assert(false);
				printf("handler and property has same name\n");
				exit(-1);
			}

			
			std::string key=std::to_string(static_cast<long long>(i))+"."+std::string(handler->name);
			int graphInd;
			
			if(keyMap.count(key)!=0)
			{
				graphInd=keyMap[key];//->nextNodes.push_back(graphInd);
			}
			else
			{
				GraphNode* graphNode=new GraphNode();
				graphNode->key=key;
				graphInd=graphNodes.size();
				keyMap[key]=graphInd;
				graphNodes.push_back(graphNode);
				//graphNodespush_back();
			}
			handler->graphInd=graphInd;
			
			if(t!=0)
			{
				// just property handler
				handler->isProperty=true;
			}
			else
			{
				handler->isProperty=false;
				// actual handler
			}
			string alp;
			//handler->source->Print(alp);
			handler->source->Process(treeInd,i);
			//processSrcReferences(handler->code,treeInd,i,false,false,graphInd,handler);
		}
	}
}





int node(int a, char b, int c, char * d)
{
	//printf("\n a%s",d);
	if(b=='l' || b=='L')
	{
		printf("\n%d List %d \n",a,c);
		return 77;
	}
	else
	{
		printf("\n%d Node %d \n",a,c);
		printf("%s\n",d);

		return 33;
	}
}

void outputFile()
{
	FILE *file;
	fopen_s(&file,"file.cpp","w");
	fprintf(file,"%s","stuff");
	fclose(file);
}



bool processFile(const char * name)
{
	printf("\n");
	FILE *srcFile;
	fopen_s(&srcFile,name,"r");
	if(!srcFile)
	{
		printf("failed to open file...\n");
		return false;
	}
	
    yyrestart(srcFile);
	if(yyparse())
	{
		return false;
	}

	int graphInd;
	std::string key=std::string(name);
			
	if(importMap.count(key)!=0)
	{
		graphInd=importMap[key];
	}
	else
	{
		GraphNode* graphNode=new GraphNode();
		graphNode->key=key;
		graphInd=importGraph.size();
		importMap[key]=graphInd;
		importGraph.push_back(graphNode);
		//graphNodespush_back();
	}

	importPathToName[std::string(name)]=std::string("output")+std::to_string(static_cast<long long>(elementTreeCnt));

	processTreeImports(elementTree, graphInd);
	elementTrees[elementTreeCnt]=elementTree;
	elementTreeGInds[elementTreeCnt]=graphInd;
	elementTreeCnt++;
	//processTree(elementTree);
	//makeSource();
	fclose(srcFile);
	return true;
}

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


int main(int argc, char ** argv)
{

	processBasicTypes();

	const char * fileName;
	if(argc<2)
	{
		printf("not enough parameters\nuse --help for more info\n");
		return  0;
	}
	if(strcmp(argv[1],"--help")==0)
	{
		PrintHelp();
		return 0;
	}
	else
	{
		fileName=argv[1];
	}
	

	//return 0;
//	FILE *srcFile;
	int a=0;
	id=0;
	//srcFile = fopen("src4.cqml","r");
	
	identifiersCount=0;
	identifiersMax=1000;
	identifiers=(char**)malloc(sizeof(char*)*identifiersMax);
	identifiersIds=(int*)malloc(sizeof(int)*identifiersMax);

	// parse tree creation and import files detection
	if(!processFile(fileName))
	{
		printf("Failed to process file: %s\nexiting...\n",fileName);
		return 0;
	}

	int importInd=0;
	while(importInd<importCnt)
	{
		if(importsProcessed[imports.at(importInd).path])
		{
			imports.at(importInd).processed=true;
		}
		else
		{
			if(!processFile(imports.at(importInd).path.c_str()))
			{
				printf("Failed to process file: %s\nexiting...\n",imports.at(importInd).path.c_str());
				return 0;
			}
			importsProcessed[imports.at(importInd).path]=true;
		}
		importInd++;
	}
	// import dependencies cycle detection
	detectCycle(importGraph);
	// topological sort of import files
	sortTopologically(importGraph);

	int * importCompInds=compInds;

	// processing parser trees (in topological order of the files)
	for(int k=compInd-1,kM=0;k>=kM;k--)
	{
		for(int i=0;i<elementTreeCnt;i++)
		{
			if(compInds[elementTreeGInds[i]]==k)
			{
				processTree(elementTrees[i],i);
				elementGroups[i]=elements;
				elementGroupSizes[i]=elementCount;
			}
		}
	}

	
	MakeAllHashes();
	// source generation
	for(int i=0;i<elementTreeCnt;i++)
	{
		elements=elementGroups[i];
		elementCount=elementGroupSizes[i];

		makeSource(std::string("output")+std::to_string(static_cast<long long>(i)),i);
	}
	makeMainSource();

	printOutputListFile(elementTreeCnt);

	return 0;
}
