#pragma once


#include <string.h>
#include <stdlib.h>


struct ClassAttibuteTable
{
	//hash and bla
	// is primitive?
	int isPrimitive;
	AttributeHash * AttributeHash;
};

// record of parameter
struct TableRecord
{
	char * name;
	long typeId;
	
	//void ** updater; // pointer to pointer on updater function of said parameter
	int updaterOffset;

	int offset;
	int size;
};

struct ClassAttribute
{
	char * name;
	long typeId;
	void (*Setter)(void* obj,value_type in);
	value_type (*Getter)(void* obj);
	
	int offset;
	int size;
};

struct AttributeHash
{
	long hash;
	char * type;
	int offset;
	int size;
	//type
};

//obj.width = stuff.height
class AttributeProxy
{
public:
	long type;
};

class AttributeProxyFloat
{
	float * attPointer;

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


struct ClassAttributeTable
{
	int size;
	TableRecord * records;
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
void InitClassesSize(ClassHashTable*& tabs,int cnt);
void InitAttribCnt(int classInd,int cnt, int parentInd);
void AddAttribute(int classInd,long nameHash, int offset, char*typeName, int typeSize);
void InitHashTab(ClassHashTable * tab, int n, int m);
void QMLInitHashes();

int GetHash(long classID, const char* name);