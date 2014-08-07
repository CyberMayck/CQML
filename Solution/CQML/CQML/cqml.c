#include "cqml.h"
#include "gui.h"
#include "input.h"
#include "draw_iface.h"


void InitQML()
{
	QMLInitInput();
	InitGUI();
}

 DrawIFace * drawer;

void SetDrawIFace(DrawIFace * dr)
{
	drawer=dr;
}