//#define USECAIRO
#define USESDL

#ifdef USECAIRO
#define LIBCAIRO_EXPORTS

#include <cairo/cairo-win32.h>
#endif

#ifdef USESDL
#include <SDL/SDL.h>
#endif

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct GUI_Element GUI_Element;
typedef struct GUI_Rectangle GUI_Rectangle;
typedef struct Color Color;
void mGUI_Element_Draw(GUI_Element *self);
void mGUI_Rectangle_Draw(GUI_Element *self);


#ifdef USESDL
//SDL_Surface*    Surf_Display;
SDL_Window*  SDLWindow;
SDL_Renderer* SDLRenderer;

void SDLInit()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	//SDL_CreateWindow("CQML SDL TEST", 5, 5, 800, 600,SDL_WINDOW_OPENGL);
	SDL_CreateWindowAndRenderer(800, 600,SDL_WINDOW_OPENGL,&SDLWindow,&SDLRenderer);


	//Surf_Display = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
}
#endif

#ifdef USECAIRO
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
#endif

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
	//printf("coord %d \n",(*self).x);


	for(i=0;i<(*self).childrenCount;i++)
	{
		//printf("kid %d: ",i);
		(*(*self).children[i]).Draw((*self).children[i]);
	}
	return;
}
void mGUI_Rectangle_Draw(GUI_Element *self)
{
	int x,y,w,h;
	
#ifdef USESDL
	SDL_Rect sdlRect;
#endif

	x=mGUI_Element_Left(self);
	y=mGUI_Element_Top(self);
	w=(*self).width;
	h=(*self).height;


	//cairo draw

	//printf("%d %d %d %d\n",x, y, w, h);
#ifdef USECAIRO
	cairo_set_line_width (cr, 2);
	cairo_set_source_rgb (cr, 0, 0, 0);
	cairo_rectangle (cr, x, y, w, h);
	cairo_stroke (cr);
#endif
#ifdef USESDL
	sdlRect.x=x;
	sdlRect.y=y;
	sdlRect.w=w;
	sdlRect.h=h;
	SDL_RenderDrawRect(SDLRenderer, &sdlRect);
#endif


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
	}

	(*self).children[(*self).childrenCount]=child;
	(*child).parent=self;

	if((*self).childrenCount>0)
	{
		free(oldChildren);
	}
	(*self).childrenCount++;
}

// parser output stuff
#include "parser_output.c"

int main()
{
	int quit=0;
#ifdef USECAIRO
	CairoInit();
#endif
#ifdef USESDL
	SDL_Event sdlEvent;
	SDLInit();
	//SDL_RenderFillRect(SDLRenderer,NULL);
	if(SDLWindow==NULL || SDLRenderer==NULL)
		return 0;
#endif
	_QML_Init();
	//mGUI_Element_Draw((GUI_Element*)root);

	
#ifdef USESDL
	while(quit==0)
	{
		SDL_WaitEvent(&sdlEvent);
		switch (sdlEvent.type)
		{
		case SDL_QUIT:
			quit=1;
			break;
		case SDL_KEYDOWN:
			printf("pressed %c\n",sdlEvent.key.keysym.sym);
			break;
		case SDL_MOUSEBUTTONDOWN:
			printf("mouse click %d %d\n",sdlEvent.button.x,sdlEvent.button.y);
			break;
		}
		SDL_SetRenderDrawColor(SDLRenderer,255,0,0,255);
		SDL_RenderClear(SDLRenderer);
		SDL_SetRenderDrawColor(SDLRenderer,0,0,0,255);
		mGUI_Element_Draw((GUI_Element*)root);
		SDL_RenderPresent(SDLRenderer);
	}
	//SDL_Delay(3000);
	
    SDL_DestroyRenderer(SDLRenderer);
    SDL_DestroyWindow(SDLWindow);

    SDL_Quit();
#endif

	
#ifdef USECAIRO
	CairoEnd();
#endif


	return 0;
}
