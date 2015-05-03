#include "output0outer.h"
#include"parser_output.h"
#include "qml_includes.h"
void _QML_Update();
void _QML_ClassTabsInit();
void _QML_Draw();
CQMLGUI::Element* root;

void _QML_Start()
{
	SetInitHashTabs(&InitHashTabs);
	QMLInitHashes();
	root = (CQMLGUI::Element*) CQMLGUI::acGUI_Rootoutput0();
	CQMLGUI::SetRoot(root);
	_QML_Update();
}

void _QML_Update()
{
	CQMLGUI::PreUpdate();
	root->Update();
	CQMLGUI::PostUpdate();
}

void _QML_Draw()
{
	CQMLGUI::PreDraw();
	root->Draw();
	CQMLGUI::PostDraw();
}
// print default constructors;
using namespace CQMLGUI;
void InitHashTabs(ClassHashTable *& hashTabs)
{
ClassHashTable * data;
InitClassesSize(hashTabs, 13);

hashTabs[0].isValueType=1;
hashTabs[0].parentID=-1;
hashTabs[1].isValueType=1;
hashTabs[1].parentID=-1;
hashTabs[2].isValueType=1;
hashTabs[2].parentID=-1;
hashTabs[3].isValueType=0;
hashTabs[3].parentID=-1;
hashTabs[4].isValueType=0;
hashTabs[4].parentID=3;
hashTabs[5].isValueType=0;
hashTabs[5].parentID=3;
hashTabs[6].isValueType=1;
hashTabs[6].parentID=-1;
hashTabs[7].isValueType=0;
hashTabs[7].parentID=4;
hashTabs[8].isValueType=0;
hashTabs[8].parentID=7;
hashTabs[9].isValueType=0;
hashTabs[9].parentID=3;
hashTabs[10].isValueType=0;
hashTabs[10].parentID=9;
hashTabs[11].isValueType=0;
hashTabs[11].parentID=3;
hashTabs[12].isValueType=0;
hashTabs[12].parentID=10;
data=&hashTabs[11];
InitHashTab(data,16,5);
data->keys[0]=(char *)malloc(sizeof(char) * 6);
strcpy_s(data->keys[0],6,"refEl");
data->keys[1]=(char *)malloc(sizeof(char) * 2);
strcpy_s(data->keys[1],2,"x");
data->keys[2]=(char *)malloc(sizeof(char) * 2);
strcpy_s(data->keys[2],2,"y");
data->keys[3]=(char *)malloc(sizeof(char) * 6);
strcpy_s(data->keys[3],6,"width");
data->keys[4]=(char *)malloc(sizeof(char) * 7);
strcpy_s(data->keys[4],7,"height");

data->T1[0]=4;
data->T1[1]=6;
data->T1[2]=13;
data->T1[3]=11;
data->T1[4]=9;

data->T2[0]=13;
data->T2[1]=8;
data->T2[2]=15;
data->T2[3]=15;
data->T2[4]=14;

data->g[0]=0;
data->g[1]=0;
data->g[2]=0;
data->g[3]=0;
data->g[4]=0;
data->g[5]=2;
data->g[6]=0;
data->g[7]=0;
data->g[8]=1;
data->g[9]=0;
data->g[10]=0;
data->g[11]=3;
data->g[12]=4;
data->g[13]=0;
data->g[14]=0;
data->g[15]=0;


data=&hashTabs[12];
InitHashTab(data,33,11);
data->keys[0]=(char *)malloc(sizeof(char) * 6);
strcpy_s(data->keys[0],6,"refEl");
data->keys[1]=(char *)malloc(sizeof(char) * 7);
strcpy_s(data->keys[1],7,"status");
data->keys[2]=(char *)malloc(sizeof(char) * 11);
strcpy_s(data->keys[2],11,"leftBorder");
data->keys[3]=(char *)malloc(sizeof(char) * 13);
strcpy_s(data->keys[3],13,"bottomBorder");
data->keys[4]=(char *)malloc(sizeof(char) * 12);
strcpy_s(data->keys[4],12,"rightBorder");
data->keys[5]=(char *)malloc(sizeof(char) * 10);
strcpy_s(data->keys[5],10,"topBorder");
data->keys[6]=(char *)malloc(sizeof(char) * 4);
strcpy_s(data->keys[6],4,"img");
data->keys[7]=(char *)malloc(sizeof(char) * 2);
strcpy_s(data->keys[7],2,"x");
data->keys[8]=(char *)malloc(sizeof(char) * 2);
strcpy_s(data->keys[8],2,"y");
data->keys[9]=(char *)malloc(sizeof(char) * 6);
strcpy_s(data->keys[9],6,"width");
data->keys[10]=(char *)malloc(sizeof(char) * 7);
strcpy_s(data->keys[10],7,"height");

data->T1[0]=30;
data->T1[1]=0;
data->T1[2]=17;
data->T1[3]=17;
data->T1[4]=9;
data->T1[5]=27;
data->T1[6]=11;
data->T1[7]=23;
data->T1[8]=4;
data->T1[9]=30;
data->T1[10]=1;

data->T2[0]=20;
data->T2[1]=19;
data->T2[2]=13;
data->T2[3]=6;
data->T2[4]=10;
data->T2[5]=2;
data->T2[6]=16;
data->T2[7]=20;
data->T2[8]=19;
data->T2[9]=31;
data->T2[10]=30;

data->g[0]=0;
data->g[1]=0;
data->g[2]=0;
data->g[3]=0;
data->g[4]=0;
data->g[5]=0;
data->g[6]=0;
data->g[7]=0;
data->g[8]=5;
data->g[9]=1;
data->g[10]=0;
data->g[11]=8;
data->g[12]=0;
data->g[13]=0;
data->g[14]=0;
data->g[15]=0;
data->g[16]=0;
data->g[17]=2;
data->g[18]=0;
data->g[19]=3;
data->g[20]=0;
data->g[21]=0;
data->g[22]=0;
data->g[23]=0;
data->g[24]=7;
data->g[25]=4;
data->g[26]=0;
data->g[27]=6;
data->g[28]=0;
data->g[29]=6;
data->g[30]=0;
data->g[31]=0;
data->g[32]=4;


}

