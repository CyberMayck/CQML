#pragma once
#include <stdlib.h>

typedef struct QML_Context QML_Context;
typedef struct GUI_Group GUI_Group;
typedef struct GUI_Element GUI_Element;
struct QML_Context
{
	GUI_Group * root;
	GUI_Element * self;
};

QML_Context * acQML_Context(GUI_Group* g , GUI_Element* e);
