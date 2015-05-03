#include "parser_tree.h"


SrcNode* MakeNode0KW(char * text)
{
	SrcNode* pointer=(SrcNode*)malloc(sizeof(SrcNode));
	(*pointer).childrenCount=0;
	(*pointer).children=0;

	int len=strlen(text);
	//if(len>2)
	{
		char * txt=(char * )malloc((len+3)*sizeof(char));
		strcpy_s(&txt[1],(len+1),text);
		txt[0]=' ';
		txt[len+1]=' ';
		txt[len+2]='\0';
		free(text);
		text=txt;
	}
	(*pointer).text=text;
	(*pointer).type=NODE_TYPE_LEAF;
	return pointer;
}

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


SrcNode* MakeNode1A(SrcNode* child1)
{
	SrcNode* pointer=(SrcNode*)malloc(sizeof(SrcNode));
	
	(*pointer).childrenCount=1;
	(*pointer).children=(SrcNode**)malloc(1*sizeof(SrcNode));
	(*pointer).text=0;
	(*pointer).type=NODE_TYPE_ASSIGN;

	(*pointer).children[0]=child1;
	return pointer;
}

SrcNode* MakeNode1STATM(SrcNode* child1)
{
	//return child1;
	SrcNode* pointer=(SrcNode*)malloc(sizeof(SrcNode));
	
	(*pointer).childrenCount=1;
	(*pointer).children=(SrcNode**)malloc(1*sizeof(SrcNode));
	(*pointer).text=0;
	(*pointer).type=NODE_TYPE_STATM;

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

SrcNode* MakeNode3A(SrcNode* child1,SrcNode* child2,SrcNode* child3)
{
	SrcNode* pointer=(SrcNode*)malloc(sizeof(SrcNode));
	
	(*pointer).childrenCount=3;
	(*pointer).children=(SrcNode**)malloc(3*sizeof(SrcNode));
	(*pointer).text=0;
	(*pointer).type=NODE_TYPE_ASSIGN;

	(*pointer).children[0]=child1;
	(*pointer).children[1]=child2;
	(*pointer).children[2]=child3;
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

SrcNode* MakeNode5ITER(SrcNode* child1,SrcNode* child2,SrcNode* child3,SrcNode* child4,SrcNode* child5)
{
	SrcNode* pointer=(SrcNode*)malloc(sizeof(SrcNode));
	
	(*pointer).childrenCount=5;
	(*pointer).children=(SrcNode**)malloc(5*sizeof(SrcNode));
	(*pointer).text=0;
	(*pointer).type=NODE_TYPE_ITER;

	(*pointer).children[0]=child1;
	(*pointer).children[1]=child2;
	(*pointer).children[2]=child3;
	(*pointer).children[3]=child4;
	(*pointer).children[4]=child5;
	return pointer;
}

SrcNode* MakeNode5(SrcNode* child1,SrcNode* child2,SrcNode* child3,SrcNode* child4,SrcNode* child5)
{
	SrcNode* pointer=(SrcNode*)malloc(sizeof(SrcNode));
	
	(*pointer).childrenCount=5;
	(*pointer).children=(SrcNode**)malloc(5*sizeof(SrcNode));
	(*pointer).text=0;
	(*pointer).type=NODE_TYPE_NORMAL;

	(*pointer).children[0]=child1;
	(*pointer).children[1]=child2;
	(*pointer).children[2]=child3;
	(*pointer).children[3]=child4;
	(*pointer).children[4]=child5;
	return pointer;
}


SrcNode* MakeNode6ITER(SrcNode* child1,SrcNode* child2,SrcNode* child3,SrcNode* child4,SrcNode* child5,SrcNode* child6)
{
	SrcNode* pointer=(SrcNode*)malloc(sizeof(SrcNode));
	
	(*pointer).childrenCount=6;
	(*pointer).children=(SrcNode**)malloc(6*sizeof(SrcNode));
	(*pointer).text=0;
	(*pointer).type=NODE_TYPE_ITER;

	(*pointer).children[0]=child1;
	(*pointer).children[1]=child2;
	(*pointer).children[2]=child3;
	(*pointer).children[3]=child4;
	(*pointer).children[4]=child5;
	(*pointer).children[5]=child6;
	return pointer;
}


SrcNode* MakeNode6(SrcNode* child1,SrcNode* child2,SrcNode* child3,SrcNode* child4,SrcNode* child5,SrcNode* child6)
{
	SrcNode* pointer=(SrcNode*)malloc(sizeof(SrcNode));
	
	(*pointer).childrenCount=6;
	(*pointer).children=(SrcNode**)malloc(6*sizeof(SrcNode));
	(*pointer).text=0;
	(*pointer).type=NODE_TYPE_NORMAL;

	(*pointer).children[0]=child1;
	(*pointer).children[1]=child2;
	(*pointer).children[2]=child3;
	(*pointer).children[3]=child4;
	(*pointer).children[4]=child5;
	(*pointer).children[5]=child6;
	return pointer;
}

SrcNode* MakeNode7(SrcNode* child1,SrcNode* child2,SrcNode* child3,SrcNode* child4,SrcNode* child5,SrcNode* child6,SrcNode* child7)
{
	SrcNode* pointer=(SrcNode*)malloc(sizeof(SrcNode));
	
	(*pointer).childrenCount=7;
	(*pointer).children=(SrcNode**)malloc(7*sizeof(SrcNode));
	(*pointer).text=0;
	(*pointer).type=NODE_TYPE_NORMAL;

	(*pointer).children[0]=child1;
	(*pointer).children[1]=child2;
	(*pointer).children[2]=child3;
	(*pointer).children[3]=child4;
	(*pointer).children[4]=child5;
	(*pointer).children[5]=child6;
	(*pointer).children[6]=child7;
	return pointer;
}

SrcNode* MakeNode7ITER(SrcNode* child1,SrcNode* child2,SrcNode* child3,SrcNode* child4,SrcNode* child5,SrcNode* child6,SrcNode* child7)
{
	SrcNode* pointer=(SrcNode*)malloc(sizeof(SrcNode));
	
	(*pointer).childrenCount=7;
	(*pointer).children=(SrcNode**)malloc(7*sizeof(SrcNode));
	(*pointer).text=0;
	(*pointer).type=NODE_TYPE_ITER;

	(*pointer).children[0]=child1;
	(*pointer).children[1]=child2;
	(*pointer).children[2]=child3;
	(*pointer).children[3]=child4;
	(*pointer).children[4]=child5;
	(*pointer).children[5]=child6;
	(*pointer).children[6]=child7;
	return pointer;
}

void makeParseTree(int *l)
{
	//ParserList* list;
//	int i;
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

int* createProperty(int *a, char *text, char * text2)
{
	ParserProperty * pointer;
	pointer=(ParserProperty*)malloc(sizeof(ParserProperty));
	(*pointer).typeName=text;
	(*pointer).attName=text2;
	(*pointer).attribute=0;
	(*pointer).base.type=TYPE_PROPERTY;
	return (int*)pointer;
}

int* createPropertyInit(int *a, int *attPointer, char * text)
{
	ParserProperty * pointer;
	pointer=(ParserProperty*)malloc(sizeof(ParserProperty));
	(*pointer).typeName=text;
	(*pointer).attribute=(ParserAttribute*)attPointer;
	(*pointer).attName=pointer->attribute->name;
	(*pointer).base.type=TYPE_PROPERTY;
	return (int*)pointer;
}

int* createAttribute(int* a, char b, char* name, SrcNode * cExpression)
{
	ParserAttribute * pointer;
	pointer=(ParserAttribute*)malloc(sizeof(ParserAttribute));
	(*pointer).name=name;
	(*pointer).name2=0;
	(*pointer).expression=cExpression;
	(*pointer).base.type=TYPE_ATTRIBUTE;
	return (int*)pointer;
}
int* createAttribute2(int* a, char b, char* name2, char* name, SrcNode * cExpression)
{
	ParserAttribute * pointer;
	pointer=(ParserAttribute*)malloc(sizeof(ParserAttribute));
	(*pointer).name=name;
	(*pointer).name2=name2;
	(*pointer).expression=cExpression;
	(*pointer).base.type=TYPE_ATTRIBUTE;
	return (int*)pointer;
}


int* createImport(char* path, char* name)
{
	ParserImport * pointer;
	pointer=(ParserImport*)malloc(sizeof(ParserImport));
	(*pointer).name=name;
	(*pointer).path=path;
	(*pointer).base.type=TYPE_IMPORT;
	return (int*)pointer;
}
int* createInclude(char* path)
{
	ParserInclude * pointer;
	pointer=(ParserInclude*)malloc(sizeof(ParserInclude));
	(*pointer).path=path;
	(*pointer).base.type=TYPE_INCLUDE;
	return (int*)pointer;
}


int* createHandler(int* a, char b, char* name, SrcNode * code)
{
	ParserHandler * pointer;
	pointer=(ParserHandler*)malloc(sizeof(ParserHandler));
	(*pointer).name=name;
	(*pointer).code=code;
	(*pointer).base.type=TYPE_HANDLER;
	return (int*)pointer;
}
int* createAttributeHandler(int* a, char b, char* name, SrcNode * cExpression)
{
	ParserAttribute * pointer;
	pointer=(ParserAttribute*)malloc(sizeof(ParserAttribute));
	(*pointer).name=name;
	(*pointer).name2=0;
	(*pointer).expression=cExpression;
	(*pointer).base.type=TYPE_ATTRIBUTE_HANDLER;
	return (int*)pointer;
}
int* createAttribute2Handler(int* a, char b, char* name2, char* name, SrcNode * cExpression)
{
	ParserAttribute * pointer;
	pointer=(ParserAttribute*)malloc(sizeof(ParserAttribute));
	(*pointer).name=name;
	(*pointer).name2=name2;
	(*pointer).expression=cExpression;
	(*pointer).base.type=TYPE_ATTRIBUTE_HANDLER;
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



