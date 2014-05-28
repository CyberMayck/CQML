#include <stdio.h>
#include <stdlib.h>
//#include "lex.yy.c"
//#include "cqml_grammar.tab.c"
//#include "cqml_grammar.tab.h"
#include "y.tab.h"
typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE yy_scan_string(char *);
YY_BUFFER_STATE yyrestart(FILE * file);
YY_BUFFER_STATE yyparse();

FILE *file;
int id;

#define TYPE_GUI_ELEMENT		(0)
#define TYPE_ATTRIBUTE			(1)

#define NODE_TYPE_NORMAL		(0)
#define NODE_TYPE_ID			(1)

typedef struct ParserList ParserList;
typedef struct ParserGUIElement ParserGUIElement;
typedef struct ParserAttribute ParserAttribute;
typedef struct ParserListElement ParserListElement;
typedef struct SrcNode SrcNode;

struct ParserListElement{
	int type;
};

struct ParserGUIElement {
	ParserListElement base;
	ParserList* list;
	char * name;
};
struct ParserAttribute{
	ParserListElement base;
	char * name;
	SrcNode * expression;
};
struct ParserList {
	ParserListElement ** members;
	int memberCount;
};

struct SrcNode{
	SrcNode ** children;
	int childrenCount;
	char* text;
	int type;
};

void PrintNode(SrcNode* node)
{
	int i;
	if((*node).text!=0 && (*node).type==NODE_TYPE_ID)
	{
		//
		printf("id: %s",(*node).text);
	}
	for(i=0;i<(*node).childrenCount;i++)
	{
		PrintNode((*node).children[i]);
	}
}


SrcNode* MakeNode0(char * text)
{
	SrcNode* pointer=(SrcNode*)malloc(sizeof(SrcNode));
	(*pointer).childrenCount=0;
	(*pointer).children=0;
	(*pointer).text=text;
	(*pointer).type=NODE_TYPE_NORMAL;
	return pointer;
}
SrcNode* MakeNode0ID(char * text)
{
	SrcNode* pointer=MakeNode0(text);
	(*pointer).type=NODE_TYPE_ID;
	return pointer;
}

SrcNode* MakeNode1(SrcNode* child1)
{
	SrcNode* pointer=(SrcNode*)malloc(sizeof(SrcNode));
	
	(*pointer).childrenCount=1;
	(*pointer).children=(SrcNode**)malloc(1*sizeof(SrcNode));
	(*pointer).text=0;
	(*pointer).type=NODE_TYPE_NORMAL;

	(*pointer).children[0]=child1;
	return pointer;
}


SrcNode* MakeNode2(SrcNode* child1,SrcNode* child2)
{
	SrcNode* pointer=(SrcNode*)malloc(sizeof(SrcNode));
	
	(*pointer).childrenCount=2;
	(*pointer).children=(SrcNode**)malloc(2*sizeof(SrcNode));
	(*pointer).text=0;
	(*pointer).type=NODE_TYPE_NORMAL;

	(*pointer).children[0]=child1;
	(*pointer).children[1]=child2;
	return pointer;
}

SrcNode* MakeNode3(SrcNode* child1,SrcNode* child2,SrcNode* child3)
{
	SrcNode* pointer=(SrcNode*)malloc(sizeof(SrcNode));
	
	(*pointer).childrenCount=3;
	(*pointer).children=(SrcNode**)malloc(3*sizeof(SrcNode));
	(*pointer).text=0;
	(*pointer).type=NODE_TYPE_NORMAL;

	(*pointer).children[0]=child1;
	(*pointer).children[1]=child2;
	(*pointer).children[2]=child3;
	return pointer;
}

SrcNode* MakeNode4(SrcNode* child1,SrcNode* child2,SrcNode* child3,SrcNode* child4)
{
	SrcNode* pointer=(SrcNode*)malloc(sizeof(SrcNode));
	
	(*pointer).childrenCount=4;
	(*pointer).children=(SrcNode**)malloc(4*sizeof(SrcNode));
	(*pointer).text=0;
	(*pointer).type=NODE_TYPE_NORMAL;

	(*pointer).children[0]=child1;
	(*pointer).children[1]=child2;
	(*pointer).children[2]=child3;
	(*pointer).children[3]=child4;
	return pointer;
}

void recursionAttributesProcessing(ParserGUIElement * element, int parentId)
{
	int i;

	int currentId;
	currentId=id;
	
	id++;
	if((*element).list!=0)
	{
		for(i=0;i<(*(*element).list).memberCount;i++)
		{
			if((*(*(*element).list).members[i]).type==TYPE_GUI_ELEMENT)
				recursionAttributesProcessing((ParserGUIElement*)(*(*element).list).members[i], currentId);
			if((*(*(*element).list).members[i]).type==TYPE_ATTRIBUTE)
			{
				
//				sprintf(str, "%d", currentId);
				PrintNode((*((ParserAttribute*)(*(*element).list).members[i])).expression);
			}
		}
	}


	//printf("}; ");
	//fprintf(file,"}; ");
}

void recursionDeclaration(ParserGUIElement * element)
{
	int i;
	//printf("%s { ",(*element).name);
	//fprintf(file,"%s { ",(*element).name);
	
	fprintf(file, "GUI_Element* _QML_element%d;\n",id);
	id++;
	if((*element).list!=0)
	{
		for(i=0;i<(*(*element).list).memberCount;i++)
		{
			if((*(*(*element).list).members[i]).type==TYPE_GUI_ELEMENT)
				recursionDeclaration((ParserGUIElement *)(*(*element).list).members[i]);
		}
	}


	//printf("}; ");
	//fprintf(file,"}; ");
}

void recursionInit(ParserGUIElement * element, int parentId)
{
	int i;
	//printf("%s { ",(*element).name);
	//fprintf(file,"%s { ",(*element).name);

	int currentId;
	currentId=id;
	fprintf(file, "_QML_element%d = (GUI_Element*)acGUI_%s();\n",currentId,(*element).name);
	
	if(parentId>0)fprintf(file, "mGUI_Element_InsertChild((GUI_Element*)_QML_element%d, (GUI_Element*)_QML_element%d);\n",parentId,currentId);
	else fprintf(file, "mGUI_Element_InsertChild((GUI_Element*)root, (GUI_Element*)_QML_element%d);\n",currentId);

	id++;
	if((*element).list!=0)
	{
		for(i=0;i<(*(*element).list).memberCount;i++)
		{
			if((*(*(*element).list).members[i]).type==TYPE_GUI_ELEMENT)
				recursionInit((ParserGUIElement*)(*(*element).list).members[i], currentId);
		}
	}


	//printf("}; ");
	//fprintf(file,"}; ");
}


void makeSource(int *l)
{
	ParserList* list;
	int i;
	list=(ParserList*)l;
	//printf("\n");
	//return;
	file = fopen("file.c","w");
	
	fprintf(file, "GUI_Element* root;\n");
	id=1;
	//(*list).memberCount
	for(i=0;i<(*list).memberCount;i++)
	{
		recursionDeclaration((ParserGUIElement*)(*list).members[i]);
	}
	fprintf(file, "\n");
	
	id=1;
	fprintf(file,"void _QML_Init()\n{\n");
	fprintf(file, "root = (GUI_Element*) acGUI_Element();\n");
	
	for(i=0;i<(*list).memberCount;i++)
	{
		recursionInit((ParserGUIElement*)(*list).members[i],-1);
	}
	fprintf(file,"}\n");
	
	id=1;
	for(i=0;i<(*list).memberCount;i++)
	{
		recursionAttributesProcessing((ParserGUIElement*)(*list).members[i],-1);
	}

	fclose(file);
}

int* createElement(int *a, char b, int *listPointer, char * text)
{
	ParserGUIElement * pointer;
	pointer=(ParserGUIElement*)malloc(sizeof(ParserGUIElement));
	(*pointer).list=(ParserList*)listPointer;
	(*pointer).name=text;
	(*pointer).base.type=TYPE_GUI_ELEMENT;
	return (int*)pointer;
}



int* createAttribute(int* a, char b, char* name, SrcNode * cExpression)
{
	ParserAttribute * pointer;
	pointer=(ParserAttribute*)malloc(sizeof(ParserAttribute));
	(*pointer).name=name;
	(*pointer).expression=cExpression;
	(*pointer).base.type=TYPE_ATTRIBUTE;
	return (int*)pointer;
}


int* createList(int *elementPointer, char type, int *listPointer, char * d)
{
	ParserList * list;
	ParserListElement * pointer;
	ParserListElement ** oldChildren;
	int i;
	list=(ParserList*)listPointer;
	pointer=(ParserListElement*)elementPointer;
	if(list==0)
	{
		//new List
		list=(ParserList*)malloc(sizeof(ParserList));
		(*list).memberCount=0;
	}
	

	//

	
	oldChildren=(*list).members;
	(*list).members=(ParserListElement **) malloc(((*list).memberCount+1)*sizeof(ParserListElement *));
	
	for(i=0;i<(*list).memberCount;i++)
	{
		(*list).members[i+1]=oldChildren[i];
	}

	(*list).members[0]=pointer;
	if((*list).memberCount>0)
	{
		free(oldChildren);
	}
	(*list).memberCount++;
	//


	return (int*)list;
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
	srcFile = fopen("src2.cqml","r");
	
    yyrestart(srcFile);
	//yy_scan_string("Rectangle { Rectangle { Rectangle { }; }; Rectangle { }; }");
	
	if(yyparse())
	{
		a=1;//eror
	}
	fclose(srcFile);

	return 0;
}