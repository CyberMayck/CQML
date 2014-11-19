#pragma once

#include<stdio.h>
#include<stdlib.h>
#include"draw_iface.h"
#include"input.h"
#include "struct_definition_macros.h"

typedef struct GUI_Group GUI_Group;
//typedef struct GUI_Element GUI_Element;
//typedef struct GUI_Rectangle GUI_Rectangle;
//typedef struct GUI_Color GUI_Color;
void mGUI_Element_Draw(GUI_Element *self);
void mGUI_Element_Update(GUI_Element *self);
void mGUI_Rectangle_Draw(GUI_Element *self);

int mGUI_Element_MouseMoved(GUI_Element *self,int x, int y, int relx, int rely);
int mGUI_Element_MouseReleased(GUI_Element *self,int x, int y, int button);
int mGUI_Element_MousePressed(GUI_Element *self,int x, int y, int button);
int mGUI_Element_MouseScrolled(GUI_Element *self,int x, int y, int relx, int rely);

int mGUI_Rectangle_MouseMoved(GUI_Element *self,int x, int y, int relx, int rely);
int mGUI_Rectangle_MouseReleased(GUI_Element *self,int x, int y, int button);
int mGUI_Rectangle_MousePressed(GUI_Element *self,int x, int y, int button);
int mGUI_Rectangle_MouseScrolled(GUI_Element *self,int x, int y, int relx, int rely);


#define MakeNewThing(type, parent)	(mGUI_Element_InsertChild((GUI_Element*)&parent,(GUI_Element*)ac##type()))

struct GUI_Group {
	GUI_Element * root;
	int memberCount;
	GUI_Element ** members;
};



//#define NOPE
#ifdef NOPE
struct GUI_Element {
	int classID;
	GUI_Element * root;
	//GUI_Group * localGroup;

	GUI_Element * parent;
	GUI_Element ** children;
	int childrenCount;
	
	int flags;
	int x;
	int y;
	int width;
	int height;

	void (*Draw)(GUI_Element *self);
	void (*Update)(GUI_Element *self);

	int (*MousePressed)(GUI_Element *self,int x, int y, int button);
	int (*MouseReleased)(GUI_Element *self,int x, int y, int button);
	int (*MouseMoved)(GUI_Element *self,int x, int y, int relx, int rely);
	int (*MouseScrolled)(GUI_Element *self,int x, int y, int relx, int rely);

	//int (*MousePressed)(GUI_Element *self,QMLEvent Event);
	//int (*MouseReleased)(GUI_Element *self,QMLEvent Event);
	//int (*MouseMoved)(GUI_Element *self,QMLEvent Event);
	//int (*MouseScrolled)(GUI_Element *self,QMLEvent Event);

	
	/*void (*CustomMouseClicked)(GUI_Element *self,int x, int y, int button);
	void (*CustomMousePressed)(GUI_Element *self,int x, int y, int button);
	void (*CustomMouseReleased)(GUI_Element *self,int x, int y, int button);
	void (*CustomMouseMoved)(GUI_Element *self,int x, int y, int relx, int rely);
	void (*CustomMouseEntered)(GUI_Element *self,int x, int y, int relx, int rely);
	void (*CustomMouseExited)(GUI_Element *self,int x, int y, int relx, int rely);
	void (*CustomMouseScrolled)(GUI_Element *self,int x, int y, int relx, int rely);*/
	void (*CustomMouseClicked)(GUI_Element *self,QMLEvent Event);
	void (*CustomMousePressed)(GUI_Element *self,QMLEvent Event);
	void (*CustomMouseReleased)(GUI_Element *self,QMLEvent Event);
	void (*CustomMouseMoved)(GUI_Element *self,QMLEvent Event);
	void (*CustomMouseEntered)(GUI_Element *self,QMLEvent Event);
	void (*CustomMouseExited)(GUI_Element *self,QMLEvent Event);
	void (*CustomMouseScrolled)(GUI_Element *self,QMLEvent Event);
};


struct GUI_Color{
	float red;
	float green;
	float blue;
	//float a;
};

struct GUI_Rectangle {
	GUI_Element base;
	int id;
	GUI_Color color;
};

typedef struct GUI_Anchor GUI_Anchor;

struct GUI_Anchor {
	GUI_Element * top;
	GUI_Element * left;
	GUI_Element * right;
	GUI_Element * bottom;
};

#endif


void InitGUI();

GUI_Element cGUI_Element();
GUI_Element* acGUI_Element();
GUI_Rectangle cGUI_Rectangle();

GUI_Rectangle* acGUI_Rectangle();
int mGUI_Element_Top(GUI_Element *self);
int mGUI_Element_Left(GUI_Element *self);
void mGUI_Element_InsertChild(GUI_Element *self,GUI_Element *child);

int mGUI_Element_Clicked(GUI_Element *self, int x, int y, int button);
int mGUI_Rectangle_Clicked(GUI_Element *self, int x, int y, int button);


