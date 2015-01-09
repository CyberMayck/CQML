#pragma once
#include <vector>
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

class GetSetter
{
public:
	virtual void print()=0;
};

class Setter:public GetSetter
{
public:
	string dest;
	string key;
	string src;
	Setter(string, string, string);
	void print();
};

class Expr:public GetSetter
{
public:
	string dest;
	string expr;
	Expr(string,string);
	void print();
};
class Getter:public GetSetter
{
public:
	string src;
	string key;
	string dest;
	Getter(string, string, string);
	void print();
};

struct SrcApendix
{
public:
	vector<GetSetter*> getsetters;
	vector<AssignSentence> sentences;
	void addSetter(int, string ,int);
	void addSetter(string, string ,int);
	void addGetter(int, string ,int);
	void addGetter(string, string ,int);
	void addExpr(int, string);
};