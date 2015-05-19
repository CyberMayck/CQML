#include "output4.h"

#include "qml_includes.h"
//classDeclaration
CQMLGUI::MouseAreaCustom0Custom1* CQMLGUI::acMouseAreaCustom0Custom1()
{
	CQMLGUI::MouseAreaCustom0Custom1 * pointer;
	pointer=new CQMLGUI::MouseAreaCustom0Custom1();
	return pointer;
}
CQMLGUI::MouseAreaCustom0Custom1::MouseAreaCustom0Custom1()
{
	classID=12;
	value_Update=0;
	value_context=0;
	matcher_Update=0;
	matcher_context=0;
	matcher=0;
}
VariantRef CQMLGUI::MouseAreaCustom0Custom1::Get(const char* s)
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
		return VariantRef(value,&value_Update);
	case 1:
		return VariantRef((CQMLObject**)&matcher,&matcher_Update);
	case 2:
		return VariantRef(pressed,&pressed_Update);
	case 3:
		return VariantRef(entered,&entered_Update);
	case 4:
		return VariantRef(pressedImg,&pressedImg_Update);
	case 5:
		return VariantRef(overImg,&overImg_Update);
	case 6:
		return VariantRef(defImg,&defImg_Update);
	case 7:
		return VariantRef(x,&x_Update);
	case 8:
		return VariantRef(y,&y_Update);
	case 9:
		return VariantRef(width,&width_Update);
	case 10:
		return VariantRef(height,&height_Update);
	case 11:
		return VariantRef(visible,&visible_Update);
	case 12:
		return VariantRef(enabled,&enabled_Update);
	default: break;
	}
	return VariantRef();
}
static void _CQML_Update(CQMLGUI::Element *s);


//printHandlers()
using namespace CQMLGUI;
static void _CQML_element0_MouseClicked(CQMLGUI::CQML_Context * context,  CQMLMouseEvent EVENT)
{
{if((*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).matcher->Get("status")== 0 ){(*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).matcher->Get("first")=(((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0);
(*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).matcher->Get("first").SetUpdater(0);
;
(*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).matcher->Get("firstValue")=(*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).value;
(*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).matcher->Get("firstValue").SetUpdater(0);
;
(*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).matcher->Get("status")= 1 ;
(*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).matcher->Get("status").SetUpdater(0);
;
(*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).enabled= 0 ;
(*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).enabled_Update=0;
;
} else if((*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).matcher->Get("status")== 1 ){(*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).matcher->Get("status")= 0 ;
(*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).matcher->Get("status").SetUpdater(0);
;
if((*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).matcher->Get("firstValue")==(*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).value){(*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).matcher->Get("score")=(*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).matcher->Get("score")+(*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).value+ 1 ;
(*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).matcher->Get("score").SetUpdater(0);
;
(*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).matcher->Get("first").Get("enabled")= 0 ;
(*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).matcher->Get("first").Get("enabled").SetUpdater(0);
;
(*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).matcher->Get("first").Get("visible")= 0 ;
(*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).matcher->Get("first").Get("visible").SetUpdater(0);
;
(*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).enabled= 0 ;
(*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).enabled_Update=0;
;
(*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).visible= 0 ;
(*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).visible_Update=0;
;
if((*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).matcher->Get("score")== 17 ){(*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).matcher->Get("winMsg").Get("visible")= 1 ;
(*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).matcher->Get("winMsg").Get("visible").SetUpdater(0);
;
}} else {(*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).matcher->Get("first").Get("enabled")= 1 ;
(*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).matcher->Get("first").Get("enabled").SetUpdater(0);
;
}}}

}
static void Update_E0_pressedImg(CQMLGUI::CQML_Context *);
static string Handler_E0_pressedImg(CQMLGUI::CQML_Context *);
static void Update_E0_pressedImg(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0*)context->self)->pressedImg=Handler_E0_pressedImg(context);
}
static string Handler_E0_pressedImg(CQMLGUI::CQML_Context *context)
{
{if((*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).value== 0 ){ return  "pics/red_round_down.png" ;
} else if((*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).value== 1 ){ return  "pics/green_round_down.png" ;
} else if((*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).value== 2 ){ return  "pics/blue_round_down.png" ;
} else { return  "pics/yellow_round_down.png" ;
}}
}
static void Update_E0_overImg(CQMLGUI::CQML_Context *);
static string Handler_E0_overImg(CQMLGUI::CQML_Context *);
static void Update_E0_overImg(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0*)context->self)->overImg=Handler_E0_overImg(context);
}
static string Handler_E0_overImg(CQMLGUI::CQML_Context *context)
{
{if((*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).value== 0 ){ return  "pics/red_round_over.png" ;
} else if((*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).value== 1 ){ return  "pics/green_round_over.png" ;
} else if((*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).value== 2 ){ return  "pics/blue_round_over.png" ;
} else { return  "pics/yellow_round_over.png" ;
}}
}
static void Update_E0_defImg(CQMLGUI::CQML_Context *);
static string Handler_E0_defImg(CQMLGUI::CQML_Context *);
static void Update_E0_defImg(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0*)context->self)->defImg=Handler_E0_defImg(context);
}
static string Handler_E0_defImg(CQMLGUI::CQML_Context *context)
{
{if((*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).value== 0 ){ return  "pics/red_round.png" ;
} else if((*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).value== 1 ){ return  "pics/green_round.png" ;
} else if((*((CQMLGUI::Rootoutput4*)context->root)->_CQML_element0).value== 2 ){ return  "pics/blue_round.png" ;
} else { return  "pics/yellow_round.png" ;
}}
}

 //rootElementAllocation() 
CQMLGUI::MouseAreaCustom0Custom1* CQMLGUI::acGUI_Rootoutput4()
{
	CQMLGUI::Rootoutput4 * pointer;
	pointer=new CQMLGUI::Rootoutput4();
	return pointer->_CQML_element0;
}

 //printAttributeUpdatersHeaders() 
static void Update_E0_width(CQMLGUI::CQML_Context *);
static void Update_E0_height(CQMLGUI::CQML_Context *);
static void Update_E0_value(CQMLGUI::CQML_Context *);

 //printElementUpdatersHeaders() 
static void Update_E0(CQMLGUI::Element *self);

 //rootElementConstructor() 
CQMLGUI::Rootoutput4::Rootoutput4()
{
	CQMLGUI::Element*tmp=0;
	_CQML_element0 = CQMLGUI::acMouseAreaCustom0Custom1();
	tmp=CQMLGUI::acGUI_Rootoutput6();
	CopyChildren(_CQML_element0,tmp);
	tmp=tmp->root;
	_CQML_element0->pressed=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->pressed;
	_CQML_element0->pressed_Update=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->pressed_Update;
	_CQML_element0->pressed_context=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->pressed_context;
	if(_CQML_element0->pressed_context)
		_CQML_element0->pressed_context->self=_CQML_element0;
	_CQML_element0->entered=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->entered;
	_CQML_element0->entered_Update=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->entered_Update;
	_CQML_element0->entered_context=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->entered_context;
	if(_CQML_element0->entered_context)
		_CQML_element0->entered_context->self=_CQML_element0;
	_CQML_element0->pressedImg=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->pressedImg;
	_CQML_element0->pressedImg_Update=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->pressedImg_Update;
	_CQML_element0->pressedImg_context=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->pressedImg_context;
	if(_CQML_element0->pressedImg_context)
		_CQML_element0->pressedImg_context->self=_CQML_element0;
	_CQML_element0->overImg=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->overImg;
	_CQML_element0->overImg_Update=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->overImg_Update;
	_CQML_element0->overImg_context=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->overImg_context;
	if(_CQML_element0->overImg_context)
		_CQML_element0->overImg_context->self=_CQML_element0;
	_CQML_element0->defImg=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->defImg;
	_CQML_element0->defImg_Update=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->defImg_Update;
	_CQML_element0->defImg_context=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->defImg_context;
	if(_CQML_element0->defImg_context)
		_CQML_element0->defImg_context->self=_CQML_element0;
	_CQML_element0->CustomMouseClicked=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->CustomMouseClicked;
	_CQML_element0->CustomMouseClicked_context=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->CustomMouseClicked_context;
	if(_CQML_element0->CustomMouseClicked_context)
		_CQML_element0->CustomMouseClicked_context->self=_CQML_element0;
	_CQML_element0->CustomMousePressed=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->CustomMousePressed;
	_CQML_element0->CustomMousePressed_context=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->CustomMousePressed_context;
	if(_CQML_element0->CustomMousePressed_context)
		_CQML_element0->CustomMousePressed_context->self=_CQML_element0;
	_CQML_element0->CustomMouseReleased=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->CustomMouseReleased;
	_CQML_element0->CustomMouseReleased_context=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->CustomMouseReleased_context;
	if(_CQML_element0->CustomMouseReleased_context)
		_CQML_element0->CustomMouseReleased_context->self=_CQML_element0;
	_CQML_element0->CustomMouseMoved=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->CustomMouseMoved;
	_CQML_element0->CustomMouseMoved_context=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->CustomMouseMoved_context;
	if(_CQML_element0->CustomMouseMoved_context)
		_CQML_element0->CustomMouseMoved_context->self=_CQML_element0;
	_CQML_element0->CustomMouseEntered=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->CustomMouseEntered;
	_CQML_element0->CustomMouseEntered_context=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->CustomMouseEntered_context;
	if(_CQML_element0->CustomMouseEntered_context)
		_CQML_element0->CustomMouseEntered_context->self=_CQML_element0;
	_CQML_element0->CustomMouseExited=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->CustomMouseExited;
	_CQML_element0->CustomMouseExited_context=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->CustomMouseExited_context;
	if(_CQML_element0->CustomMouseExited_context)
		_CQML_element0->CustomMouseExited_context->self=_CQML_element0;
	_CQML_element0->CustomMouseScrolled=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->CustomMouseScrolled;
	_CQML_element0->CustomMouseScrolled_context=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->CustomMouseScrolled_context;
	if(_CQML_element0->CustomMouseScrolled_context)
		_CQML_element0->CustomMouseScrolled_context->self=_CQML_element0;
	_CQML_element0->CustomKeyPressed=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->CustomKeyPressed;
	_CQML_element0->CustomKeyPressed_context=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->CustomKeyPressed_context;
	if(_CQML_element0->CustomKeyPressed_context)
		_CQML_element0->CustomKeyPressed_context->self=_CQML_element0;
	_CQML_element0->CustomKeyReleased=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->CustomKeyReleased;
	_CQML_element0->CustomKeyReleased_context=((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0->CustomKeyReleased_context;
	if(_CQML_element0->CustomKeyReleased_context)
		_CQML_element0->CustomKeyReleased_context->self=_CQML_element0;
	delete ((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0;
	((CQMLGUI::Rootoutput6*)tmp)->_CQML_element0=_CQML_element0;
	_CQML_element0->root=(CQMLGUI::Element*)this;

 //printAttributeUpdaters() 
	((Element*)_CQML_element0)->width_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element0);
	((Element*)_CQML_element0)->width_Update  = Update_E0_width;
	((Element*)_CQML_element0)->height_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element0);
	((Element*)_CQML_element0)->height_Update  = Update_E0_height;
	((MouseAreaCustom0Custom1*)_CQML_element0)->value_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element0);
	((MouseAreaCustom0Custom1*)_CQML_element0)->value_Update  = Update_E0_value;
//printHandlerAssignment()
	_CQML_element0->CustomMouseClicked=_CQML_element0_MouseClicked;
	_CQML_element0->CustomMouseClicked_context=acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element0);
	((MouseAreaCustom0*)_CQML_element0)->pressedImg_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element0);
	((MouseAreaCustom0*)_CQML_element0)->pressedImg_Update  = Update_E0_pressedImg;
	((MouseAreaCustom0*)_CQML_element0)->overImg_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element0);
	((MouseAreaCustom0*)_CQML_element0)->overImg_Update  = Update_E0_overImg;
	((MouseAreaCustom0*)_CQML_element0)->defImg_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element0);
	((MouseAreaCustom0*)_CQML_element0)->defImg_Update  = Update_E0_defImg;
	_CQML_Update((CQMLGUI::Element *)_CQML_element0);

}

 //rootElementUpdater() 
static void _CQML_Update(CQMLGUI::Element *s)
{
	CQMLGUI::Rootoutput4 * self=(CQMLGUI::Rootoutput4 *)s;
	s->Update();

}

 //printAttributesBodies()
static void Update_E0_width(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->width= 100 ;
}
static void Update_E0_height(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->height= 100 ;
}
static void Update_E0_value(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->value= 0 ;
}

 //printElementUpdaters() 
using namespace CQMLGUI;
void MouseAreaCustom0Custom1::Update()
{
	if(!enabled)
		return;
	if(value_Update)value_Update(value_context);
	if(matcher_Update)matcher_Update(matcher_context);
	 MouseAreaCustom0::Update();
}
