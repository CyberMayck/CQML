#pragma once
#include "qml_includes.h"
#include "output6.h"
namespace CQMLGUI{
struct Rootoutput4;

struct MouseAreaCustom0Custom1;

struct MouseAreaCustom0Custom1
	: MouseAreaCustom0
{
	int value;
	CQML_Context * value_context;
	void (* value_Update)(CQML_Context*);
	Element * matcher;
	CQML_Context * matcher_context;
	void (* matcher_Update)(CQML_Context*);
	virtual void Update();
VariantRef Get(const char* s);
MouseAreaCustom0Custom1();
};
MouseAreaCustom0Custom1* acMouseAreaCustom0Custom1();

struct Rootoutput4
	:Component
{
	Rootoutput4();
	MouseAreaCustom0Custom1* _CQML_element0;
};
MouseAreaCustom0Custom1* acGUI_Rootoutput4();
Rootoutput4 cGUI_Rootoutput4();
};