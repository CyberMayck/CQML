#include "output1.h"

#include "qml_includes.h"
//classDeclaration
static void _CQML_Update(CQMLGUI::Element *s);


//printHandlers()
using namespace CQMLGUI;

 //rootElementAllocation() 
CQMLGUI::MouseAreaCustom0* CQMLGUI::acGUI_Rootoutput1()
{
	CQMLGUI::Rootoutput1 * pointer;
	pointer=new CQMLGUI::Rootoutput1();
	return pointer->_CQML_element0;
}

 //printAttributeUpdatersHeaders() 
static void Update_E0_width(CQMLGUI::CQML_Context *);
static void Update_E0_height(CQMLGUI::CQML_Context *);
static void Update_E0_defImg(CQMLGUI::CQML_Context *);
static void Update_E0_pressedImg(CQMLGUI::CQML_Context *);
static void Update_E0_overImg(CQMLGUI::CQML_Context *);

 //printElementUpdatersHeaders() 
static void Update_E0(CQMLGUI::Element *self);

 //rootElementConstructor() 
CQMLGUI::Rootoutput1::Rootoutput1()
{
	CQMLGUI::Element*tmp=0;
	_CQML_element0 = CQMLGUI::acGUI_Rootoutput2();
	_CQML_element0->root=(CQMLGUI::Element*)this;

 //printAttributeUpdaters() 
	((Element*)_CQML_element0)->width_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element0);
	((Element*)_CQML_element0)->width_Update  = Update_E0_width;
	((Element*)_CQML_element0)->height_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element0);
	((Element*)_CQML_element0)->height_Update  = Update_E0_height;
	((MouseAreaCustom0*)_CQML_element0)->defImg_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element0);
	((MouseAreaCustom0*)_CQML_element0)->defImg_Update  = Update_E0_defImg;
	((MouseAreaCustom0*)_CQML_element0)->pressedImg_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element0);
	((MouseAreaCustom0*)_CQML_element0)->pressedImg_Update  = Update_E0_pressedImg;
	((MouseAreaCustom0*)_CQML_element0)->overImg_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element0);
	((MouseAreaCustom0*)_CQML_element0)->overImg_Update  = Update_E0_overImg;
//printHandlerAssignment()
	_CQML_Update((CQMLGUI::Element *)_CQML_element0);

}

 //rootElementUpdater() 
static void _CQML_Update(CQMLGUI::Element *s)
{
	CQMLGUI::Rootoutput1 * self=(CQMLGUI::Rootoutput1 *)s;
	s->Update();

}

 //printAttributesBodies()
static void Update_E0_width(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->width= 150 ;
}
static void Update_E0_height(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->height= 150 ;
}
static void Update_E0_defImg(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0*)context->self)->defImg= "pics/button_square_blue.png" ;
}
static void Update_E0_pressedImg(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0*)context->self)->pressedImg= "pics/button_square_blue_down.png" ;
}
static void Update_E0_overImg(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0*)context->self)->overImg= "pics/button_square_blue_over.png" ;
}

 //printElementUpdaters() 
using namespace CQMLGUI;
