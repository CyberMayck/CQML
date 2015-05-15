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
	CQML_Context * first_context;
	void (* first_Update)(CQML_Context*);
	int firstValue;
	CQML_Context * firstValue_context;
	void (* firstValue_Update)(CQML_Context*);
	int score;
	CQML_Context * score_context;
	void (* score_Update)(CQML_Context*);
	int status;
	CQML_Context * status_context;
	void (* status_Update)(CQML_Context*);
	Text * winMsg;
	CQML_Context * winMsg_context;
	void (* winMsg_Update)(CQML_Context*);
	virtual void Update();
VariantRef Get(const char* s);
ElementCustom2();
};
ElementCustom2* acElementCustom2();

struct Rootoutput2
	:Component
{
	Rootoutput2();
	Rectangle* _CQML_element0;
	ElementCustom2* _CQML_element1;
	Text* _CQML_element2;
	MouseAreaCustom0Custom1* _CQML_element3;
	MouseAreaCustom0Custom1* _CQML_element4;
	MouseAreaCustom0Custom1* _CQML_element5;
	MouseAreaCustom0Custom1* _CQML_element6;
	MouseAreaCustom0Custom1* _CQML_element7;
	MouseAreaCustom0Custom1* _CQML_element8;
	MouseAreaCustom0Custom1* _CQML_element9;
	MouseAreaCustom0Custom1* _CQML_element10;
	MouseAreaCustom0Custom1* _CQML_element11;
	MouseAreaCustom0Custom1* _CQML_element12;
	MouseAreaCustom0Custom1* _CQML_element13;
	MouseAreaCustom0Custom1* _CQML_element14;
	MouseAreaCustom0Custom1* _CQML_element15;
	MouseAreaCustom0Custom1* _CQML_element16;
	MouseAreaCustom0Custom1* _CQML_element17;
	MouseAreaCustom0Custom1* _CQML_element18;
	ScaledImage* _CQML_element19;
	Text* _CQML_element20;
};
Rectangle* acGUI_Rootoutput2();
Rootoutput2 cGUI_Rootoutput2();
};