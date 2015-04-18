#include "qml_includes.h"
namespace CQMLGUI{
struct Rootoutput0;

struct ScaledImageCustom0;

struct ScaledImageCustom0
	: ScaledImage
{
	int status;
	QML_Context * status_context;
	void (* status_Update)(QML_Context*);
	virtual void Update();
};
ScaledImageCustom0* acScaledImageCustom0();

struct Rootoutput0
	:Component
{
	Rootoutput0();
	Element* _QML_element0;
	ScaledImageCustom0* _QML_element1;
	Text* _QML_element2;
	Rectangle* _QML_element3;
	MouseArea* _QML_element4;
};
Element* acGUI_Rootoutput0();
Rootoutput0 cGUI_Rootoutput0();
};