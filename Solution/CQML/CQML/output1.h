#pragma once
#include "qml_includes.h"
namespace CQMLGUI{
struct Rootoutput1;

struct MouseAreaCustom3;

struct MouseAreaCustom3
	: MouseArea
{
	int pressed;
	QML_Context * pressed_context;
	void (* pressed_Update)(QML_Context*);
	int entered;
	QML_Context * entered_context;
	void (* entered_Update)(QML_Context*);
	string pressedImg;
	QML_Context * pressedImg_context;
	void (* pressedImg_Update)(QML_Context*);
	string overImg;
	QML_Context * overImg_context;
	void (* overImg_Update)(QML_Context*);
	string defImg;
	QML_Context * defImg_context;
	void (* defImg_Update)(QML_Context*);
	string text;
	QML_Context * text_context;
	void (* text_Update)(QML_Context*);
	virtual void Update();
VariantRef Get(const char* s);
MouseAreaCustom3();
};
MouseAreaCustom3* acMouseAreaCustom3();

struct Rootoutput1
	:Component
{
	Rootoutput1();
	MouseAreaCustom3* _QML_element0;
	Image* _QML_element1;
	Text* _QML_element2;
};
MouseAreaCustom3* acGUI_Rootoutput1();
Rootoutput1 cGUI_Rootoutput1();
};