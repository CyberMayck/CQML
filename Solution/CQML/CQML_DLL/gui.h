#pragma once


#include "dll_export.h"

#include<stdio.h>
#include<stdlib.h>
#include"draw_iface.h"
#include"input.h"

#include "CQMLObject.h"
//#include "..\CQML\struct_definition_macros.h"
#include "struct_definition_macros.h"



namespace CQMLGUI
{

#define MakeNewThing(type, parent)	(mGUI_Element_InsertChild((CQMLGUI::Element*)&parent,(CQMLGUI::Element*)ac##type()))

struct Component
{
	//CQMLGUI::Element * root;
	//int memberCount;
	//CQMLGUI::Element ** members;
};

	CQML_API void PreUpdate();
	CQML_API void PostUpdate();
	CQML_API void PreDraw();
	CQML_API void PostDraw();

	CQML_API void GetQMLWindow(int &w,int &h);

	CQML_API void InitGUI();

	CQML_API CQMLGUI::Element* acElement();

	CQML_API CQMLGUI::Rectangle* acRectangle();
	CQML_API CQMLGUI::Text* acText();
	CQML_API CQMLGUI::TextInput* acTextInput();
	CQML_API CQMLGUI::MouseArea* acMouseArea();
	CQML_API CQMLGUI::Image* acImage();
	CQML_API CQMLGUI::ScaledImage* acScaledImage();


	CQML_API void mGUI_Element_InsertChild(CQMLGUI::Element *self,CQMLGUI::Element *child);

	CQML_API int mGUI_Element_Clicked(CQMLGUI::Element *self, int x, int y, int button);
	CQML_API int mGUI_Rectangle_Clicked(CQMLGUI::Element *self, int x, int y, int button);

	

CQML_API QML_Context * acQML_Context(Component* g , Element* e);


};



