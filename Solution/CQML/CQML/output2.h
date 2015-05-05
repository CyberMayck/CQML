#pragma once
#include "qml_includes.h"
#include "output4.h"
namespace CQMLGUI{
struct Rootoutput2;

struct ElementCustom2;

struct ElementCustom2
	: Element
{
	Element * first;
	QML_Context * first_context;
	void (* first_Update)(QML_Context*);
	int firstValue;
	QML_Context * firstValue_context;
	void (* firstValue_Update)(QML_Context*);
	int score;
	QML_Context * score_context;
	void (* score_Update)(QML_Context*);
	int status;
	QML_Context * status_context;
	void (* status_Update)(QML_Context*);
	Text * winMsg;
	QML_Context * winMsg_context;
	void (* winMsg_Update)(QML_Context*);
	virtual void Update();
VariantRef Get(const char* s);
ElementCustom2();
};
ElementCustom2* acElementCustom2();

struct Rootoutput2
	:Component
{
	Rootoutput2();
	Rectangle* _QML_element0;
	ElementCustom2* _QML_element1;
	Text* _QML_element2;
	MouseAreaCustom0Custom1* _QML_element3;
	MouseAreaCustom0Custom1* _QML_element4;
	MouseAreaCustom0Custom1* _QML_element5;
	MouseAreaCustom0Custom1* _QML_element6;
	MouseAreaCustom0Custom1* _QML_element7;
	MouseAreaCustom0Custom1* _QML_element8;
	MouseAreaCustom0Custom1* _QML_element9;
	MouseAreaCustom0Custom1* _QML_element10;
	MouseAreaCustom0Custom1* _QML_element11;
	MouseAreaCustom0Custom1* _QML_element12;
	MouseAreaCustom0Custom1* _QML_element13;
	MouseAreaCustom0Custom1* _QML_element14;
	MouseAreaCustom0Custom1* _QML_element15;
	MouseAreaCustom0Custom1* _QML_element16;
	MouseAreaCustom0Custom1* _QML_element17;
	MouseAreaCustom0Custom1* _QML_element18;
	ScaledImage* _QML_element19;
	Text* _QML_element20;
};
Rectangle* acGUI_Rootoutput2();
Rootoutput2 cGUI_Rootoutput2();
};