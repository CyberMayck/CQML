#include "output5.h"

#include "qml_includes.h"
//classDeclaration
static void _QML_Update(CQMLGUI::Element *s);


//printHandlers()
using namespace CQMLGUI;

 //rootElementAllocation() 
CQMLGUI::MouseAreaCustom3* CQMLGUI::acGUI_Rootoutput5()
{
	CQMLGUI::Rootoutput5 * pointer;
	pointer=new CQMLGUI::Rootoutput5();
	return pointer->_QML_element0;
}

 //printAttributeUpdatersHeaders() 
static void Update_E0_width(CQMLGUI::QML_Context *);
static void Update_E0_height(CQMLGUI::QML_Context *);
static void Update_E0_defImg(CQMLGUI::QML_Context *);
static void Update_E0_pressedImg(CQMLGUI::QML_Context *);
static void Update_E0_overImg(CQMLGUI::QML_Context *);

 //printElementUpdatersHeaders() 
static void Update_E0(CQMLGUI::Element *self);

 //rootElementConstructor() 
CQMLGUI::Rootoutput5::Rootoutput5()
{
	CQMLGUI::Element*tmp=0;
	_QML_element0 = CQMLGUI::acGUI_Rootoutput1();
	_QML_element0->root=(CQMLGUI::Element*)this;

 //printAttributeUpdaters() 
	((Element*)_QML_element0)->width_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((Element*)_QML_element0)->width_Update  = Update_E0_width;
	((Element*)_QML_element0)->height_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((Element*)_QML_element0)->height_Update  = Update_E0_height;
	((MouseAreaCustom3*)_QML_element0)->defImg_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((MouseAreaCustom3*)_QML_element0)->defImg_Update  = Update_E0_defImg;
	((MouseAreaCustom3*)_QML_element0)->pressedImg_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((MouseAreaCustom3*)_QML_element0)->pressedImg_Update  = Update_E0_pressedImg;
	((MouseAreaCustom3*)_QML_element0)->overImg_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((MouseAreaCustom3*)_QML_element0)->overImg_Update  = Update_E0_overImg;
//printHandlerAssignment()

 //printElementUpdaterAssignments() 
	_QML_Update((CQMLGUI::Element *)_QML_element0);

}

 //rootElementUpdater() 
static void _QML_Update(CQMLGUI::Element *s)
{
	CQMLGUI::Rootoutput5 * self=(CQMLGUI::Rootoutput5 *)s;
	s->Update();

}

 //printAttributesBodies()
static void Update_E0_defImg(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::MouseAreaCustom3*)context->self)->defImg= "pics/button_square_blue.png" ;
}
static void Update_E0_overImg(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::MouseAreaCustom3*)context->self)->overImg= "pics/button_square_blue_over.png" ;
}
static void Update_E0_pressedImg(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::MouseAreaCustom3*)context->self)->pressedImg= "pics/button_square_blue_down.png" ;
}
static void Update_E0_height(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->height= 150 ;
}
static void Update_E0_width(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->width= 150 ;
}

 //printElementUpdaters() 
using namespace CQMLGUI;
