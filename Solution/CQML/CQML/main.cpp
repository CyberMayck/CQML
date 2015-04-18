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
#undef main
#include <SDL/SDL_TTF.h>
#include <SDL/SDL_image.h>
#endif

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#include "../CQML_DLL/cqml.h"
#include "../CQML_DLL/gui.h"
#include "../CQML_DLL/draw_iface.h"
#include "../CQML_DLL/qml_includes.h"
#include "../CQML_DLL/resource_manager.h"
#include "../CQML_DLL/resource_manager.h"
#include "parser_output.h"



#ifdef USESDL
//SDL_Surface*    Surf_Display;
SDL_Window*  SDLWindow;
SDL_Renderer* SDLRenderer;
TTF_Font *fntCourier;
SDL_Texture *strTex;


struct SDL_Drawer
	: DrawIFace
{

};




void SDLInit(int w, int h)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	//SDL_CreateWindow("CQML SDL TEST", 5, 5, 800, 600,SDL_WINDOW_OPENGL);

	TTF_Init();
	int flags=IMG_INIT_JPG|IMG_INIT_PNG|IMG_INIT_TIF;
	int initted=IMG_Init(flags);
	if((initted&flags) != flags) {
		printf("IMG_Init: Failed to init required jpg and png and tif support!\n");
		printf("IMG_Init: %s\n", IMG_GetError());
	}
	//fntCourier = TTF_OpenFont( "c64.ttf", 12 );
	//FILE* f= fopen("c64.ttf","r");

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

struct SDLResourceManager
	: ResourceManagerIface
{
	virtual void* LoadFont(const char * fontStr, int fontSize)
	{
		TTF_Font *fnt = TTF_OpenFont( (string(fontStr)+".ttf").c_str(), fontSize );
		//printf("TTF_OpenFont: %s\n", TTF_GetError());
		return fnt;
	}
	virtual ImageData LoadImage(const char *  path)
	{
		SDL_Surface *image;
		string strPath=path;
		//int i=strPath.length()-1;
		//for(;i>=0;i--)
		{
		//	if(strPath[i]=='.');
		}
		image=IMG_Load(path);
		if(!image)
		{
			printf("IMG_Load: %s\n", IMG_GetError());
			// handle error
		}
		ImageData data;
		data.img=image;
		data.width=image->w;
		data.height=image->h;
		return data;
	}
};
struct SDLDrawer
	: DrawIFace
{
	virtual void DrawRectangle(int x,int y,int w,int h,float r, float g, float b)
	{
		SDL_Rect sdlRect;
		sdlRect.x=x;
		sdlRect.y=y;
		sdlRect.w=w;
		sdlRect.h=h;
	
		SDL_SetRenderDrawColor(SDLRenderer,r,g,b,255);
		SDL_RenderDrawRect(SDLRenderer, &sdlRect);
	}
	virtual void DrawFilledRectangle(int x,int y,int w,int h,float r, float g, float b)
	{
		SDL_Rect sdlRect;
		sdlRect.x=x;
		sdlRect.y=y;
		sdlRect.w=w;
		sdlRect.h=h;
	
		SDL_SetRenderDrawColor(SDLRenderer,r,g,b,255);
		SDL_RenderFillRect(SDLRenderer, &sdlRect);
	}
	virtual void DrawFilledBorderedRectangle(int x,int y,int w,int h,float r, float g, float b, float border, float br, float bg, float bb)
	{
		SDL_Rect sdlRect;
		sdlRect.x=x;
		sdlRect.y=y;
		sdlRect.w=w;
		sdlRect.h=h;
	
		SDL_SetRenderDrawColor(SDLRenderer,br,bg,bb,255);
		SDL_RenderFillRect(SDLRenderer, &sdlRect);
		
		sdlRect.x+=border;
		sdlRect.y+=border;
		sdlRect.w-=2*border;
		sdlRect.h-=2*border;
		SDL_SetRenderDrawColor(SDLRenderer,r,g,b,255);
		SDL_RenderFillRect(SDLRenderer, &sdlRect);
	}
	virtual void DrawLine(int x1,int y1,int x2,int y2,float r, float g, float b){}
	virtual void DrawPoint(int x,int y,float r, float g, float b){}
	virtual void DrawArc(int x,int y,int w,int h, float angle1, float angle2, float r, float g, float b){}
	virtual void DrawFilledArc(int x,int y,int w,int h, float angle1, float angle2, float r, float g, float b){}

	virtual void DrawText(int x, int y, int w, int h, const char* text, void* font, float r, float g, float b)
	{

		SDL_Rect sdlRect;
		sdlRect.x=x;
		sdlRect.y=y;
		sdlRect.w=w;
		sdlRect.h=h;

		SDL_Surface *sText;
		SDL_Texture * strTex;
		SDL_Color clrFg = {r*255,g*255,b*255,0};
		
		TTF_Font *fnt=(TTF_Font *)font;
		if(!font)
			return;
		sText = TTF_RenderText_Solid( fnt, text, clrFg );
		strTex=SDL_CreateTextureFromSurface(SDLRenderer, sText);
		SDL_QueryTexture(strTex, 0, 0, &sdlRect.w, &sdlRect.h);
		SDL_RenderCopy(SDLRenderer, strTex, NULL, &sdlRect);
		
		//printf("TTF_OpenFont: %s\n", TTF_GetError());
		SDL_FreeSurface(sText);
		SDL_RenderCopy(SDLRenderer, strTex, NULL, &sdlRect);
		SDL_DestroyTexture(strTex);
	}
	void DrawImage(int x, int y, int w, int h, void* image)
	{
		SDL_Rect sdlRect;
		SDL_Surface * imgSurf = (SDL_Surface *)image;
		SDL_Texture * imgTex=SDL_CreateTextureFromSurface(SDLRenderer, imgSurf);
		sdlRect.x=x;
		sdlRect.y=y;
		sdlRect.w=w;
		sdlRect.h=h;
		
		SDL_RenderCopy(SDLRenderer, imgTex, NULL, &sdlRect);
		SDL_DestroyTexture(imgTex);
	}
	virtual void DrawImageSegment(int x, int y, int w, int h, void* image, int iX, int iY, int iW, int iH)
	{
		SDL_Rect sdlRect;
		SDL_Rect sdlSrcRect;
		SDL_Surface * imgSurf = (SDL_Surface *)image;
		SDL_Texture * imgTex=SDL_CreateTextureFromSurface(SDLRenderer, imgSurf);
		//std::cout << SDL_GetError() << endl;;
		sdlRect.x=x;
		sdlRect.y=y;
		sdlRect.w=w;
		sdlRect.h=h;
		sdlSrcRect.x=iX;
		sdlSrcRect.y=iY;
		sdlSrcRect.w=iW;
		sdlSrcRect.h=iH;
		
		SDL_RenderCopy(SDLRenderer, imgTex, &sdlSrcRect, &sdlRect);
		SDL_DestroyTexture(imgTex);
	}
};

void InitSDLDrawer()
{
	DrawIFace * drawer=new SDLDrawer();
//	drawer->DrawRectangle=DrawRectangle;
//	drawer->DrawFilledRectangle=DrawRectangleFilled;
	SetDrawIFace(drawer);
}

void InitSDLResourceManager()
{
	ResourceManagerIface * man= new SDLResourceManager();
	SetResourceManager(man);
}

#endif

//GUI_Element ** drawQueue;
//GUI_Element ** updateQueue;
CQMLGUI::Element ** allElements;
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
	printf("%d fps\n",fps);

	}
}

int InputHandling()
{
	SDL_Event sdlEvent;
	CQMLGUI::QMLEvent qmlEvent;

	while (SDL_PollEvent(&sdlEvent)) {
	switch (sdlEvent.type)
	{
		case SDL_QUIT:
			return 1;
			break;
		case SDL_KEYDOWN:
			qmlEvent.EventType=QML_KEY_EVENT;
			qmlEvent.keyEvent.action=KEY_PRESSED;
			qmlEvent.keyEvent.key=sdlEvent.key.keysym.sym;
			CQMLGUI::PushEvent(qmlEvent);

			break;
		case SDL_KEYUP:
			qmlEvent.EventType=QML_KEY_EVENT;
			qmlEvent.keyEvent.action=KEY_RELEASED;
			qmlEvent.keyEvent.key=sdlEvent.key.keysym.sym;
			CQMLGUI::PushEvent(qmlEvent);

			break;
		case SDL_MOUSEBUTTONDOWN:
			qmlEvent.EventType=QML_MOUSE_EVENT;
			qmlEvent.mouseEvent.action=MOUSE_BUTTON_PRESSED;
			qmlEvent.mouseEvent.button=sdlEvent.button.button;
			qmlEvent.mouseEvent.x=sdlEvent.button.x;
			qmlEvent.mouseEvent.y=sdlEvent.button.y;
			CQMLGUI::PushEvent(qmlEvent);
			
			break;
		case SDL_MOUSEBUTTONUP:
			qmlEvent.EventType=QML_MOUSE_EVENT;
			qmlEvent.mouseEvent.action=MOUSE_BUTTON_RELEASED;
			qmlEvent.mouseEvent.button=sdlEvent.button.button;
			qmlEvent.mouseEvent.x=sdlEvent.button.x;
			qmlEvent.mouseEvent.y=sdlEvent.button.y;
			CQMLGUI::PushEvent(qmlEvent);

			break;
		case SDL_MOUSEMOTION:
			qmlEvent.EventType=QML_MOUSE_EVENT;
			qmlEvent.mouseEvent.action=MOUSE_MOVEMENT;
			qmlEvent.mouseEvent.x=sdlEvent.motion.x;
			qmlEvent.mouseEvent.y=sdlEvent.motion.y;
			qmlEvent.mouseEvent.relativeX=sdlEvent.motion.xrel;
			qmlEvent.mouseEvent.relativeY=sdlEvent.motion.yrel;
			CQMLGUI::PushEvent(qmlEvent);

			break;
		case SDL_MOUSEWHEEL:
			qmlEvent.EventType=QML_MOUSE_EVENT;
			qmlEvent.mouseEvent.action=MOUSE_WHEEL_SCROLLED;
			qmlEvent.mouseEvent.x=sdlEvent.wheel.x;
			qmlEvent.mouseEvent.y=sdlEvent.wheel.y;
			qmlEvent.mouseEvent.relativeX=sdlEvent.wheel.x;
			qmlEvent.mouseEvent.relativeY=sdlEvent.wheel.y;
			CQMLGUI::PushEvent(qmlEvent);
			
			break;
	}
	}
	return 0;
}

void Update()
{
	_QML_Update();

}

void Redraw()
{

		SDL_SetRenderDrawColor(SDLRenderer,0,0,0,255);
		SDL_RenderClear(SDLRenderer);

		_QML_Draw();

		SDL_Rect sdlRect;
		sdlRect.x=10;
		sdlRect.y=10;
		sdlRect.w=100;
		sdlRect.h=100;

		SDL_Surface *sText;
		SDL_Color clrFg = {1*255,1*255,0*255,0};



		SDL_RenderPresent(SDLRenderer);
}

int main()
{
	int quit=0;
#ifdef USECAIRO
	CairoInit();
#endif
	
	SDLInit(0,0);

	_QML_Init();
	InitSDLDrawer();
	InitSDLResourceManager();
	_QML_Start();

	int w;
	int h;
	CQMLGUI::GetQMLWindow(w,h);

#ifdef USESDL
	SDL_Event sdlEvent;
	SDL_CreateWindowAndRenderer(w, h,SDL_WINDOW_OPENGL,&SDLWindow,&SDLRenderer);

	//SDL_RenderFillRect(SDLRenderer,NULL);
	if(SDLWindow==NULL || SDLRenderer==NULL)
		return 0;
#endif

	GUIMainLoop();
#ifdef USESDL
	/*while(quit==0)
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
			root->MousePressed(sdlEvent.button.x,sdlEvent.button.y,1);
			printf("mouse click %d %d\n",sdlEvent.button.x,sdlEvent.button.y);
			break;
		case SDL_MOUSEBUTTONUP:
			root->MouseReleased(sdlEvent.button.x,sdlEvent.button.y,1);
			printf("mouse click %d %d\n",sdlEvent.button.x,sdlEvent.button.y);
			break;

		}
		SDL_SetRenderDrawColor(SDLRenderer,255,0,0,255);
		SDL_RenderClear(SDLRenderer);
		SDL_SetRenderDrawColor(SDLRenderer,0,0,0,255);
		root->Draw();
		//CQMLGUI::mGUI_Element_Draw((CQMLGUI::Element*)root);
		SDL_RenderPresent(SDLRenderer);
	}*/
	//SDL_Delay(3000);
	
    SDL_DestroyRenderer(SDLRenderer);
    SDL_DestroyWindow(SDLWindow);

	IMG_Quit();
    SDL_Quit();
#endif

#ifdef USECAIRO
	CairoEnd();
#endif

	//_CrtDumpMemoryLeaks();
	//getchar();
	return 0;
}
