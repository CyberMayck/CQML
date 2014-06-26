GUI_Element* root;
GUI_Element* _QML_element1;
GUI_Element* _QML_element2;
GUI_Element* _QML_element3;
GUI_Element* _QML_element4;
GUI_Element* _QML_element5;
GUI_Element* _QML_element6;
GUI_Element* _QML_element7;

void _QML_Init()
{ 
root = (GUI_Element*) acGUI_Element();
_QML_element1 = (GUI_Element*)acGUI_Rectangle();
mGUI_Element_InsertChild((GUI_Element*)root, (GUI_Element*)_QML_element1);
_QML_element2 = (GUI_Element*)acGUI_Rectangle();
mGUI_Element_InsertChild((GUI_Element*)_QML_element1, (GUI_Element*)_QML_element2);
_QML_element3 = (GUI_Element*)acGUI_Rectangle();
mGUI_Element_InsertChild((GUI_Element*)_QML_element2, (GUI_Element*)_QML_element3);
_QML_element4 = (GUI_Element*)acGUI_Rectangle();
mGUI_Element_InsertChild((GUI_Element*)_QML_element2, (GUI_Element*)_QML_element4);
_QML_element5 = (GUI_Element*)acGUI_Rectangle();
mGUI_Element_InsertChild((GUI_Element*)_QML_element1, (GUI_Element*)_QML_element5);
_QML_element6 = (GUI_Element*)acGUI_Rectangle();
mGUI_Element_InsertChild((GUI_Element*)_QML_element5, (GUI_Element*)_QML_element6);
_QML_element7 = (GUI_Element*)acGUI_Rectangle();
mGUI_Element_InsertChild((GUI_Element*)_QML_element6, (GUI_Element*)_QML_element7);
_QML_element1->x=100;
_QML_element1->y=100;
_QML_element1->width=600;
_QML_element1->height=400;
_QML_element2->x=5;
_QML_element2->y=5;
_QML_element2->width=(*_QML_element2->parent).width/2-10;
_QML_element2->height=(*_QML_element2->parent).height-10;
_QML_element5->x=(*_QML_element5->parent).width/2+5;
_QML_element5->y=5;
_QML_element5->width=(*_QML_element5->parent).width/2-10;
_QML_element5->height=(*_QML_element5->parent).height-10;
_QML_element6->width=(*_QML_element6->parent).width/2;
_QML_element6->height=(*_QML_element6->parent).height/2;
_QML_element7->width=(*_QML_element7->parent).width/2;
_QML_element7->height=(*_QML_element7->parent).height/2;

}
