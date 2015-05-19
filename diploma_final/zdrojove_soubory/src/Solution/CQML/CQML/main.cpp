#include "SDL/SDL.h"
#undef main
#include "SDL/SDL_TTF.h"
#include "SDL/SDL_image.h"


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "qml_includes.h"
#include "parser_output.h"




SDL_Window*  SDLWindow;
SDL_Renderer* SDLRenderer;
TTF_Font *fntCourier;
SDL_Texture *strTex;




/**
 * Initializes SDL
 * 
 *
 * @param 
 */
void SDLInit()
{
	SDL_Init(SDL_INIT_EVERYTHING);


	TTF_Init();
	int flags=IMG_INIT_JPG|IMG_INIT_PNG|IMG_INIT_TIF;
	int initted=IMG_Init(flags);
	if((initted&flags) != flags) {
		printf("IMG_Init: Failed to init required jpg and png and tif support!\n");
		printf("IMG_Init: %s\n", IMG_GetError());
	}

}


/**
 * Resource managing interface.
 */
struct SDLResourceManager
	: ResourceManagerIface
{
	
/**
 * Loads font.
 */
	virtual void* LoadFont(const char * fontStr, int fontSize)
	{
		TTF_Font *fnt = TTF_OpenFont( fontStr, fontSize );
		if(!fnt)
			printf("TTF_OpenFont: %s\n", TTF_GetError());
		return fnt;
	}
	
/**
 * Loads image data.
 */
	virtual ImageData LoadImage(const char *  path)
	{
		SDL_Surface *image;
		string strPath=path;
		ImageData data;
		image=IMG_Load(path);
		if(!image)
		{
			printf("IMG_Load: %s\n", IMG_GetError());
			// handle error
			data.img=0;
			data.width=0;
			data.height=0;
		}
		else
		{
			data.img=image;
			data.width=image->w;
			data.height=image->h;
		}
		return data;
	}
};

/**
 * Drawing Interface
 */
struct SDLDrawer
	: DrawIFace
{
/**
 * Draws rectangle.
 */
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
/**
 * Draws filled rectangle.
 */
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
/**
 * Draws rectangle with border.
 */
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
	
/**
 * Draws text.
 */
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
		
		if(font==0)
			return;
		TTF_Font *fnt=(TTF_Font *)font;
		if(!font)
			return;
		sText = TTF_RenderText_Solid( fnt, text, clrFg );
		strTex=SDL_CreateTextureFromSurface(SDLRenderer, sText);
		SDL_QueryTexture(strTex, 0, 0, &sdlRect.w, &sdlRect.h);
		SDL_RenderCopy(SDLRenderer, strTex, NULL, &sdlRect);
		

		SDL_FreeSurface(sText);
		SDL_RenderCopy(SDLRenderer, strTex, NULL, &sdlRect);
		SDL_DestroyTexture(strTex);
	}
/**
 * Draws Image.
 */
	void DrawImage(int x, int y, int w, int h, void* image)
	{
		SDL_Rect sdlRect;
		if(image==0)
			return;
		SDL_Surface * imgSurf = (SDL_Surface *)image;
		SDL_Texture * imgTex=SDL_CreateTextureFromSurface(SDLRenderer, imgSurf);
		sdlRect.x=x;
		sdlRect.y=y;
		sdlRect.w=w;
		sdlRect.h=h;
		
		SDL_RenderCopy(SDLRenderer, imgTex, NULL, &sdlRect);
		SDL_DestroyTexture(imgTex);
	}
/**
 * Draws segment of an image.
 */
	virtual void DrawImageSegment(int x, int y, int w, int h, void* image, int iX, int iY, int iW, int iH)
	{
		SDL_Rect sdlRect;
		SDL_Rect sdlSrcRect;
		if(image==0)
			return;
		SDL_Surface * imgSurf = (SDL_Surface *)image;
		SDL_Texture * imgTex=SDL_CreateTextureFromSurface(SDLRenderer, imgSurf);

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

/**
 * Initializes and sets SDL drawing interface.
 */
void InitSDLDrawer()
{
	DrawIFace * drawer=new SDLDrawer();
	SetDrawIFace(drawer);
}

/**
 * Initializes and sets resource management interface.
 */
void InitSDLResourceManager()
{
	ResourceManagerIface * man= new SDLResourceManager();
	SetResourceManager(man);
}

void Update();
void Redraw();
int InputHandling();

#include<time.h>

clock_t prevTime;
clock_t t;
float timey;
int fps;


/**
 * Main loop.
 * Runs main gui loop and calls update and draw functions.
 */
void GUIMainLoop()
{
	int quit;

	t=clock();
	fps=0;
	quit=0;
	while(quit==0)
	{
		quit=InputHandling();
		Update();

		Redraw();

		timey=timey*0.95+0.05*(((float)(t-prevTime))/CLOCKS_PER_SEC);
		fps=1/timey;
		prevTime=t;
		t=clock();
		
		//cout << fps << "fps" << endl;
	}
}

/**
 * Input handling function.
 * Processes use input.
 *
 * @return 1 if application is supposed quit. 0 otherwise
 */
int InputHandling()
{
	SDL_Event sdlEvent;
	CQMLGUI::CQMLEvent qmlEvent;

	while (SDL_PollEvent(&sdlEvent)) {
	switch (sdlEvent.type)
	{
		case SDL_QUIT:
			return 1;
			break;
		case SDL_KEYDOWN:
			qmlEvent.EventType=CQML_KEY_EVENT;
			qmlEvent.keyEvent.action=KEY_PRESSED;
			qmlEvent.keyEvent.key=sdlEvent.key.keysym.sym;
			CQMLGUI::PushEvent(qmlEvent);

			break;
		case SDL_KEYUP:
			qmlEvent.EventType=CQML_KEY_EVENT;
			qmlEvent.keyEvent.action=KEY_RELEASED;
			qmlEvent.keyEvent.key=sdlEvent.key.keysym.sym;
			CQMLGUI::PushEvent(qmlEvent);

			break;
		case SDL_MOUSEBUTTONDOWN:
			qmlEvent.EventType=CQML_MOUSE_EVENT;
			qmlEvent.mouseEvent.action=MOUSE_BUTTON_PRESSED;
			qmlEvent.mouseEvent.button=sdlEvent.button.button;
			qmlEvent.mouseEvent.x=sdlEvent.button.x;
			qmlEvent.mouseEvent.y=sdlEvent.button.y;
			CQMLGUI::PushEvent(qmlEvent);
			
			break;
		case SDL_MOUSEBUTTONUP:
			qmlEvent.EventType=CQML_MOUSE_EVENT;
			qmlEvent.mouseEvent.action=MOUSE_BUTTON_RELEASED;
			qmlEvent.mouseEvent.button=sdlEvent.button.button;
			qmlEvent.mouseEvent.x=sdlEvent.button.x;
			qmlEvent.mouseEvent.y=sdlEvent.button.y;
			CQMLGUI::PushEvent(qmlEvent);

			break;
		case SDL_MOUSEMOTION:
			qmlEvent.EventType=CQML_MOUSE_EVENT;
			qmlEvent.mouseEvent.action=MOUSE_MOVEMENT;
			qmlEvent.mouseEvent.x=sdlEvent.motion.x;
			qmlEvent.mouseEvent.y=sdlEvent.motion.y;
			qmlEvent.mouseEvent.relativeX=sdlEvent.motion.xrel;
			qmlEvent.mouseEvent.relativeY=sdlEvent.motion.yrel;
			CQMLGUI::PushEvent(qmlEvent);

			break;
		case SDL_MOUSEWHEEL:
			qmlEvent.EventType=CQML_MOUSE_EVENT;
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

/**
 * Update.
 * Calls GUI update function.
 */
void Update()
{
	_CQML_Update();

}

/**
 * Redraw.
 * Draws GUI.
 */
void Redraw()
{
		SDL_SetRenderDrawColor(SDLRenderer,0,0,0,255);
		SDL_RenderClear(SDLRenderer);

		_CQML_Draw();

		SDL_Rect sdlRect;
		sdlRect.x=10;
		sdlRect.y=10;
		sdlRect.w=100;
		sdlRect.h=100;

		SDL_Surface *sText;
		SDL_Color clrFg = {1*255,1*255,0*255,0};



		SDL_RenderPresent(SDLRenderer);
}

/**
 * Main function.
 * Initializes libraries and calls main loop.
 *
 * @return returns 0
 */
int main()
{
	int quit=0;
	
	SDLInit();

	_CQML_Init();
	InitSDLDrawer();
	InitSDLResourceManager();
	_CQML_Start();

	int w;
	int h;
	CQMLGUI::GetCQMLWindow(w,h);

	SDL_Event sdlEvent;
	SDL_CreateWindowAndRenderer(w, h,SDL_WINDOW_OPENGL,&SDLWindow,&SDLRenderer);

	if(SDLWindow==NULL || SDLRenderer==NULL)
		return 0;

	GUIMainLoop();;
	
    SDL_DestroyRenderer(SDLRenderer);
    SDL_DestroyWindow(SDLWindow);

	IMG_Quit();
    SDL_Quit();

	return 0;
}
