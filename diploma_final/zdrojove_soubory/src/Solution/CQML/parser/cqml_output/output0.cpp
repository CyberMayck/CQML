#include "output0.h"

#include "qml_includes.h"
//classDeclaration
static void _CQML_Update(CQMLGUI::Element *s);


//printHandlers()
using namespace CQMLGUI;
static void _CQML_element1_MouseClicked(CQMLGUI::CQML_Context * context,  CQMLMouseEvent EVENT)
{
{(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element1).visible= 0 ;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element1).visible_Update=0;
;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element1).enabled= 0 ;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element1).enabled_Update=0;
;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element2).visible= 0 ;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element2).visible_Update=0;
;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element2).enabled= 0 ;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element2).enabled_Update=0;
;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element3).visible= 0 ;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element3).visible_Update=0;
;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element3).enabled= 0 ;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element3).enabled_Update=0;
;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element5).visible= 1 ;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element5).visible_Update=0;
;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element5).enabled= 1 ;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element5).enabled_Update=0;
;
}

}
static void _CQML_element2_MouseClicked(CQMLGUI::CQML_Context * context,  CQMLMouseEvent EVENT)
{
{(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element1).visible= 0 ;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element1).visible_Update=0;
;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element1).enabled= 0 ;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element1).enabled_Update=0;
;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element2).visible= 0 ;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element2).visible_Update=0;
;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element2).enabled= 0 ;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element2).enabled_Update=0;
;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element3).visible= 0 ;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element3).visible_Update=0;
;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element3).enabled= 0 ;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element3).enabled_Update=0;
;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element4).enabled= 1 ;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element4).enabled_Update=0;
;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element4).visible= 1 ;
(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element4).visible_Update=0;
;
}

}
static void _CQML_element3_MouseClicked(CQMLGUI::CQML_Context * context,  CQMLMouseEvent EVENT)
{
{exit( 0 );
}

}

 //rootElementAllocation() 
CQMLGUI::Rectangle* CQMLGUI::acGUI_Rootoutput0()
{
	CQMLGUI::Rootoutput0 * pointer;
	pointer=new CQMLGUI::Rootoutput0();
	return pointer->_CQML_element0;
}

 //printAttributeUpdatersHeaders() 
static void Update_E0_width(CQMLGUI::CQML_Context *);
static void Update_E0_height(CQMLGUI::CQML_Context *);
static void Update_E0_color_red(CQMLGUI::CQML_Context *);
static void Update_E0_color_green(CQMLGUI::CQML_Context *);
static void Update_E0_color_blue(CQMLGUI::CQML_Context *);
static void Update_E1_text(CQMLGUI::CQML_Context *);
static void Update_E1_x(CQMLGUI::CQML_Context *);
static void Update_E1_y(CQMLGUI::CQML_Context *);
static void Update_E2_text(CQMLGUI::CQML_Context *);
static void Update_E2_x(CQMLGUI::CQML_Context *);
static void Update_E2_y(CQMLGUI::CQML_Context *);
static void Update_E3_text(CQMLGUI::CQML_Context *);
static void Update_E3_x(CQMLGUI::CQML_Context *);
static void Update_E3_y(CQMLGUI::CQML_Context *);
static void Update_E4_x(CQMLGUI::CQML_Context *);
static void Update_E4_y(CQMLGUI::CQML_Context *);
static void Update_E4_visible(CQMLGUI::CQML_Context *);
static void Update_E4_enabled(CQMLGUI::CQML_Context *);
static void Update_E5_x(CQMLGUI::CQML_Context *);
static void Update_E5_y(CQMLGUI::CQML_Context *);
static void Update_E5_visible(CQMLGUI::CQML_Context *);
static void Update_E5_enabled(CQMLGUI::CQML_Context *);

 //printElementUpdatersHeaders() 
static void Update_E0(CQMLGUI::Element *self);
static void Update_E1(CQMLGUI::Element *self);
static void Update_E2(CQMLGUI::Element *self);
static void Update_E3(CQMLGUI::Element *self);
static void Update_E4(CQMLGUI::Element *self);
static void Update_E5(CQMLGUI::Element *self);

 //rootElementConstructor() 
CQMLGUI::Rootoutput0::Rootoutput0()
{
	CQMLGUI::Element*tmp=0;
	_CQML_element0 = CQMLGUI::acRectangle();
	_CQML_element0->root=(CQMLGUI::Element*)this;
	_CQML_element1 = CQMLGUI::acGUI_Rootoutput1();
	_CQML_element1->root=(CQMLGUI::Element*)this;
	_CQML_element2 = CQMLGUI::acGUI_Rootoutput1();
	_CQML_element2->root=(CQMLGUI::Element*)this;
	_CQML_element3 = CQMLGUI::acGUI_Rootoutput1();
	_CQML_element3->root=(CQMLGUI::Element*)this;
	_CQML_element4 = CQMLGUI::acGUI_Rootoutput2();
	_CQML_element4->root=(CQMLGUI::Element*)this;
	_CQML_element5 = CQMLGUI::acGUI_Rootoutput3();
	_CQML_element5->root=(CQMLGUI::Element*)this;
	mGUI_Element_InsertChild((CQMLGUI::Element*)_CQML_element0, (CQMLGUI::Element*)_CQML_element1);
	mGUI_Element_InsertChild((CQMLGUI::Element*)_CQML_element0, (CQMLGUI::Element*)_CQML_element2);
	mGUI_Element_InsertChild((CQMLGUI::Element*)_CQML_element0, (CQMLGUI::Element*)_CQML_element3);
	mGUI_Element_InsertChild((CQMLGUI::Element*)_CQML_element0, (CQMLGUI::Element*)_CQML_element4);
	mGUI_Element_InsertChild((CQMLGUI::Element*)_CQML_element0, (CQMLGUI::Element*)_CQML_element5);

 //printAttributeUpdaters() 
	((Element*)_CQML_element0)->width_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element0);
	((Element*)_CQML_element0)->width_Update  = Update_E0_width;
	((Element*)_CQML_element0)->height_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element0);
	((Element*)_CQML_element0)->height_Update  = Update_E0_height;
	((Rectangle*)_CQML_element0)->color.red_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_CQML_element0));
	((Rectangle*)_CQML_element0)->color.red_Update  = Update_E0_color_red;
	((Rectangle*)_CQML_element0)->color.green_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_CQML_element0));
	((Rectangle*)_CQML_element0)->color.green_Update  = Update_E0_color_green;
	((Rectangle*)_CQML_element0)->color.blue_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_CQML_element0));
	((Rectangle*)_CQML_element0)->color.blue_Update  = Update_E0_color_blue;
	((MouseAreaCustom3*)_CQML_element1)->text_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element1);
	((MouseAreaCustom3*)_CQML_element1)->text_Update  = Update_E1_text;
	((Element*)_CQML_element1)->x_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element1);
	((Element*)_CQML_element1)->x_Update  = Update_E1_x;
	((Element*)_CQML_element1)->y_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element1);
	((Element*)_CQML_element1)->y_Update  = Update_E1_y;
	((MouseAreaCustom3*)_CQML_element2)->text_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element2);
	((MouseAreaCustom3*)_CQML_element2)->text_Update  = Update_E2_text;
	((Element*)_CQML_element2)->x_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element2);
	((Element*)_CQML_element2)->x_Update  = Update_E2_x;
	((Element*)_CQML_element2)->y_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element2);
	((Element*)_CQML_element2)->y_Update  = Update_E2_y;
	((MouseAreaCustom3*)_CQML_element3)->text_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element3);
	((MouseAreaCustom3*)_CQML_element3)->text_Update  = Update_E3_text;
	((Element*)_CQML_element3)->x_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element3);
	((Element*)_CQML_element3)->x_Update  = Update_E3_x;
	((Element*)_CQML_element3)->y_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element3);
	((Element*)_CQML_element3)->y_Update  = Update_E3_y;
	((Element*)_CQML_element4)->x_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element4);
	((Element*)_CQML_element4)->x_Update  = Update_E4_x;
	((Element*)_CQML_element4)->y_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element4);
	((Element*)_CQML_element4)->y_Update  = Update_E4_y;
	((Element*)_CQML_element4)->visible_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element4);
	((Element*)_CQML_element4)->visible_Update  = Update_E4_visible;
	((Element*)_CQML_element4)->enabled_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element4);
	((Element*)_CQML_element4)->enabled_Update  = Update_E4_enabled;
	((Element*)_CQML_element5)->x_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element5);
	((Element*)_CQML_element5)->x_Update  = Update_E5_x;
	((Element*)_CQML_element5)->y_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element5);
	((Element*)_CQML_element5)->y_Update  = Update_E5_y;
	((Element*)_CQML_element5)->visible_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element5);
	((Element*)_CQML_element5)->visible_Update  = Update_E5_visible;
	((Element*)_CQML_element5)->enabled_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element5);
	((Element*)_CQML_element5)->enabled_Update  = Update_E5_enabled;
//printHandlerAssignment()
	_CQML_element1->CustomMouseClicked=_CQML_element1_MouseClicked;
	_CQML_element1->CustomMouseClicked_context=acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element1);
	_CQML_element2->CustomMouseClicked=_CQML_element2_MouseClicked;
	_CQML_element2->CustomMouseClicked_context=acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element2);
	_CQML_element3->CustomMouseClicked=_CQML_element3_MouseClicked;
	_CQML_element3->CustomMouseClicked_context=acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element3);
	_CQML_Update((CQMLGUI::Element *)_CQML_element0);

}

 //rootElementUpdater() 
static void _CQML_Update(CQMLGUI::Element *s)
{
	CQMLGUI::Rootoutput0 * self=(CQMLGUI::Rootoutput0 *)s;
	s->Update();

}

 //printAttributesBodies()
static void Update_E0_width(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->width= 1024 ;
}
static void Update_E0_height(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->height= 768 ;
}
static void Update_E0_color_red(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Rectangle*)context->self)->color.red= 1 ;
}
static void Update_E0_color_green(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Rectangle*)context->self)->color.green= 1 ;
}
static void Update_E0_color_blue(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Rectangle*)context->self)->color.blue= 1 ;
}
static void Update_E1_text(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom3*)context->self)->text= "Calculator" ;
}
static void Update_E1_x(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x=(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element0).width/ 2 -(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element1).width/ 2 ;
}
static void Update_E1_y(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y= 1 *(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element0).height/ 4 -(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element1).height/ 2 ;
}
static void Update_E2_text(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom3*)context->self)->text= "Match 2" ;
}
static void Update_E2_x(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x=(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element0).width/ 2 -(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element2).width/ 2 ;
}
static void Update_E2_y(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y= 2 *(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element0).height/ 4 -(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element2).height/ 2 ;
}
static void Update_E3_text(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom3*)context->self)->text= "Quit" ;
}
static void Update_E3_x(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x=(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element0).width/ 2 -(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element3).width/ 2 ;
}
static void Update_E3_y(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y= 3 *(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element0).height/ 4 -(*((CQMLGUI::Rootoutput0*)context->root)->_CQML_element3).height/ 2 ;
}
static void Update_E4_x(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x= 0 ;
}
static void Update_E4_y(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y= 0 ;
}
static void Update_E4_visible(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->visible= 0 ;
}
static void Update_E4_enabled(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->enabled= 0 ;
}
static void Update_E5_x(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x= 0 ;
}
static void Update_E5_y(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y= 0 ;
}
static void Update_E5_visible(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->visible= 0 ;
}
static void Update_E5_enabled(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->enabled= 0 ;
}

 //printElementUpdaters() 
using namespace CQMLGUI;
