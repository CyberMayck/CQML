#include "parser_tree.h"



SrcNode* MakeNode0(char * text)
{
	SrcNode* pointer=(SrcNode*)malloc(sizeof(SrcNode));
	(*pointer).childrenCount=0;
	(*pointer).children=0;
	(*pointer).text=text;
	(*pointer).type=NODE_TYPE_LEAF;
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
	return child1;
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
SrcNode* MakeNode3Dot(SrcNode* child1,SrcNode* child2,SrcNode* child3)
{
	SrcNode* pointer=MakeNode3(child1,child2,child3);
	pointer->type=NODE_TYPE_DOT;
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

void makeParseTree(int *l)
{
	//ParserList* list;
	int i;
	elementTree=(ParserList*)l;
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



