#pragma once

#include "dll_export.h"



	struct Component;
	struct Element;
	
struct QML_Context
{
	Component * root;
	Element * self;
};
