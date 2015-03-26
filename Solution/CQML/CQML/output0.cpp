#include "output0.h"

#include "qml_includes.h"
//classDeclaration
static void _QML_Update(CQMLGUI::Element *s);


//printHandlers()
static void _QML_element2_MouseReleased(CQMLGUI::QML_Context * context, QMLEvent Event)
{
{(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).text="released";
}

}
static void _QML_element2_MousePressed(CQMLGUI::QML_Context * context, QMLEvent Event)
{
{(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).text="pressed";
}

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
static void Update_E1_font_family(CQMLGUI::QML_Context *);
static void Update_E1_font_size(CQMLGUI::QML_Context *);
static void Update_E1_text_color_red(CQMLGUI::QML_Context *);
static void Update_E1_text_color_green(CQMLGUI::QML_Context *);
static void Update_E1_text_color_blue(CQMLGUI::QML_Context *);
static void Update_E2_x(CQMLGUI::QML_Context *);
static void Update_E2_y(CQMLGUI::QML_Context *);
static void Update_E2_width(CQMLGUI::QML_Context *);
static void Update_E2_height(CQMLGUI::QML_Context *);

 //printElementUpdatersHeaders() 
static void Update_E0(CQMLGUI::Element *self);
static void Update_E1(CQMLGUI::Element *self);
static void Update_E2(CQMLGUI::Element *self);

 //rootElementConstructor() 
CQMLGUI::Rootoutput0::Rootoutput0()
{
	_QML_element0 = CQMLGUI::acRectangle();
	_QML_element0->root=(CQMLGUI::Element*)this;
	_QML_element1 = CQMLGUI::acText();
	_QML_element1->root=(CQMLGUI::Element*)this;
	_QML_element2 = CQMLGUI::acRectangle();
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
	((Text*)_QML_element1)->font.family_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_QML_element1));
	((Text*)_QML_element1)->font.family_Update  = Update_E1_font_family;
	((Text*)_QML_element1)->font.size_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_QML_element1));
	((Text*)_QML_element1)->font.size_Update  = Update_E1_font_size;
	((Text*)_QML_element1)->text_color.red_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_QML_element1));
	((Text*)_QML_element1)->text_color.red_Update  = Update_E1_text_color_red;
	((Text*)_QML_element1)->text_color.green_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_QML_element1));
	((Text*)_QML_element1)->text_color.green_Update  = Update_E1_text_color_green;
	((Text*)_QML_element1)->text_color.blue_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_QML_element1));
	((Text*)_QML_element1)->text_color.blue_Update  = Update_E1_text_color_blue;
	((Element*)_QML_element2)->x_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element2);
	((Element*)_QML_element2)->x_Update  = Update_E2_x;
	((Element*)_QML_element2)->y_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element2);
	((Element*)_QML_element2)->y_Update  = Update_E2_y;
	((Element*)_QML_element2)->width_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element2);
	((Element*)_QML_element2)->width_Update  = Update_E2_width;
	((Element*)_QML_element2)->height_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element2);
	((Element*)_QML_element2)->height_Update  = Update_E2_height;
//printHandlerAssignment()	_QML_element2->CustomMouseReleased=_QML_element2_MouseReleased;
	_QML_element2->CustomMousePressed=_QML_element2_MousePressed;

 //printElementUpdaterAssignments() 
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
	((CQMLGUI::Element*)context->self)->height=(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element0).height/2-10;
}
static void Update_E2_width(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->width=(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element0).width/2-10;
}
static void Update_E2_y(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y=(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element0).height/2;
}
static void Update_E2_x(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x=5;
}
static void Update_E1_text_color_blue(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Text*)context->self)->text_color.blue=1;
}
static void Update_E1_text_color_green(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Text*)context->self)->text_color.green=0;
}
static void Update_E1_text_color_red(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Text*)context->self)->text_color.red=1;
}
static void Update_E1_font_size(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Text*)context->self)->font.size=12;
}
static void Update_E1_font_family(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Text*)context->self)->font.family="C64.ttf";
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
	((CQMLGUI::Element*)context->self)->y=5;
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
using namespace CQMLGUI;
void Rectangle::Update()
{
	if(color_Update)color_Update(color_context);
	else
	{
		if(color.red_Update)color.red_Update(color.red_context);
		if(color.green_Update)color.green_Update(color.green_context);
		if(color.blue_Update)color.blue_Update(color.blue_context);
	}
	 Element::Update();
}
void Text::Update()
{
	if(text_color_Update)text_color_Update(text_color_context);
	else
	{
		if(text_color.red_Update)text_color.red_Update(text_color.red_context);
		if(text_color.green_Update)text_color.green_Update(text_color.green_context);
		if(text_color.blue_Update)text_color.blue_Update(text_color.blue_context);
	}
	if(text_Update)text_Update(text_context);
	if(font_Update)font_Update(font_context);
	else
	{
		if(font.capital_Update)font.capital_Update(font.capital_context);
		if(font.italic_Update)font.italic_Update(font.italic_context);
		if(font.bold_Update)font.bold_Update(font.bold_context);
		if(font.size_Update)font.size_Update(font.size_context);
		if(font.family_Update)font.family_Update(font.family_context);
	}
	 Rectangle::Update();
}
void TextInput::Update()
{
	 Text::Update();
}
