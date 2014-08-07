#include "custom_classes.h"

void _QML_Update();
GUI_Element* root;
GUI_Element* _QML_element0;
GUI_Element* _QML_element1;
GUI_Element* _QML_element2;
GUI_Element* _QML_element3;
GUI_Element* _QML_element4;
GUI_Element* _QML_element5;
GUI_Element* _QML_element6;

void _QML_element3_MouseClicked(GUI_Element * self, QMLEvent Event)
{
{(*_QML_element1).x=0;(*(GUI_Rectangle*)_QML_element3).color.red=0;}
}
void _QML_Init()
{
_QML_element0 = (GUI_Element*)acGUI_Rectangle();
_QML_element1 = (GUI_Element*)acGUI_Rectangle();
_QML_element2 = (GUI_Element*)acGUI_Rectangle();
_QML_element3 = (GUI_Element*)acGUI_Rectangle();
_QML_element4 = (GUI_Element*)acGUI_Rectangle();
_QML_element5 = (GUI_Element*)acGUI_Rectangle();
_QML_element6 = (GUI_Element*)acGUI_Rectangle();
mGUI_Element_InsertChild((GUI_Element*)_QML_element0, (GUI_Element*)_QML_element1);
mGUI_Element_InsertChild((GUI_Element*)_QML_element0, (GUI_Element*)_QML_element4);
mGUI_Element_InsertChild((GUI_Element*)_QML_element1, (GUI_Element*)_QML_element2);
mGUI_Element_InsertChild((GUI_Element*)_QML_element1, (GUI_Element*)_QML_element3);
mGUI_Element_InsertChild((GUI_Element*)_QML_element4, (GUI_Element*)_QML_element5);
mGUI_Element_InsertChild((GUI_Element*)_QML_element5, (GUI_Element*)_QML_element6);
root = (GUI_Element*) acGUI_Element();
mGUI_Element_InsertChild((GUI_Element*)root, (GUI_Element*)_QML_element0);
_QML_element3->CustomMouseClicked=_QML_element3_MouseClicked;
_QML_Update();
}
void _QML_Update()
{
_QML_element6->y=5;
_QML_element6->x=5;
_QML_element5->y=5;
_QML_element5->x=5;
_QML_element4->y=5;
_QML_element3->x=5;
_QML_element2->y=5;
_QML_element2->x=5;
_QML_element1->y=5;
_QML_element1->x=5;
_QML_element0->width=500;
_QML_element4->width=(*_QML_element0).width/2-10;
_QML_element5->width=(*_QML_element4).width/2;
_QML_element6->width=(*_QML_element5).width/2;
_QML_element1->width=(*_QML_element0).width/2-10;
_QML_element4->x=(*_QML_element1).width+5;
_QML_element3->width=(*_QML_element1).width-10;
_QML_element2->width=(*_QML_element1).width-10;
_QML_element0->height=(*_QML_element0).width;
_QML_element4->height=(*_QML_element0).height-10;
_QML_element5->height=(*_QML_element4).height/2;
_QML_element6->height=(*_QML_element5).height/2;
_QML_element1->height=(*_QML_element0).height-10;
_QML_element3->height=(*_QML_element1).height/2-10;
_QML_element3->y=(*_QML_element1).height/2+5;
_QML_element2->height=(*_QML_element1).height/2-10;
_QML_element0->y=0;
_QML_element0->x=0;

}
