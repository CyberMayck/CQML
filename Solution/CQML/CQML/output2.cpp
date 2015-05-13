#include "output2.h"

#include "qml_includes.h"
//classDeclaration
CQMLGUI::ElementCustom2* CQMLGUI::acElementCustom2()
{
	CQMLGUI::ElementCustom2 * pointer;
	pointer=new CQMLGUI::ElementCustom2();
	return pointer;
}
CQMLGUI::ElementCustom2::ElementCustom2()
{
	classID=13;
	first_Update=0;
	first_context=0;
	first=0;
	firstValue_Update=0;
	firstValue_context=0;
	score_Update=0;
	score_context=0;
	status_Update=0;
	status_context=0;
	winMsg_Update=0;
	winMsg_context=0;
	winMsg=0;
}
VariantRef CQMLGUI::ElementCustom2::Get(const char* s)
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
		return VariantRef((CQMLObject**)&first,&first_Update);
	case 1:
		return VariantRef(firstValue,&firstValue_Update);
	case 2:
		return VariantRef(score,&score_Update);
	case 3:
		return VariantRef(status,&status_Update);
	case 4:
		return VariantRef((CQMLObject**)&winMsg,&winMsg_Update);
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
static void _CQML_Update(CQMLGUI::Element *s);


//printHandlers()
using namespace CQMLGUI;
static void Update_E20_text(CQMLGUI::CQML_Context *);
static string Handler_E20_text(CQMLGUI::CQML_Context *);
static void Update_E20_text(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Text*)context->self)->text=Handler_E20_text(context);
}
static string Handler_E20_text(CQMLGUI::CQML_Context *context)
{
{ return INTTOSTR((*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).score);
}
}

 //rootElementAllocation() 
CQMLGUI::Rectangle* CQMLGUI::acGUI_Rootoutput2()
{
	CQMLGUI::Rootoutput2 * pointer;
	pointer=new CQMLGUI::Rootoutput2();
	return pointer->_CQML_element0;
}

 //printAttributeUpdatersHeaders() 
static void Update_E0_width(CQMLGUI::CQML_Context *);
static void Update_E0_height(CQMLGUI::CQML_Context *);
static void Update_E0_color_red(CQMLGUI::CQML_Context *);
static void Update_E0_color_green(CQMLGUI::CQML_Context *);
static void Update_E0_color_blue(CQMLGUI::CQML_Context *);
static void Update_E1_x(CQMLGUI::CQML_Context *);
static void Update_E1_y(CQMLGUI::CQML_Context *);
static void Update_E1_width(CQMLGUI::CQML_Context *);
static void Update_E1_height(CQMLGUI::CQML_Context *);
static void Update_E1_score(CQMLGUI::CQML_Context *);
static void Update_E1_status(CQMLGUI::CQML_Context *);
static void Update_E1_winMsg(CQMLGUI::CQML_Context *);
static void Update_E2_visible(CQMLGUI::CQML_Context *);
static void Update_E2_x(CQMLGUI::CQML_Context *);
static void Update_E2_y(CQMLGUI::CQML_Context *);
static void Update_E2_width(CQMLGUI::CQML_Context *);
static void Update_E2_height(CQMLGUI::CQML_Context *);
static void Update_E2_color_red(CQMLGUI::CQML_Context *);
static void Update_E2_color_green(CQMLGUI::CQML_Context *);
static void Update_E2_color_blue(CQMLGUI::CQML_Context *);
static void Update_E2_font_family(CQMLGUI::CQML_Context *);
static void Update_E2_font_size(CQMLGUI::CQML_Context *);
static void Update_E2_text(CQMLGUI::CQML_Context *);
static void Update_E3_matcher(CQMLGUI::CQML_Context *);
static void Update_E3_value(CQMLGUI::CQML_Context *);
static void Update_E3_x(CQMLGUI::CQML_Context *);
static void Update_E3_y(CQMLGUI::CQML_Context *);
static void Update_E4_matcher(CQMLGUI::CQML_Context *);
static void Update_E4_value(CQMLGUI::CQML_Context *);
static void Update_E4_x(CQMLGUI::CQML_Context *);
static void Update_E4_y(CQMLGUI::CQML_Context *);
static void Update_E5_matcher(CQMLGUI::CQML_Context *);
static void Update_E5_value(CQMLGUI::CQML_Context *);
static void Update_E5_x(CQMLGUI::CQML_Context *);
static void Update_E5_y(CQMLGUI::CQML_Context *);
static void Update_E6_matcher(CQMLGUI::CQML_Context *);
static void Update_E6_value(CQMLGUI::CQML_Context *);
static void Update_E6_x(CQMLGUI::CQML_Context *);
static void Update_E6_y(CQMLGUI::CQML_Context *);
static void Update_E7_matcher(CQMLGUI::CQML_Context *);
static void Update_E7_value(CQMLGUI::CQML_Context *);
static void Update_E7_x(CQMLGUI::CQML_Context *);
static void Update_E7_y(CQMLGUI::CQML_Context *);
static void Update_E8_matcher(CQMLGUI::CQML_Context *);
static void Update_E8_value(CQMLGUI::CQML_Context *);
static void Update_E8_x(CQMLGUI::CQML_Context *);
static void Update_E8_y(CQMLGUI::CQML_Context *);
static void Update_E9_matcher(CQMLGUI::CQML_Context *);
static void Update_E9_value(CQMLGUI::CQML_Context *);
static void Update_E9_x(CQMLGUI::CQML_Context *);
static void Update_E9_y(CQMLGUI::CQML_Context *);
static void Update_E10_matcher(CQMLGUI::CQML_Context *);
static void Update_E10_value(CQMLGUI::CQML_Context *);
static void Update_E10_x(CQMLGUI::CQML_Context *);
static void Update_E10_y(CQMLGUI::CQML_Context *);
static void Update_E11_matcher(CQMLGUI::CQML_Context *);
static void Update_E11_value(CQMLGUI::CQML_Context *);
static void Update_E11_x(CQMLGUI::CQML_Context *);
static void Update_E11_y(CQMLGUI::CQML_Context *);
static void Update_E12_matcher(CQMLGUI::CQML_Context *);
static void Update_E12_value(CQMLGUI::CQML_Context *);
static void Update_E12_x(CQMLGUI::CQML_Context *);
static void Update_E12_y(CQMLGUI::CQML_Context *);
static void Update_E13_matcher(CQMLGUI::CQML_Context *);
static void Update_E13_value(CQMLGUI::CQML_Context *);
static void Update_E13_x(CQMLGUI::CQML_Context *);
static void Update_E13_y(CQMLGUI::CQML_Context *);
static void Update_E14_matcher(CQMLGUI::CQML_Context *);
static void Update_E14_value(CQMLGUI::CQML_Context *);
static void Update_E14_x(CQMLGUI::CQML_Context *);
static void Update_E14_y(CQMLGUI::CQML_Context *);
static void Update_E15_matcher(CQMLGUI::CQML_Context *);
static void Update_E15_value(CQMLGUI::CQML_Context *);
static void Update_E15_x(CQMLGUI::CQML_Context *);
static void Update_E15_y(CQMLGUI::CQML_Context *);
static void Update_E16_matcher(CQMLGUI::CQML_Context *);
static void Update_E16_value(CQMLGUI::CQML_Context *);
static void Update_E16_x(CQMLGUI::CQML_Context *);
static void Update_E16_y(CQMLGUI::CQML_Context *);
static void Update_E17_matcher(CQMLGUI::CQML_Context *);
static void Update_E17_value(CQMLGUI::CQML_Context *);
static void Update_E17_x(CQMLGUI::CQML_Context *);
static void Update_E17_y(CQMLGUI::CQML_Context *);
static void Update_E18_matcher(CQMLGUI::CQML_Context *);
static void Update_E18_value(CQMLGUI::CQML_Context *);
static void Update_E18_x(CQMLGUI::CQML_Context *);
static void Update_E18_y(CQMLGUI::CQML_Context *);
static void Update_E19_img_src(CQMLGUI::CQML_Context *);
static void Update_E19_x(CQMLGUI::CQML_Context *);
static void Update_E19_y(CQMLGUI::CQML_Context *);
static void Update_E19_topBorder(CQMLGUI::CQML_Context *);
static void Update_E19_leftBorder(CQMLGUI::CQML_Context *);
static void Update_E19_rightBorder(CQMLGUI::CQML_Context *);
static void Update_E19_bottomBorder(CQMLGUI::CQML_Context *);
static void Update_E19_width(CQMLGUI::CQML_Context *);
static void Update_E19_height(CQMLGUI::CQML_Context *);
static void Update_E20_x(CQMLGUI::CQML_Context *);
static void Update_E20_width(CQMLGUI::CQML_Context *);
static void Update_E20_height(CQMLGUI::CQML_Context *);
static void Update_E20_y(CQMLGUI::CQML_Context *);
static void Update_E20_color_red(CQMLGUI::CQML_Context *);
static void Update_E20_color_green(CQMLGUI::CQML_Context *);
static void Update_E20_color_blue(CQMLGUI::CQML_Context *);
static void Update_E20_font_family(CQMLGUI::CQML_Context *);
static void Update_E20_font_size(CQMLGUI::CQML_Context *);

 //printElementUpdatersHeaders() 
static void Update_E0(CQMLGUI::Element *self);
static void Update_E1(CQMLGUI::Element *self);
static void Update_E2(CQMLGUI::Element *self);
static void Update_E3(CQMLGUI::Element *self);
static void Update_E4(CQMLGUI::Element *self);
static void Update_E5(CQMLGUI::Element *self);
static void Update_E6(CQMLGUI::Element *self);
static void Update_E7(CQMLGUI::Element *self);
static void Update_E8(CQMLGUI::Element *self);
static void Update_E9(CQMLGUI::Element *self);
static void Update_E10(CQMLGUI::Element *self);
static void Update_E11(CQMLGUI::Element *self);
static void Update_E12(CQMLGUI::Element *self);
static void Update_E13(CQMLGUI::Element *self);
static void Update_E14(CQMLGUI::Element *self);
static void Update_E15(CQMLGUI::Element *self);
static void Update_E16(CQMLGUI::Element *self);
static void Update_E17(CQMLGUI::Element *self);
static void Update_E18(CQMLGUI::Element *self);
static void Update_E19(CQMLGUI::Element *self);
static void Update_E20(CQMLGUI::Element *self);

 //rootElementConstructor() 
CQMLGUI::Rootoutput2::Rootoutput2()
{
	CQMLGUI::Element*tmp=0;
	_CQML_element0 = CQMLGUI::acRectangle();
	_CQML_element0->root=(CQMLGUI::Element*)this;
	_CQML_element1 = CQMLGUI::acElementCustom2();
	_CQML_element1->root=(CQMLGUI::Element*)this;
	_CQML_element2 = CQMLGUI::acText();
	_CQML_element2->root=(CQMLGUI::Element*)this;
	_CQML_element3 = CQMLGUI::acGUI_Rootoutput4();
	_CQML_element3->root=(CQMLGUI::Element*)this;
	_CQML_element4 = CQMLGUI::acGUI_Rootoutput4();
	_CQML_element4->root=(CQMLGUI::Element*)this;
	_CQML_element5 = CQMLGUI::acGUI_Rootoutput4();
	_CQML_element5->root=(CQMLGUI::Element*)this;
	_CQML_element6 = CQMLGUI::acGUI_Rootoutput4();
	_CQML_element6->root=(CQMLGUI::Element*)this;
	_CQML_element7 = CQMLGUI::acGUI_Rootoutput4();
	_CQML_element7->root=(CQMLGUI::Element*)this;
	_CQML_element8 = CQMLGUI::acGUI_Rootoutput4();
	_CQML_element8->root=(CQMLGUI::Element*)this;
	_CQML_element9 = CQMLGUI::acGUI_Rootoutput4();
	_CQML_element9->root=(CQMLGUI::Element*)this;
	_CQML_element10 = CQMLGUI::acGUI_Rootoutput4();
	_CQML_element10->root=(CQMLGUI::Element*)this;
	_CQML_element11 = CQMLGUI::acGUI_Rootoutput4();
	_CQML_element11->root=(CQMLGUI::Element*)this;
	_CQML_element12 = CQMLGUI::acGUI_Rootoutput4();
	_CQML_element12->root=(CQMLGUI::Element*)this;
	_CQML_element13 = CQMLGUI::acGUI_Rootoutput4();
	_CQML_element13->root=(CQMLGUI::Element*)this;
	_CQML_element14 = CQMLGUI::acGUI_Rootoutput4();
	_CQML_element14->root=(CQMLGUI::Element*)this;
	_CQML_element15 = CQMLGUI::acGUI_Rootoutput4();
	_CQML_element15->root=(CQMLGUI::Element*)this;
	_CQML_element16 = CQMLGUI::acGUI_Rootoutput4();
	_CQML_element16->root=(CQMLGUI::Element*)this;
	_CQML_element17 = CQMLGUI::acGUI_Rootoutput4();
	_CQML_element17->root=(CQMLGUI::Element*)this;
	_CQML_element18 = CQMLGUI::acGUI_Rootoutput4();
	_CQML_element18->root=(CQMLGUI::Element*)this;
	_CQML_element19 = CQMLGUI::acScaledImage();
	_CQML_element19->root=(CQMLGUI::Element*)this;
	_CQML_element20 = CQMLGUI::acText();
	_CQML_element20->root=(CQMLGUI::Element*)this;
	mGUI_Element_InsertChild((CQMLGUI::Element*)_CQML_element0, (CQMLGUI::Element*)_CQML_element1);
	mGUI_Element_InsertChild((CQMLGUI::Element*)_CQML_element0, (CQMLGUI::Element*)_CQML_element19);
	mGUI_Element_InsertChild((CQMLGUI::Element*)_CQML_element1, (CQMLGUI::Element*)_CQML_element2);
	mGUI_Element_InsertChild((CQMLGUI::Element*)_CQML_element1, (CQMLGUI::Element*)_CQML_element3);
	mGUI_Element_InsertChild((CQMLGUI::Element*)_CQML_element1, (CQMLGUI::Element*)_CQML_element4);
	mGUI_Element_InsertChild((CQMLGUI::Element*)_CQML_element1, (CQMLGUI::Element*)_CQML_element5);
	mGUI_Element_InsertChild((CQMLGUI::Element*)_CQML_element1, (CQMLGUI::Element*)_CQML_element6);
	mGUI_Element_InsertChild((CQMLGUI::Element*)_CQML_element1, (CQMLGUI::Element*)_CQML_element7);
	mGUI_Element_InsertChild((CQMLGUI::Element*)_CQML_element1, (CQMLGUI::Element*)_CQML_element8);
	mGUI_Element_InsertChild((CQMLGUI::Element*)_CQML_element1, (CQMLGUI::Element*)_CQML_element9);
	mGUI_Element_InsertChild((CQMLGUI::Element*)_CQML_element1, (CQMLGUI::Element*)_CQML_element10);
	mGUI_Element_InsertChild((CQMLGUI::Element*)_CQML_element1, (CQMLGUI::Element*)_CQML_element11);
	mGUI_Element_InsertChild((CQMLGUI::Element*)_CQML_element1, (CQMLGUI::Element*)_CQML_element12);
	mGUI_Element_InsertChild((CQMLGUI::Element*)_CQML_element1, (CQMLGUI::Element*)_CQML_element13);
	mGUI_Element_InsertChild((CQMLGUI::Element*)_CQML_element1, (CQMLGUI::Element*)_CQML_element14);
	mGUI_Element_InsertChild((CQMLGUI::Element*)_CQML_element1, (CQMLGUI::Element*)_CQML_element15);
	mGUI_Element_InsertChild((CQMLGUI::Element*)_CQML_element1, (CQMLGUI::Element*)_CQML_element16);
	mGUI_Element_InsertChild((CQMLGUI::Element*)_CQML_element1, (CQMLGUI::Element*)_CQML_element17);
	mGUI_Element_InsertChild((CQMLGUI::Element*)_CQML_element1, (CQMLGUI::Element*)_CQML_element18);
	mGUI_Element_InsertChild((CQMLGUI::Element*)_CQML_element19, (CQMLGUI::Element*)_CQML_element20);

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
	((Element*)_CQML_element1)->x_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element1);
	((Element*)_CQML_element1)->x_Update  = Update_E1_x;
	((Element*)_CQML_element1)->y_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element1);
	((Element*)_CQML_element1)->y_Update  = Update_E1_y;
	((Element*)_CQML_element1)->width_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element1);
	((Element*)_CQML_element1)->width_Update  = Update_E1_width;
	((Element*)_CQML_element1)->height_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element1);
	((Element*)_CQML_element1)->height_Update  = Update_E1_height;
	((ElementCustom2*)_CQML_element1)->score_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element1);
	((ElementCustom2*)_CQML_element1)->score_Update  = Update_E1_score;
	((ElementCustom2*)_CQML_element1)->status_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element1);
	((ElementCustom2*)_CQML_element1)->status_Update  = Update_E1_status;
	((ElementCustom2*)_CQML_element1)->winMsg_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element1);
	((ElementCustom2*)_CQML_element1)->winMsg_Update  = Update_E1_winMsg;
	((Element*)_CQML_element2)->visible_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element2);
	((Element*)_CQML_element2)->visible_Update  = Update_E2_visible;
	((Element*)_CQML_element2)->x_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element2);
	((Element*)_CQML_element2)->x_Update  = Update_E2_x;
	((Element*)_CQML_element2)->y_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element2);
	((Element*)_CQML_element2)->y_Update  = Update_E2_y;
	((Element*)_CQML_element2)->width_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element2);
	((Element*)_CQML_element2)->width_Update  = Update_E2_width;
	((Element*)_CQML_element2)->height_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element2);
	((Element*)_CQML_element2)->height_Update  = Update_E2_height;
	((Rectangle*)_CQML_element2)->color.red_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_CQML_element2));
	((Rectangle*)_CQML_element2)->color.red_Update  = Update_E2_color_red;
	((Rectangle*)_CQML_element2)->color.green_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_CQML_element2));
	((Rectangle*)_CQML_element2)->color.green_Update  = Update_E2_color_green;
	((Rectangle*)_CQML_element2)->color.blue_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_CQML_element2));
	((Rectangle*)_CQML_element2)->color.blue_Update  = Update_E2_color_blue;
	((Text*)_CQML_element2)->font.family_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_CQML_element2));
	((Text*)_CQML_element2)->font.family_Update  = Update_E2_font_family;
	((Text*)_CQML_element2)->font.size_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_CQML_element2));
	((Text*)_CQML_element2)->font.size_Update  = Update_E2_font_size;
	((Text*)_CQML_element2)->text_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element2);
	((Text*)_CQML_element2)->text_Update  = Update_E2_text;
	((MouseAreaCustom0Custom1*)_CQML_element3)->matcher_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element3);
	((MouseAreaCustom0Custom1*)_CQML_element3)->matcher_Update  = Update_E3_matcher;
	((MouseAreaCustom0Custom1*)_CQML_element3)->value_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element3);
	((MouseAreaCustom0Custom1*)_CQML_element3)->value_Update  = Update_E3_value;
	((Element*)_CQML_element3)->x_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element3);
	((Element*)_CQML_element3)->x_Update  = Update_E3_x;
	((Element*)_CQML_element3)->y_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element3);
	((Element*)_CQML_element3)->y_Update  = Update_E3_y;
	((MouseAreaCustom0Custom1*)_CQML_element4)->matcher_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element4);
	((MouseAreaCustom0Custom1*)_CQML_element4)->matcher_Update  = Update_E4_matcher;
	((MouseAreaCustom0Custom1*)_CQML_element4)->value_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element4);
	((MouseAreaCustom0Custom1*)_CQML_element4)->value_Update  = Update_E4_value;
	((Element*)_CQML_element4)->x_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element4);
	((Element*)_CQML_element4)->x_Update  = Update_E4_x;
	((Element*)_CQML_element4)->y_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element4);
	((Element*)_CQML_element4)->y_Update  = Update_E4_y;
	((MouseAreaCustom0Custom1*)_CQML_element5)->matcher_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element5);
	((MouseAreaCustom0Custom1*)_CQML_element5)->matcher_Update  = Update_E5_matcher;
	((MouseAreaCustom0Custom1*)_CQML_element5)->value_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element5);
	((MouseAreaCustom0Custom1*)_CQML_element5)->value_Update  = Update_E5_value;
	((Element*)_CQML_element5)->x_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element5);
	((Element*)_CQML_element5)->x_Update  = Update_E5_x;
	((Element*)_CQML_element5)->y_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element5);
	((Element*)_CQML_element5)->y_Update  = Update_E5_y;
	((MouseAreaCustom0Custom1*)_CQML_element6)->matcher_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element6);
	((MouseAreaCustom0Custom1*)_CQML_element6)->matcher_Update  = Update_E6_matcher;
	((MouseAreaCustom0Custom1*)_CQML_element6)->value_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element6);
	((MouseAreaCustom0Custom1*)_CQML_element6)->value_Update  = Update_E6_value;
	((Element*)_CQML_element6)->x_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element6);
	((Element*)_CQML_element6)->x_Update  = Update_E6_x;
	((Element*)_CQML_element6)->y_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element6);
	((Element*)_CQML_element6)->y_Update  = Update_E6_y;
	((MouseAreaCustom0Custom1*)_CQML_element7)->matcher_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element7);
	((MouseAreaCustom0Custom1*)_CQML_element7)->matcher_Update  = Update_E7_matcher;
	((MouseAreaCustom0Custom1*)_CQML_element7)->value_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element7);
	((MouseAreaCustom0Custom1*)_CQML_element7)->value_Update  = Update_E7_value;
	((Element*)_CQML_element7)->x_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element7);
	((Element*)_CQML_element7)->x_Update  = Update_E7_x;
	((Element*)_CQML_element7)->y_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element7);
	((Element*)_CQML_element7)->y_Update  = Update_E7_y;
	((MouseAreaCustom0Custom1*)_CQML_element8)->matcher_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element8);
	((MouseAreaCustom0Custom1*)_CQML_element8)->matcher_Update  = Update_E8_matcher;
	((MouseAreaCustom0Custom1*)_CQML_element8)->value_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element8);
	((MouseAreaCustom0Custom1*)_CQML_element8)->value_Update  = Update_E8_value;
	((Element*)_CQML_element8)->x_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element8);
	((Element*)_CQML_element8)->x_Update  = Update_E8_x;
	((Element*)_CQML_element8)->y_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element8);
	((Element*)_CQML_element8)->y_Update  = Update_E8_y;
	((MouseAreaCustom0Custom1*)_CQML_element9)->matcher_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element9);
	((MouseAreaCustom0Custom1*)_CQML_element9)->matcher_Update  = Update_E9_matcher;
	((MouseAreaCustom0Custom1*)_CQML_element9)->value_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element9);
	((MouseAreaCustom0Custom1*)_CQML_element9)->value_Update  = Update_E9_value;
	((Element*)_CQML_element9)->x_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element9);
	((Element*)_CQML_element9)->x_Update  = Update_E9_x;
	((Element*)_CQML_element9)->y_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element9);
	((Element*)_CQML_element9)->y_Update  = Update_E9_y;
	((MouseAreaCustom0Custom1*)_CQML_element10)->matcher_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element10);
	((MouseAreaCustom0Custom1*)_CQML_element10)->matcher_Update  = Update_E10_matcher;
	((MouseAreaCustom0Custom1*)_CQML_element10)->value_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element10);
	((MouseAreaCustom0Custom1*)_CQML_element10)->value_Update  = Update_E10_value;
	((Element*)_CQML_element10)->x_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element10);
	((Element*)_CQML_element10)->x_Update  = Update_E10_x;
	((Element*)_CQML_element10)->y_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element10);
	((Element*)_CQML_element10)->y_Update  = Update_E10_y;
	((MouseAreaCustom0Custom1*)_CQML_element11)->matcher_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element11);
	((MouseAreaCustom0Custom1*)_CQML_element11)->matcher_Update  = Update_E11_matcher;
	((MouseAreaCustom0Custom1*)_CQML_element11)->value_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element11);
	((MouseAreaCustom0Custom1*)_CQML_element11)->value_Update  = Update_E11_value;
	((Element*)_CQML_element11)->x_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element11);
	((Element*)_CQML_element11)->x_Update  = Update_E11_x;
	((Element*)_CQML_element11)->y_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element11);
	((Element*)_CQML_element11)->y_Update  = Update_E11_y;
	((MouseAreaCustom0Custom1*)_CQML_element12)->matcher_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element12);
	((MouseAreaCustom0Custom1*)_CQML_element12)->matcher_Update  = Update_E12_matcher;
	((MouseAreaCustom0Custom1*)_CQML_element12)->value_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element12);
	((MouseAreaCustom0Custom1*)_CQML_element12)->value_Update  = Update_E12_value;
	((Element*)_CQML_element12)->x_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element12);
	((Element*)_CQML_element12)->x_Update  = Update_E12_x;
	((Element*)_CQML_element12)->y_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element12);
	((Element*)_CQML_element12)->y_Update  = Update_E12_y;
	((MouseAreaCustom0Custom1*)_CQML_element13)->matcher_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element13);
	((MouseAreaCustom0Custom1*)_CQML_element13)->matcher_Update  = Update_E13_matcher;
	((MouseAreaCustom0Custom1*)_CQML_element13)->value_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element13);
	((MouseAreaCustom0Custom1*)_CQML_element13)->value_Update  = Update_E13_value;
	((Element*)_CQML_element13)->x_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element13);
	((Element*)_CQML_element13)->x_Update  = Update_E13_x;
	((Element*)_CQML_element13)->y_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element13);
	((Element*)_CQML_element13)->y_Update  = Update_E13_y;
	((MouseAreaCustom0Custom1*)_CQML_element14)->matcher_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element14);
	((MouseAreaCustom0Custom1*)_CQML_element14)->matcher_Update  = Update_E14_matcher;
	((MouseAreaCustom0Custom1*)_CQML_element14)->value_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element14);
	((MouseAreaCustom0Custom1*)_CQML_element14)->value_Update  = Update_E14_value;
	((Element*)_CQML_element14)->x_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element14);
	((Element*)_CQML_element14)->x_Update  = Update_E14_x;
	((Element*)_CQML_element14)->y_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element14);
	((Element*)_CQML_element14)->y_Update  = Update_E14_y;
	((MouseAreaCustom0Custom1*)_CQML_element15)->matcher_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element15);
	((MouseAreaCustom0Custom1*)_CQML_element15)->matcher_Update  = Update_E15_matcher;
	((MouseAreaCustom0Custom1*)_CQML_element15)->value_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element15);
	((MouseAreaCustom0Custom1*)_CQML_element15)->value_Update  = Update_E15_value;
	((Element*)_CQML_element15)->x_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element15);
	((Element*)_CQML_element15)->x_Update  = Update_E15_x;
	((Element*)_CQML_element15)->y_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element15);
	((Element*)_CQML_element15)->y_Update  = Update_E15_y;
	((MouseAreaCustom0Custom1*)_CQML_element16)->matcher_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element16);
	((MouseAreaCustom0Custom1*)_CQML_element16)->matcher_Update  = Update_E16_matcher;
	((MouseAreaCustom0Custom1*)_CQML_element16)->value_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element16);
	((MouseAreaCustom0Custom1*)_CQML_element16)->value_Update  = Update_E16_value;
	((Element*)_CQML_element16)->x_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element16);
	((Element*)_CQML_element16)->x_Update  = Update_E16_x;
	((Element*)_CQML_element16)->y_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element16);
	((Element*)_CQML_element16)->y_Update  = Update_E16_y;
	((MouseAreaCustom0Custom1*)_CQML_element17)->matcher_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element17);
	((MouseAreaCustom0Custom1*)_CQML_element17)->matcher_Update  = Update_E17_matcher;
	((MouseAreaCustom0Custom1*)_CQML_element17)->value_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element17);
	((MouseAreaCustom0Custom1*)_CQML_element17)->value_Update  = Update_E17_value;
	((Element*)_CQML_element17)->x_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element17);
	((Element*)_CQML_element17)->x_Update  = Update_E17_x;
	((Element*)_CQML_element17)->y_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element17);
	((Element*)_CQML_element17)->y_Update  = Update_E17_y;
	((MouseAreaCustom0Custom1*)_CQML_element18)->matcher_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element18);
	((MouseAreaCustom0Custom1*)_CQML_element18)->matcher_Update  = Update_E18_matcher;
	((MouseAreaCustom0Custom1*)_CQML_element18)->value_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element18);
	((MouseAreaCustom0Custom1*)_CQML_element18)->value_Update  = Update_E18_value;
	((Element*)_CQML_element18)->x_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element18);
	((Element*)_CQML_element18)->x_Update  = Update_E18_x;
	((Element*)_CQML_element18)->y_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element18);
	((Element*)_CQML_element18)->y_Update  = Update_E18_y;
	((Image*)_CQML_element19)->img.src_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_CQML_element19));
	((Image*)_CQML_element19)->img.src_Update  = Update_E19_img_src;
	((Element*)_CQML_element19)->x_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element19);
	((Element*)_CQML_element19)->x_Update  = Update_E19_x;
	((Element*)_CQML_element19)->y_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element19);
	((Element*)_CQML_element19)->y_Update  = Update_E19_y;
	((ScaledImage*)_CQML_element19)->topBorder_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element19);
	((ScaledImage*)_CQML_element19)->topBorder_Update  = Update_E19_topBorder;
	((ScaledImage*)_CQML_element19)->leftBorder_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element19);
	((ScaledImage*)_CQML_element19)->leftBorder_Update  = Update_E19_leftBorder;
	((ScaledImage*)_CQML_element19)->rightBorder_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element19);
	((ScaledImage*)_CQML_element19)->rightBorder_Update  = Update_E19_rightBorder;
	((ScaledImage*)_CQML_element19)->bottomBorder_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element19);
	((ScaledImage*)_CQML_element19)->bottomBorder_Update  = Update_E19_bottomBorder;
	((Element*)_CQML_element19)->width_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element19);
	((Element*)_CQML_element19)->width_Update  = Update_E19_width;
	((Element*)_CQML_element19)->height_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element19);
	((Element*)_CQML_element19)->height_Update  = Update_E19_height;
	((Element*)_CQML_element20)->x_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element20);
	((Element*)_CQML_element20)->x_Update  = Update_E20_x;
	((Element*)_CQML_element20)->width_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element20);
	((Element*)_CQML_element20)->width_Update  = Update_E20_width;
	((Element*)_CQML_element20)->height_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element20);
	((Element*)_CQML_element20)->height_Update  = Update_E20_height;
	((Element*)_CQML_element20)->y_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element20);
	((Element*)_CQML_element20)->y_Update  = Update_E20_y;
	((Rectangle*)_CQML_element20)->color.red_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_CQML_element20));
	((Rectangle*)_CQML_element20)->color.red_Update  = Update_E20_color_red;
	((Rectangle*)_CQML_element20)->color.green_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_CQML_element20));
	((Rectangle*)_CQML_element20)->color.green_Update  = Update_E20_color_green;
	((Rectangle*)_CQML_element20)->color.blue_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_CQML_element20));
	((Rectangle*)_CQML_element20)->color.blue_Update  = Update_E20_color_blue;
	((Text*)_CQML_element20)->font.family_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_CQML_element20));
	((Text*)_CQML_element20)->font.family_Update  = Update_E20_font_family;
	((Text*)_CQML_element20)->font.size_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)(_CQML_element20));
	((Text*)_CQML_element20)->font.size_Update  = Update_E20_font_size;
//printHandlerAssignment()
	((Text*)_CQML_element20)->text_context  = acCQML_Context((CQMLGUI::Component*)this,(CQMLGUI::Element*)_CQML_element20);
	((Text*)_CQML_element20)->text_Update  = Update_E20_text;

 //printElementUpdaterAssignments() 
	_CQML_Update((CQMLGUI::Element *)_CQML_element0);

}

 //rootElementUpdater() 
static void _CQML_Update(CQMLGUI::Element *s)
{
	CQMLGUI::Rootoutput2 * self=(CQMLGUI::Rootoutput2 *)s;
	s->Update();

}

 //printAttributesBodies()
static void Update_E20_font_size(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Text*)context->self)->font.size=(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element19).height/ 2 ;
}
static void Update_E20_font_family(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Text*)context->self)->font.family= "Tahoma" ;
}
static void Update_E20_color_blue(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Rectangle*)context->self)->color.blue= 0 ;
}
static void Update_E20_color_green(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Rectangle*)context->self)->color.green= 0 ;
}
static void Update_E20_color_red(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Rectangle*)context->self)->color.red= 0 ;
}
static void Update_E20_y(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y= 10 ;
}
static void Update_E20_height(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->height=(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element19).height;
}
static void Update_E20_width(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->width=(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element19).width;
}
static void Update_E20_x(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x= 40 ;
}
static void Update_E19_height(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->height= 150 ;
}
static void Update_E19_width(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->width= 3 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element0).width/ 5 + 150 ;
}
static void Update_E19_bottomBorder(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::ScaledImage*)context->self)->bottomBorder= 60 ;
}
static void Update_E19_rightBorder(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::ScaledImage*)context->self)->rightBorder= 60 ;
}
static void Update_E19_leftBorder(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::ScaledImage*)context->self)->leftBorder= 60 ;
}
static void Update_E19_topBorder(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::ScaledImage*)context->self)->topBorder= 60 ;
}
static void Update_E19_y(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y= 0 ;
}
static void Update_E19_x(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x=(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element0).width/ 5 - 75 ;
}
static void Update_E19_img_src(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Image*)context->self)->img.src= "pics/button_square.png" ;
}
static void Update_E18_y(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y= 3 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).height/ 4 ;
}
static void Update_E18_x(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x= 3 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).width/ 4 ;
}
static void Update_E18_value(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->value= 1 ;
}
static void Update_E18_matcher(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->matcher=(((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1);
}
static void Update_E17_y(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y= 3 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).height/ 4 ;
}
static void Update_E17_x(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x= 2 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).width/ 4 ;
}
static void Update_E17_value(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->value= 0 ;
}
static void Update_E17_matcher(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->matcher=(((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1);
}
static void Update_E16_y(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y= 3 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).height/ 4 ;
}
static void Update_E16_x(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x= 1 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).width/ 4 ;
}
static void Update_E16_value(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->value= 1 ;
}
static void Update_E16_matcher(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->matcher=(((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1);
}
static void Update_E15_y(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y= 3 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).height/ 4 ;
}
static void Update_E15_x(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x= 0 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).width/ 4 ;
}
static void Update_E15_value(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->value= 0 ;
}
static void Update_E15_matcher(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->matcher=(((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1);
}
static void Update_E14_y(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y= 2 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).height/ 4 ;
}
static void Update_E14_x(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x= 3 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).width/ 4 ;
}
static void Update_E14_value(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->value= 0 ;
}
static void Update_E14_matcher(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->matcher=(((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1);
}
static void Update_E13_y(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y= 2 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).height/ 4 ;
}
static void Update_E13_x(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x= 2 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).width/ 4 ;
}
static void Update_E13_value(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->value= 2 ;
}
static void Update_E13_matcher(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->matcher=(((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1);
}
static void Update_E12_y(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y= 2 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).height/ 4 ;
}
static void Update_E12_x(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x= 1 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).width/ 4 ;
}
static void Update_E12_value(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->value= 2 ;
}
static void Update_E12_matcher(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->matcher=(((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1);
}
static void Update_E11_y(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y= 2 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).height/ 4 ;
}
static void Update_E11_x(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x= 0 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).width/ 4 ;
}
static void Update_E11_value(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->value= 0 ;
}
static void Update_E11_matcher(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->matcher=(((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1);
}
static void Update_E10_y(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y= 1 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).height/ 4 ;
}
static void Update_E10_x(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x= 3 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).width/ 4 ;
}
static void Update_E10_value(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->value= 0 ;
}
static void Update_E10_matcher(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->matcher=(((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1);
}
static void Update_E9_y(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y= 1 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).height/ 4 ;
}
static void Update_E9_x(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x= 2 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).width/ 4 ;
}
static void Update_E9_value(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->value= 2 ;
}
static void Update_E9_matcher(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->matcher=(((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1);
}
static void Update_E8_y(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y= 1 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).height/ 4 ;
}
static void Update_E8_x(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x= 1 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).width/ 4 ;
}
static void Update_E8_value(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->value= 1 ;
}
static void Update_E8_matcher(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->matcher=(((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1);
}
static void Update_E7_y(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y= 1 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).height/ 4 ;
}
static void Update_E7_x(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x= 0 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).width/ 4 ;
}
static void Update_E7_value(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->value= 3 ;
}
static void Update_E7_matcher(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->matcher=(((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1);
}
static void Update_E6_y(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y= 0 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).height/ 4 ;
}
static void Update_E6_x(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x= 3 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).width/ 4 ;
}
static void Update_E6_value(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->value= 3 ;
}
static void Update_E6_matcher(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->matcher=(((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1);
}
static void Update_E5_y(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y= 0 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).height/ 4 ;
}
static void Update_E5_x(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x= 2 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).width/ 4 ;
}
static void Update_E5_value(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->value= 1 ;
}
static void Update_E5_matcher(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->matcher=(((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1);
}
static void Update_E4_y(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y= 0 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).height/ 4 ;
}
static void Update_E4_x(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x= 1 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).width/ 4 ;
}
static void Update_E4_value(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->value= 2 ;
}
static void Update_E4_matcher(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->matcher=(((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1);
}
static void Update_E3_y(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y= 0 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).height/ 4 ;
}
static void Update_E3_x(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x= 0 *(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).width/ 4 ;
}
static void Update_E3_value(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->value= 0 ;
}
static void Update_E3_matcher(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::MouseAreaCustom0Custom1*)context->self)->matcher=(((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1);
}
static void Update_E2_text(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Text*)context->self)->text= "You Win!!!" ;
}
static void Update_E2_font_size(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Text*)context->self)->font.size=(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).height/ 2 ;
}
static void Update_E2_font_family(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Text*)context->self)->font.family= "Tahoma" ;
}
static void Update_E2_color_blue(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Rectangle*)context->self)->color.blue= 0 ;
}
static void Update_E2_color_green(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Rectangle*)context->self)->color.green= 0 ;
}
static void Update_E2_color_red(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Rectangle*)context->self)->color.red= 0 ;
}
static void Update_E2_height(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->height=(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).height;
}
static void Update_E2_width(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->width=(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).width;
}
static void Update_E2_y(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y=(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).height/ 2 ;
}
static void Update_E2_x(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x=-(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element1).width/ 2 ;
}
static void Update_E2_visible(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->visible=false;
}
static void Update_E1_winMsg(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::ElementCustom2*)context->self)->winMsg=(((CQMLGUI::Rootoutput2*)context->root)->_CQML_element2);
}
static void Update_E1_status(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::ElementCustom2*)context->self)->status= 0 ;
}
static void Update_E1_score(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::ElementCustom2*)context->self)->score= 0 ;
}
static void Update_E1_y(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->y= 150 ;
}
static void Update_E1_x(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->x=(*((CQMLGUI::Rootoutput2*)context->root)->_CQML_element0).width/ 2 - 200 ;
}
static void Update_E0_color_blue(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Rectangle*)context->self)->color.blue= 1 ;
}
static void Update_E0_color_green(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Rectangle*)context->self)->color.green= 1 ;
}
static void Update_E0_color_red(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Rectangle*)context->self)->color.red= 1 ;
}
static void Update_E1_height(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->height= 400 ;
}
static void Update_E1_width(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->width= 400 ;
}
static void Update_E0_height(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->height= 768 ;
}
static void Update_E0_width(CQMLGUI::CQML_Context *context)
{
	((CQMLGUI::Element*)context->self)->width= 1024 ;
}

 //printElementUpdaters() 
using namespace CQMLGUI;
void ElementCustom2::Update()
{
	if(!enabled)
		return;
	if(first_Update)first_Update(first_context);
	if(firstValue_Update)firstValue_Update(firstValue_context);
	if(score_Update)score_Update(score_context);
	if(status_Update)status_Update(status_context);
	if(winMsg_Update)winMsg_Update(winMsg_context);
	 Element::Update();
}
