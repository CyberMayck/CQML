#include "gui.h"

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

	instance.MouseMoved=mGUI_Element_MouseMoved;
	instance.MousePressed=mGUI_Element_MousePressed;
	instance.MouseReleased=mGUI_Element_MouseReleased;
	instance.MouseScrolled=mGUI_Element_MouseScrolled;

	instance.CustomMouseClicked=0;
	instance.CustomMouseEntered=0;
	instance.CustomMouseExited=0;
	instance.CustomMouseMoved=0;
	instance.CustomMousePressed=0;
	instance.CustomMouseReleased=0;
	instance.CustomMouseScrolled=0;
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
	
	instance.base.MouseMoved=mGUI_Rectangle_MouseMoved;
	instance.base.MousePressed=mGUI_Rectangle_MousePressed;
	instance.base.MouseReleased=mGUI_Rectangle_MouseReleased;
	instance.base.MouseScrolled=mGUI_Rectangle_MouseScrolled;

	instance.color.red=1.0f;
	instance.color.green=1.0f;
	instance.color.blue=1.0f;

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

int mGUI_Element_MousePressed(GUI_Element *self,int x, int y, int button)
{
	int i;
	int processed=0;
	for(i=0;i<(*self).childrenCount;i++)
	{
		processed+=(*(*self).children[i]).MousePressed((*self).children[i],x,y,button);
	}
	return processed;
}

int mGUI_Element_MouseReleased(GUI_Element *self,int x, int y, int button)
{
	int i;
	int processed=0;
	for(i=0;i<(*self).childrenCount;i++)
	{
		processed+=(*(*self).children[i]).MouseReleased((*self).children[i],x,y,button);
	}
	return processed;
}

int mGUI_Element_MouseMoved(GUI_Element *self,int x, int y, int relx, int rely)
{
	int i;
	int processed=0;
	for(i=0;i<(*self).childrenCount;i++)
	{
		processed+=(*(*self).children[i]).MouseMoved((*self).children[i],x,y,relx,rely);
	}
	return processed;
}

int mGUI_Element_MouseScrolled(GUI_Element *self,int x, int y, int relx, int rely)
{
	int i;
	int processed=0;
	for(i=0;i<(*self).childrenCount;i++)
	{
		processed+=(*(*self).children[i]).MouseScrolled((*self).children[i],x,y,relx,rely);
	}
	return processed;
}

int mGUI_Element_Clicked(GUI_Element *self, int x, int y, int button)
{
	int i;
	int processed=0;
	for(i=0;i<(*self).childrenCount;i++)
	{
		//processed+=(*(*self).children[i]).Clicked((*self).children[i],x,y);
	}
	return processed;
}


int mGUI_Rectangle_Clicked(GUI_Element *self, int x, int y,int button)
{
	int x1,y1,w,h;
	GUI_Rectangle* me;
	
	int processed=mGUI_Element_Clicked(self,x,y,button);
	if(processed!=0)
		return processed;
	me=(GUI_Rectangle* )self;
	x1=mGUI_Element_Left(self);
	y1=mGUI_Element_Top(self);
	w=(*self).width;
	h=(*self).height;
	
	if(x1<x && x<x1+w && y1<y && y<y1+h)
	{
		if(self->CustomMouseClicked!=0)
			self->CustomMouseClicked(self, MakeEvent());
			//self->CustomMouseClicked(self,x,y,button);
		//me->color.r=1;
		//me->color.g=0;
		//me->color.b=0;
		return 1;
	}

	return 0;
}

GUI_Element * lastPressed;

void InitGUI()
{
	lastPressed=0;
}

int mGUI_Rectangle_MousePressed(GUI_Element *self,int x, int y, int button)
{
	int x1,y1,w,h;
	GUI_Rectangle* me;
	
	int processed=mGUI_Element_MousePressed(self,x,y,button);
	if(processed!=0)
		return processed;
	me=(GUI_Rectangle* )self;
	x1=mGUI_Element_Left(self);
	y1=mGUI_Element_Top(self);
	w=(*self).width;
	h=(*self).height;
	
	if(x1<x && x<x1+w && y1<y && y<y1+h)
	{
		lastPressed=self;
		if(self->CustomMousePressed!=0)
			self->CustomMousePressed(self, MakeEvent());
			//self->CustomMousePressed(self, x, y, button);
		return 1;
	}

	return 0;
}

int mGUI_Rectangle_MouseReleased(GUI_Element *self,int x, int y, int button)
{
	int x1,y1,w,h;
	GUI_Rectangle* me;
	
	int processed=mGUI_Element_MouseReleased(self,x,y,button);
	if(processed!=0)
		return processed;
	me=(GUI_Rectangle* )self;
	x1=mGUI_Element_Left(self);
	y1=mGUI_Element_Top(self);
	w=(*self).width;
	h=(*self).height;
	
	if(x1<x && x<x1+w && y1<y && y<y1+h)
	{
		if(self->CustomMouseReleased!=0)
			self->CustomMouseReleased(self, MakeEvent());
			//self->CustomMouseReleased(self, x, y, button);
		if(lastPressed==self && self->CustomMouseClicked!=0)
			self->CustomMouseClicked(self, MakeEvent());
			//self->CustomMouseClicked(self, x, y, button);
		return 1;
	}

	return 0;
}

int mGUI_Rectangle_MouseMoved(GUI_Element *self,int x, int y, int relx, int rely)
{
	int x1,y1,w,h;
	int xold, yold;
	GUI_Rectangle* me;
	int processed=mGUI_Element_MouseMoved(self,x,y,relx,rely);
	if(processed!=0)
		return processed;
	me=(GUI_Rectangle* )self;
	x1=mGUI_Element_Left(self);
	y1=mGUI_Element_Top(self);
	w=(*self).width;
	h=(*self).height;
	
	
	xold=x-relx;
	yold=y-rely;

	if(x1<x && x<x1+w && y1<y && y<y1+h)
	{
		if(self->CustomMouseEntered!=0)
		{
			if(!(x1<xold && xold<x1+w && y1<yold && yold<y1+h))
				self->CustomMouseEntered(self, MakeEvent());
				//self->CustomMouseEntered(self, x, y, relx, rely);
		}
		if(self->CustomMouseMoved!=0)
			self->CustomMouseMoved(self, MakeEvent());
			//self->CustomMouseMoved(self, x, y, relx, rely);
		//return 0;
	}
	else
	{
		if(self->CustomMouseExited!=0)
		{
			if(x1<xold && xold<x1+w && y1<yold && yold<y1+h)
				self->CustomMouseExited(self, MakeEvent());
				//self->CustomMouseExited(self, x, y, relx, rely);
		}
	}

	return 0;
}

int mGUI_Rectangle_MouseScrolled(GUI_Element *self,int x, int y, int relx, int rely)
{
	int x1,y1,w,h;
	GUI_Rectangle* me;
	int processed=mGUI_Element_MouseScrolled(self,x,y,relx,rely);
	if(processed!=0)
		return processed;
	me=(GUI_Rectangle* )self;
	x1=mGUI_Element_Left(self);
	y1=mGUI_Element_Top(self);
	w=(*self).width;
	h=(*self).height;
	
	if(x1<x && x<x1+w && y1<y && y<y1+h)
	{
		if(self->CustomMouseScrolled!=0)
			self->CustomMouseScrolled(self, MakeEvent());
			//self->CustomMouseScrolled(self, x, y, relx, rely);
		return 1;
	}

	return 0;
}


void mGUI_Rectangle_Draw(GUI_Element *self)
{
	int x,y,w,h;
	GUI_Rectangle* me=(GUI_Rectangle* )self;
	
#ifdef USESDL
	//SDL_Rect sdlRect;
#endif

	x=mGUI_Element_Left(self);
	y=mGUI_Element_Top(self);
	w=(*self).width;
	h=(*self).height;

	
	drawer->DrawRectangle(x,y,w,h,255,255,255);
	drawer->DrawFilledRectangle(x,y,w,h,me->color.red*255,me->color.green*255,me->color.blue*255);

	//cairo draw

	//printf("%d %d %d %d\n",x, y, w, h);
#ifdef USECAIRO
	//cairo_set_line_width (cr, 2);
	//cairo_set_source_rgb (cr, 0, 0, 0);
	//cairo_rectangle (cr, x, y, w, h);
	//cairo_stroke (cr);
#endif
#ifdef USESDL
	//sdlRect.x=x;
	//sdlRect.y=y;
	//sdlRect.w=w;
	//sdlRect.h=h;
	//SDL_RenderDrawRect(SDLRenderer, &sdlRect);
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