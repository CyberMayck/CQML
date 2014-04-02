#include <stdio.h>
#include <stdlib.h>
//#include "lex.yy.c"
//#include "cqml_grammar.tab.c"
#include "cqml_grammar.tab.h"
#include "y.tab.h"
typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE yy_scan_string(char *);
YY_BUFFER_STATE yyrestart(FILE * file);
YY_BUFFER_STATE yyparse();

FILE *file;
int id;

typedef struct ParserList ParserList;
typedef struct ParserElement ParserElement;

struct ParserElement {
	ParserList* list;
	char * name;
};
struct ParserList {
	ParserElement ** members;
	int memberCount;
};

void recursionDecl(ParserElement * element)
{
	int i;
	//printf("%s { ",(*element).name);
	//fprintf(file,"%s { ",(*element).name);
	
	fprintf(file, "GUI_Element* _QML_element%d;\n",id);
	id++;
	if((*element).list!=0)
	{
		for(i=0;i<(*(*element).list).memberCount;i++)
		{
			recursionDecl((*(*element).list).members[i]);
		}
	}


	//printf("}; ");
	//fprintf(file,"}; ");
}

void recursionInit(ParserElement * element, int parentId)
{
	int i;
	//printf("%s { ",(*element).name);
	//fprintf(file,"%s { ",(*element).name);

	int currentId;
	currentId=id;
	fprintf(file, "_QML_element%d = (GUI_Element*)acGUI_%s();\n",currentId,(*element).name);
	
	if(parentId>0)fprintf(file, "mGUI_Element_InsertChild((GUI_Element*)_QML_element%d, (GUI_Element*)_QML_element%d);\n",parentId,currentId);
	else fprintf(file, "mGUI_Element_InsertChild((GUI_Element*)root, (GUI_Element*)_QML_element%d);\n",currentId);

	id++;
	if((*element).list!=0)
	{
		for(i=0;i<(*(*element).list).memberCount;i++)
		{
			recursionInit((*(*element).list).members[i], currentId);

		}
	}


	//printf("}; ");
	//fprintf(file,"}; ");
}

void makeSource(int *l)
{
	ParserList* list;
	int i;
	list=(ParserList*)l;
	//printf("\n");
	//return;
	file = fopen("file.c","w");
	
	fprintf(file, "GUI_Element* root;\n");
	id=1;
	//(*list).memberCount
	for(i=0;i<(*list).memberCount;i++)
	{
		recursionDecl((*list).members[i]);
	}
	fprintf(file, "\n");
	
	id=1;
	fprintf(file,"void _QML_Init()\n{\n");
	fprintf(file, "root = (GUI_Element*) acGUI_Element();\n");
	
	for(i=0;i<(*list).memberCount;i++)
	{
		recursionInit((*list).members[i],-1);
	}
	fprintf(file,"}\n");
	

	fclose(file);
}

int* createElement(int *a, char b, int *listPointer, char * text)
{
	ParserElement * pointer;
	pointer=(ParserElement*)malloc(sizeof(ParserElement));
	(*pointer).list=(ParserList*)listPointer;
	(*pointer).name=text;
	return (int*)pointer;
}

int* createList(int *elementPointer, char b, int *listPointer, char * d)
{
	ParserList * list;
	ParserElement * pointer;
	ParserElement ** oldChildren;
	int i;
	list=(ParserList*)listPointer;
	pointer=(ParserElement*)elementPointer;
	if(list==0)
	{
		//new List
		list=(ParserList*)malloc(sizeof(ParserList));
		(*list).memberCount=0;
	}
	

	//

	
	oldChildren=(*list).members;
	(*list).members=(ParserElement **) malloc(((*list).memberCount+1)*sizeof(ParserElement *));
	
	for(i=0;i<(*list).memberCount;i++)
	{
		(*list).members[i+1]=oldChildren[i];
	}

	(*list).members[0]=pointer;
	if((*list).memberCount>0)
	{
		free(oldChildren);
	}
	(*list).memberCount++;
	//


	return (int*)list;
}

int node(int a, char b, int c, char * d)
{
	//printf("\n a%s",d);
	if(b=='l' || b=='L')
	{
		printf("\n%d List %d \n",a,c);
		return 77;
	}
	else
	{
		printf("\n%d Node %d \n",a,c);
		printf("%s\n",d);

		return 33;
	}
}

void outputFile()
{
	FILE *file;
	file = fopen("file.c","w");
	fprintf(file,"%s","stuff");
	fclose(file);
}

int main()
{
	FILE *srcFile;
	int a=0;
	id=0;
	srcFile = fopen("src.qml","r");
	
    yyrestart(srcFile);
	//yy_scan_string("Rectangle { Rectangle { Rectangle { }; }; Rectangle { }; }");
	
	if(yyparse())
	{
		a=1;//eror
	}
	fclose(srcFile);

	return 0;
}