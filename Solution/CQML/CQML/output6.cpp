#include "output6.h"

#include "qml_includes.h"
//classDeclaration
CQMLGUI::MouseAreaCustom0* CQMLGUI::acMouseAreaCustom0()
{
	CQMLGUI::MouseAreaCustom0 * pointer;
	pointer=new CQMLGUI::MouseAreaCustom0();
	return pointer;
}
CQMLGUI::MouseAreaCustom0::MouseAreaCustom0()
{
	classID=11;
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
}
VariantRef CQMLGUI::MouseAreaCustom0::Get(const char* s)
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
		return VariantRef(x,&x_Update);
	case 6:
		return VariantRef(y,&y_Update);
	case 7:
		return VariantRef(width,&width_Update);
	case 8:
		return VariantRef(height,&height_Update);
	case 9:
		return VariantRef(visible,&visible_Update);
	case 10:
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
{(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element0).entered= 0 ;
(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element0).entered_Update=0;
;
(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element1).img.src=(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element0).defImg;
(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element1).img.src_Update=0;
;
}

}
static void _QML_element0_MouseEntered(CQMLGUI::QML_Context * context,  QMLMouseEvent EVENT)
{
{(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element0).entered= 1 ;
(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element0).entered_Update=0;
;
if((*((CQMLGUI::Rootoutput6*)context->root)->_QML_element0).pressed== 1 ){(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element1).img.src=(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element0).pressedImg;
(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element1).img.src_Update=0;
;
} else {(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element1).img.src=(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element0).overImg;
(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element1).img.src_Update=0;
;
}}

}
static void _QML_element0_MouseReleased(CQMLGUI::QML_Context * context,  QMLMouseEvent EVENT)
{
{(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element0).pressed= 0 ;
(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element0).pressed_Update=0;
;
if((*((CQMLGUI::Rootoutput6*)context->root)->_QML_element0).entered== 1 ){(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element1).img.src=(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element0).overImg;
(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element1).img.src_Update=0;
;
} else {(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element1).img.src=(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element0).defImg;
(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element1).img.src_Update=0;
;
}}

}
static void _QML_element0_MousePressed(CQMLGUI::QML_Context * context,  QMLMouseEvent EVENT)
{
{(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element0).pressed= 1 ;
(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element0).pressed_Update=0;
;
(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element1).img.src=(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element0).pressedImg;
(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element1).img.src_Update=0;
;
}

}

 //rootElementAllocation() 
CQMLGUI::MouseAreaCustom0* CQMLGUI::acGUI_Rootoutput6()
{
	CQMLGUI::Rootoutput6 * pointer;
	pointer=new CQMLGUI::Rootoutput6();
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
static void Update_E1_width(CQMLGUI::QML_Context *);
static void Update_E1_height(CQMLGUI::QML_Context *);
static void Update_E1_img_src(CQMLGUI::QML_Context *);

 //printElementUpdatersHeaders() 
static void Update_E0(CQMLGUI::Element *self);
static void Update_E1(CQMLGUI::Element *self);

 //rootElementConstructor() 
CQMLGUI::Rootoutput6::Rootoutput6()
{
	CQMLGUI::Element*tmp=0;
	_QML_element0 = CQMLGUI::acMouseAreaCustom0();
	_QML_element0->root=(CQMLGUI::Element*)this;
	_QML_element1 = CQMLGUI::acImage();
	_QML_element1->root=(CQMLGUI::Element*)this;
	mGUI_Element_InsertChild((CQMLGUI::Element*)_QML_element0, (CQMLGUI::Element*)_QML_element1);

 //printAttributeUpdaters() 
	((Element*)_QML_element0)->width_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((Element*)_QML_element0)->width_Update  = Update_E0_width;
	((Element*)_QML_element0)->height_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((Element*)_QML_element0)->height_Update  = Update_E0_height;
	((MouseAreaCustom0*)_QML_element0)->pressed_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((MouseAreaCustom0*)_QML_element0)->pressed_Update  = Update_E0_pressed;
	((MouseAreaCustom0*)_QML_element0)->entered_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((MouseAreaCustom0*)_QML_element0)->entered_Update  = Update_E0_entered;
	((MouseAreaCustom0*)_QML_element0)->pressedImg_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((MouseAreaCustom0*)_QML_element0)->pressedImg_Update  = Update_E0_pressedImg;
	((MouseAreaCustom0*)_QML_element0)->overImg_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((MouseAreaCustom0*)_QML_element0)->overImg_Update  = Update_E0_overImg;
	((MouseAreaCustom0*)_QML_element0)->defImg_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element0);
	((MouseAreaCustom0*)_QML_element0)->defImg_Update  = Update_E0_defImg;
	((Element*)_QML_element1)->width_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element1);
	((Element*)_QML_element1)->width_Update  = Update_E1_width;
	((Element*)_QML_element1)->height_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_QML_element1);
	((Element*)_QML_element1)->height_Update  = Update_E1_height;
	((Image*)_QML_element1)->img.src_context  = acQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_QML_element1));
	((Image*)_QML_element1)->img.src_Update  = Update_E1_img_src;
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
	CQMLGUI::Rootoutput6 * self=(CQMLGUI::Rootoutput6 *)s;
	s->Update();

}

 //printAttributesBodies()
static void Update_E1_img_src(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Image*)context->self)->img.src=(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element0).defImg;
}
static void Update_E1_height(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->height=(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element0).height;
}
static void Update_E1_width(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->width=(*((CQMLGUI::Rootoutput6*)context->root)->_QML_element0).width;
}
static void Update_E0_defImg(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0*)context->self)->defImg= "pics/button_long.png" ;
}
static void Update_E0_overImg(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0*)context->self)->overImg= "pics/button_long_over.png" ;
}
static void Update_E0_pressedImg(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0*)context->self)->pressedImg= "pics/button_long_down.png" ;
}
static void Update_E0_entered(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0*)context->self)->entered= 0 ;
}
static void Update_E0_pressed(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0*)context->self)->pressed= 0 ;
}
static void Update_E0_height(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->height= 100 ;
}
static void Update_E0_width(CQMLGUI::QML_Context *context)
{
	((CQMLGUI::Element*)context->self)->width= 100 ;
}

 //printElementUpdaters() 
using namespace CQMLGUI;
void MouseAreaCustom0::Update()
{
	if(!enabled)
		return;
	if(pressed_Update)pressed_Update(pressed_context);
	if(entered_Update)entered_Update(entered_context);
	if(pressedImg_Update)pressedImg_Update(pressedImg_context);
	if(overImg_Update)overImg_Update(overImg_context);
	if(defImg_Update)defImg_Update(defImg_context);
	 MouseArea::Update();
}
