#pragma once
#include "qml_includes.h"
namespace CQMLGUI{
struct Rootoutput1;

struct MouseAreaCustom3;

struct MouseAreaCustom3
	: MouseArea
{
	int pressed;
	CQML_Context * pressed_context;
	void (* pressed_Update)(CQML_Context*);
	int entered;
	CQML_Context * entered_context;
	void (* entered_Update)(CQML_Context*);
	string pressedImg;
	CQML_Context * pressedImg_context;
	void (* pressedImg_Update)(CQML_Context*);
	string overImg;
	CQML_Context * overImg_context;
	void (* overImg_Update)(CQML_Context*);
	string defImg;
	CQML_Context * defImg_context;
	void (* defImg_Update)(CQML_Context*);
	string text;
	CQML_Context * text_context;
	void (* text_Update)(CQML_Context*);
	virtual void Update();
VariantRef Get(const char* s);
MouseAreaCustom3();
};
MouseAreaCustom3* acMouseAreaCustom3();

struct Rootoutput1
	:Component
{
	Rootoutput1();
	MouseAreaCustom3* _CQML_element0;
	Image* _CQML_element1;
	Text* _CQML_element2;
};
MouseAreaCustom3* acGUI_Rootoutput1();
Rootoutput1 cGUI_Rootoutput1();
};