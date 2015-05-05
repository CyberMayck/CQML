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
	QML_Context * value_context;
	void (* value_Update)(QML_Context*);
	Element * matcher;
	QML_Context * matcher_context;
	void (* matcher_Update)(QML_Context*);
	virtual void Update();
VariantRef Get(const char* s);
MouseAreaCustom0Custom1();
};
MouseAreaCustom0Custom1* acMouseAreaCustom0Custom1();

struct Rootoutput4
	:Component
{
	Rootoutput4();
	MouseAreaCustom0Custom1* _QML_element0;
};
MouseAreaCustom0Custom1* acGUI_Rootoutput4();
Rootoutput4 cGUI_Rootoutput4();
};