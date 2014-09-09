GUI_RectangleCustom0* acGUI_RectangleCustom0()
{
GUI_RectangleCustom0 * pointer;
pointer=(GUI_RectangleCustom0*)malloc(sizeof(GUI_RectangleCustom0));
pointer->original=cGUI_Rectangle();
return pointer;
}
