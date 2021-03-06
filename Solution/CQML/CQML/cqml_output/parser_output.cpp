#include "output0.h"
#include"parser_output.h"
#include "qml_includes.h"
void _CQML_ClassTabsInit();
CQMLGUI::Element* root;

void _CQML_Start()
{
	SetInitHashTabs(&InitHashTabs);
	CQMLInitHashes();
	root = (CQMLGUI::Element*) CQMLGUI::acGUI_Rootoutput0();
	CQMLGUI::SetRoot(root);
	_CQML_Update();
}
// print default constructors;
using namespace CQMLGUI;
void InitHashTabs(ClassHashTable *& hashTabs)
{
ClassHashTable * data;
InitClassesSize(hashTabs, 15);

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
hashTabs[14].isValueType=0;
hashTabs[14].parentID=5;
hashTabs[13].isValueType=0;
hashTabs[13].parentID=3;
hashTabs[12].isValueType=0;
hashTabs[12].parentID=11;
hashTabs[11].isValueType=0;
hashTabs[11].parentID=5;
data=&hashTabs[14];
InitHashTab(data,36,12);
data->maxT=10;
data->keys[0]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[0],8,"pressed");
data->keys[1]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[1],8,"entered");
data->keys[2]=(char *)malloc(sizeof(char) * 11);
strcpy_s(data->keys[2],11,"pressedImg");
data->keys[3]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[3],8,"overImg");
data->keys[4]=(char *)malloc(sizeof(char) * 7);
strcpy_s(data->keys[4],7,"defImg");
data->keys[5]=(char *)malloc(sizeof(char) * 5);
strcpy_s(data->keys[5],5,"text");
data->keys[6]=(char *)malloc(sizeof(char) * 2);
strcpy_s(data->keys[6],2,"x");
data->keys[7]=(char *)malloc(sizeof(char) * 2);
strcpy_s(data->keys[7],2,"y");
data->keys[8]=(char *)malloc(sizeof(char) * 6);
strcpy_s(data->keys[8],6,"width");
data->keys[9]=(char *)malloc(sizeof(char) * 7);
strcpy_s(data->keys[9],7,"height");
data->keys[10]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[10],8,"visible");
data->keys[11]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[11],8,"enabled");

data->T1[0]=8;
data->T1[1]=35;
data->T1[2]=6;
data->T1[3]=32;
data->T1[4]=26;
data->T1[5]=29;
data->T1[6]=9;
data->T1[7]=12;
data->T1[8]=32;
data->T1[9]=29;
data->T1[10]=-1414812757;
data->T1[11]=-1414812757;

data->T2[0]=10;
data->T2[1]=30;
data->T2[2]=1;
data->T2[3]=7;
data->T2[4]=23;
data->T2[5]=19;
data->T2[6]=1;
data->T2[7]=8;
data->T2[8]=29;
data->T2[9]=0;
data->T2[10]=-1414812757;
data->T2[11]=-1414812757;

data->g[0]=0;
data->g[1]=0;
data->g[2]=0;
data->g[3]=0;
data->g[4]=0;
data->g[5]=0;
data->g[6]=0;
data->g[7]=9;
data->g[8]=0;
data->g[9]=0;
data->g[10]=5;
data->g[11]=7;
data->g[12]=0;
data->g[13]=0;
data->g[14]=0;
data->g[15]=8;
data->g[16]=0;
data->g[17]=0;
data->g[18]=4;
data->g[19]=0;
data->g[20]=11;
data->g[21]=0;
data->g[22]=0;
data->g[23]=0;
data->g[24]=6;
data->g[25]=0;
data->g[26]=0;
data->g[27]=0;
data->g[28]=0;
data->g[29]=0;
data->g[30]=3;
data->g[31]=2;
data->g[32]=7;
data->g[33]=3;
data->g[34]=0;
data->g[35]=4;


data=&hashTabs[13];
InitHashTab(data,33,11);
data->maxT=10;
data->keys[0]=(char *)malloc(sizeof(char) * 6);
strcpy_s(data->keys[0],6,"first");
data->keys[1]=(char *)malloc(sizeof(char) * 11);
strcpy_s(data->keys[1],11,"firstValue");
data->keys[2]=(char *)malloc(sizeof(char) * 6);
strcpy_s(data->keys[2],6,"score");
data->keys[3]=(char *)malloc(sizeof(char) * 7);
strcpy_s(data->keys[3],7,"status");
data->keys[4]=(char *)malloc(sizeof(char) * 7);
strcpy_s(data->keys[4],7,"winMsg");
data->keys[5]=(char *)malloc(sizeof(char) * 2);
strcpy_s(data->keys[5],2,"x");
data->keys[6]=(char *)malloc(sizeof(char) * 2);
strcpy_s(data->keys[6],2,"y");
data->keys[7]=(char *)malloc(sizeof(char) * 6);
strcpy_s(data->keys[7],6,"width");
data->keys[8]=(char *)malloc(sizeof(char) * 7);
strcpy_s(data->keys[8],7,"height");
data->keys[9]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[9],8,"visible");
data->keys[10]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[10],8,"enabled");

data->T1[0]=18;
data->T1[1]=26;
data->T1[2]=19;
data->T1[3]=19;
data->T1[4]=23;
data->T1[5]=10;
data->T1[6]=6;
data->T1[7]=5;
data->T1[8]=11;
data->T1[9]=8;
data->T1[10]=-1414812757;

data->T2[0]=8;
data->T2[1]=24;
data->T2[2]=30;
data->T2[3]=5;
data->T2[4]=26;
data->T2[5]=5;
data->T2[6]=32;
data->T2[7]=28;
data->T2[8]=25;
data->T2[9]=18;
data->T2[10]=-1414812757;

data->g[0]=0;
data->g[1]=0;
data->g[2]=0;
data->g[3]=0;
data->g[4]=0;
data->g[5]=2;
data->g[6]=0;
data->g[7]=0;
data->g[8]=0;
data->g[9]=0;
data->g[10]=0;
data->g[11]=6;
data->g[12]=0;
data->g[13]=0;
data->g[14]=0;
data->g[15]=5;
data->g[16]=9;
data->g[17]=0;
data->g[18]=0;
data->g[19]=0;
data->g[20]=1;
data->g[21]=9;
data->g[22]=4;
data->g[23]=8;
data->g[24]=0;
data->g[25]=0;
data->g[26]=0;
data->g[27]=0;
data->g[28]=0;
data->g[29]=10;
data->g[30]=0;
data->g[31]=7;
data->g[32]=0;


data=&hashTabs[12];
InitHashTab(data,39,13);
data->maxT=10;
data->keys[0]=(char *)malloc(sizeof(char) * 6);
strcpy_s(data->keys[0],6,"value");
data->keys[1]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[1],8,"matcher");
data->keys[2]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[2],8,"pressed");
data->keys[3]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[3],8,"entered");
data->keys[4]=(char *)malloc(sizeof(char) * 11);
strcpy_s(data->keys[4],11,"pressedImg");
data->keys[5]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[5],8,"overImg");
data->keys[6]=(char *)malloc(sizeof(char) * 7);
strcpy_s(data->keys[6],7,"defImg");
data->keys[7]=(char *)malloc(sizeof(char) * 2);
strcpy_s(data->keys[7],2,"x");
data->keys[8]=(char *)malloc(sizeof(char) * 2);
strcpy_s(data->keys[8],2,"y");
data->keys[9]=(char *)malloc(sizeof(char) * 6);
strcpy_s(data->keys[9],6,"width");
data->keys[10]=(char *)malloc(sizeof(char) * 7);
strcpy_s(data->keys[10],7,"height");
data->keys[11]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[11],8,"visible");
data->keys[12]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[12],8,"enabled");

data->T1[0]=6;
data->T1[1]=36;
data->T1[2]=16;
data->T1[3]=38;
data->T1[4]=30;
data->T1[5]=28;
data->T1[6]=8;
data->T1[7]=32;
data->T1[8]=21;
data->T1[9]=2;
data->T1[10]=-1414812757;
data->T1[11]=-1414812757;
data->T1[12]=0;

data->T2[0]=17;
data->T2[1]=35;
data->T2[2]=29;
data->T2[3]=22;
data->T2[4]=26;
data->T2[5]=17;
data->T2[6]=16;
data->T2[7]=23;
data->T2[8]=17;
data->T2[9]=22;
data->T2[10]=-1414812757;
data->T2[11]=-1414812757;
data->T2[12]=0;

data->g[0]=0;
data->g[1]=0;
data->g[2]=0;
data->g[3]=0;
data->g[4]=0;
data->g[5]=5;
data->g[6]=0;
data->g[7]=0;
data->g[8]=0;
data->g[9]=0;
data->g[10]=11;
data->g[11]=9;
data->g[12]=8;
data->g[13]=0;
data->g[14]=0;
data->g[15]=0;
data->g[16]=0;
data->g[17]=9;
data->g[18]=12;
data->g[19]=9;
data->g[20]=0;
data->g[21]=0;
data->g[22]=0;
data->g[23]=0;
data->g[24]=0;
data->g[25]=0;
data->g[26]=0;
data->g[27]=8;
data->g[28]=0;
data->g[29]=8;
data->g[30]=0;
data->g[31]=3;
data->g[32]=6;
data->g[33]=0;
data->g[34]=0;
data->g[35]=0;
data->g[36]=0;
data->g[37]=10;
data->g[38]=0;


data=&hashTabs[11];
InitHashTab(data,33,11);
data->maxT=10;
data->keys[0]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[0],8,"pressed");
data->keys[1]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[1],8,"entered");
data->keys[2]=(char *)malloc(sizeof(char) * 11);
strcpy_s(data->keys[2],11,"pressedImg");
data->keys[3]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[3],8,"overImg");
data->keys[4]=(char *)malloc(sizeof(char) * 7);
strcpy_s(data->keys[4],7,"defImg");
data->keys[5]=(char *)malloc(sizeof(char) * 2);
strcpy_s(data->keys[5],2,"x");
data->keys[6]=(char *)malloc(sizeof(char) * 2);
strcpy_s(data->keys[6],2,"y");
data->keys[7]=(char *)malloc(sizeof(char) * 6);
strcpy_s(data->keys[7],6,"width");
data->keys[8]=(char *)malloc(sizeof(char) * 7);
strcpy_s(data->keys[8],7,"height");
data->keys[9]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[9],8,"visible");
data->keys[10]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[10],8,"enabled");

data->T1[0]=17;
data->T1[1]=2;
data->T1[2]=25;
data->T1[3]=1;
data->T1[4]=26;
data->T1[5]=16;
data->T1[6]=15;
data->T1[7]=21;
data->T1[8]=11;
data->T1[9]=29;
data->T1[10]=-1414812757;

data->T2[0]=7;
data->T2[1]=18;
data->T2[2]=10;
data->T2[3]=8;
data->T2[4]=24;
data->T2[5]=9;
data->T2[6]=5;
data->T2[7]=29;
data->T2[8]=10;
data->T2[9]=2;
data->T2[10]=-1414812757;

data->g[0]=0;
data->g[1]=0;
data->g[2]=0;
data->g[3]=0;
data->g[4]=0;
data->g[5]=0;
data->g[6]=0;
data->g[7]=0;
data->g[8]=0;
data->g[9]=2;
data->g[10]=0;
data->g[11]=0;
data->g[12]=0;
data->g[13]=0;
data->g[14]=0;
data->g[15]=1;
data->g[16]=2;
data->g[17]=0;
data->g[18]=8;
data->g[19]=1;
data->g[20]=0;
data->g[21]=7;
data->g[22]=6;
data->g[23]=0;
data->g[24]=0;
data->g[25]=4;
data->g[26]=0;
data->g[27]=4;
data->g[28]=0;
data->g[29]=6;
data->g[30]=0;
data->g[31]=2;
data->g[32]=0;


}

