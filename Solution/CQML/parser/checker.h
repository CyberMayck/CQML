#pragma once
#include <string>
#include <vector>
#include "parameter_handling.h"
#include <stdio.h>
using namespace std;

class Checker
{
	string elementName;
	vector<PropertyAndType> checkers;
public:
	void SetStartName(string s);
	void PushCheck(PropertyAndType * p);//string s);
	void Print(FILE * f);
};