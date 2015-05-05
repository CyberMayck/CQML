#include "output1.h"

#include "qml_includes.h"
//classDeclaration
CQMLGUI::MouseAreaCustom3* CQMLGUI::acMouseAreaCustom3()
{
	CQMLGUI::MouseAreaCustom3 * pointer;
	pointer=new CQMLGUI::MouseAreaCustom3();
	return pointer;
}
CQMLGUI::MouseAreaCustom3::MouseAreaCustom3()
{
	classID=14;
	pressed_Update=0;
	pressed_context=0;
	entered_Update=0;
	entered_context=0;
	pressedImg_Update=0;
	pressedImg_context=0;
	overImg_Update=0;
	overImg_context=0;
	defImg_Update=0;
	defImg_context=0;
	text_Update=0;
	text_context=0;
}
VariantRef CQMLGUI::MouseAreaCustom3::Get(const char* s)
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
		return VariantRef(pressed,&pressed_Update);
	case 1:
		return VariantRef(entered,&entered_Update);
	case 2:
		return VariantRef(pressedImg,&pressedImg_Update);
	case 3:
		return VariantRef(overImg,&overImg_Update);
	case 4:
		return VariantRef(defImg,&defImg_Update);
	case 5:
		return VariantRef(text,&text_Update);
	case 6:
		return VariantRef(x,&x_Update);
	case 7:
		return VariantRef(y,&y_Update);
	case 8:
		return VariantRef(width,&width_Update);
	case 9:
		return VariantRef(height,&height_Update);
	case 10:
		return VariantRef(visible,&visible_Update);
	case 11:
		return VariantRef(enabled,&enabled_Update);
	default: break;
	}
	return VariantRef();
}
static void _QML_Update(CQMLGUI::Element *s);


//printHandlers()
using namespace CQMLGUI;
static void _QML_element0_MouseExited(CQMLGUI::QML_Context * context,  QMLMouseEvent EVENT)
{
{(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element0).entered= 0 ;
(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element0).entered_Update=0;
;
(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element1).img.src=(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element0).defImg;
(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element1).img.src_Update=0;
;
}

}
static void _QML_element0_MouseEntered(CQMLGUI::QML_Context * context,  QMLMouseEvent EVENT)
{
{(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element0).entered= 1 ;
(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element0).entered_Update=0;
;
if((*((CQMLGUI::Rootoutput1*)context->root)->_QML_element0).pressed== 1 ){(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element1).img.src=(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element0).pressedImg;
(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element1).img.src_Update=0;
;
} else {(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element1).img.src=(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element0).overImg;
(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element1).img.src_Update=0;
;
}}

}
static void _QML_element0_MouseReleased(CQMLGUI::QML_Context * context,  QMLMouseEvent EVENT)
{
{(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element0).pressed= 0 ;
(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element0).pressed_Update=0;
;
if((*((CQMLGUI::Rootoutput1*)context->root)->_QML_element0).entered== 1 ){(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element1).img.src=(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element0).overImg;
(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element1).img.src_Update=0;
;
} else {(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element1).img.src=(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element0).defImg;
(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element1).img.src_Update=0;
;
}}

}
static void _QML_element0_MousePressed(CQMLGUI::QML_Context * context,  QMLMouseEvent EVENT)
{
{(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element0).pressed= 1 ;
(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element0).pressed_Update=0;
;
(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element1).img.src=(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element0).pressedImg;
(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element1).img.src_Update=0;
;
}

}

 //rootElementAllocation() 
CQMLGUI::MouseAreaCustom3* CQMLGUI::acGUI_Rootoutput1()
{
	CQMLGUI::Rootoutput1 * pointer;
	pointer=new CQMLGUI::Rootoutput1();
	return pointer->_QML_element0;
}

 //printAttributeUpdatersHeaders() 
static void Update_E0_width(CQMLGUI::QML_Context *);
static void Update_E0_height(CQMLGUI::QML_Context *);
static void Update_E0_pressed(CQMLGUI::QML_Context *);
static void Update_E0_entered(CQMLGUI::QML_Context *);
static void Update_E0_pressedImg(CQMLGUI::QML_Context *);
static void Update_E0_overImg(CQMLGUI::QML_Context *);
static void Update_E0_defImg(CQMLGUI::QML_Context *);
static void Update_E0_text(CQMLGUI::QML_Context *);
static void Update_E1_width(CQMLGUI::QML_Context *);
static void Update_E1_height(CQMLGUI::QML_Context *);
static void Update_E1_img_src(CQMLGUI::QML_Context *);
static void Update_E2_text(CQMLGUI::QML_Context *);
static void Update_E2_font_family(CQMLGUI::QML_Context *);
static void Update_E2_font_size(CQMLGUI::QML_Context *);
static void Update_E2_color_red(CQMLGUI::QML_Context *);
static void Update_E2_color_green(CQMLGUI::QML_Context *);
static void Update_E2_color_blue(CQMLGUI::QML_Context *);
static void Update_E2_x(CQMLGUI::QML_Context *);
static void Update_E2_y(CQMLGUI::QML_Context *);

 //printElementUpdatersHeaders() 
static void Update_E0(CQMLGUI::Element *self);
static void Update_E1(CQMLGUI::Element *self);
static void Update_E2(CQMLGUI::Element *self);

 //rootElementConstructor() 
CQMLGUI::Rootoutput1::Rootoutput1()
{
	CQMLGUI::Element*tmp=0;
	_QML_element0 = CQMLGUI::acMouseAreaCustom3();
	_QML_element0->root=(CQMLGUI::Element*)this;
	_QML_element1 = CQMLGUI::acImage();
	_QML_element1->root=(CQMLGUI::Element*)this;
	_QML_element2 = CQMLGUI::acText();
	_QML_element2->root=(CQMLGUI::Element*)this;
	mGUI_Element_InsertChild((CQMLGUI::Element*)_QML_element0, (CQMLGUI::Element*)_QML_element1);
	mGUI_Element_InsertChild((CQMLGUI::Element*)_QML_element0, (CQMLGUI::Element*)_QML_element2);

 //printAttributeUpdaters() 
	((Element*)_QML_element0)->width_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((Element*)_QML_element0)->width_Update  = Update_E0_width;
	((Element*)_QML_element0)->height_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((Element*)_QML_element0)->height_Update  = Update_E0_height;
	((MouseAreaCustom3*)_QML_element0)->pressed_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((MouseAreaCustom3*)_QML_element0)->pressed_Update  = Update_E0_pressed;
	((MouseAreaCustom3*)_QML_element0)->entered_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((MouseAreaCustom3*)_QML_element0)->entered_Update  = Update_E0_entered;
	((MouseAreaCustom3*)_QML_element0)->pressedImg_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((MouseAreaCustom3*)_QML_element0)->pressedImg_Update  = Update_E0_pressedImg;
	((MouseAreaCustom3*)_QML_element0)->overImg_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((MouseAreaCustom3*)_QML_element0)->overImg_Update  = Update_E0_overImg;
	((MouseAreaCustom3*)_QML_element0)->defImg_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((MouseAreaCustom3*)_QML_element0)->defImg_Update  = Update_E0_defImg;
	((MouseAreaCustom3*)_QML_element0)->text_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((MouseAreaCustom3*)_QML_element0)->text_Update  = Update_E0_text;
	((Element*)_QML_element1)->width_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element1);
	((Element*)_QML_element1)->width_Update  = Update_E1_width;
	((Element*)_QML_element1)->height_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element1);
	((Element*)_QML_element1)->height_Update  = Update_E1_height;
	((Image*)_QML_element1)->img.src_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_QML_element1));
	((Image*)_QML_element1)->img.src_Update  = Update_E1_img_src;
	((Text*)_QML_element2)->text_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element2);
	((Text*)_QML_element2)->text_Update  = Update_E2_text;
	((Text*)_QML_element2)->font.family_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_QML_element2));
	((Text*)_QML_element2)->font.family_Update  = Update_E2_font_family;
	((Text*)_QML_element2)->font.size_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_QML_element2));
	((Text*)_QML_element2)->font.size_Update  = Update_E2_font_size;
	((Rectangle*)_QML_element2)->color.red_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_QML_element2));
	((Rectangle*)_QML_element2)->color.red_Update  = Update_E2_color_red;
	((Rectangle*)_QML_element2)->color.green_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_QML_element2));
	((Rectangle*)_QML_element2)->color.green_Update  = Update_E2_color_green;
	((Rectangle*)_QML_element2)->color.blue_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_QML_element2));
	((Rectangle*)_QML_element2)->color.blue_Update  = Update_E2_color_blue;
	((Element*)_QML_element2)->x_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element2);
	((Element*)_QML_element2)->x_Update  = Update_E2_x;
	((Element*)_QML_element2)->y_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element2);
	((Element*)_QML_element2)->y_Update  = Update_E2_y;
//printHandlerAssignment()
	_QML_element0->CustomMouseExited=_QML_element0_MouseExited;
	_QML_element0->CustomMouseExited_context=acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	_QML_element0->CustomMouseEntered=_QML_element0_MouseEntered;
	_QML_element0->CustomMouseEntered_context=acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	_QML_element0->CustomMouseReleased=_QML_element0_MouseReleased;
	_QML_element0->CustomMouseReleased_context=acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	_QML_element0->CustomMousePressed=_QML_element0_MousePressed;
	_QML_element0->CustomMousePressed_context=acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);

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
static void Update_E0_text(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::MouseAreaCustom3*)context->self)->text= "Button" ;
}
static void Update_E2_text(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Text*)context->self)->text=(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element0).text;
}
static void Update_E2_font_size(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Text*)context->self)->font.size=(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element0).height/ 4 ;
}
static void Update_E2_font_family(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Text*)context->self)->font.family= "Tahoma" ;
}
static void Update_E2_color_blue(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Rectangle*)context->self)->color.blue= 1 ;
}
static void Update_E2_color_green(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Rectangle*)context->self)->color.green= 1 ;
}
static void Update_E2_color_red(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Rectangle*)context->self)->color.red= 1 ;
}
static void Update_E2_y(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y=(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element0).height/ 2 ;
}
static void Update_E2_x(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x=(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element0).width/ 2 ;
}
static void Update_E1_img_src(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Image*)context->self)->img.src=(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element0).defImg;
}
static void Update_E1_height(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->height=(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element0).height;
}
static void Update_E1_width(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->width=(*((CQMLGUI::Rootoutput1*)context->root)->_QML_element0).width;
}
static void Update_E0_defImg(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::MouseAreaCustom3*)context->self)->defImg= "pics/button_long.png" ;
}
static void Update_E0_overImg(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::MouseAreaCustom3*)context->self)->overImg= "pics/button_long_over.png" ;
}
static void Update_E0_pressedImg(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::MouseAreaCustom3*)context->self)->pressedImg= "pics/button_long_down.png" ;
}
static void Update_E0_entered(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::MouseAreaCustom3*)context->self)->entered= 0 ;
}
static void Update_E0_pressed(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::MouseAreaCustom3*)context->self)->pressed= 0 ;
}
static void Update_E0_height(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->height= 140 ;
}
static void Update_E0_width(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->width= 600 ;
}

 //printElementUpdaters() 
using namespace CQMLGUI;
void MouseAreaCustom3::Update()
{
	if(!enabled)
		return;
	if(pressed_Update)pressed_Update(pressed_context);
	if(entered_Update)entered_Update(entered_context);
	if(pressedImg_Update)pressedImg_Update(pressedImg_context);
	if(overImg_Update)overImg_Update(overImg_context);
	if(defImg_Update)defImg_Update(defImg_context);
	if(text_Update)text_Update(text_context);
	 MouseArea::Update();
}
