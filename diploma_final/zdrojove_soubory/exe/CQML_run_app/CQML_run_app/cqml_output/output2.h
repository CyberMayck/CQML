#pragma once
#include "qml_includes.h"
namespace CQMLGUI{
struct Rootoutput2;

struct MouseAreaCustom0;

struct MouseAreaCustom0
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
MouseAreaCustom0();
};
MouseAreaCustom0* acMouseAreaCustom0();

struct Rootoutput2
	:Component
{
	Rootoutput2();
	MouseAreaCustom0* _CQML_element0;
	Image* _CQML_element1;
	Text* _CQML_element2;
};
MouseAreaCustom0* acGUI_Rootoutput2();
Rootoutput2 cGUI_Rootoutput2();
};