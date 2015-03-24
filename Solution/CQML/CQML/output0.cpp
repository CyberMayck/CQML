#include "output0.h"

#include "qml_includes.h"
CQMLGUI::RectangleCustom0* CQMLGUI::acGUI_RectangleCustom0()
{
	CQMLGUI::RectangleCustom0 * pointer;
	pointer=new CQMLGUI::RectangleCustom0();
	return pointer;
}
CQMLGUI::RectangleCustom1* CQMLGUI::acGUI_RectangleCustom1()
{
	CQMLGUI::RectangleCustom1 * pointer;
	pointer=new CQMLGUI::RectangleCustom1();
	return pointer;
}
static void _QML_Update(CQMLGUI::Element *s);

static void _QML_element1_MousePressed(CQMLGUI::QML_Context * context, QMLEvent Event)
{
//{_QVar1=(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).refAttempt.Get("rah3").Get("hey3")+8;
//;}

}

 //rootElementAllocation() 
CQMLGUI::Rootoutput0* CQMLGUI::acGUI_Rootoutput0()
{
	CQMLGUI::Rootoutput0 * pointer;
	pointer=new CQMLGUI::Rootoutput0();
	return (CQMLGUI::Rootoutput0*)pointer->_QML_element0;
}

 //printAttributeUpdatersHeaders() 
static void Update_E0_x(CQMLGUI::QML_Context *);
static void Update_E0_y(CQMLGUI::QML_Context *);
static void Update_E0_width(CQMLGUI::QML_Context *);
static void Update_E0_height(CQMLGUI::QML_Context *);
static void Update_E1_x(CQMLGUI::QML_Context *);
static void Update_E1_y(CQMLGUI::QML_Context *);
static void Update_E1_width(CQMLGUI::QML_Context *);
static void Update_E1_height(CQMLGUI::QML_Context *);
static void Update_E1_refAttempt(CQMLGUI::QML_Context *);
static void Update_E2_x(CQMLGUI::QML_Context *);
static void Update_E2_y(CQMLGUI::QML_Context *);
static void Update_E2_hey(CQMLGUI::QML_Context *);
static void Update_E2_width(CQMLGUI::QML_Context *);
static void Update_E2_height(CQMLGUI::QML_Context *);

 //printElementUpdatersHeaders() 
static void Update_E0(CQMLGUI::Element *self);
static void Update_E1(CQMLGUI::Element *self);
static void Update_E2(CQMLGUI::Element *self);

 //rootElementConstructor() 
CQMLGUI::Rootoutput0::Rootoutput0()
{
	_QML_element0 = CQMLGUI::acGUI_Rectangle();
	_QML_element0->root=(CQMLGUI::Element*)this;
	_QML_element1 = CQMLGUI::acGUI_RectangleCustom0();
	_QML_element1->root=(CQMLGUI::Element*)this;
	_QML_element2 = CQMLGUI::acGUI_RectangleCustom1();
	_QML_element2->root=(CQMLGUI::Element*)this;
	mGUI_Element_InsertChild((CQMLGUI::Element*)_QML_element0, (CQMLGUI::Element*)_QML_element1);
	mGUI_Element_InsertChild((CQMLGUI::Element*)_QML_element0, (CQMLGUI::Element*)_QML_element2);

 //printAttributeUpdaters() 
	((Element*)_QML_element0)->x_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((Element*)_QML_element0)->x_Update  = Update_E0_x;
	((Element*)_QML_element0)->y_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((Element*)_QML_element0)->y_Update  = Update_E0_y;
	((Element*)_QML_element0)->width_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((Element*)_QML_element0)->width_Update  = Update_E0_width;
	((Element*)_QML_element0)->height_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((Element*)_QML_element0)->height_Update  = Update_E0_height;
	((Element*)_QML_element1)->x_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element1);
	((Element*)_QML_element1)->x_Update  = Update_E1_x;
	((Element*)_QML_element1)->y_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element1);
	((Element*)_QML_element1)->y_Update  = Update_E1_y;
	((Element*)_QML_element1)->width_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element1);
	((Element*)_QML_element1)->width_Update  = Update_E1_width;
	((Element*)_QML_element1)->height_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element1);
	((Element*)_QML_element1)->height_Update  = Update_E1_height;
	((RectangleCustom0*)_QML_element1)->refAttempt_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element1);
	((RectangleCustom0*)_QML_element1)->refAttempt_Update  = Update_E1_refAttempt;
	((Element*)_QML_element2)->x_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element2);
	((Element*)_QML_element2)->x_Update  = Update_E2_x;
	((Element*)_QML_element2)->y_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element2);
	((Element*)_QML_element2)->y_Update  = Update_E2_y;
	((RectangleCustom1*)_QML_element2)->hey_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element2);
	((RectangleCustom1*)_QML_element2)->hey_Update  = Update_E2_hey;
	((Element*)_QML_element2)->width_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element2);
	((Element*)_QML_element2)->width_Update  = Update_E2_width;
	((Element*)_QML_element2)->height_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element2);
	((Element*)_QML_element2)->height_Update  = Update_E2_height;
//printHandlerAssignment()	_QML_element1->CustomMousePressed=_QML_element1_MousePressed;

 //printElementUpdaterAssignments() 
	((CQMLGUI::Element *)_QML_element0)->CustomUpdate=Update_E0;
	((CQMLGUI::Element *)_QML_element1)->CustomUpdate=Update_E1;
	((CQMLGUI::Element *)_QML_element2)->CustomUpdate=Update_E2;
	_QML_Update((CQMLGUI::Element *)_QML_element0);

}

 //rootElementUpdater() 
static void _QML_Update(CQMLGUI::Element *s)
{
	CQMLGUI::Rootoutput0 * self=(CQMLGUI::Rootoutput0 *)s;
	s->Update();

}

 //printAttributesBodies() 
static void Update_E2_height(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->height=(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element0).height-10;
}
static void Update_E2_width(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->width=(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element0).width/2-10;
}
static void Update_E2_hey(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::RectangleCustom1*)context->self)->hey=0;
}
static void Update_E2_y(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y=5;
}
static void Update_E2_x(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x=(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).width+5;
}
static void Update_E1_refAttempt(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::RectangleCustom0*)context->self)->refAttempt=(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1);
}
static void Update_E1_height(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->height=(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element0).height/2-10;
}
static void Update_E1_width(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->width=(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element0).width/2-10;
}
static void Update_E1_y(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y=(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element0).height/2;
}
static void Update_E1_x(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x=5;
}
static void Update_E0_height(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->height=(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element0).width;
}
static void Update_E0_width(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->width=500;
}
static void Update_E0_y(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y=0;
}
static void Update_E0_x(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x=0;
}

 //printElementUpdaters() 
static void Update_E0(CQMLGUI::Element *self)
{
	self->Update();
	((CQMLGUI::Element*)self)->x_Update	(((CQMLGUI::Element*)self)->x_context);
	((CQMLGUI::Element*)self)->y_Update	(((CQMLGUI::Element*)self)->y_context);
	((CQMLGUI::Element*)self)->width_Update	(((CQMLGUI::Element*)self)->width_context);
	((CQMLGUI::Element*)self)->height_Update	(((CQMLGUI::Element*)self)->height_context);
}
static void Update_E1(CQMLGUI::Element *self)
{
	self->Update();
	((CQMLGUI::Element*)self)->x_Update	(((CQMLGUI::Element*)self)->x_context);
	((CQMLGUI::Element*)self)->y_Update	(((CQMLGUI::Element*)self)->y_context);
	((CQMLGUI::Element*)self)->width_Update	(((CQMLGUI::Element*)self)->width_context);
	((CQMLGUI::Element*)self)->height_Update	(((CQMLGUI::Element*)self)->height_context);
	((CQMLGUI::RectangleCustom0*)self)->refAttempt_Update	(((CQMLGUI::RectangleCustom0*)self)->refAttempt_context);
}
static void Update_E2(CQMLGUI::Element *self)
{
	self->Update();
	((CQMLGUI::Element*)self)->x_Update	(((CQMLGUI::Element*)self)->x_context);
	((CQMLGUI::Element*)self)->y_Update	(((CQMLGUI::Element*)self)->y_context);
	((CQMLGUI::RectangleCustom1*)self)->hey_Update	(((CQMLGUI::RectangleCustom1*)self)->hey_context);
	((CQMLGUI::Element*)self)->width_Update	(((CQMLGUI::Element*)self)->width_context);
	((CQMLGUI::Element*)self)->height_Update	(((CQMLGUI::Element*)self)->height_context);
}
