#pragma once
#include <string>
#include <vector>
#include<stdarg.h>
#include "hashing.h"
using namespace std;
unsigned long CRC32(char * str, unsigned int len);

int processBasicTypes();
void PrintClassTabs(FILE * file, int cnt);
void PrintClassHashTabs(FILE * file, int cnt);

class ClassContainer;

class PropertyAndType
{
public:
	string type;
	string name;
	long nameHash;
	ClassContainer* cont;
	bool IsReference();
	bool IsPrimitive();
};

class HandlerAndType
{
public:
	string returnType;
	string name;
	vector<string> paramTypes;
	vector<string> paramNames;
	ClassContainer * cont;
};

class PrimitiveType
{
public:
	string name;
	PrimitiveType(string);
};

class ClassContainer
{
	ClassContainer* ancestor;

public:
	long classHash;
	int classID;
	int fileId;
	bool isReferencable;
	string className;
	vector<PropertyAndType> props;
	vector<HandlerAndType> handlers;
	PerfectHashData * hashData;

	ClassContainer(string str, int fileId, int classID);
	void SetAncestor(ClassContainer *);
	void AddProp(PropertyAndType);
	ClassContainer* GetAncestor();
	PropertyAndType* CheckExistence(string);

	void AddHandler(HandlerAndType);
	HandlerAndType* CheckHExistence(string);
};


ClassContainer* GetDefaultClassContainer(string);
ClassContainer* GetClassContainer(string n, int treeInd);