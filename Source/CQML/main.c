#define LIBCAIRO_EXPORTS
 
#include <cairo/cairo-win32.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct GUI_Element GUI_Element;
typedef struct GUI_Rectangle GUI_Rectangle;
typedef struct Color Color;
void mGUI_Element_Draw(GUI_Element *self);
void mGUI_Rectangle_Draw(GUI_Element *self);


cairo_surface_t *surface;
cairo_t *cr;

void CairoInit()
{
	
surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 480, 360);
cr = cairo_create (surface);
}

void CairoEnd()
{
cairo_destroy (cr);
cairo_surface_write_to_png(surface, "out.png");
cairo_surface_destroy(surface);
}

struct Color{
	float r;
	float g;
	float b;
	//float a;
};

struct GUI_Element {
	GUI_Element * parent;
	GUI_Element ** children;
	int childrenCount;

	int x;
	int y;
	int width;
	int height;
	//int (*Top)(GUI_Element *self);
	//int (*Left)(GUI_Element *self);
	void (*Draw)(GUI_Element *self);
};



struct GUI_Rectangle {
	GUI_Element base;
	int id;
	Color color;
};

GUI_Element cGUI_Element()
{
	GUI_Element instance;
	instance.children=0;
	instance.parent=0;
	instance.childrenCount=0;

	instance.x=0;
	instance.y=0;
	instance.width=0;
	instance.height=0;

	instance.Draw=mGUI_Element_Draw;
	return instance;
}

GUI_Element* acGUI_Element()
{
	GUI_Element * pointer=(GUI_Element*)malloc(sizeof(GUI_Element));
	*pointer=cGUI_Element();
	return pointer;
}


GUI_Rectangle cGUI_Rectangle()
{
	GUI_Rectangle instance;
	instance.base=cGUI_Element();
	instance.base.Draw=mGUI_Rectangle_Draw;

	return instance;
}

GUI_Rectangle* acGUI_Rectangle()
{
	GUI_Rectangle * pointer;
	pointer=(GUI_Rectangle*)malloc(sizeof(GUI_Rectangle));
	*pointer=cGUI_Rectangle();
	return pointer;
}

int mGUI_Element_Top(GUI_Element *self)
{
	if((*self).parent!=0)
	{
		return mGUI_Element_Top((*self).parent)+(*self).y;
	}
	return (*self).y;
}
int mGUI_Element_Left(GUI_Element *self)
{
	if((*self).parent!=0)
	{
		return mGUI_Element_Left((*self).parent)+(*self).x;
	}
	return (*self).x;
}

void mGUI_Element_Draw(GUI_Element *self)
{
	int i;
	printf("coord %d \n",(*self).x);


	
	/*for(i=0;i<(*self).childrenCount;i++)
	{
		(*(*self).children[i]).x=5+i*((*self).width-10)/((*self).childrenCount);
		(*(*self).children[i]).y=10;
		(*(*self).children[i]).width=((*self).width-10)/((*self).childrenCount);
		(*(*self).children[i]).height=(*self).height-20;
	}*/


	for(i=0;i<(*self).childrenCount;i++)
	{
		printf("kid %d: ",i);
		(*(*self).children[i]).Draw((*self).children[i]);
	}
	return;
}
void mGUI_Rectangle_Draw(GUI_Element *self)
{
	int x,y,w,h;
	x=mGUI_Element_Left(self);
	y=mGUI_Element_Top(self);
	w=(*self).width;
	h=(*self).height;

	//cairo draw

	printf("%d %d %d %d\n",x, y, w, h);
	
	cairo_set_line_width (cr, 2);
	cairo_set_source_rgb (cr, 0, 0, 0);
	cairo_rectangle (cr, x, y, w, h);
	cairo_stroke (cr);

	//draw kids
	mGUI_Element_Draw(self);
}

void mGUI_Element_InsertChild(GUI_Element *self,GUI_Element *child)
{
	GUI_Element ** oldChildren;
	int i;
	oldChildren=(*self).children;
	(*self).children=(GUI_Element **) malloc(((*self).childrenCount+1)*sizeof(GUI_Element *));
	
	for(i=0;i<(*self).childrenCount;i++)
	{
		(*self).children[i]=oldChildren[i];
		// nope comm
		//(*(*self).children[i]).y=5;
		//(*(*self).children[i]).x=5+i*((*self).width-10)/((*self).childrenCount+1);
		//(*(*self).children[i]).width=((*self).width-10)/((*self).childrenCount+1);
		//(*(*self).children[i]).height=(*self).height-10;
	}
	//(*child).y=5;
	//(*child).x=5+(*self).childrenCount*((*self).width-10)/((*self).childrenCount+1);
	//(*child).width=((*self).width-10)/((*self).childrenCount+1);
	//(*child).height=(*self).height-10;

	(*self).children[(*self).childrenCount]=child;
	(*child).parent=self;

	if((*self).childrenCount>0)
	{
		free(oldChildren);
	}
	(*self).childrenCount++;
}


GUI_Element* root;
GUI_Element* _QML_element1;
GUI_Element* _QML_element2;
GUI_Element* _QML_element3;
GUI_Element* _QML_element4;
GUI_Element* _QML_element5;
GUI_Element* _QML_element6;
GUI_Element* _QML_element7;
GUI_Element* _QML_element8;
GUI_Element* _QML_element9;
GUI_Element* _QML_element10;
GUI_Element* _QML_element11;
GUI_Element* _QML_element12;
GUI_Element* _QML_element13;
GUI_Element* _QML_element14;

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
_QML_element8 = (GUI_Element*)acGUI_Rectangle();
mGUI_Element_InsertChild((GUI_Element*)root, (GUI_Element*)_QML_element8);
_QML_element9 = (GUI_Element*)acGUI_Rectangle();
mGUI_Element_InsertChild((GUI_Element*)_QML_element8, (GUI_Element*)_QML_element9);
_QML_element10 = (GUI_Element*)acGUI_Rectangle();
mGUI_Element_InsertChild((GUI_Element*)_QML_element9, (GUI_Element*)_QML_element10);
_QML_element11 = (GUI_Element*)acGUI_Rectangle();
mGUI_Element_InsertChild((GUI_Element*)_QML_element8, (GUI_Element*)_QML_element11);
_QML_element12 = (GUI_Element*)acGUI_Rectangle();
mGUI_Element_InsertChild((GUI_Element*)_QML_element11, (GUI_Element*)_QML_element12);
_QML_element13 = (GUI_Element*)acGUI_Rectangle();
mGUI_Element_InsertChild((GUI_Element*)_QML_element11, (GUI_Element*)_QML_element13);
_QML_element14 = (GUI_Element*)acGUI_Rectangle();
mGUI_Element_InsertChild((GUI_Element*)_QML_element13, (GUI_Element*)_QML_element14);
}




int main()
{
	int baj;
	/*GUI_Element al;
	GUI_Rectangle rec;
	char buffer[100];
	int i;
	GUI_Rectangle * r01 = acGUI_Rectangle();
	GUI_Rectangle * r02 = acGUI_Rectangle();
	GUI_Rectangle * r03 = acGUI_Rectangle();

	GUI_Element * b=acGUI_Element();

	r01 = acGUI_Rectangle();
	r02 = acGUI_Rectangle();
	r03 = acGUI_Rectangle();
	(*r01).base.x=1;
	(*r01).base.y=1;
	(*r02).base.x=2;
	(*r02).base.y=2;
	(*r03).base.x=3;
	(*r03).base.y=3;
	mGUI_Element_InsertChild(b,(GUI_Element*)r01);
	mGUI_Element_InsertChild((GUI_Element*)r01,(GUI_Element*)r02);
	mGUI_Element_InsertChild((GUI_Element*)r01,(GUI_Element*)r03);
	(*b).Draw(b);*/

	CairoInit();
	_QML_Init();
	mGUI_Element_Draw((GUI_Element*)root);


	
//cairo_surface_t *surface;
//cairo_t *cr;
//surface = cairo_win32_surface_create (GetDC(NULL));

 
//cairo_select_font_face (cr, "serif", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
//cairo_set_font_size (cr, 32.0);
//cairo_set_source_rgb (cr, 1.0, 0.0, 0.0);
//cairo_move_to (cr, 10.0, 50.0);
//cairo_show_text (cr, "Hello, World");

	CairoEnd();

	//scanf("%d",&baj);
	return 0;
}

//bison cqml_grammar.g -o cqml_grammar.tab.c -d