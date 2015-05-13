#include "dll_export.h"

#include "cqml.h"
#include "gui.h"
#include "input.h"
#include "draw_iface.h"
#include "attribControl.h"

using namespace CQMLGUI;

void InitGUI();
void _CQML_Init()
{
	CQMLInitInput();
	CQMLGUI::InitGUI();
	//CQMLInitHashes();
}

 DrawIFace * drawer;

void SetDrawIFace(DrawIFace * dr)
{
	drawer=dr;
}