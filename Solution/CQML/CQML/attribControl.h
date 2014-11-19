#pragma once

#include <string.h>
#include <stdlib.h>

typedef struct AttributeCheck AttributeCheck;
typedef struct AttributeHash AttributeHash;

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

int checkAttributeInd(int classInd, int attHash);
int checkAttributeExistence(int classInd, int attHash);
void InitClassesSize(int cnt);
void InitAttribCnt(int classInd,int cnt, int parentInd);
void AddAttribute(int classInd,long nameHash, int offset, char*typeName, int typeSize);