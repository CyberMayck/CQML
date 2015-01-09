
//#include "src_apendix.h"
//#include <vector>
//#include <string>

#include <vector>
#include <string>

#include "parser_tree.h"
#include "src_apendix.h"

Setter::Setter(string d,string k, string s)
{
	dest=d;
	key=k;
	src=s;
}
Getter::Getter(string s,string k, string d)
{
	src=s;
	key=k;
	dest=d;
}
Expr::Expr(string d, string e)
{
	dest=d;
	expr=e;
}

void Getter::print()
{
}
void Setter::print()
{
}
void Expr::print()
{
}

void SrcApendix::addSetter(int d, string k ,int s)
{
	getsetters.push_back(new Setter(string("var")+std::to_string(static_cast<long long>(d)),
		k,string("var")+std::to_string(static_cast<long long>(s)) ));
}
void SrcApendix::addSetter(string d, string k,int s)
{
	getsetters.push_back(new Setter(d,
		k,string("var")+std::to_string(static_cast<long long>(s)) ));
}
void SrcApendix::addGetter(int s, string k,int d)
{
	getsetters.push_back(new Getter(string("var")+std::to_string(static_cast<long long>(s)),
		k,string("var")+std::to_string(static_cast<long long>(d)) ));
}
void SrcApendix::addGetter(string s, string k,int d)
{
	getsetters.push_back(new Getter(s,
		k,string("var")+std::to_string(static_cast<long long>(d)) ));
}

void SrcApendix::addExpr(int d, string e)
{
	getsetters.push_back(new Expr(string("var")+std::to_string(static_cast<long long>(d)),e));
}

