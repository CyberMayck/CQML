#include "output0outer.h"

#include "qml_includes.h"
void _QML_Update();
void _QML_ClassTabsInit();
CQMLGUI::Element* root;

void _QML_Init()
{
	root = (CQMLGUI::Element*) CQMLGUI::acGUI_Rootoutput0();
	_QML_Update();
}

void _QML_Update()
{
	root->Update();
}/*
CQMLGUI::Color::Color()
{
	classID=0;
}*/
CQMLGUI::Font::Font()
{
	classID=1;
}
/*CQMLGUI::Element::Element()
{
	classID=2;
}*/
/*
CQMLGUI::Rectangle::Rectangle()
{
	classID=3;
}*/
CQMLGUI::Anchor::Anchor()
{
	classID=4;
}
CQMLGUI::Text::Text()
{
	text_color_Update=0;
	
	text_color.red_Update=0;
	text_color.green_Update=0;
	text_color.blue_Update=0;
	
	text_Update=0;
	font_Update=0;
	font.capital_Update=0;
	font.italic_Update=0;
	font.bold_Update=0;
	font.size_Update=0;
	font.family_Update=0;
	classID=5;
}
CQMLGUI::TextInput::TextInput()
{
	classID=6;
}
void InitHashTabs(ClassHashTable * hashTabs)
{
ClassHashTable * data;InitClassesSize(hashTabs,7);


 //PrintClassTabs()
InitAttribCnt(0,3,-1);
InitAttribCnt(1,5,-1);
InitAttribCnt(2,9,-1);
InitAttribCnt(3,1,2);
InitAttribCnt(4,4,-1);
InitAttribCnt(5,3,3);
InitAttribCnt(6,0,5);

data=&hashTabs[0];
InitHashTab(data,9,3);
data->keys[0]=(char *)malloc(sizeof(char) * 4);
strcpy(data->keys[0],"red");
data->keys[1]=(char *)malloc(sizeof(char) * 6);
strcpy(data->keys[1],"green");
data->keys[2]=(char *)malloc(sizeof(char) * 5);
strcpy(data->keys[2],"blue");

data->T1[0]=8;
data->T1[1]=7;
data->T1[2]=7;

data->T2[0]=2;
data->T2[1]=6;
data->T2[2]=5;

data->g[0]=0;
data->g[1]=0;
data->g[2]=0;
data->g[3]=0;
data->g[4]=0;
data->g[5]=2;
data->g[6]=0;
data->g[7]=1;
data->g[8]=0;


data=&hashTabs[1];
InitHashTab(data,15,5);
data->keys[0]=(char *)malloc(sizeof(char) * 8);
strcpy(data->keys[0],"capital");
data->keys[1]=(char *)malloc(sizeof(char) * 7);
strcpy(data->keys[1],"italic");
data->keys[2]=(char *)malloc(sizeof(char) * 5);
strcpy(data->keys[2],"bold");
data->keys[3]=(char *)malloc(sizeof(char) * 5);
strcpy(data->keys[3],"size");
data->keys[4]=(char *)malloc(sizeof(char) * 7);
strcpy(data->keys[4],"family");

data->T1[0]=6;
data->T1[1]=2;
data->T1[2]=7;
data->T1[3]=6;
data->T1[4]=8;

data->T2[0]=9;
data->T2[1]=3;
data->T2[2]=7;
data->T2[3]=11;
data->T2[4]=5;

data->g[0]=0;
data->g[1]=0;
data->g[2]=0;
data->g[3]=0;
data->g[4]=1;
data->g[5]=3;
data->g[6]=0;
data->g[7]=0;
data->g[8]=0;
data->g[9]=0;
data->g[10]=0;
data->g[11]=2;
data->g[12]=0;
data->g[13]=1;
data->g[14]=0;


data=&hashTabs[2];
InitHashTab(data,27,9);
data->keys[0]=(char *)malloc(sizeof(char) * 5);
strcpy(data->keys[0],"root");
data->keys[1]=(char *)malloc(sizeof(char) * 7);
strcpy(data->keys[1],"parent");
data->keys[2]=(char *)malloc(sizeof(char) * 9);
strcpy(data->keys[2],"children");
data->keys[3]=(char *)malloc(sizeof(char) * 14);
strcpy(data->keys[3],"childrenCount");
data->keys[4]=(char *)malloc(sizeof(char) * 6);
strcpy(data->keys[4],"flags");
data->keys[5]=(char *)malloc(sizeof(char) * 2);
strcpy(data->keys[5],"x");
data->keys[6]=(char *)malloc(sizeof(char) * 2);
strcpy(data->keys[6],"y");
data->keys[7]=(char *)malloc(sizeof(char) * 6);
strcpy(data->keys[7],"width");
data->keys[8]=(char *)malloc(sizeof(char) * 7);
strcpy(data->keys[8],"height");

data->T1[0]=6;
data->T1[1]=17;
data->T1[2]=25;
data->T1[3]=2;
data->T1[4]=2;
data->T1[5]=15;
data->T1[6]=21;
data->T1[7]=11;
data->T1[8]=5;

data->T2[0]=13;
data->T2[1]=1;
data->T2[2]=12;
data->T2[3]=24;
data->T2[4]=12;
data->T2[5]=20;
data->T2[6]=16;
data->T2[7]=10;
data->T2[8]=23;

data->g[0]=0;
data->g[1]=0;
data->g[2]=0;
data->g[3]=0;
data->g[4]=0;
data->g[5]=0;
data->g[6]=0;
data->g[7]=0;
data->g[8]=0;
data->g[9]=0;
data->g[10]=0;
data->g[11]=0;
data->g[12]=5;
data->g[13]=0;
data->g[14]=0;
data->g[15]=0;
data->g[16]=4;
data->g[17]=7;
data->g[18]=8;
data->g[19]=8;
data->g[20]=0;
data->g[21]=6;
data->g[22]=3;
data->g[23]=0;
data->g[24]=6;
data->g[25]=0;
data->g[26]=2;


data=&hashTabs[3];
InitHashTab(data,31,10);
data->keys[0]=(char *)malloc(sizeof(char) * 6);
strcpy(data->keys[0],"color");
data->keys[1]=(char *)malloc(sizeof(char) * 5);
strcpy(data->keys[1],"root");
data->keys[2]=(char *)malloc(sizeof(char) * 7);
strcpy(data->keys[2],"parent");
data->keys[3]=(char *)malloc(sizeof(char) * 9);
strcpy(data->keys[3],"children");
data->keys[4]=(char *)malloc(sizeof(char) * 14);
strcpy(data->keys[4],"childrenCount");
data->keys[5]=(char *)malloc(sizeof(char) * 6);
strcpy(data->keys[5],"flags");
data->keys[6]=(char *)malloc(sizeof(char) * 2);
strcpy(data->keys[6],"x");
data->keys[7]=(char *)malloc(sizeof(char) * 2);
strcpy(data->keys[7],"y");
data->keys[8]=(char *)malloc(sizeof(char) * 6);
strcpy(data->keys[8],"width");
data->keys[9]=(char *)malloc(sizeof(char) * 7);
strcpy(data->keys[9],"height");

data->T1[0]=26;
data->T1[1]=19;
data->T1[2]=1;
data->T1[3]=13;
data->T1[4]=22;
data->T1[5]=7;
data->T1[6]=1;
data->T1[7]=20;
data->T1[8]=20;
data->T1[9]=14;

data->T2[0]=10;
data->T2[1]=17;
data->T2[2]=0;
data->T2[3]=20;
data->T2[4]=3;
data->T2[5]=10;
data->T2[6]=12;
data->T2[7]=18;
data->T2[8]=18;
data->T2[9]=26;

data->g[0]=0;
data->g[1]=0;
data->g[2]=0;
data->g[3]=0;
data->g[4]=0;
data->g[5]=0;
data->g[6]=0;
data->g[7]=0;
data->g[8]=0;
data->g[9]=0;
data->g[10]=0;
data->g[11]=0;
data->g[12]=3;
data->g[13]=0;
data->g[14]=0;
data->g[15]=7;
data->g[16]=0;
data->g[17]=2;
data->g[18]=0;
data->g[19]=0;
data->g[20]=1;
data->g[21]=0;
data->g[22]=5;
data->g[23]=0;
data->g[24]=0;
data->g[25]=0;
data->g[26]=4;
data->g[27]=4;
data->g[28]=0;
data->g[29]=4;
data->g[30]=0;


data=&hashTabs[4];
InitHashTab(data,12,4);
data->keys[0]=(char *)malloc(sizeof(char) * 4);
strcpy(data->keys[0],"top");
data->keys[1]=(char *)malloc(sizeof(char) * 7);
strcpy(data->keys[1],"bottom");
data->keys[2]=(char *)malloc(sizeof(char) * 5);
strcpy(data->keys[2],"left");
data->keys[3]=(char *)malloc(sizeof(char) * 6);
strcpy(data->keys[3],"right");

data->T1[0]=0;
data->T1[1]=1;
data->T1[2]=6;
data->T1[3]=2;

data->T2[0]=3;
data->T2[1]=4;
data->T2[2]=6;
data->T2[3]=0;

data->g[0]=0;
data->g[1]=0;
data->g[2]=0;
data->g[3]=0;
data->g[4]=3;
data->g[5]=0;
data->g[6]=0;
data->g[7]=0;
data->g[8]=1;
data->g[9]=1;
data->g[10]=0;
data->g[11]=0;


data=&hashTabs[5];
InitHashTab(data,39,13);
data->keys[0]=(char *)malloc(sizeof(char) * 11);
strcpy(data->keys[0],"text_color");
data->keys[1]=(char *)malloc(sizeof(char) * 5);
strcpy(data->keys[1],"text");
data->keys[2]=(char *)malloc(sizeof(char) * 5);
strcpy(data->keys[2],"font");
data->keys[3]=(char *)malloc(sizeof(char) * 6);
strcpy(data->keys[3],"color");
data->keys[4]=(char *)malloc(sizeof(char) * 5);
strcpy(data->keys[4],"root");
data->keys[5]=(char *)malloc(sizeof(char) * 7);
strcpy(data->keys[5],"parent");
data->keys[6]=(char *)malloc(sizeof(char) * 9);
strcpy(data->keys[6],"children");
data->keys[7]=(char *)malloc(sizeof(char) * 14);
strcpy(data->keys[7],"childrenCount");
data->keys[8]=(char *)malloc(sizeof(char) * 6);
strcpy(data->keys[8],"flags");
data->keys[9]=(char *)malloc(sizeof(char) * 2);
strcpy(data->keys[9],"x");
data->keys[10]=(char *)malloc(sizeof(char) * 2);
strcpy(data->keys[10],"y");
data->keys[11]=(char *)malloc(sizeof(char) * 6);
strcpy(data->keys[11],"width");
data->keys[12]=(char *)malloc(sizeof(char) * 7);
strcpy(data->keys[12],"height");

data->T1[0]=16;
data->T1[1]=21;
data->T1[2]=5;
data->T1[3]=9;
data->T1[4]=14;
data->T1[5]=17;
data->T1[6]=37;
data->T1[7]=6;
data->T1[8]=32;
data->T1[9]=13;
data->T1[10]=25;
data->T1[11]=18;
data->T1[12]=33;

data->T2[0]=23;
data->T2[1]=2;
data->T2[2]=22;
data->T2[3]=30;
data->T2[4]=23;
data->T2[5]=35;
data->T2[6]=28;
data->T2[7]=18;
data->T2[8]=4;
data->T2[9]=19;
data->T2[10]=27;
data->T2[11]=32;
data->T2[12]=8;

data->g[0]=0;
data->g[1]=0;
data->g[2]=0;
data->g[3]=0;
data->g[4]=0;
data->g[5]=0;
data->g[6]=5;
data->g[7]=0;
data->g[8]=0;
data->g[9]=0;
data->g[10]=0;
data->g[11]=3;
data->g[12]=0;
data->g[13]=12;
data->g[14]=0;
data->g[15]=0;
data->g[16]=12;
data->g[17]=0;
data->g[18]=6;
data->g[19]=2;
data->g[20]=1;
data->g[21]=8;
data->g[22]=0;
data->g[23]=7;
data->g[24]=7;
data->g[25]=10;
data->g[26]=0;
data->g[27]=0;
data->g[28]=0;
data->g[29]=0;
data->g[30]=9;
data->g[31]=0;
data->g[32]=0;
data->g[33]=0;
data->g[34]=0;
data->g[35]=0;
data->g[36]=0;
data->g[37]=0;
data->g[38]=0;


data=&hashTabs[6];
InitHashTab(data,39,13);
data->keys[0]=(char *)malloc(sizeof(char) * 11);
strcpy(data->keys[0],"text_color");
data->keys[1]=(char *)malloc(sizeof(char) * 5);
strcpy(data->keys[1],"text");
data->keys[2]=(char *)malloc(sizeof(char) * 5);
strcpy(data->keys[2],"font");
data->keys[3]=(char *)malloc(sizeof(char) * 6);
strcpy(data->keys[3],"color");
data->keys[4]=(char *)malloc(sizeof(char) * 5);
strcpy(data->keys[4],"root");
data->keys[5]=(char *)malloc(sizeof(char) * 7);
strcpy(data->keys[5],"parent");
data->keys[6]=(char *)malloc(sizeof(char) * 9);
strcpy(data->keys[6],"children");
data->keys[7]=(char *)malloc(sizeof(char) * 14);
strcpy(data->keys[7],"childrenCount");
data->keys[8]=(char *)malloc(sizeof(char) * 6);
strcpy(data->keys[8],"flags");
data->keys[9]=(char *)malloc(sizeof(char) * 2);
strcpy(data->keys[9],"x");
data->keys[10]=(char *)malloc(sizeof(char) * 2);
strcpy(data->keys[10],"y");
data->keys[11]=(char *)malloc(sizeof(char) * 6);
strcpy(data->keys[11],"width");
data->keys[12]=(char *)malloc(sizeof(char) * 7);
strcpy(data->keys[12],"height");

data->T1[0]=12;
data->T1[1]=31;
data->T1[2]=20;
data->T1[3]=36;
data->T1[4]=9;
data->T1[5]=35;
data->T1[6]=34;
data->T1[7]=13;
data->T1[8]=10;
data->T1[9]=26;
data->T1[10]=26;
data->T1[11]=25;
data->T1[12]=9;

data->T2[0]=34;
data->T2[1]=13;
data->T2[2]=37;
data->T2[3]=35;
data->T2[4]=31;
data->T2[5]=0;
data->T2[6]=9;
data->T2[7]=33;
data->T2[8]=2;
data->T2[9]=0;
data->T2[10]=0;
data->T2[11]=36;
data->T2[12]=16;

data->g[0]=0;
data->g[1]=0;
data->g[2]=0;
data->g[3]=0;
data->g[4]=0;
data->g[5]=0;
data->g[6]=0;
data->g[7]=0;
data->g[8]=7;
data->g[9]=10;
data->g[10]=0;
data->g[11]=0;
data->g[12]=12;
data->g[13]=0;
data->g[14]=0;
data->g[15]=2;
data->g[16]=0;
data->g[17]=9;
data->g[18]=0;
data->g[19]=0;
data->g[20]=0;
data->g[21]=0;
data->g[22]=0;
data->g[23]=3;
data->g[24]=0;
data->g[25]=0;
data->g[26]=0;
data->g[27]=0;
data->g[28]=0;
data->g[29]=11;
data->g[30]=4;
data->g[31]=5;
data->g[32]=0;
data->g[33]=3;
data->g[34]=0;
data->g[35]=0;
data->g[36]=9;
data->g[37]=10;
data->g[38]=0;


}

