#include "output0outer.h"

#include "qml_includes.h"
void _CQML_Update();
void _CQML_ClassTabsInit();
GUI_Element* root;

void _CQML_Init()
{
	root = (GUI_Element*) acGUI_Rootoutput0();
	_CQML_Update();
}

void _CQML_Update()
{
	root->Update(root);
}
void InitHashTabs(ClassHashTable * hashTabs)
{
ClassHashTable * data;InitClassesSize(4);
data=&hashTabs[0]
InitHashTab(&data,9,3);
data->keys[0]=(char *)malloc(sizeof(char) * 4);
strcpy(data->keys[0],"red");
data->keys[1]=(char *)malloc(sizeof(char) * 6);
strcpy(data->keys[1],"green");
data->keys[2]=(char *)malloc(sizeof(char) * 5);
strcpy(data->keys[2],"blue");

data->T1[0]=8
data->T1[1]=7
data->T1[2]=7

data->T2[0]=2
data->T2[1]=6
data->T2[2]=5

data->g[0]=0
data->g[1]=0
data->g[2]=0
data->g[3]=0
data->g[4]=0
data->g[5]=2
data->g[6]=0
data->g[7]=1
data->g[8]=0


data=&hashTabs[1]
InitHashTab(&data,27,9);
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

data->T1[0]=18
data->T1[1]=14
data->T1[2]=22
data->T1[3]=6
data->T1[4]=8
data->T1[5]=20
data->T1[6]=2
data->T1[7]=6
data->T1[8]=17

data->T2[0]=24
data->T2[1]=18
data->T2[2]=16
data->T2[3]=5
data->T2[4]=23
data->T2[5]=18
data->T2[6]=9
data->T2[7]=13
data->T2[8]=1

data->g[0]=0
data->g[1]=0
data->g[2]=0
data->g[3]=0
data->g[4]=0
data->g[5]=4
data->g[6]=0
data->g[7]=0
data->g[8]=0
data->g[9]=0
data->g[10]=0
data->g[11]=0
data->g[12]=0
data->g[13]=2
data->g[14]=0
data->g[15]=1
data->g[16]=0
data->g[17]=0
data->g[18]=5
data->g[19]=3
data->g[20]=0
data->g[21]=0
data->g[22]=1
data->g[23]=7
data->g[24]=8
data->g[25]=0
data->g[26]=0


data=&hashTabs[2]
InitHashTab(&data,31,10);
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

data->T1[0]=1
data->T1[1]=20
data->T1[2]=20
data->T1[3]=14
data->T1[4]=28
data->T1[5]=29
data->T1[6]=12
data->T1[7]=4
data->T1[8]=0
data->T1[9]=11

data->T2[0]=12
data->T2[1]=18
data->T2[2]=18
data->T2[3]=26
data->T2[4]=13
data->T2[5]=17
data->T2[6]=2
data->T2[7]=0
data->T2[8]=28
data->T2[9]=19

data->g[0]=0
data->g[1]=0
data->g[2]=0
data->g[3]=0
data->g[4]=0
data->g[5]=0
data->g[6]=0
data->g[7]=3
data->g[8]=0
data->g[9]=2
data->g[10]=9
data->g[11]=0
data->g[12]=0
data->g[13]=8
data->g[14]=0
data->g[15]=6
data->g[16]=0
data->g[17]=0
data->g[18]=0
data->g[19]=0
data->g[20]=0
data->g[21]=0
data->g[22]=0
data->g[23]=0
data->g[24]=0
data->g[25]=0
data->g[26]=0
data->g[27]=6
data->g[28]=7
data->g[29]=5
data->g[30]=4


data=&hashTabs[3]
InitHashTab(&data,12,4);
data->keys[0]=(char *)malloc(sizeof(char) * 4);
strcpy(data->keys[0],"top");
data->keys[1]=(char *)malloc(sizeof(char) * 7);
strcpy(data->keys[1],"bottom");
data->keys[2]=(char *)malloc(sizeof(char) * 5);
strcpy(data->keys[2],"left");
data->keys[3]=(char *)malloc(sizeof(char) * 6);
strcpy(data->keys[3],"right");

data->T1[0]=8
data->T1[1]=10
data->T1[2]=6
data->T1[3]=8

data->T2[0]=1
data->T2[1]=10
data->T2[2]=1
data->T2[3]=2

data->g[0]=0
data->g[1]=0
data->g[2]=0
data->g[3]=0
data->g[4]=3
data->g[5]=0
data->g[6]=2
data->g[7]=1
data->g[8]=0
data->g[9]=0
data->g[10]=2
data->g[11]=0


}

