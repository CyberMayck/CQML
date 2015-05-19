#pragma once
#include <vector>
#include <unordered_map>

struct SrcNode;
struct AssignmentOperator;

using namespace std;


class SourceStatementToken;

class SourceToken
{
public:
	virtual void Print(string&)=0;
	virtual void PrintZeroUpdaters(string&);
	virtual void Process(int , int , SourceStatementToken*, bool);
};
class SourceTokenContainer : public SourceToken
{
public:
	virtual void PushToken(SourceToken *)=0;
};

class SourceHandler: public SourceTokenContainer
{
	vector<SourceToken*> tokens;
public:
	void Process(int treeInd, int currentElementId);
	void Print(string&);
	void PushToken(SourceToken *);
};

class SourceStringToken: public SourceToken
{
	string str;
public:
	SourceStringToken(SrcNode* node);
	void Print(string&);
};

class SourceStatementToken : public SourceTokenContainer
{
	vector<SourceToken *> tokens;
public:
	//SourceStatementToken();
	void Print(string&);
	void PushToken(SourceToken *);
	void Process(int , int , SourceStatementToken*, bool);
};

class SourceIdToken : public SourceToken
{
	string str;
	bool isElement;
	bool isVar;
	int fileId;
	int elementId;
	int variableId;
public:
	SourceIdToken(SrcNode *);
	string GetId();
	void Print(string&);
	void Process(int , int , SourceStatementToken*, bool);
	virtual void PrintZeroUpdaters(string& dest);
};

class SourceDotToken : public SourceToken
{
	vector<SourceToken *> tokens;
	vector<SourceIdToken *> identifiers;
	vector<bool> isStatic;
	bool isVarReplaced;
	int variableId;
	int fileId;
public:
	SourceDotToken(SrcNode *);
	void PushToken(SourceToken *);
	void PushIdToken(SourceIdToken *);
	void Print(string&);
	void Process(int , int , SourceStatementToken*, bool);
	virtual void PrintZeroUpdaters(string& dest);
};
class SourceExprToken: public SourceTokenContainer
{
	vector<SourceToken *> tokens;
	bool isVar;
	int variableId;
public:
	SourceExprToken(SrcNode *);
	void PushToken(SourceToken *);
	void Print(string&);
	void Process(int , int , SourceStatementToken*, bool);
	virtual void PrintZeroUpdaters(string& dest);
};

class SourceAssignmentToken : public SourceToken
{
	//vector<SourceToken *> nodes;
	vector<SourceExprToken *> nodes;
	vector<AssignmentOperator> ops;
public:
	SourceAssignmentToken(SrcNode *);
	void PushSubNode(SrcNode * node);
	void PushOperator(AssignmentOperator op);
	void Construct(SrcNode* node);
	void Print(string&);
	void Process(int , int , SourceStatementToken*, bool);
};


#include <string>
using namespace std;

struct AssignmentOperator
{
	string str;
};

struct AssignSentence
{
	vector<SrcNode *> nodes;
	vector<AssignmentOperator> ops;
};


void ProcessSource(SourceHandler * handler);

SourceHandler* ExprToHandler(SrcNode * node);
SourceHandler* SourceToHandler(SrcNode * node);

