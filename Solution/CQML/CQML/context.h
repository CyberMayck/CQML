#pragma once
typedef struct QML_Context QML_Context;
#include "gui.h"

QML_Context * acQML_Context(GUI_Group*, GUI_Element*);

struct QML_Context
{
	GUI_Group * root;
	GUI_Element * self;
};