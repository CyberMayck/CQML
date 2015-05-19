#pragma once
#include <string>
struct CalculatorLogic
{
	double val;
	double curNum;
	double curMultipl;
	int isNew;
	char curOp;

	double output;
	CalculatorLogic();
	std::string comma();
	std::string reset();
	std::string setOp(char);
	std::string setNum(int);
	std::string getOutput();
};

extern CalculatorLogic CalcLogic;