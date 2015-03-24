#include "cqml.h"
#include "gui.h"
#include "input.h"
#include "draw_iface.h"
#include "attribControl.h"


void InitGUI();
void InitQML()
{
	QMLInitInput();
	CQMLGUI::InitGUI();
	QMLInitHashes();
}

 DrawIFace * drawer;

void SetDrawIFace(DrawIFace * dr)
{
	drawer=dr;
}