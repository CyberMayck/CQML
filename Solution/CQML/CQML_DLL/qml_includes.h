#pragma once

#include "dll_export.h"

#include "cqml.h"
#include "gui.h"
#include "draw_iface.h"
#include "resource_manager.h"
#include "attribControl.h"
#include "context.h"
#include "variant.h"

#define member_size(type, member) sizeof(((type *)0)->member)
void PrintMeMyFriend(char * str);