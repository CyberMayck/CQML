#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unordered_map>
//#include "lex.yy.c"
//#include "cqml_grammar.tab.c"
//#include "cqml_grammar.tab.h"
#include "cqml_grammar.tab.h"
#include "parser_tree.h"
typedef struct yy_buffer_state *YY_BUFFER_STATE;

void PrintNodeToFile(SrcNode* node);

class GUIElement;
class GUIElementAttribute;

class GUIElement
{
public:
	int id;
	char * name;
	GUIElement ** children;
	GUIElementAttribute * attributes;
	int childrenCount;
	int attributeCount;
};

class GUIElementAttribute
{
public:
	char * name;
	SrcNode * expression;
};

GUIElement * elements;
int elementCount;

ParserList* elementTree;
std::unordered_map<std::string, int> idMap;

extern "C"
{
YY_BUFFER_STATE yy_scan_string(char *);
YY_BUFFER_STATE yyrestart(FILE * file);
YY_BUFFER_STATE yyparse();
}

FILE *file;
int id;

int * identifiersIds;
char ** identifiers;
int identifiersCount;
int identifiersMax;

int rootElements[100];
int rootElementCount;



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



void printAttributes()
{
	int i;
	ParserAttribute* att;
	int currentId;
	currentId=id;

	for(int i=0;i<elementCount;i++)
	{
		for(int j=0;j<elements[i].attributeCount;i++)
		{
			GUIElementAttribute* att=&elements[i].attributes[j];
			if(strcmp("id",att->name)==0)
			{
				continue;
			}
			fprintf(file, "_QML_element%d->%s=",i,att->name);
				
			PrintNodeToFile(att->expression);
			fprintf(file, ";\n");
		}
	}
}


void recursionDeclaration()
{
	for(int i=0;i<elementCount;i++)
	{
		fprintf(file, "GUI_Element* _QML_element%d;\n",i);
	}
}

void recursionInit()
{
	for(int i=0;i<elementCount;i++)
	{
		fprintf(file, "_QML_element%d = (GUI_Element*)acGUI_%s();\n",i,elements[i].name);
		for(int j=0;j<elements[i].childrenCount;j++)
		{
			fprintf(file, "mGUI_Element_InsertChild((GUI_Element*)_QML_element%d, (GUI_Element*)_QML_element%d);\n",i,elements[i].children[j]->id);
		}
	}
}

void makeSource()
{
	//ParserList* list;
	int i;
	//list=(ParserList*)l;

	//printf("\n");
	//return;
	file = fopen("parser_output.c","w");
	
	fprintf(file, "GUI_Element* root;\n");
	id=0;

	recursionDeclaration();
	fprintf(file, "\n");
	
	id=0;
	fprintf(file,"void _QML_Init()\n{\n");
	fprintf(file, "root = (GUI_Element*) acGUI_Element();\n");
	
	for(int i=0;i<rootElementCount;i++)
	{
		fprintf(file, "mGUI_Element_InsertChild((GUI_Element*)root, (GUI_Element*)_QML_element%d);\n",rootElements[i]);
	}

	recursionInit();
		

	printAttributes();


	fprintf(file,"\n}\n");

	fclose(file);
}



GUIElement * recursionProcessTree(ParserGUIElement * element)
{
	int i;
	elements[id]=GUIElement();
	GUIElement * instance=&elements[id];

	int childCnt=0;
	int attribCnt=0;
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
		}
	}
	instance->attributeCount=attribCnt;
	instance->attributes=new GUIElementAttribute[attribCnt];
	instance->childrenCount=childCnt;
	instance->children=new GUIElement*[childCnt];
	instance->id=id;
	instance->name=element->name;


	id++;
	childCnt=0;
	attribCnt=0;
	if(element->list!=0)
	{
		for(i=0;i<element->list->memberCount;i++)
		{
			if(element->list->members[i]->type==TYPE_GUI_ELEMENT)
			{
				instance->children[childCnt]=recursionProcessTree((ParserGUIElement *)element->list->members[i]);
				childCnt++;
			}
			else if(element->list->members[i]->type==TYPE_ATTRIBUTE)
			{
				instance->attributes[attribCnt]=GUIElementAttribute();
				instance->attributes[attribCnt].name=((ParserAttribute *)element->list->members[i])->name;
				instance->attributes[attribCnt].expression=((ParserAttribute *)element->list->members[i])->expression;
				attribCnt++;
			}
		}
	}

	return instance;
}

int recursionCount(ParserGUIElement * element)
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

void processSrcReferences(SrcNode * node, int currentId, bool leftMostFound)
{
	char str[100];
	if(node->text!=0)
	{
		if(node->type==NODE_TYPE_ID)
		{
			bool isOtherId=false;//idMap.count(std::string(node->text))!=0;
			if(leftMostFound)
			{
				if(isOtherId)
				{
					int otherId=0;//idMap[std::string(node->text)];
					free(node->text);
					sprintf(str,"(*_QML_element%d)",otherId);
					node->text=new char[strlen(str)];
					strcpy(node->text,str);
				}
				else
				{
					if(strcmp("parent",node->text)==0)
					{
						free(node->text);
						sprintf(str,"(*_QML_element%d->parent)",currentId);
						node->text=new char[strlen(str)];
						strcpy(node->text,str);
					}
					else
					{
						sprintf(str,"(*_QML_element%d->%s)",currentId,node->text);
						free(node->text);
						node->text=new char[strlen(str)];
						strcpy(node->text,str);
					}
				}
			}
			//else
			//{
			//}
			leftMostFound=true;
		}
	}
	for(int i=0;i<node->childrenCount;i++)
	{
		processSrcReferences(node->children[i],currentId,leftMostFound);
	}
}


void PrintNodeToFile(SrcNode* node)
{
	int i;
	if((*node).text!=0)
	{
		fprintf(file, "%s",node->text);
	}
	for(i=0;i<(*node).childrenCount;i++)
	{
		PrintNodeToFile(node->children[i]);
	}
}

void processTree(ParserList* root)
{
	//int id=0;
	elementCount=0;
	for(int i=0;i<elementTree->memberCount;i++)
	{
		recursionCount((ParserGUIElement*)elementTree->members[i]);
	}
	elements=new GUIElement[elementCount];
	
	id=0;
	for(int i=0;i<elementTree->memberCount;i++)
	{
		rootElements[rootElementCount]=id;
		recursionProcessTree((ParserGUIElement*)elementTree->members[i]);
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
				//char * getString() error
				//idMap[std::string(att->name)]=i;
			}
			break; // should check for duplicities !!!
		}
	}

	// process expressions
	for(int i=0;i<elementCount;i++)
	{
		for(int j=0;j<elements[i].attributeCount;j++)
		{
			GUIElementAttribute * att=&elements[i].attributes[j];
			// should check for duplicities !!!

			if(strcmp(att->name,"id")==0)
				continue;
			processSrcReferences(att->expression,i,false);
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

int main()
{
	FILE *srcFile;
	int a=0;
	id=0;
	srcFile = fopen("src4.cqml","r");
	
	identifiersCount=0;
	identifiersMax=100;
	identifiers=(char**)malloc(sizeof(char*)*identifiersMax);
	identifiersIds=(int*)malloc(sizeof(int)*identifiersMax);
	

    yyrestart(srcFile);
	//yy_scan_string("Rectangle { Rectangle { Rectangle { }; }; Rectangle { }; }");
	
	if(yyparse())
	{
		a=1;//eror
	}
	processTree(elementTree);
	makeSource();
	fclose(srcFile);

	return 0;
}