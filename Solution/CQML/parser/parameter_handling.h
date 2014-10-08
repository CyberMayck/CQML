#pragma once
#include <string>
#include <vector>
using namespace std;
unsigned long CRC32(char * str, unsigned int len);

int processBasicTypes();
class ClassContainer;

class PropertyAndType
{
public:
	string type;
	string name;
	long nameHash;
	ClassContainer* cont;
};


class ClassContainer
{
	ClassContainer* ancestor;

public:
	long classHash;
	int fileId;
	string className;
	vector<PropertyAndType> props;

	ClassContainer(string str, int fileId);
	void SetAncestor(ClassContainer *);
	void AddProp(PropertyAndType);
	ClassContainer* GetAncestor();
	PropertyAndType* CheckExistence(string);
};