#include "calc_logic.h"
using namespace std;
CalculatorLogic CalcLogic=CalculatorLogic();

/**
 * A constructor.
 * Initializes calculator instance to default values.
 */
CalculatorLogic::CalculatorLogic()
{
	
	val = 0;
	curNum=0;
	curMultipl=0;
	isNew=1;
	curOp='=';
	output=0;
	
}

/**
 * Output getter
 * Gets text on calculator display.
 *
 * @return text on calculator display.
 */
string CalculatorLogic::getOutput()
{
    if(isNew==1)
		return std::to_string(val);
    else
        return std::to_string(curNum);
}

/**
 * Comma function
 * Sets comma in calculator
 *
 * @return text on calculator display.
 */
string CalculatorLogic::comma()
{
    if(curMultipl<1)
        curMultipl=10;
    return getOutput();
}

/**
 * Reset function
 * Resets calculator.
 *
 * @return text on calculator display.
 */
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

/**
 * Operator setter
 * Sets operator.
 *
 * @param operator
 *
 * @return text on calculator display.
 */
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

/**
 * Number setter.
 * Sets calculator number.
 *
 * @param number.
 *
 * @return text on calculator display.
 */
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