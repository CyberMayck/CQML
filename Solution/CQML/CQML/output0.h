#include "qml_includes.h"
typedef struct GUI_Rootoutput0 GUI_Rootoutput0;

typedef struct GUI_RectangleCustom0 GUI_RectangleCustom0;

typedef struct GUI_RectangleCustom1 GUI_RectangleCustom1;

struct GUI_RectangleCustom0
	: GUI_Rectangle
{
	GUI_Rectangle refAttempt;
	QML_Context * refAttempt_context;
	void (* refAttempt_Update)(QML_Context*);
	int gammma;
	QML_Context * gammma_context;
	void (* gammma_Update)(QML_Context*);
};
GUI_RectangleCustom0* acGUI_RectangleCustom0();

struct GUI_RectangleCustom1
	: GUI_Rectangle
{
	int hey;
	QML_Context * hey_context;
	void (* hey_Update)(QML_Context*);
};
GUI_RectangleCustom1* acGUI_RectangleCustom1();

struct GUI_Rootoutput0
{
	GUI_Rectangle* _QML_element0;
	GUI_RectangleCustom0* _QML_element1;
	GUI_RectangleCustom1* _QML_element2;
};
GUI_Rootoutput0* acGUI_Rootoutput0();
GUI_Rootoutput0 cGUI_Rootoutput0();
