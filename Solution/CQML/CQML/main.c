//#define USECAIRO
#define SET_FLAG(x,flag)	(x|flag)
#define UNSET_FLAG(x,flag)	(x&(~flag))
#define FLAG(x,flag)		(x&flag)


#define USESDL

#ifdef USECAIRO
#define LIBCAIRO_EXPORTS

#include <cairo/cairo-win32.h>
#endif

#ifdef USESDL
#include <SDL/SDL.h>
#include <SDL/SDL_TTF.h>
#endif

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "cqml.h"
#include "gui.h"
#include "draw_iface.h"



#ifdef USESDL
//SDL_Surface*    Surf_Display;
SDL_Window*  SDLWindow;
SDL_Renderer* SDLRenderer;
TTF_Font *fntCourier;
SDL_Texture *strTex;

void SDLInit()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	//SDL_CreateWindow("CQML SDL TEST", 5, 5, 800, 600,SDL_WINDOW_OPENGL);
	SDL_CreateWindowAndRenderer(800, 600,SDL_WINDOW_OPENGL,&SDLWindow,&SDLRenderer);

	TTF_Init();
	fntCourier = TTF_OpenFont( "C64.ttf", 12 );
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






void DrawRectangle(int x,int y,int w,int h,float r, float g, float b)
{
#ifdef USESDL
	SDL_Rect sdlRect;
#endif
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
	
	SDL_SetRenderDrawColor(SDLRenderer,r,g,b,255);
	SDL_RenderDrawRect(SDLRenderer, &sdlRect);
#endif
}


void DrawRectangleFilled(int x,int y,int w,int h,float r, float g, float b)
{
#ifdef USESDL
	SDL_Rect sdlRect;
#endif
#ifdef USESDL
	sdlRect.x=x;
	sdlRect.y=y;
	sdlRect.w=w;
	sdlRect.h=h;
	
	SDL_SetRenderDrawColor(SDLRenderer,r,g,b,255);
	SDL_RenderFillRect(SDLRenderer, &sdlRect);
#endif
}


#ifdef USESDL
void InitSDLDrawer()
{
	DrawIFace * drawer=(DrawIFace * )malloc(sizeof(DrawIFace));
	drawer->DrawRectangle=DrawRectangle;
	drawer->DrawFilledRectangle=DrawRectangleFilled;
	SetDrawIFace(drawer);
}
#endif

//GUI_Element ** drawQueue;
//GUI_Element ** updateQueue;
GUI_Element ** allElements;
int allElementCount;
int * drawQueue;
int * updateQueue;

void Update();
void Redraw();
int InputHandling();

#include<time.h>

clock_t prevTime;
clock_t t;
float timey;
int fps;

void PrintMeMyFriend(char * str)
{
	printf("Print: %s\n",str);
}

#include "parser_output.c"

void GUIMainLoop()
{
	int quit;

	t=clock();
	fps=0;
	quit=0;
	while(quit==0)
	{
		quit=InputHandling();
		//printf("quit %d\n",quit);
		Update();

		Redraw();

		timey=timey*0.95+0.05*(((float)(t-prevTime))/CLOCKS_PER_SEC);
		fps=1/timey;
		prevTime=t;
		t=clock();

	}
}

int InputHandling()
{
	SDL_Event sdlEvent;
	//SDL_WaitEvent(&sdlEvent);
	while (SDL_PollEvent(&sdlEvent)) {
	switch (sdlEvent.type)
	{
		case SDL_QUIT:
			return 1;
			break;
		case SDL_KEYDOWN:
			printf("pressed %c\n",sdlEvent.key.keysym.sym);
			break;
		case SDL_MOUSEBUTTONDOWN:
			printf("mouse click %d %d\n",sdlEvent.button.x,sdlEvent.button.y);
			root->MousePressed(root,sdlEvent.button.x,sdlEvent.button.y,sdlEvent.button.button);
			break;
//			
		case SDL_MOUSEBUTTONUP:
			root->MouseReleased(root,sdlEvent.button.x,sdlEvent.button.y,sdlEvent.button.button);
			break;
		case SDL_MOUSEMOTION:
			root->MouseMoved(root,sdlEvent.motion.x,sdlEvent.motion.y,sdlEvent.motion.xrel,sdlEvent.motion.yrel);
			break;
		case SDL_MOUSEWHEEL:
			root->MouseScrolled(root,sdlEvent.wheel.x,sdlEvent.wheel.y,sdlEvent.wheel.x,sdlEvent.wheel.y);
			break;
	}
	}
	return 0;
}

void Update()
{
	int i;
	_QML_Update();
	for(i=0;i<allElementCount;i++)
	{
		//allElements[i]->Update(allElements[i]);
	}
}


// parser output stuff

void Redraw()
{
	/*int i;
	for(i=0;i<allElementCount;i++)
	{
		allElements[i]->Draw(allElements[i]);
	}*/

	SDL_Surface *sText;
	SDL_Color clrFg = {255,255,255,0};
	SDL_Rect sdlRect = {700,0,100,100};
	char fpsStr[100];

		SDL_SetRenderDrawColor(SDLRenderer,0,0,0,255);
		SDL_RenderClear(SDLRenderer);

		mGUI_Element_Draw((GUI_Element*)root);


		sprintf(fpsStr,"%d",fps);
		sText = TTF_RenderText_Solid( fntCourier, fpsStr, clrFg );
		strTex=SDL_CreateTextureFromSurface(SDLRenderer, sText);
		SDL_FreeSurface(sText);
		SDL_RenderCopy(SDLRenderer, strTex, NULL, &sdlRect);

		SDL_RenderPresent(SDLRenderer);
}

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
	InitQML();
	_QML_Init();
	InitSDLDrawer();
	//mGUI_Element_Draw((GUI_Element*)root);

	GUIMainLoop();
#ifdef USESDL
	while(quit==0 && quit==1)
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
