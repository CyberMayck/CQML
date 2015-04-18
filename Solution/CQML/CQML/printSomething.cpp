#include "printSomething.h"
#include <stdio.h>

int meta=200;
int xLimit=0;
int yLimit=0;

void WindowLimit(int w, int h)
{
	xLimit=w;
	yLimit=h;
}

bool CanMove(int x, int y, int status)
{
	if(status==DIR_DOWN)
	{
		if(yLimit>y)
			return true;
	}
	if(status==DIR_UP)
	{
		if(y>0)
			return true;
	}
	if(status==DIR_LEFT)
	{
		if(x>0)
			return true;
	}
	if(status==DIR_RIGHT)
	{
		if(xLimit>x)
			return true;
	}
	return false;
}

void PrintNumber(int a)
{
}
