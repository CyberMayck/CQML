#include "output1.h"

#include "qml_includes.h"
//classDeclaration
static void _QML_Update(CQMLGUI::Element *s);


//printHandlers()
using namespace CQMLGUI;

 //rootElementAllocation() 
CQMLGUI::Rectangle* CQMLGUI::acGUI_Rootoutput1()
{
	CQMLGUI::Rootoutput1 * pointer;
	pointer=new CQMLGUI::Rootoutput1();
	return pointer->_QML_element0;
}

 //printAttributeUpdatersHeaders() 
static void Update_E0_x(CQMLGUI::QML_Context *);
static void Update_E0_y(CQMLGUI::QML_Context *);
static void Update_E0_width(CQMLGUI::QML_Context *);
static void Update_E0_height(CQMLGUI::QML_Context *);
static void Update_E0_color_red(CQMLGUI::QML_Context *);
static void Update_E0_color_green(CQMLGUI::QML_Context *);
static void Update_E0_color_blue(CQMLGUI::QML_Context *);

 //printElementUpdatersHeaders() 
static void Update_E0(CQMLGUI::Element *self);

 //rootElementConstructor() 
CQMLGUI::Rootoutput1::Rootoutput1()
{
	_QML_element0 = CQMLGUI::acRectangle();
	_QML_element0->root=(CQMLGUI::Element*)this;

 //printAttributeUpdaters() 
	((Element*)_QML_element0)->x_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((Element*)_QML_element0)->x_Update  = Update_E0_x;
	((Element*)_QML_element0)->y_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((Element*)_QML_element0)->y_Update  = Update_E0_y;
	((Element*)_QML_element0)->width_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((Element*)_QML_element0)->width_Update  = Update_E0_width;
	((Element*)_QML_element0)->height_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((Element*)_QML_element0)->height_Update  = Update_E0_height;
	((Rectangle*)_QML_element0)->color.red_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_QML_element0));
	((Rectangle*)_QML_element0)->color.red_Update  = Update_E0_color_red;
	((Rectangle*)_QML_element0)->color.green_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_QML_element0));
	((Rectangle*)_QML_element0)->color.green_Update  = Update_E0_color_green;
	((Rectangle*)_QML_element0)->color.blue_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_QML_element0));
	((Rectangle*)_QML_element0)->color.blue_Update  = Update_E0_color_blue;
//printHandlerAssignment()

 //printElementUpdaterAssignments() 
	_QML_Update((CQMLGUI::Element *)_QML_element0);

}

 //rootElementUpdater() 
static void _QML_Update(CQMLGUI::Element *s)
{
	CQMLGUI::Rootoutput1 * self=(CQMLGUI::Rootoutput1 *)s;
	s->Update();

}

 //printAttributesBodies()
static void Update_E0_color_blue(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Rectangle*)context->self)->color.blue= 0 ;
}
static void Update_E0_color_green(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Rectangle*)context->self)->color.green= 0 ;
}
static void Update_E0_color_red(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Rectangle*)context->self)->color.red= 1 ;
}
static void Update_E0_height(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->height= 100 ;
}
static void Update_E0_width(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->width= 100 ;
}
static void Update_E0_y(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y= 10 ;
}
static void Update_E0_x(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x= 10 ;
}

 //printElementUpdaters() 
using namespace CQMLGUI;
