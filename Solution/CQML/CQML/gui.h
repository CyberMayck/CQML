#pragma once

#include<stdio.h>
#include<stdlib.h>
#include"draw_iface.h"
#include"input.h"

#include "CQMLObject.h"

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




	void InitGUI();

	CQMLGUI::Element* acGUI_Element();

	CQMLGUI::Rectangle* acGUI_Rectangle();


	void mGUI_Element_InsertChild(CQMLGUI::Element *self,CQMLGUI::Element *child);

	int mGUI_Element_Clicked(CQMLGUI::Element *self, int x, int y, int button);
	int mGUI_Rectangle_Clicked(CQMLGUI::Element *self, int x, int y, int button);

	

QML_Context * acQML_Context(Component* g , Element* e);


};



