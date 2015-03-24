#include "qml_includes.h"
namespace CQMLGUI{struct Rootoutput0;

struct RectangleCustom0;

struct RectangleCustom1;

struct RectangleCustom0
	: Rectangle
{
	Rectangle refAttempt;
	QML_Context * refAttempt_context;
	void (* refAttempt_Update)(QML_Context*);
	int gammma;
	QML_Context * gammma_context;
	void (* gammma_Update)(QML_Context*);
};
RectangleCustom0* acGUI_RectangleCustom0();

struct RectangleCustom1
	: Rectangle
{
	int hey;
	QML_Context * hey_context;
	void (* hey_Update)(QML_Context*);
};
RectangleCustom1* acGUI_RectangleCustom1();

struct Rootoutput0
	:Component
{
	Rootoutput0();
	Rectangle* _QML_element0;
	RectangleCustom0* _QML_element1;
	RectangleCustom1* _QML_element2;
};
Rootoutput0* acGUI_Rootoutput0();
Rootoutput0 cGUI_Rootoutput0();
};