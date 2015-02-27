#include "output0.h"

#include "qml_includes.h"
GUI_RectangleCustom0* acGUI_RectangleCustom0()
{
	GUI_RectangleCustom0 * pointer;
	pointer=(GUI_RectangleCustom0*)malloc(sizeof(GUI_RectangleCustom0));
	//pointer->original=cGUI_Rectangle();
	return pointer;
}
GUI_RectangleCustom1* acGUI_RectangleCustom1()
{
	GUI_RectangleCustom1 * pointer;
	pointer=(GUI_RectangleCustom1*)malloc(sizeof(GUI_RectangleCustom1));
	//pointer->original=cGUI_Rectangle();
	return pointer;
}
static void _QML_Update(GUI_Element *s);

static void _QML_element1_MousePressed(QML_Context * context, QMLEvent Event)
{
{(*((GUI_Rootoutput0*)context->root)->_QML_element1).refAttempt.Get("rah3").Get("hey3")+8;
;}

}

 //rootElementAllocation() 
GUI_Rootoutput0* acGUI_Rootoutput0()
{
	GUI_Rootoutput0 * pointer;
	pointer=(GUI_Rootoutput0*)malloc(sizeof(GUI_Rootoutput0));
	*pointer=cGUI_Rootoutput0((GUI_Element *)pointer);
	return (GUI_Rootoutput0*)pointer->_QML_element0;
}

 //printAttributeUpdatersHeaders() 
static void Update_E0_x(QML_Context *);
static void Update_E0_y(QML_Context *);
static void Update_E0_width(QML_Context *);
static void Update_E0_height(QML_Context *);
static void Update_E1_x(QML_Context *);
static void Update_E1_y(QML_Context *);
static void Update_E1_width(QML_Context *);
static void Update_E1_height(QML_Context *);
static void Update_E1_refAttempt(QML_Context *);
static void Update_E2_x(QML_Context *);
static void Update_E2_y(QML_Context *);
static void Update_E2_hey(QML_Context *);
static void Update_E2_width(QML_Context *);
static void Update_E2_height(QML_Context *);

 //printElementUpdatersHeaders() 
static void Update_E0(GUI_Element *self);
static void Update_E1(GUI_Element *self);
static void Update_E2(GUI_Element *self);

 //rootElementConstructor() 
GUI_Rootoutput0 cGUI_Rootoutput0(GUI_Element * pointer)
{
	GUI_Rootoutput0 s;
	GUI_Rootoutput0 * self=&s;
	self->_QML_element0 = (GUI_Element*)acGUI_Rectangle();
	self->_QML_element0->root=pointer;
	self->_QML_element1 = (GUI_Element*)acGUI_RectangleCustom0();
	self->_QML_element1->root=pointer;
	self->_QML_element2 = (GUI_Element*)acGUI_RectangleCustom1();
	self->_QML_element2->root=pointer;
	mGUI_Element_InsertChild((GUI_Element*)self->_QML_element0, (GUI_Element*)self->_QML_element1);
	mGUI_Element_InsertChild((GUI_Element*)self->_QML_element0, (GUI_Element*)self->_QML_element2);

 //printAttributeUpdaters() 
	((GUI_Element*)self->_QML_element0)->x_context  = acQML_Context((GUI_Group*)self,(GUI_Element*)self->_QML_element0);
	((GUI_Element*)self->_QML_element0)->x_Update  = Update_E0_x;
	((GUI_Element*)self->_QML_element0)->y_context  = acQML_Context((GUI_Group*)self,(GUI_Element*)self->_QML_element0);
	((GUI_Element*)self->_QML_element0)->y_Update  = Update_E0_y;
	((GUI_Element*)self->_QML_element0)->width_context  = acQML_Context((GUI_Group*)self,(GUI_Element*)self->_QML_element0);
	((GUI_Element*)self->_QML_element0)->width_Update  = Update_E0_width;
	((GUI_Element*)self->_QML_element0)->height_context  = acQML_Context((GUI_Group*)self,(GUI_Element*)self->_QML_element0);
	((GUI_Element*)self->_QML_element0)->height_Update  = Update_E0_height;
	((GUI_Element*)self->_QML_element1)->x_context  = acQML_Context((GUI_Group*)self,(GUI_Element*)self->_QML_element1);
	((GUI_Element*)self->_QML_element1)->x_Update  = Update_E1_x;
	((GUI_Element*)self->_QML_element1)->y_context  = acQML_Context((GUI_Group*)self,(GUI_Element*)self->_QML_element1);
	((GUI_Element*)self->_QML_element1)->y_Update  = Update_E1_y;
	((GUI_Element*)self->_QML_element1)->width_context  = acQML_Context((GUI_Group*)self,(GUI_Element*)self->_QML_element1);
	((GUI_Element*)self->_QML_element1)->width_Update  = Update_E1_width;
	((GUI_Element*)self->_QML_element1)->height_context  = acQML_Context((GUI_Group*)self,(GUI_Element*)self->_QML_element1);
	((GUI_Element*)self->_QML_element1)->height_Update  = Update_E1_height;
	((GUI_RectangleCustom0*)self->_QML_element1)->refAttempt_context  = acQML_Context((GUI_Group*)self,(GUI_Element*)self->_QML_element1);
	((GUI_RectangleCustom0*)self->_QML_element1)->refAttempt_Update  = Update_E1_refAttempt;
	((GUI_Element*)self->_QML_element2)->x_context  = acQML_Context((GUI_Group*)self,(GUI_Element*)self->_QML_element2);
	((GUI_Element*)self->_QML_element2)->x_Update  = Update_E2_x;
	((GUI_Element*)self->_QML_element2)->y_context  = acQML_Context((GUI_Group*)self,(GUI_Element*)self->_QML_element2);
	((GUI_Element*)self->_QML_element2)->y_Update  = Update_E2_y;
	((GUI_RectangleCustom1*)self->_QML_element2)->hey_context  = acQML_Context((GUI_Group*)self,(GUI_Element*)self->_QML_element2);
	((GUI_RectangleCustom1*)self->_QML_element2)->hey_Update  = Update_E2_hey;
	((GUI_Element*)self->_QML_element2)->width_context  = acQML_Context((GUI_Group*)self,(GUI_Element*)self->_QML_element2);
	((GUI_Element*)self->_QML_element2)->width_Update  = Update_E2_width;
	((GUI_Element*)self->_QML_element2)->height_context  = acQML_Context((GUI_Group*)self,(GUI_Element*)self->_QML_element2);
	((GUI_Element*)self->_QML_element2)->height_Update  = Update_E2_height;
	self->_QML_element1->CustomMousePressed=_QML_element1_MousePressed;

 //printElementUpdaterAssignments() 
	((GUI_Element *)self->_QML_element0)->Update=Update_E0;
	((GUI_Element *)self->_QML_element1)->Update=Update_E1;
	((GUI_Element *)self->_QML_element2)->Update=Update_E2;
	_QML_Update((GUI_Element *)self->_QML_element0);
	return *self;
}

 //rootElementUpdater() 
static void _QML_Update(GUI_Element *s)
{
	GUI_Rootoutput0 * self=(GUI_Rootoutput0 *)s;
	mGUI_Element_Update((GUI_Element *)self);

}

 //printAttributesBodies() 
static void Update_E2_height(QML_Context *context)
{
	((GUI_Element*)context->self)->height=parent.height-10;
}
static void Update_E2_width(QML_Context *context)
{
	((GUI_Element*)context->self)->width=parent.width/2-10;
}
static void Update_E2_hey(QML_Context *context)
{
	((GUI_RectangleCustom1*)context->self)->hey=0;
}
static void Update_E2_y(QML_Context *context)
{
	((GUI_Element*)context->self)->y=5;
}
static void Update_E2_x(QML_Context *context)
{
	((GUI_Element*)context->self)->x=crap.width+5;
}
static void Update_E1_refAttempt(QML_Context *context)
{
	((GUI_RectangleCustom0*)context->self)->refAttempt=nope;
}
static void Update_E1_height(QML_Context *context)
{
	((GUI_Element*)context->self)->height=parent.height/2-10;
}
static void Update_E1_width(QML_Context *context)
{
	((GUI_Element*)context->self)->width=parent.width/2-10;
}
static void Update_E1_y(QML_Context *context)
{
	((GUI_Element*)context->self)->y=parent.height/2;
}
static void Update_E1_x(QML_Context *context)
{
	((GUI_Element*)context->self)->x=5;
}
static void Update_E0_height(QML_Context *context)
{
	((GUI_Element*)context->self)->height=width;
}
static void Update_E0_width(QML_Context *context)
{
	((GUI_Element*)context->self)->width=500;
}
static void Update_E0_y(QML_Context *context)
{
	((GUI_Element*)context->self)->y=0;
}
static void Update_E0_x(QML_Context *context)
{
	((GUI_Element*)context->self)->x=0;
}

 //printElementUpdaters() 
static void Update_E0(GUI_Element *self)
{
	mGUI_Element_Update((GUI_Element *)self);
	((GUI_Element*)self)->x_Update	(((GUI_Element*)self)->x_context);
	((GUI_Element*)self)->y_Update	(((GUI_Element*)self)->y_context);
	((GUI_Element*)self)->width_Update	(((GUI_Element*)self)->width_context);
	((GUI_Element*)self)->height_Update	(((GUI_Element*)self)->height_context);
}
static void Update_E1(GUI_Element *self)
{
	mGUI_Element_Update((GUI_Element *)self);
	((GUI_Element*)self)->x_Update	(((GUI_Element*)self)->x_context);
	((GUI_Element*)self)->y_Update	(((GUI_Element*)self)->y_context);
	((GUI_Element*)self)->width_Update	(((GUI_Element*)self)->width_context);
	((GUI_Element*)self)->height_Update	(((GUI_Element*)self)->height_context);
	((GUI_RectangleCustom0*)self)->refAttempt_Update	(((GUI_RectangleCustom0*)self)->refAttempt_context);
}
static void Update_E2(GUI_Element *self)
{
	mGUI_Element_Update((GUI_Element *)self);
	((GUI_Element*)self)->x_Update	(((GUI_Element*)self)->x_context);
	((GUI_Element*)self)->y_Update	(((GUI_Element*)self)->y_context);
	((GUI_RectangleCustom1*)self)->hey_Update	(((GUI_RectangleCustom1*)self)->hey_context);
	((GUI_Element*)self)->width_Update	(((GUI_Element*)self)->width_context);
	((GUI_Element*)self)->height_Update	(((GUI_Element*)self)->height_context);
}
