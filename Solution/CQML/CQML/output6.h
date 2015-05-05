#pragma once
#include "qml_includes.h"
namespace CQMLGUI{
struct Rootoutput6;

struct MouseAreaCustom0;

struct MouseAreaCustom0
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
	virtual void Update();
VariantRef Get(const char* s);
MouseAreaCustom0();
};
MouseAreaCustom0* acMouseAreaCustom0();

struct Rootoutput6
	:Component
{
	Rootoutput6();
	MouseAreaCustom0* _QML_element0;
	Image* _QML_element1;
};
MouseAreaCustom0* acGUI_Rootoutput6();
Rootoutput6 cGUI_Rootoutput6();
};