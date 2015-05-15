#include "dll_export.h"

#include "cqml.h"
#include "gui.h"
#include "input.h"
#include "draw_iface.h"
#include "attribControl.h"

namespace CQMLGUI
{
	void MainDraw();
	void MainUpdate();
}

using namespace CQMLGUI;


/**
 * Initializes CQML
 * 
 */
void _CQML_Init()
{
	CQMLInitInput();
	InitGUI();
}

 DrawIFace * drawer;
 
/**
 * Sets drawing interface
 * 
 *
 * @param interface pointer
 */
void SetDrawIFace(DrawIFace * dr)
{
	drawer=dr;
}

/**
 * Draws GUI
 * 
 */
void _CQML_Draw()
{
	PreDraw();
	MainDraw();
	PostDraw();
}

/**
 * Updates GUI
 * 
 */
void _CQML_Update()
{
	PreUpdate();
	MainUpdate();
	PostUpdate();
}