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
extern int totalClassCnt;

typedef struct yy_buffer_state *YY_BUFFER_STATE;

void PrintNodeToFile(FILE* file, SrcNode* node);


std::unordered_map<std::string, int> keyMap;
std::vector<GraphNode*> graphNodes;

std::unordered_map<std::string, bool> importsProcessed;
std::vector<GUIImport> imports;

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

ParserList* elementTree;
std::unordered_map<std::string, int> idMaps[100];

extern "C"
{
YY_BUFFER_STATE yy_scan_string(char *);
YY_BUFFER_STATE yyrestart(FILE * file);
YY_BUFFER_STATE yyparse();
}

FILE *file;
FILE *file_classes;
FILE *file_classes2;
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
	int i;

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
				fprintf(file_classes2, "\tself->_QML_element%d->Custom%s=_QML_element%d_%s;\n",i,handler->name,i,handler->name);
			}
		}
	}
}

void printHandlers()
{
	int i;

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
				fprintf(file_classes2, "static void _QML_element%d_%s(QML_Context * context, QMLEvent Event)\n{\n",i,handler->name);
				
				string hSrc;
				handler->source->Print(hSrc);
				//PrintNodeToFile(file_classes2,handler->code);
				fprintf(file_classes2, "%s\n",hSrc.c_str());
				fprintf(file_classes2, "\n}\n");
			}
		}
	}
}


void printAttributes()
{
	int i;
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
					if(prop->cont)
					{
						if(att->name2==0)
							fprintf(file_classes2, "\t((GUI_%s*)self->_QML_element%d)->%s=",prop->cont->className.c_str(),i,att->name);
						else
							fprintf(file_classes2, "\t((GUI_%s*)self->_QML_element%d)->%s.%s=",prop->cont->className.c_str(),i,att->name,att->name2);
					}
				}
				else
				{
					assert(false);
				}
				
				//PrintNodeToFile(file_classes2,att->expression);
				string hSrc;
				att->source->Print(hSrc);
				fprintf(file_classes2, "%s\n",hSrc.c_str());
				fprintf(file_classes2, ";\n");
			}
		}
	}
}

void classDeclaration(const char* rootName)
{
	int customClassCount=0;
	fprintf(file_classes,"typedef struct GUI_Root%s GUI_Root%s;\n\n",rootName,rootName);

	for(int i=0;i<elementCount;i++)
	{
		if(!elements[i].hasCustomClass)
			continue;

		
		char * customClassName= new char[100];
		sprintf(customClassName,"%sCustom%d",elements[i].name,customClassCount);
		customClassCount++;
		//clear?
		elements[i].origClassName=elements[i].name;
		elements[i].name=customClassName;
		
		fprintf(file_classes,"typedef struct GUI_%s GUI_%s;\n\n",elements[i].name,elements[i].name);
	}
	for(int i=0;i<elementCount;i++)
	{
		if(!elements[i].hasCustomClass)
			continue;
		
		fprintf(file_classes,"struct GUI_%s\n{\n",elements[i].name);
		fprintf(file_classes,"\tGUI_%s original;\n",elements[i].origClassName);

		for(int j=0;j<elements[i].propertiesCount;j++)
		{
			GUIElementProperty * prop= &elements[i].properties[j];
			fprintf(file_classes,"%s %s;\n",prop->typeName,prop->name);
		}
		fprintf(file_classes,"};\n");

		fprintf(file_classes,"GUI_%s* acGUI_%s();\n",elements[i].name,elements[i].name);

		fprintf(file_classes2,"GUI_%s* acGUI_%s()\n{\n",elements[i].name,elements[i].name);
		fprintf(file_classes2,"\tGUI_%s * pointer;\n\tpointer=(GUI_%s*)malloc(sizeof(GUI_%s));\n",elements[i].name,elements[i].name,elements[i].name);

		fprintf(file_classes2,"\tpointer->original=cGUI_%s();\n",elements[i].origClassName);
		fprintf(file_classes2,"\treturn pointer;\n");

		fprintf(file_classes2,"}\n");
	}


}

void recursionDeclaration(const char * rootName)
{
	fprintf(file_classes,"struct GUI_Root%s\n{\n",rootName);
	//fprintf(file_classes,"GUI_Element base;\n"); //no base
	for(int i=0;i<elementCount;i++)
	{
		
		//fprintf(file, "GUI_Element* _QML_element%d;\n",i);
		fprintf(file_classes, "\tGUI_Element* _QML_element%d;\n",i);
	}
	fprintf(file_classes,"};\n");
}
void printAttributeUpdaters();
void printAttributeUpdatersHeaders();
void printElementUpdatersHeaders();

void recursionInit(const char * rootName, int treeInd)
{
	
		fprintf(file_classes,"GUI_Root%s* acGUI_Root%s();\n",rootName,rootName);
		fprintf(file_classes,"GUI_Root%s cGUI_Root%s();\n",rootName,rootName);

		fprintf(file_classes2,"GUI_Root%s* acGUI_Root%s()\n{\n",rootName,rootName);
		fprintf(file_classes2,"\tGUI_Root%s * pointer;\n\tpointer=(GUI_Root%s*)malloc(sizeof(GUI_Root%s));\n",rootName,rootName,rootName);

		////fprintf(file_classes2,"pointer->original=cGUI_Root();\n",elements[i].origClassName);
		fprintf(file_classes2,"\t*pointer=cGUI_Root%s((GUI_Element *)pointer);\n",rootName);
		
		//fprintf(file_classes2, "mGUI_Element_InsertChild((GUI_Element*)pointer, (GUI_Element*)pointer->_QML_element0);\n");
		//fprintf(file_classes2,"return pointer;\n");
		fprintf(file_classes2,"\treturn (GUI_Root%s*)pointer->_QML_element0;\n",rootName);
			

		fprintf(file_classes2,"}\n");

		printAttributeUpdatersHeaders();
		printElementUpdatersHeaders();
		
		fprintf(file_classes2,"GUI_Root%s cGUI_Root%s(GUI_Element * pointer)\n{\n",rootName,rootName);
		fprintf(file_classes2,"\tGUI_Root%s s;\n",rootName);
		fprintf(file_classes2,"\tGUI_Root%s * self=&s;\n",rootName);
		//fprintf(file_classes2,"self->base=cGUI_Element();\n"); //no base
		//fprintf(file_classes2,"self->base.root=(GUI_Element*)self;\n");

	for(int i=0;i<elementCount;i++)
	{
		bool isImportName=importToKeyMaps[treeInd].count(std::string(elements[i].name))!=0;
		if(isImportName)
		{
			const char *nam= importPathToName[imports[importToKeyMaps[treeInd][std::string(elements[i].name)]].path].c_str();
			fprintf(file_classes2, "\tself->_QML_element%d = (GUI_Element*)acGUI_Root%s();\n",i,nam);
		}
		else
			fprintf(file_classes2, "\tself->_QML_element%d = (GUI_Element*)acGUI_%s();\n",i,elements[i].name);
		fprintf(file_classes2, "\tself->_QML_element%d->root=pointer;\n",i);
	}
	for(int i=0;i<elementCount;i++)
	{
	//	fprintf(file, "_QML_element%d = (GUI_Element*)acGUI_%s();\n",i,elements[i].name);
		for(int j=0;j<elements[i].childrenCount;j++)
		{
			fprintf(file_classes2, "\tmGUI_Element_InsertChild((GUI_Element*)self->_QML_element%d, (GUI_Element*)self->_QML_element%d);\n",i,elements[i].children[j]->id);
		}
	}

	
	printAttributeUpdaters();
}

void printElementUpdatersHeaders()
{
	int i;
	//ParserAttribute* att;
	int currentId;
	currentId=id;

	//for(int k=compInd-1;k>=0;k--)
	{
		for(int i=0;i<elementCount;i++)
		{

			fprintf(file_classes2, "static void Update_E%d(GUI_Element *self);\n",i);
		}
	}
}

void printAttributeUpdatersHeaders()
{
	int i;
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
							fprintf(file_classes2, "static void Update_E%d_%s(QML_Context *);\n",i,att->name);
						}
						else
						{
							fprintf(file_classes2, "static void Update_E%d_%s_%s(QML_Context *);\n",i,att->name,att->name2);
						}
					}
				}
				else
				{
					assert(false);
				}
			}
		}
	}
}

void printAttributeUpdaters()
{
	int i;
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
							fprintf(file_classes2, "\t((%s*)self->_QML_element%d)->%s_context",prop->cont->className.c_str(),i,att->name);
							fprintf(file_classes2, "  = acQML_Context((GUI_Group*)self,(GUI_Element*)self->_QML_element%d);\n",i);
							fprintf(file_classes2, "\t((%s*)self->_QML_element%d)->%s_Update",prop->cont->className.c_str(),i,att->name);
							fprintf(file_classes2, "  = Update_E%d_%s;\n",i,att->name);
						}
						else
						{
							fprintf(file_classes2, "\t((%s*)self->_QML_element%d)->%s_%s_context",prop->cont->className.c_str(),i,att->name,att->name2);
							fprintf(file_classes2, "  = acQML_Context((GUI_Group*)self,(GUI_Element*)((%s*)self->_QML_element%d)->%s);\n",prop->cont->className.c_str(),i,att->name);
							fprintf(file_classes2, "\t((%s*)self->_QML_element%d)->%s_%s_Update",prop->cont->className.c_str(),i,att->name,att->name2);
							fprintf(file_classes2, "  = Update_E%d_%s_%s;\n",i,att->name,att->name2);
						}
					}
				}
				else
				{
					assert(false);
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
	for(int i=0;i<node->nextNodes.size();i++)
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
	for(int i=0;i<graphNodes.size();i++)
	{
		gIndex[i]=-1;
		stackCnts[i]=0;
	}
	for(int i=0;i<graphNodes.size();i++)
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

	for(int i=0;i<graphNodes[ind]->nextNodes.size();i++)
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
	for(int i=0;i<graphNodes.size();i++)
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
//FILE *files;
//FILE *files;


void makeMainSource()
{
	file = fopen("parser_output.c","w");
	fprintf(file,"#include \"output0outer.h\"\n\n#include \"qml_includes.h\"\n");
	fprintf(file,"void _QML_Update();\n");
	fprintf(file,"void _QML_ClassTabsInit();\n");
	fprintf(file,"GUI_Element* root;\n");
	fprintf(file,"\nvoid _QML_Init()\n{\n\troot = (GUI_Element*) acGUI_Rootoutput0();\n\t_QML_Update();\n}\n");
	fprintf(file,"\nvoid _QML_Update()\n{\n\troot->Update(root);\n}\n");

	
	fprintf(file,"void _QML_ClassTabsInit()\n");
	fprintf(file,"{\n");
	PrintClassTabs(file,elementTreeCnt);
	fprintf(file,"}\n");

	fclose(file);
}

void printElementUpdaters()
{
	int i;
	//ParserAttribute* att;
	int currentId;
	currentId=id;

	//for(int k=compInd-1;k>=0;k--)
	{
		for(int i=0;i<elementCount;i++)
		{

			fprintf(file_classes2, "static void Update_E%d(GUI_Element *self)\n{\n",i);
			fprintf(file_classes2, "\tmGUI_Element_Update((GUI_Element *)self);\n",i);
			for(int j=0;j<elements[i].attributeCount;j++)
			{
				GUIElementAttribute* att=&elements[i].attributes[j];
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
						fprintf(file_classes2, "\t((%s*)self)->%s_Update",prop->cont->className.c_str(),att->name);
						fprintf(file_classes2, "\t(((%s*)self)->%s_context);\n",prop->cont->className.c_str(),att->name);
					}
					else
					{
						fprintf(file_classes2, "\t((%s*)self)->%s_%s_Update",prop->cont->className.c_str(),att->name,att->name2);
						fprintf(file_classes2, "\t(((%s*)self)->%s_%s_context);\n",prop->cont->className.c_str(),att->name,att->name2);
					}
				}
				else
				{
					assert(false);
				}
				
			}
			fprintf(file_classes2, "}\n",i);
		}
	}
}


void printAttributesBodies()
{
	int i;
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
						fprintf(file_classes2, "static void Update_E%d_%s(QML_Context *context)\n",i,att->name);
						fprintf(file_classes2, "{\n");
						// add dynamic check //todo

						att->handler->CheckerPrint(file_classes2);

						fprintf(file_classes2,"\t((%s*)context->self)->%s=",prop->cont->className.c_str(),att->name);
						
						PrintNodeToFile(file_classes2,att->expression);
						fprintf(file_classes2, ";\n");
						
						fprintf(file_classes2, "}\n");
					}
					else
					{
						fprintf(file_classes2, "static void Update_E%d_%s_%s(QML_Context *context)\n",i,att->name,att->name2);
						fprintf(file_classes2, "{\n");
						// add dynamic check
						att->handler->CheckerPrint(file_classes2);

						fprintf(file_classes2,"\t((%s*)context->self)->%s.%s=",prop->cont->className.c_str(),att->name,att->name2);
						
						PrintNodeToFile(file_classes2,att->expression);
						fprintf(file_classes2, ";\n");
						fprintf(file_classes2, "}\n");
					}
				}
				else
				{
					assert(false);
				}
				
			}
		}
	}
}

void printElementUpdaterAssignments();
//

void printElementUpdaterAssignments()
{
	int i;
	//ParserAttribute* att;
	int currentId;
	currentId=id;

	//for(int k=compInd-1;k>=0;k--)
	{
		for(int i=0;i<elementCount;i++)
		{
			fprintf(file_classes2,"\t((GUI_Element *)self->_QML_element%d)->Update=Update_E%d;\n",i,i);
		}
	}
}

void makeSource(std::string name, int treeInd)
{
	//ParserList* list;
	//int i;
	std::string name1 = name+std::string(".h");
	std::string name2 = name+std::string(".c");
	std::string name3 = name+std::string("outer.h");

	//files=new FILE*[3*elementTreeCnt];
	//for(int i=0;i<elementTreeCnt;i++)
	{
		//file = fopen("parser_output.c","w");
		//file_classes= fopen("custom_classes.h","w");
		//file_classes2= fopen("custom_classes.c","w");

		//file = fopen("parser_output.c","w");
		file = fopen(name3.c_str(),"w");
		file_classes= fopen(name1.c_str(),"w");
		file_classes2= fopen(name2.c_str(),"w");

		//makeSource(elementTrees[i]);
	}
	//list=(ParserList*)l;

	//printf("\n");
	//return;
	//file = fopen("parser_output.c","w");
	//file_classes= fopen("custom_classes.h","w");
	//file_classes2= fopen("custom_classes.c","w");
	
	fprintf(file_classes,"#include \"qml_includes.h\"\n");
	fprintf(file_classes2,"#include \"%s\"\n\n#include \"qml_includes.h\"\n",name1.c_str());
	for(int i=0;i<importCnt;i++)
	{
		if(imports[i].treeInd==treeInd)
		{
			fprintf(file_classes2,"#include \"%souter.h\"\n",importPathToName[imports[i].path].c_str());
		}
	}

	//fprintf(file, "GUI_Element* root;\n");
	id=0;

	//fprintf(file,"#include \"custom_classes.h\"\n#include \"qml_includes.h\"\n\nvoid _QML_Update();\n");

	classDeclaration(name.c_str());

	
	fprintf(file,"typedef struct GUI_Root%s GUI_Root%s;\n\n",name.c_str(),name.c_str());
	fprintf(file,"GUI_Root%s* acGUI_Root%s();\n",name.c_str(),name.c_str());
	//here

	recursionDeclaration(name.c_str());
	fprintf(file, "\n");
	
	bool cycle=detectCycle(graphNodes);
	sortTopologically(graphNodes);
	
	
	fprintf(file_classes2,"static void _QML_Update(GUI_Element *s);\n\n");

	printHandlers();
	

	//fprintf(file,"void _QML_Init()\n{\n");
	id=0;
	recursionInit(name.c_str(), treeInd);
	//fprintf(file, "root = (GUI_Element*) acGUI_Element();\n");
	
	for(int i=0;i<rootElementCount;i++)
	{
		//fprintf(file, "mGUI_Element_InsertChild((GUI_Element*)root, (GUI_Element*)_QML_element%d);\n",rootElements[i]);
	}

	printHandlerAssignment();


	if(cycle)
	{
		printf("Cycle Detected\n");
	}

	//fprintf(file,"_QML_Update();\n}\n");
	//fprintf(file,"void _QML_Update()\n{\n");
	//printAttributes();

	//fprintf(file_classes2,"self->base.Update=_QML_Update;\n"); //
	printElementUpdaterAssignments();
	fprintf(file_classes2,"\t_QML_Update((GUI_Element *)self->_QML_element0);\n");

	
	//fprintf(file_classes2,"self->base.root=pointer;\n");
	fprintf(file_classes2,"\treturn *self;\n}\n");
	


	fprintf(file_classes2,"static void _QML_Update(GUI_Element *s)\n{\n\tGUI_Root%s * self=(GUI_Root%s *)s;\n",name.c_str(),name.c_str());
	fprintf(file_classes2,"\tmGUI_Element_Update((GUI_Element *)self);\n");
	//printAttributes(); // original
	fprintf(file_classes2,"\n}\n");

	printAttributesBodies();
	//
	//fprintf(file_classes2,"mGUI_Element_Update((GUI_Element *)self);\n}\n");
	printElementUpdaters();

	//printhand

	//fprintf(file,"\n}\n");

	fclose(file);
	fclose(file_classes);
	fclose(file_classes2);
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
				instance->attributes[attribCnt].handler=new GUIElementHandler();
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
				
				if(prop->attribute!=0)
				{
					instance->attributes[attribCnt]=GUIElementAttribute();
					instance->attributes[attribCnt].name=prop->attribute->name;
					instance->attributes[attribCnt].name2=0;
					instance->attributes[attribCnt].expression=prop->attribute->expression;
					instance->attributes[attribCnt].source=ExprToHandler(prop->attribute->expression);

					instance->attributes[attribCnt].handler=new GUIElementHandler();

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
		
		sprintf(str,"(*((GUI_Rootoutput%d *)context->root)->_QML_element%d)",treeInd,curId);
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
		sprintf(str,"(*((GUI_Rootoutput%d *)context->root)->_QML_element%d)",treeInd,curId);
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
		sprintf(str,"var%d",(varId-1));

		node->text=new char[strlen(str)+1];
		strcpy(node->text,str);
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
			sprintf(str,"(*((GUI_Rootoutput%d *)context->root)->_QML_element%d)",treeInd,curId);
			//sprintf(str,"(*self->localGroup->members[%d])",otherId);
			node->text=new char[strlen(str)+1];
			strcpy(node->text,str);
		}
		else
		{
			curId=currentElementId;
			ClassContainer * cont=elements[currentElementId].classContainer;
			PropertyAndType * prop=cont->CheckExistence(std::string(node->text));
			
			sprintf(str,"(*((GUI_Rootoutput%d *)context->root)->_QML_element%d)",treeInd,curId);
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
					sprintf(str,"var%d",(varId-1));

					node->text=new char[strlen(str)+1];
					strcpy(node->text,str);
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
	for(int l=0;l<ap->sentences.size();l++)
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
	char str[100];
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
				sprintf(str,"(*((GUI_Rootoutput%d *)context->root)->_QML_element%d)",treeInd,otherId);
				//sprintf(str,"(*self->localGroup->members[%d])",otherId);
				node->text=new char[strlen(str)+1];
				strcpy(node->text,str);
			}
			else if(isImportName)
			{
				int otherId=importToKeyMaps[treeInd][std::string(node->text)];
				
				free(node->text);
				sprintf(str,"GUI_Root%s",importPathToName[imports[otherId].path].c_str());
				//sprintf(str,"(*self->localGroup->members[%d])",otherId);
				node->text=new char[strlen(str)+1];
				strcpy(node->text,str);
			}
			else
			{
				if(strcmp("parent",node->text)==0)
				{
					free(node->text);
					sprintf(str,"(*((GUI_Rootoutput%d *)context->root)->_QML_element%d->parent)",treeInd,currentId);
					//sprintf(str,"(*self->localGroup->members[%d]->parent)",currentId);
					node->text=new char[strlen(str)+1];
					strcpy(node->text,str);
				}
				else
				{
					ClassContainer * cont=elements[currentId].classContainer;
					PropertyAndType * prop=cont->CheckExistence(std::string(node->text));
					if(prop!=0)
					{
						//
						sprintf(str,"((%s*)((GUI_Rootoutput%d *)context->root)->_QML_element%d)->%s",prop->cont->className.c_str(),treeInd,currentId,node->text);
							string checkStr=string("((GUI_Rootoutput")
							+std::to_string(static_cast<long long>(treeInd))
							+string(" *)context->root)->_QML_element")
							+std::to_string(static_cast<long long>(currentId));
						Checker checker;//(checkStr,string(node->text));
						checker.SetStartName(checkStr);
						checker.PushCheck(prop);//string(node->text));
						h->checkers.push_back(checker);
						
						std::string key=std::to_string(static_cast<long long>(currentId))+std::string(".")+std::string(node->text);

						free(node->text);
						node->text=new char[strlen(str)+1];
						strcpy(node->text,str);

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
	//		+string(" *)context->root)->_QML_element");
	
			
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
				completeName=string("((GUI_Rootoutput")
					+std::to_string(static_cast<long long>(treeInd))
					+string(" *)context->root)->_QML_element")
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
					//if(prop->cont)
					{

					}
					//else
					{
						// is basic type
						prevClassCont=0;
					}
				}
			}
		}
		else
		{
			assert(false);
			//unknown att error
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
	std::strcpy(node->text,completeStr.c_str());

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

			completeStr=std::string("(((GUI_Rootoutput")+std::to_string(static_cast<long long>(treeInd))+std::string(" *)((GUI_Element*)self)->root)->_QML_element")+std::to_string(static_cast<long long>(curId))+std::string(")");

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
					completeStr=std::string("(((GUI_Rootoutput")+std::to_string(static_cast<long long>(treeInd))+std::string(" *)((GUI_Element*)self)->root)->_QML_element")+std::to_string(static_cast<long long>(curId))+std::string(")");
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
					assert(false);
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
					assert(false);
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
	//	attribs=std::string("(*((GUI_Rootoutput")+std::to_string(static_cast<long long>(treeInd))+std::string(" *)((GUI_Element*)self)->root)->_QML_element")+std::to_string(static_cast<long long>(curId))+std::string(")")+attribs;
	//else
	//	attribs=std::string("(*(GUI_")+std::string(elements[curId].name)+std::string("*)((GUI_Rootoutput")+std::to_string(static_cast<long long>(treeInd))+std::string(" *)((GUI_Element*)self)->root)->_QML_element")+std::to_string(static_cast<long long>(curId))+std::string(")")+attribs;
		
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
		if(elementTree->members[i]->type==TYPE_IMPORT)
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
		if(elementTree->members[i]->type==TYPE_IMPORT)
		{
			continue;
		}

		// just one element as root
		rootElements[rootElementCount]=id;
		recursionConstructGUIStructures((ParserGUIElement*)elementTree->members[i]);
		elements[rootElements[rootElementCount]].parentId=-1;
		rootElementCount++;
	}

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
					assert(false);
					perror("same id multiple times");
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
				std::string className=std::string(elements[i].name)+std::string("Custom")+std::to_string(static_cast<long long>(customClassCount));
				customClassCount++;
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
				std::string className=std::string(elements[i].name)+std::string("Custom")+std::to_string(static_cast<long long>(customClassCount));
				customClassCount++;
				ClassContainer * cont=new ClassContainer(className, treeInd,totalClassCnt++);
				cont->SetAncestor(defaultClasses[defaultClassMap[string("GUI_")+string(elements[i].name)]]);
				
				elements[i].classContainer=cont;
			}
			else
			{
				elements[i].classContainer=defaultClasses[defaultClassMap[string("GUI_")+string(elements[i].name)]];
			}
		}

		for(int j=0;j<elements[i].propertiesCount;j++)
		{
			PropertyAndType temp;
			temp.name=elements[i].properties[j].name;
			// todo check default type
			if(strcmp(elements[i].properties[j].typeName,"int")!=0)
			{
				temp.type=(string("GUI_")+string(elements[i].properties[j].typeName));
			}
			else
			{
				temp.type=elements[i].properties[j].typeName+string("*");
				temp.name=temp.name;
			}

			elements[i].classContainer->AddProp(temp);
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
			///here
			if(t==0)
			{
					assert(false);
				perror("nonexistent atribute");
				exit(-1);
			}

			// check for existence after '.'
			if(att->name2!=0)
			{
				// todo? maybe check non-default too?
				t=defaultClasses[defaultClassMap[t->type]]->CheckExistence(std::string(att->name2));
				if(t==0)
				{
						assert(false);
					perror("nonexistent atribute");
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
			
			att->source->Process(treeInd,i);
			//processSrcReferences(att->expression,treeInd,i,false,false,graphInd,att->handler);
		}

		for(int j=0;j<elements[i].handlerCount;j++)
		{
			GUIElementHandler * handler=&elements[i].handlers[j];

			PropertyAndType* t= elements[i].classContainer->CheckExistence(std::string(handler->name));
			HandlerAndType* h= elements[i].classContainer->CheckHExistence(std::string(handler->name));
			///here
			if(t==0 && h==0)
			{
					assert(false);
				perror("nonexistent atribute");
				exit(-1);
			}

			if(t!=0 && h!=0)
			{
					assert(false);
				perror("handler and property has same name");
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
	file = fopen("file.c","w");
	fprintf(file,"%s","stuff");
	fclose(file);
}



bool processFile(const char * name)
{
	FILE *srcFile;
	srcFile = fopen(name,"r");
	
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

int main()
{
	processBasicTypes();

	//return 0;
	FILE *srcFile;
	int a=0;
	id=0;
	//srcFile = fopen("src4.cqml","r");
	
	identifiersCount=0;
	identifiersMax=1000;
	identifiers=(char**)malloc(sizeof(char*)*identifiersMax);
	identifiersIds=(int*)malloc(sizeof(int)*identifiersMax);

	// parse tree creation and import files detection
	processFile("src4.cqml");

	int importInd=0;
	while(importInd<importCnt)
	{
		if(importsProcessed[imports.at(importInd).path])
		{
			imports.at(importInd).processed=true;
		}
		else
		{
			processFile(imports.at(importInd).path.c_str());
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


	// source generation
	for(int i=0;i<elementTreeCnt;i++)
	{
		elements=elementGroups[i];
		elementCount=elementGroupSizes[i];

		makeSource(std::string("output")+std::to_string(static_cast<long long>(i)),i);
	}

	makeMainSource();

	//for(int i=0;)
	

    //yyrestart(srcFile);
	
	//if(yyparse())
	{
		a=1;//eror
	}
	//processTree(elementTree);
	//makeSource();
	//fclose(srcFile);
	printf("\n%d\n",compInd);
	//scanf("%d",&a);

	return 0;
}
