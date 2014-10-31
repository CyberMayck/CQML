#include "output0outer.h"

#include "qml_includes.h"
void _QML_Update();
GUI_Element* root;

void _QML_Init()
{
	root = (GUI_Element*) acGUI_Rootoutput0();
	_QML_Update();
}

void _QML_Update()
{
	root->Update(root);
}
