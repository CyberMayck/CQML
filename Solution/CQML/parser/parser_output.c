#include "custom_classes.h"
#include "qml_includes.h"

void _QML_Update();
GUI_Element* root;
GUI_Element* _QML_element0;
GUI_Element* _QML_element1;
GUI_Element* _QML_element2;
GUI_Element* _QML_element3;
GUI_Element* _QML_element4;
GUI_Element* _QML_element5;
GUI_Element* _QML_element6;

void _QML_element6_MouseReleased(GUI_Element * self, QMLEvent Event)
{
{(*(GUI_Rectangle*)_QML_element6).color.green=1;}
}
void _QML_element6_MousePressed(GUI_Element * self, QMLEvent Event)
{
{(*(GUI_Rectangle*)_QML_element6).color.green=0;}
}
void _QML_element4_MouseReleased(GUI_Element * self, QMLEvent Event)
{
{(*(GUI_Rectangle*)_QML_element4).color.red=1;}
}
void _QML_element4_MousePressed(GUI_Element * self, QMLEvent Event)
{
{(*(GUI_Rectangle*)_QML_element4).color.red=0;}
}
void _QML_element3_MouseReleased(GUI_Element * self, QMLEvent Event)
{
{(*(GUI_Rectangle*)_QML_element3).color.red=1;}
}
void _QML_element3_MousePressed(GUI_Element * self, QMLEvent Event)
{
{(*(GUI_Rectangle*)_QML_element3).color.red=0;}
}
void _QML_element2_MouseReleased(GUI_Element * self, QMLEvent Event)
{
{(*(GUI_Rectangle*)_QML_element2).color.red=1;}
}
void _QML_element2_MousePressed(GUI_Element * self, QMLEvent Event)
{
{(*(GUI_Rectangle*)_QML_element2).color.red=0;}
}
void _QML_element2_MouseExited(GUI_Element * self, QMLEvent Event)
{
{(*(GUI_Rectangle*)_QML_element2).color.green=1;(*(GUI_Rectangle*)_QML_element2).color.blue=1;}
}
void _QML_element2_MouseEntered(GUI_Element * self, QMLEvent Event)
{
{(*(GUI_Rectangle*)_QML_element2).color.green=0;(*(GUI_Rectangle*)_QML_element2).color.blue=0;}
}
void _QML_Init()
{
_QML_element0 = (GUI_Element*)acGUI_Rectangle();
_QML_element1 = (GUI_Element*)acGUI_Rectangle();
_QML_element2 = (GUI_Element*)acGUI_RectangleCustom0();
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
_QML_element6->CustomMouseReleased=_QML_element6_MouseReleased;
_QML_element6->CustomMousePressed=_QML_element6_MousePressed;
_QML_element4->CustomMouseReleased=_QML_element4_MouseReleased;
_QML_element4->CustomMousePressed=_QML_element4_MousePressed;
_QML_element3->CustomMouseReleased=_QML_element3_MouseReleased;
_QML_element3->CustomMousePressed=_QML_element3_MousePressed;
_QML_element2->CustomMouseReleased=_QML_element2_MouseReleased;
_QML_element2->CustomMousePressed=_QML_element2_MousePressed;
_QML_element2->CustomMouseExited=_QML_element2_MouseExited;
_QML_element2->CustomMouseEntered=_QML_element2_MouseEntered;
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
_QML_element2->prop1=4;
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
