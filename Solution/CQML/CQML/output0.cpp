#include "output0.h"

#include "qml_includes.h"
#include "output1outer.h"
#include "printSomething.h"
//classDeclaration
CQMLGUI::ElementCustom0* CQMLGUI::acElementCustom0()
{
	CQMLGUI::ElementCustom0 * pointer;
	pointer=new CQMLGUI::ElementCustom0();
	return pointer;
}
CQMLGUI::ScaledImageCustom1* CQMLGUI::acScaledImageCustom1()
{
	CQMLGUI::ScaledImageCustom1 * pointer;
	pointer=new CQMLGUI::ScaledImageCustom1();
	return pointer;
}
CQMLGUI::ElementCustom0::ElementCustom0()
{
	classID=11;
}
CQMLGUI::ScaledImageCustom1::ScaledImageCustom1()
{
	classID=12;
}
VariantRef CQMLGUI::ElementCustom0::Get(const char* s)
{
	int hash=GetHash(classID,s);
	if(hash<0) 
	{
		throw(0); 
		return VariantRef();
	}
	switch(hash)
	{
	case 0:
		return VariantRef((CQMLObject**)&refEl,&refEl_Update);
	case 1:
		return VariantRef(x,&x_Update);
	case 2:
		return VariantRef(y,&y_Update);
	case 3:
		return VariantRef(width,&width_Update);
	case 4:
		return VariantRef(height,&height_Update);
	default: break;
	}
	return VariantRef();
}
VariantRef CQMLGUI::ScaledImageCustom1::Get(const char* s)
{
	int hash=GetHash(classID,s);
	if(hash<0) 
	{
		throw(0); 
		return VariantRef();
	}
	switch(hash)
	{
	case 0:
		return VariantRef((CQMLObject**)&refEl,&refEl_Update);
	case 1:
		return VariantRef(status,&status_Update);
	case 2:
		return VariantRef(leftBorder,&leftBorder_Update);
	case 3:
		return VariantRef(bottomBorder,&bottomBorder_Update);
	case 4:
		return VariantRef(rightBorder,&rightBorder_Update);
	case 5:
		return VariantRef(topBorder,&topBorder_Update);
	case 6:
		return VariantRef((CQMLObject*)&img,&img_Update);
	case 7:
		return VariantRef(x,&x_Update);
	case 8:
		return VariantRef(y,&y_Update);
	case 9:
		return VariantRef(width,&width_Update);
	case 10:
		return VariantRef(height,&height_Update);
	default: break;
	}
	return VariantRef();
}
static void _QML_Update(CQMLGUI::Element *s);


//printHandlers()
using namespace CQMLGUI;
static void _QML_element4_MouseReleased(CQMLGUI::QML_Context * context,  QMLMouseEvent EVENT)
{
{(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element2).text= "released" ;
(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element2).text_Update=0;
;
}

}
static void _QML_element4_MousePressed(CQMLGUI::QML_Context * context,  QMLMouseEvent EVENT)
{
{PrintNumber( 13 );
if(meta== 100 ){(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).width= 100 ;
(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).width_Update=0;
;
(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).height= 100 ;
(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).height_Update=0;
;
meta= 200 ;
;
} else {(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element0).refEl=(((CQMLGUI::Rootoutput0*)context->root)->_QML_element1);
(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element0).refEl_Update=0;
;
(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element0).refEl->Get("refEl").Get("refEl").Get("width")=(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element0).refEl->Get("refEl").Get("refEl").Get("width")+ 200 ;
(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element0).refEl->Get("refEl").Get("refEl").Get("width").SetUpdater(0);
;
(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).height= 200 ;
(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).height_Update=0;
;
meta= 100 ;
;
}(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element2).text= "pressed" ;
(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element2).text_Update=0;
;
}

}
static void _QML_element1_KeyPressed(CQMLGUI::QML_Context * context,  QMLKeyboardEvent EVENT)
{
{WindowLimit((*((CQMLGUI::Rootoutput0*)context->root)->_QML_element0).width,(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element0).height);
if(EVENT.key== 'w' ){(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).status= 3 ;
(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).status_Update=0;
;
}if(EVENT.key== 's' ){(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).status= 1 ;
(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).status_Update=0;
;
}if(EVENT.key== 'd' ){(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).status= 0 ;
(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).status_Update=0;
;
}if(EVENT.key== 'a' ){(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).status= 2 ;
(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).status_Update=0;
;
}}

}
static void Update_E1_y(CQMLGUI::QML_Context *);
static int Handler_E1_y(CQMLGUI::QML_Context *);
static void Update_E1_y(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y=Handler_E1_y(context);
}
static int Handler_E1_y(CQMLGUI::QML_Context *context)
{
{if((*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).status== 5 ){ return  25 ;
}if(CanMove((*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).x,(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).y,(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).status)){if((*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).status== 1 ){ return (*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).y+ 1 ;
}if((*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).status== 3 ){ return (*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).y- 1 ;
}} return (*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).y;
}
}
static void Update_E1_x(CQMLGUI::QML_Context *);
static int Handler_E1_x(CQMLGUI::QML_Context *);
static void Update_E1_x(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x=Handler_E1_x(context);
}
static int Handler_E1_x(CQMLGUI::QML_Context *context)
{
{if((*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).status== 5 ){ return  25 ;
}if(CanMove((*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).x,(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).y,(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).status)){if((*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).status== 0 ){ return (*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).x+ 1 ;
}if((*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).status== 2 ){ return (*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).x- 1 ;
}} return (*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).x;
}
}

 //rootElementAllocation() 
CQMLGUI::ElementCustom0* CQMLGUI::acGUI_Rootoutput0()
{
	CQMLGUI::Rootoutput0 * pointer;
	pointer=new CQMLGUI::Rootoutput0();
	return pointer->_QML_element0;
}

 //printAttributeUpdatersHeaders() 
static void Update_E0_x(CQMLGUI::QML_Context *);
static void Update_E0_y(CQMLGUI::QML_Context *);
static void Update_E0_width(CQMLGUI::QML_Context *);
static void Update_E0_height(CQMLGUI::QML_Context *);
static void Update_E0_refEl(CQMLGUI::QML_Context *);
static void Update_E1_refEl(CQMLGUI::QML_Context *);
static void Update_E1_status(CQMLGUI::QML_Context *);
static void Update_E1_width(CQMLGUI::QML_Context *);
static void Update_E1_height(CQMLGUI::QML_Context *);
static void Update_E1_img_src(CQMLGUI::QML_Context *);
static string Handler_E1_img_src(CQMLGUI::QML_Context *);
static void Update_E1_topBorder(CQMLGUI::QML_Context *);
static void Update_E1_leftBorder(CQMLGUI::QML_Context *);
static void Update_E1_rightBorder(CQMLGUI::QML_Context *);
static void Update_E1_bottomBorder(CQMLGUI::QML_Context *);
static void Update_E2_x(CQMLGUI::QML_Context *);
static void Update_E2_y(CQMLGUI::QML_Context *);
static void Update_E2_width(CQMLGUI::QML_Context *);
static void Update_E2_height(CQMLGUI::QML_Context *);
static void Update_E2_font_family(CQMLGUI::QML_Context *);
static void Update_E2_font_size(CQMLGUI::QML_Context *);
static void Update_E2_text(CQMLGUI::QML_Context *);
static void Update_E2_text_color_red(CQMLGUI::QML_Context *);
static void Update_E2_text_color_green(CQMLGUI::QML_Context *);
static void Update_E2_text_color_blue(CQMLGUI::QML_Context *);
static void Update_E3_x(CQMLGUI::QML_Context *);
static void Update_E3_y(CQMLGUI::QML_Context *);
static void Update_E3_color_red(CQMLGUI::QML_Context *);
static void Update_E3_color_green(CQMLGUI::QML_Context *);
static void Update_E3_color_blue(CQMLGUI::QML_Context *);
static void Update_E3_border(CQMLGUI::QML_Context *);
static void Update_E3_borderColor_red(CQMLGUI::QML_Context *);
static void Update_E3_borderColor_green(CQMLGUI::QML_Context *);
static void Update_E3_borderColor_blue(CQMLGUI::QML_Context *);
static void Update_E3_width(CQMLGUI::QML_Context *);
static void Update_E3_height(CQMLGUI::QML_Context *);
static void Update_E4_width(CQMLGUI::QML_Context *);
static void Update_E4_height(CQMLGUI::QML_Context *);

 //printElementUpdatersHeaders() 
static void Update_E0(CQMLGUI::Element *self);
static void Update_E1(CQMLGUI::Element *self);
static void Update_E2(CQMLGUI::Element *self);
static void Update_E3(CQMLGUI::Element *self);
static void Update_E4(CQMLGUI::Element *self);

 //rootElementConstructor() 
CQMLGUI::Rootoutput0::Rootoutput0()
{
	_QML_element0 = CQMLGUI::acElementCustom0();
	_QML_element0->root=(CQMLGUI::Element*)this;
	_QML_element1 = CQMLGUI::acScaledImageCustom1();
	_QML_element1->root=(CQMLGUI::Element*)this;
	_QML_element2 = CQMLGUI::acText();
	_QML_element2->root=(CQMLGUI::Element*)this;
	_QML_element3 = CQMLGUI::acRectangle();
	_QML_element3->root=(CQMLGUI::Element*)this;
	_QML_element4 = CQMLGUI::acMouseArea();
	_QML_element4->root=(CQMLGUI::Element*)this;
	mGUI_Element_InsertChild((CQMLGUI::Element*)_QML_element0, (CQMLGUI::Element*)_QML_element1);
	mGUI_Element_InsertChild((CQMLGUI::Element*)_QML_element0, (CQMLGUI::Element*)_QML_element2);
	mGUI_Element_InsertChild((CQMLGUI::Element*)_QML_element0, (CQMLGUI::Element*)_QML_element3);
	mGUI_Element_InsertChild((CQMLGUI::Element*)_QML_element3, (CQMLGUI::Element*)_QML_element4);

 //printAttributeUpdaters() 
	((Element*)_QML_element0)->x_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((Element*)_QML_element0)->x_Update  = Update_E0_x;
	((Element*)_QML_element0)->y_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((Element*)_QML_element0)->y_Update  = Update_E0_y;
	((Element*)_QML_element0)->width_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((Element*)_QML_element0)->width_Update  = Update_E0_width;
	((Element*)_QML_element0)->height_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((Element*)_QML_element0)->height_Update  = Update_E0_height;
	((ElementCustom0*)_QML_element0)->refEl_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((ElementCustom0*)_QML_element0)->refEl_Update  = Update_E0_refEl;
	((ScaledImageCustom1*)_QML_element1)->refEl_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element1);
	((ScaledImageCustom1*)_QML_element1)->refEl_Update  = Update_E1_refEl;
	((ScaledImageCustom1*)_QML_element1)->status_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element1);
	((ScaledImageCustom1*)_QML_element1)->status_Update  = Update_E1_status;
	((Element*)_QML_element1)->width_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element1);
	((Element*)_QML_element1)->width_Update  = Update_E1_width;
	((Element*)_QML_element1)->height_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element1);
	((Element*)_QML_element1)->height_Update  = Update_E1_height;
	((Image*)_QML_element1)->img.src_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_QML_element1));
	((Image*)_QML_element1)->img.src_Update  = Update_E1_img_src;
	((ScaledImage*)_QML_element1)->topBorder_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element1);
	((ScaledImage*)_QML_element1)->topBorder_Update  = Update_E1_topBorder;
	((ScaledImage*)_QML_element1)->leftBorder_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element1);
	((ScaledImage*)_QML_element1)->leftBorder_Update  = Update_E1_leftBorder;
	((ScaledImage*)_QML_element1)->rightBorder_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element1);
	((ScaledImage*)_QML_element1)->rightBorder_Update  = Update_E1_rightBorder;
	((ScaledImage*)_QML_element1)->bottomBorder_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element1);
	((ScaledImage*)_QML_element1)->bottomBorder_Update  = Update_E1_bottomBorder;
	((Element*)_QML_element2)->x_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element2);
	((Element*)_QML_element2)->x_Update  = Update_E2_x;
	((Element*)_QML_element2)->y_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element2);
	((Element*)_QML_element2)->y_Update  = Update_E2_y;
	((Element*)_QML_element2)->width_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element2);
	((Element*)_QML_element2)->width_Update  = Update_E2_width;
	((Element*)_QML_element2)->height_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element2);
	((Element*)_QML_element2)->height_Update  = Update_E2_height;
	((Text*)_QML_element2)->font.family_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_QML_element2));
	((Text*)_QML_element2)->font.family_Update  = Update_E2_font_family;
	((Text*)_QML_element2)->font.size_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_QML_element2));
	((Text*)_QML_element2)->font.size_Update  = Update_E2_font_size;
	((Text*)_QML_element2)->text_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element2);
	((Text*)_QML_element2)->text_Update  = Update_E2_text;
	((Text*)_QML_element2)->text_color.red_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_QML_element2));
	((Text*)_QML_element2)->text_color.red_Update  = Update_E2_text_color_red;
	((Text*)_QML_element2)->text_color.green_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_QML_element2));
	((Text*)_QML_element2)->text_color.green_Update  = Update_E2_text_color_green;
	((Text*)_QML_element2)->text_color.blue_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_QML_element2));
	((Text*)_QML_element2)->text_color.blue_Update  = Update_E2_text_color_blue;
	((Element*)_QML_element3)->x_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element3);
	((Element*)_QML_element3)->x_Update  = Update_E3_x;
	((Element*)_QML_element3)->y_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element3);
	((Element*)_QML_element3)->y_Update  = Update_E3_y;
	((Rectangle*)_QML_element3)->color.red_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_QML_element3));
	((Rectangle*)_QML_element3)->color.red_Update  = Update_E3_color_red;
	((Rectangle*)_QML_element3)->color.green_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_QML_element3));
	((Rectangle*)_QML_element3)->color.green_Update  = Update_E3_color_green;
	((Rectangle*)_QML_element3)->color.blue_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_QML_element3));
	((Rectangle*)_QML_element3)->color.blue_Update  = Update_E3_color_blue;
	((Rectangle*)_QML_element3)->border_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element3);
	((Rectangle*)_QML_element3)->border_Update  = Update_E3_border;
	((Rectangle*)_QML_element3)->borderColor.red_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_QML_element3));
	((Rectangle*)_QML_element3)->borderColor.red_Update  = Update_E3_borderColor_red;
	((Rectangle*)_QML_element3)->borderColor.green_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_QML_element3));
	((Rectangle*)_QML_element3)->borderColor.green_Update  = Update_E3_borderColor_green;
	((Rectangle*)_QML_element3)->borderColor.blue_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_QML_element3));
	((Rectangle*)_QML_element3)->borderColor.blue_Update  = Update_E3_borderColor_blue;
	((Element*)_QML_element3)->width_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element3);
	((Element*)_QML_element3)->width_Update  = Update_E3_width;
	((Element*)_QML_element3)->height_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element3);
	((Element*)_QML_element3)->height_Update  = Update_E3_height;
	((Element*)_QML_element4)->width_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element4);
	((Element*)_QML_element4)->width_Update  = Update_E4_width;
	((Element*)_QML_element4)->height_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element4);
	((Element*)_QML_element4)->height_Update  = Update_E4_height;
//printHandlerAssignment()
	_QML_element4->CustomMouseReleased=_QML_element4_MouseReleased;
	_QML_element4->CustomMouseReleased_context=acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element4);
	_QML_element4->CustomMousePressed=_QML_element4_MousePressed;
	_QML_element4->CustomMousePressed_context=acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element4);
	_QML_element1->CustomKeyPressed=_QML_element1_KeyPressed;
	_QML_element1->CustomKeyPressed_context=acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element1);
	((Element*)_QML_element1)->y_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element1);
	((Element*)_QML_element1)->y_Update  = Update_E1_y;
	((Element*)_QML_element1)->x_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element1);
	((Element*)_QML_element1)->x_Update  = Update_E1_x;

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
static void Update_E4_height(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->height=(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element3).height;
}
static void Update_E4_width(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->width=(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element3).width;
}
static void Update_E3_height(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->height= 40 ;
}
static void Update_E3_width(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->width= 40 ;
}
static void Update_E3_borderColor_blue(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Rectangle*)context->self)->borderColor.blue= 0 ;
}
static void Update_E3_borderColor_green(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Rectangle*)context->self)->borderColor.green= 0 ;
}
static void Update_E3_borderColor_red(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Rectangle*)context->self)->borderColor.red= 1 ;
}
static void Update_E3_border(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Rectangle*)context->self)->border= 4 ;
}
static void Update_E3_color_blue(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Rectangle*)context->self)->color.blue= 0 ;
}
static void Update_E3_color_green(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Rectangle*)context->self)->color.green= 1 ;
}
static void Update_E3_color_red(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Rectangle*)context->self)->color.red= 0 ;
}
static void Update_E3_y(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y=(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element0).height- 45 ;
}
static void Update_E3_x(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x= 5 ;
}
static void Update_E2_text_color_blue(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Text*)context->self)->text_color.blue= 1 ;
}
static void Update_E2_text_color_green(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Text*)context->self)->text_color.green= 0 ;
}
static void Update_E2_text_color_red(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Text*)context->self)->text_color.red= 1 ;
}
static void Update_E2_text(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Text*)context->self)->text= "You win" ;
}
static void Update_E2_font_size(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Text*)context->self)->font.size= 12 ;
}
static void Update_E2_font_family(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Text*)context->self)->font.family= "Tahoma" ;
}
static void Update_E2_height(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->height=(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element0).height/ 2 - 10 ;
}
static void Update_E2_width(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->width=(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element0).width/ 2 - 10 ;
}
static void Update_E2_y(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y= 5 ;
}
static void Update_E2_x(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x= 5 ;
}
static void Update_E1_bottomBorder(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::ScaledImage*)context->self)->bottomBorder= 10 ;
}
static void Update_E1_rightBorder(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::ScaledImage*)context->self)->rightBorder= 10 ;
}
static void Update_E1_leftBorder(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::ScaledImage*)context->self)->leftBorder= 10 ;
}
static void Update_E1_topBorder(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::ScaledImage*)context->self)->topBorder= 10 ;
}
static void Update_E1_img_src(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Image*)context->self)->img.src=Handler_E1_img_src(context);
}
static string Handler_E1_img_src(CQMLGUI::QML_Context *context)
{
{if((*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).status== 0 ||(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).status== 5 ) return  "img1.png" ;
 else if((*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).status== 1 ) return  "img2.png" ;
 else if((*((CQMLGUI::Rootoutput0*)context->root)->_QML_element1).status== 2 ) return  "img3.png" ;
 else  return  "img4.png" ;
}
}
static void Update_E1_height(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->height= 100 ;
}
static void Update_E1_width(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->width= 100 ;
}
static void Update_E1_status(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::ScaledImageCustom1*)context->self)->status= 5 ;
}
static void Update_E1_refEl(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::ScaledImageCustom1*)context->self)->refEl=(((CQMLGUI::Rootoutput0*)context->root)->_QML_element0);
}
static void Update_E0_refEl(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::ElementCustom0*)context->self)->refEl=(((CQMLGUI::Rootoutput0*)context->root)->_QML_element1);
}
static void Update_E0_height(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->height=(*((CQMLGUI::Rootoutput0*)context->root)->_QML_element0).width;
}
static void Update_E0_width(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->width= 500 ;
}
static void Update_E0_y(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y= 0 ;
}
static void Update_E0_x(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x= 0 ;
}

 //printElementUpdaters() 
using namespace CQMLGUI;
void ElementCustom0::Update()
{
	if(!enabled)
		return;
	if(refEl_Update)refEl_Update(refEl_context);
	 Element::Update();
}
void ScaledImageCustom1::Update()
{
	if(!enabled)
		return;
	if(refEl_Update)refEl_Update(refEl_context);
	if(status_Update)status_Update(status_context);
	 ScaledImage::Update();
}
