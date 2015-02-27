#include "cqml.h"
#include "gui.h"
#include "input.h"
#include "draw_iface.h"
#include "attribControl.h"


void InitQML()
{
	QMLInitInput();
	InitGUI();
	QMLInitHashes();
}

 DrawIFace * drawer;

void SetDrawIFace(DrawIFace * dr)
{
	drawer=dr;
}