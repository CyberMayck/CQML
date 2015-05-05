#pragma once
#include <string>
#include <vector>

class ClassContainer;
class SourceHandler;
struct SrcNode;
class Checker;

using namespace std;

class GUIElement;
class GUIElementAttribute;
class GUIElementProperty;
class GUIElementHandler;
class GUIImport;

class GUIImport
{
public:
	bool processed;
	GUIImport();
	std::string name;
	std::string path;
	int treeInd;
};
class GUIInclude
{
public:
	GUIInclude();
	std::string path;
	int treeInd;
};

class GraphNode
{
public:
	string key;
	vector<int> nextNodes;
};


class GUIElement
{
public:
	int id;
	int parentId;
	char * name;
	char * origClassName;
	char * importName;
	bool hasCustomClass;
	GUIElement ** children;
	GUIElementAttribute * attributes;
	GUIElementProperty * properties;
	GUIElementHandler * handlers;
	int childrenCount;
	int attributeCount;
	int handlerCount;
	int propertiesCount;

	ClassContainer* classContainer;
	GUIElement();
};


class GUIElementProperty
{
public:
	char * typeName;
	char * name;
	int hasUpdater;
	//int graphInd;
};

class GUIElementAttribute
{
public:
	char * name;
	char * name2;
	SrcNode * expression;
	SourceHandler * source;
	SourceHandler * handler;

	//GUIElementHandler * handler;
	int graphInd;
};


class GUIElementHandler
{
public:
	char * name;
	SrcNode * code;
	int graphInd;
	bool isProperty;
	SourceHandler * source;
	vector<Checker> checkers;

	void CheckerPrint(FILE *);
};
