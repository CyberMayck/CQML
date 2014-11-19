#include "output0outer.h"

#include "qml_includes.h"
void _QML_Update();
void _QML_ClassTabsInit();
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
void _QML_ClassTabsInit()
{
InitClassesSize(4);
InitAttribCnt(0,3,-1);
InitAttribCnt(1,9,-1);
InitAttribCnt(2,1,1);
InitAttribCnt(3,4,-1);
AddAttribute(0,-86017694,offsetof(GUI_Color,red),"float",member_size(GUI_Color,red));
AddAttribute(0,-381163837,offsetof(GUI_Color,green),"float",member_size(GUI_Color,green));
AddAttribute(0,1083042391,offsetof(GUI_Color,blue),"float",member_size(GUI_Color,blue));
AddAttribute(1,-934291016,offsetof(GUI_Element,root),"GUI_Element*",member_size(GUI_Element,root));
AddAttribute(1,1941126675,offsetof(GUI_Element,parent),"GUI_Element*",member_size(GUI_Element,parent));
AddAttribute(1,994742572,offsetof(GUI_Element,children),"GUI_Element**",member_size(GUI_Element,children));
AddAttribute(1,74107020,offsetof(GUI_Element,childrenCount),"int",member_size(GUI_Element,childrenCount));
AddAttribute(1,853035352,offsetof(GUI_Element,flags),"int",member_size(GUI_Element,flags));
AddAttribute(1,-1591671055,offsetof(GUI_Element,x),"int",member_size(GUI_Element,x));
AddAttribute(1,-702138777,offsetof(GUI_Element,y),"int",member_size(GUI_Element,y));
AddAttribute(1,-1245229619,offsetof(GUI_Element,width),"int",member_size(GUI_Element,width));
AddAttribute(1,-1150239917,offsetof(GUI_Element,height),"int",member_size(GUI_Element,height));
AddAttribute(2,1602961419,offsetof(GUI_Rectangle,color),"GUI_Color",member_size(GUI_Rectangle,color));
AddAttribute(3,510081319,offsetof(GUI_Anchor,top),"GUI_Element*",member_size(GUI_Anchor,top));
AddAttribute(3,-949867272,offsetof(GUI_Anchor,bottom),"GUI_Element*",member_size(GUI_Anchor,bottom));
AddAttribute(3,-1529034869,offsetof(GUI_Anchor,left),"GUI_Element*",member_size(GUI_Anchor,left));
AddAttribute(3,-1927840266,offsetof(GUI_Anchor,right),"GUI_Element*",member_size(GUI_Anchor,right));
}
