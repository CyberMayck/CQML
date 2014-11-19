#pragma once
#include <string>
#include <vector>
using namespace std;
unsigned long CRC32(char * str, unsigned int len);

int processBasicTypes();
void PrintClassTabs(FILE * file, int cnt);
class ClassContainer;

class PropertyAndType
{
public:
	string type;
	string name;
	long nameHash;
	ClassContainer* cont;
	bool IsReference();
};


class ClassContainer
{
	ClassContainer* ancestor;

public:
	long classHash;
	int classID;
	int fileId;
	string className;
	vector<PropertyAndType> props;

	ClassContainer(string str, int fileId, int classID);
	void SetAncestor(ClassContainer *);
	void AddProp(PropertyAndType);
	ClassContainer* GetAncestor();
	PropertyAndType* CheckExistence(string);
};