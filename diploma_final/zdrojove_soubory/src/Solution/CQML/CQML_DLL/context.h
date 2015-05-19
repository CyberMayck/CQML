#pragma once

#include "dll_export.h"



	struct Component;
	struct Element;
	
struct CQML_Context
{
	Component * root;
	Element * self;
};
