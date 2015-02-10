#pragma once

#include <string.h>
#include <stdlib.h>

typedef union value_type value_type;

typedef struct AttributeCheck AttributeCheck;
typedef struct AttributeHash AttributeHash;

typedef struct ClassHashTable;

typedef struct ClassAttibuteTable ClassAttibuteTable;
typedef struct Attribute Attibute;

struct ClassAttibuteTable
{
	//hash and bla
	// is primitive?
	int isPrimitive;
	AttributeHash * AttributeHash;
};

struct ClassAttributeTable
{
	char * name;
	long typeId;
	void (*Setter)(void* obj,value_type in);
	value_type (*Getter)(void* obj);
};

struct AttributeHash
{
	long hash;
	char * type;
	int offset;
	int size;
	//type
};

struct AttributeCheck
{
	int parentInd;
	int attributCnt;
	AttributeHash* attributs;
};


typedef struct Attribute Attribute;
struct Attribute
{
	int typeId;
	void * value;
};

struct ClassHashTable
{
	char ** keys; // m
	int * T1; // m
	int * T2; // m
	int * g; // n
	int m;
	int n;
};

int checkAttributeInd(int classInd, int attHash);
int checkAttributeExistence(int classInd, int attHash);
void InitClassesSize(int cnt);
void InitAttribCnt(int classInd,int cnt, int parentInd);
void AddAttribute(int classInd,long nameHash, int offset, char*typeName, int typeSize);
void InitHashTab(ClassHashTable * tab, int n, int m);
void QMLInitHashes();