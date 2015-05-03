#include "qml_includes.h"
namespace CQMLGUI{
struct Rootoutput0;

struct ElementCustom0;

struct ScaledImageCustom1;

struct ElementCustom0
	: Element
{
	Element * refEl;
	QML_Context * refEl_context;
	void (* refEl_Update)(QML_Context*);
	virtual void Update();
VariantRef Get(const char* s);
ElementCustom0();
};
ElementCustom0* acElementCustom0();

struct ScaledImageCustom1
	: ScaledImage
{
	Element * refEl;
	QML_Context * refEl_context;
	void (* refEl_Update)(QML_Context*);
	int status;
	QML_Context * status_context;
	void (* status_Update)(QML_Context*);
	virtual void Update();
VariantRef Get(const char* s);
ScaledImageCustom1();
};
ScaledImageCustom1* acScaledImageCustom1();

struct Rootoutput0
	:Component
{
	Rootoutput0();
	ElementCustom0* _QML_element0;
	ScaledImageCustom1* _QML_element1;
	Text* _QML_element2;
	Rectangle* _QML_element3;
	MouseArea* _QML_element4;
};
ElementCustom0* acGUI_Rootoutput0();
Rootoutput0 cGUI_Rootoutput0();
};