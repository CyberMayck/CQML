#include "checker.h"
void Checker::SetStartName(string s)
{
	elementName=s;
}


void Checker::PushCheck(PropertyAndType* p)//(string s)
{
	checkers.push_back(*p);
}


void Checker::Print(FILE * f)
{
	return;
	bool refPassed=false;
	bool prevRef=true;
	
	string str=elementName;

	for(int i=0;i<checkers.size();i++)
	{
		str="(("+checkers[i].cont->className+")"+str;
		if(prevRef)
		{
			str=str+")->";
		}
		else
			str=str+").";

		str=str+checkers[i].name;
		
		if(checkers[i].IsReference())
		{
			refPassed=true;
		}
		prevRef=checkers[i].IsReference();
		if(refPassed)
		{
		}
		fprintf(f,"if(!checkAttributeExistence(%s->classID,%d)) return;",
			str.c_str(),checkers[i].nameHash);
	}
}