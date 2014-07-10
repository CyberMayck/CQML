
#define TYPE_GUI_ELEMENT		(0)
#define TYPE_ATTRIBUTE			(1)

#define NODE_TYPE_NORMAL		(0)
#define NODE_TYPE_ID			(1)
#define NODE_TYPE_DOT			(2)
#define NODE_TYPE_DOT_PROCESSED	(3)
#define NODE_TYPE_LEAF			(4)

typedef struct ParserList ParserList;
typedef struct ParserGUIElement ParserGUIElement;
typedef struct ParserAttribute ParserAttribute;
typedef struct ParserListElement ParserListElement;
typedef struct SrcNode SrcNode;

#include <stdio.h>
#include <stdlib.h>


extern ParserList* elementTree;
extern int id;

#ifdef __cplusplus
extern "C"
{
	SrcNode* MakeNode0(char * text);
	SrcNode* MakeNode0ID(char * text);
	SrcNode* MakeNode1(SrcNode* child1);
	SrcNode* MakeNode2(SrcNode* child1,SrcNode* child2);
	SrcNode* MakeNode3(SrcNode* child1,SrcNode* child2,SrcNode* child3);
	SrcNode* MakeNode3Dot(SrcNode* child1,SrcNode* child2,SrcNode* child3);
	SrcNode* MakeNode4(SrcNode* child1,SrcNode* child2,SrcNode* child3,SrcNode* child4);

	int* createAttribute(int* a, char b, char* name, SrcNode * cExpression);
	int* createElement(int *a, char b, int *listPointer, char * text);
	int* createList(int *elementPointer, char type, int *listPointer, char * d);
	void makeParseTree(int *l);
}
#else
	int* createElement(int *a, char b, int *c, char * d);
	int* createList(int *a, char b, int *c, char * d);
	int* createAttribute(int *a, char b, char *c, char * d);
	int* MakeNode0ID(char * text);
	int* MakeNode0(char * text);
	int* MakeNode1(int* child1);
	int* MakeNode2(int* child1,int* child2);
	int* MakeNode3(int* child1,int* child2,int* child3);
	int* MakeNode3Dot(int* child1,int* child2,int* child3);
	int* MakeNode4(int* child1,int* child2,int* child3,int* child4);
	void makeParseTree(int *l);
#endif


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