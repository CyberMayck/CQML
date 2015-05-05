#include "calc_logic.h"
using namespace std;
CalculatorLogic CalcLogic=CalculatorLogic();

CalculatorLogic::CalculatorLogic()
{
	
	val = 0;
	curNum=0;
	curMultipl=0;
	isNew=1;
	curOp='=';
	output=0;
	
}

string CalculatorLogic::getOutput()
{
    if(isNew==1)
		return std::to_string(val);
    else
        return std::to_string(curNum);
}

string CalculatorLogic::comma()
{
    if(curMultipl<1)
        curMultipl=10;
    return getOutput();
}
string CalculatorLogic::reset()
{
	val = 0;
	curNum=0;
	curMultipl=0;
	isNew=1;
	curOp='=';
	output=0;
	
    return getOutput();
}
string CalculatorLogic::setOp(char op)
{
	if(curOp!='=')
    {
        if(curOp=='+')
        {
            val=val+curNum;
        }
        else if(curOp=='-')
        {
            val=val-curNum;
        }
        else if(curOp=='*')
        {
            val=val*curNum;
        }
        else if(curOp=='/')
        {
            val=val/curNum;
        }
    }
    else
    {
        val=curNum;
    }

    isNew=1;
    curNum=0;
    curMultipl=0;
    curOp=op;
    return getOutput();
}
string CalculatorLogic::setNum(int num)
{
    isNew=0;
    if(curMultipl<1)
    {
        curNum=curNum*10+num;
    }
    else
    {
        curNum=curNum+num/(curMultipl);
        curMultipl=curMultipl*10;
    }
    return getOutput();
}