
#define TYPE_GUI_ELEMENT		(0)
#define TYPE_ATTRIBUTE			(1)
#define TYPE_PROPERTY			(2)
#define TYPE_HANDLER			(3)
#define TYPE_IMPORT				(4)

#define NODE_TYPE_NORMAL		(0)
#define NODE_TYPE_ID			(1)
#define NODE_TYPE_DOT			(2)
#define NODE_TYPE_DOT_PROCESSED	(3)
#define NODE_TYPE_ASSIGN		(4)
#define NODE_TYPE_ASSIGN_PROCESSED	(5)
#define NODE_TYPE_EXPRESSION	(6)
#define NODE_TYPE_ITER			(7)
#define NODE_TYPE_STATM			(8)
#define NODE_TYPE_LEAF			(9)

typedef struct ParserImport ParserImport;
typedef struct ParserList ParserList;
typedef struct ParserGUIElement ParserGUIElement;
typedef struct ParserAttribute ParserAttribute;
typedef struct ParserHandler ParserHandler;
typedef struct ParserProperty ParserProperty;
typedef struct ParserListElement ParserListElement;
typedef struct SrcNode SrcNode;

#include <stdio.h>
#include <stdlib.h>


extern ParserList* elementTree;
extern int id;

#ifdef __cplusplus
#include "src_apendix.h"
extern "C"
{
	SrcNode* MakeNode0(char * text);
	SrcNode* MakeNode0ID(char * text);
	SrcNode* MakeNode1(SrcNode* child1);
	SrcNode* MakeNode1A(SrcNode* child1);
	SrcNode* MakeNode1STATM(SrcNode* child1);
	SrcNode* MakeNode2(SrcNode* child1,SrcNode* child2);
	SrcNode* MakeNode3(SrcNode* child1,SrcNode* child2,SrcNode* child3);
	SrcNode* MakeNode3A(SrcNode* child1,SrcNode* child2,SrcNode* child3);
	SrcNode* MakeNode3Dot(SrcNode* child1,SrcNode* child2,SrcNode* child3);
	SrcNode* MakeNode4(SrcNode* child1,SrcNode* child2,SrcNode* child3,SrcNode* child4);
	SrcNode* MakeNode5(SrcNode* child1,SrcNode* child2,SrcNode* child3,SrcNode* child4,SrcNode* child5);
	SrcNode* MakeNode5ITER(SrcNode* child1,SrcNode* child2,SrcNode* child3,SrcNode* child4,SrcNode* child5);
	SrcNode* MakeNode6ITER(SrcNode* child1,SrcNode* child2,SrcNode* child3,SrcNode* child4,SrcNode* child5,SrcNode* child6);
	SrcNode* MakeNode7ITER(SrcNode* child1,SrcNode* child2,SrcNode* child3,SrcNode* child4,SrcNode* child5,SrcNode* child6,SrcNode* child7);

	SrcNode* MakeNode6(SrcNode* child1,SrcNode* child2,SrcNode* child3,SrcNode* child4,SrcNode* child5,SrcNode* child6);
	SrcNode* MakeNode7(SrcNode* child1,SrcNode* child2,SrcNode* child3,SrcNode* child4,SrcNode* child5,SrcNode* child6,SrcNode* child7);

	int* createAttribute(int* a, char b, char* name, SrcNode * cExpression);
	int* createAttribute2(int* a, char b, char* name2, char* name, SrcNode * cExpression);
	int* createHandler(int* a, char b, char* name, SrcNode * code);
	int* createElement(int *a, char b, int *listPointer, char * text);
	int* createPropertyInit(int *a, int *attPointer, char * text);
	int* createProperty(int *a, char * text, char * text2);
	int* createList(int *elementPointer, char type, int *listPointer, char * d);
	int* createImport( char * text, char * text2);
	void makeParseTree(int *l);
}
#else
	int* createElement(int *a, char b, int *c, char * d);
	int* createList(int *a, char b, int *c, char * d);
	int* createPropertyInit(int *a, int *attPointer, char * text);
	int* createProperty(int *a, char * text, char * text2);
	int* createAttribute(int *a, char b, char *c, char * d);
	int* createAttribute2(int *a, char b, char *c2, char *c, char * d);
	int* createImport( char * text, char * text2);
	int* createHandler(int *a, char b, char *c, char * d);
	int* MakeNode0ID(char * text);
	int* MakeNode0(char * text);
	int* MakeNode1(int* child1);
	int* MakeNode1A(int* child1);
	int* MakeNode1STATM(int* child1);
	int* MakeNode2(int* child1,int* child2);
	int* MakeNode3(int* child1,int* child2,int* child3);
	int* MakeNode3A(int* child1,int* child2,int* child3);
	int* MakeNode3Dot(int* child1,int* child2,int* child3);
	int* MakeNode4(int* child1,int* child2,int* child3,int* child4);
	int* MakeNode5(int* child1,int* child2,int* child3,int* child4,int* child5);

	int* MakeNode5ITER(int* child1,int* child2,int* child3,int* child4,int* child5);
	int* MakeNode6ITER(int* child1,int* child2,int* child3,int* child4,int* child5,int* child6);
	int* MakeNode7ITER(int* child1,int* child2,int* child3,int* child4,int* child5,int* child6,int* child7);
	

	int* MakeNode6(int* child1,int* child2,int* child3,int* child4,int* child5,int* child6);
	int* MakeNode7(int* child1,int* child2,int* child3,int* child4,int* child5,int* child6,int* child7);
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
	char * name2;
	SrcNode * expression;
};
struct ParserHandler{
	ParserListElement base;
	char * name;
	SrcNode * code;
};
struct ParserProperty {
	ParserListElement base;
	ParserAttribute* attribute;
	char * typeName;
	char * attName;
};
struct ParserList {
	ParserListElement ** members;
	int memberCount;
};
struct ParserImport {
	ParserListElement base;
	char * path;
	char * name;
};

struct SrcNode{
	SrcNode ** children;
	int childrenCount;
	char* text;
	int type;
	
#ifdef __cplusplus
	SrcApendix *apendix;
#else
	int* apendix;
#endif
};