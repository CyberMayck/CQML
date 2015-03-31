#include "gui.h"
#include "resource_manager.h"



CQMLGUI::Element * focused;
CQMLGUI::Element * lastPressed;


namespace CQMLGUI
{
	/*
Element::Element()
{
	classID=2;
	children=0;
	parent=0;
	childrenCount=0;

	x=0;
	y=0;
	width=0;
	height=0;

	//instance.Draw=mGUI_Element_Draw;
	//instance.Update=mGUI_Element_Update;

	//instance.MouseMoved=mGUI_Element_MouseMoved;
	//instance.MousePressed=mGUI_Element_MousePressed;
	//instance.MouseReleased=mGUI_Element_MouseReleased;
	//instance.MouseScrolled=mGUI_Element_MouseScrolled;

	CustomMouseClicked=0;
	CustomMouseEntered=0;
	CustomMouseExited=0;
	CustomMouseMoved=0;
	CustomMousePressed=0;
	CustomMouseReleased=0;
	CustomMouseScrolled=0;
	//return instance;
}*/

Element* acElement()
{
	Element * a;
	return new Element();
}
Text* acText()
{
	Text * t=new Text();
	//Element * e=t;
	//e->Draw();
	return t;
}

/*
Color::Color()
{
	red=0;
	red_Update=0;
	green=0;
	green_Update=0;
	blue=0;
	blue_Update=0;
}*/

/*
Rectangle::Rectangle()
{
	//Rectangle instance;
	//instance.base=cGUI_Element();
	//instance.Draw=mGUI_Rectangle_Draw;
	
	//instance.MouseMoved=mGUI_Rectangle_MouseMoved;
	//instance.MousePressed=mGUI_Rectangle_MousePressed;
	//instance.MouseReleased=mGUI_Rectangle_MouseReleased;
	//instance.MouseScrolled=mGUI_Rectangle_MouseScrolled;
	
	this->color_Update=0;
	//color.red=1.0f;
	//color.green=1.0f;
	//color.blue=1.0f;

	//return instance;
}*/

Rectangle* acRectangle()
{
	return new Rectangle();
}

int Element::Top()
{
	if(parent!=0)
	{
		return parent->Top()+y;
	}
	return y;
}

int Element::Left()
{
	if(parent!=0)
	{
		return parent->Left()+x;
	}
	return x;
}


void Element::Update()
{
	int i;
	//printf("coord %d \n",(*self).x);


	for(i=0;i<childrenCount;i++)
	{
		children[i]->Update();
	}
	return;
}

void Element::Draw()
{
	int i;
	//printf("coord %d \n",(*self).x);


	for(i=0;i<childrenCount;i++)
	{
		//printf("kid %d: ",i);
		children[i]->Draw();
	}
	return;
}

int Element::MousePressed(int x, int y, int button)
{
	int i;
	int processed=0;
	for(i=0;i<childrenCount;i++)
	{
		processed+=children[i]->MousePressed(x,y,button);
	}
	return processed;
}

int Element::MouseReleased(int x, int y, int button)
{
	int i;
	int processed=0;
	for(i=0;i<childrenCount;i++)
	{
		processed+=children[i]->MouseReleased(x,y,button);
	}
	return processed;
}

int Element::MouseMoved(int x, int y, int relx, int rely)
{
	int i;
	int processed=0;
	for(i=0;i<childrenCount;i++)
	{
		processed+=children[i]->MouseMoved(x,y,relx,rely);
	}
	return processed;
}

int Element::MouseScrolled(int x, int y, int relx, int rely)
{
	int i;
	int processed=0;
	for(i=0;i<childrenCount;i++)
	{
		processed+=children[i]->MouseScrolled(x,y,relx,rely);
	}
	return processed;
}

int Element::MouseClicked(int x, int y, int button)
{
	int i;
	int processed=0;
	for(i=0;i<childrenCount;i++)
	{
		//processed+=(*(*self).children[i]).Clicked((*self).children[i],x,y);
	}
	return processed;
}


int Rectangle::MouseClicked(int x, int y,int button)
{
	int x1,y1,w,h;
	Rectangle* me;
	
	int processed=Element::MouseClicked(x,y,button);
	if(processed!=0)
		return processed;
	me=(Rectangle* )this;
	x1=Left();
	y1=Top();
	w=width;
	h=height;
	
	if(x1<x && x<x1+w && y1<y && y<y1+h)
	{
		if(CustomMouseClicked!=0)
			CustomMouseClicked(&this->CustomMouseClicked_context, MakeEvent());
			//self->CustomMouseClicked(self,x,y,button);
		//me->color.r=1;
		//me->color.g=0;
		//me->color.b=0;
		return 1;
	}

	return 0;
}


void InitGUI()
{
	lastPressed=0;
}

int Rectangle::MousePressed(int x, int y, int button)
{
	int x1,y1,w,h;
	Rectangle* me;
	
	int processed=Element::MousePressed(x,y,button);
	if(processed!=0)
		return processed;
	me=(Rectangle* )this;
	x1=Left();
	y1=Top();
	w=width;
	h=height;
	
	if(x1<x && x<x1+w && y1<y && y<y1+h)
	{
		lastPressed=this;
		if(CustomMousePressed!=0)
			CustomMousePressed(&this->CustomMousePressed_context, MakeEvent());
			//self->CustomMousePressed(self, x, y, button);
		return 1;
	}

	return 0;
}

int Rectangle::MouseReleased(int x, int y, int button)
{
	int x1,y1,w,h;
	Rectangle* me;
	
	int processed=Element::MouseReleased(x,y,button);
	if(processed!=0)
		return processed;
	me=(Rectangle* )this;
	x1=Left();
	y1=Top();
	w=width;
	h=height;
	
	if(x1<x && x<x1+w && y1<y && y<y1+h)
	{
		if(CustomMouseReleased!=0)
			CustomMouseReleased(&this->CustomMousePressed_context, MakeEvent());
			//self->CustomMouseReleased(self, x, y, button);
		if(lastPressed==this && CustomMouseClicked!=0)
			CustomMouseClicked(&this->CustomMouseClicked_context, MakeEvent());
			//self->CustomMouseClicked(self, x, y, button);
		return 1;
	}

	return 0;
}

int Rectangle::MouseMoved(int x, int y, int relx, int rely)
{
	int x1,y1,w,h;
	int xold, yold;
	Rectangle* me;
	int processed=Element::MouseMoved(x,y,relx,rely);
	if(processed!=0)
		return processed;
	me=(Rectangle* )this;
	x1=Left();
	y1=Top();
	w=width;
	h=height;
	
	
	xold=x-relx;
	yold=y-rely;

	if(x1<x && x<x1+w && y1<y && y<y1+h)
	{
		if(CustomMouseEntered!=0)
		{
			if(!(x1<xold && xold<x1+w && y1<yold && yold<y1+h))
				CustomMouseEntered(&this->CustomMouseEntered_context, MakeEvent());
				//self->CustomMouseEntered(self, x, y, relx, rely);
		}
		if(CustomMouseMoved!=0)
			CustomMouseMoved(&this->CustomMouseMoved_context, MakeEvent());
			//self->CustomMouseMoved(self, x, y, relx, rely);
		//return 0;
	}
	else
	{
		if(CustomMouseExited!=0)
		{
			if(x1<xold && xold<x1+w && y1<yold && yold<y1+h)
				CustomMouseExited(&this->CustomMouseExited_context, MakeEvent());
				//self->CustomMouseExited(self, x, y, relx, rely);
		}
	}

	return 0;
}

int Rectangle::MouseScrolled(int x, int y, int relx, int rely)
{
	int x1,y1,w,h;
	Rectangle* me;
	int processed=Element::MouseScrolled(x,y,relx,rely);
	if(processed!=0)
		return processed;
	me=(Rectangle* )this;
	x1=Left();
	y1=Top();
	w=width;
	h=height;
	
	if(x1<x && x<x1+w && y1<y && y<y1+h)
	{
		if(CustomMouseScrolled!=0)
			CustomMouseScrolled(&this->CustomMouseScrolled_context, MakeEvent());
			//self->CustomMouseScrolled(self, x, y, relx, rely);
		return 1;
	}

	return 0;
}
void TextInput::Init()
{
}
void TextInput::DefaultUpdate()
{
}

void TextInput::Draw()
{
}

void Text::Init()
{
}
void Text::DefaultUpdate()
{
	resourceManager.TryLoadFont(font.family,font.size);
}

void Text::Draw()
{
	int x,y,w,h;
	x=Left();
	y=Top();
	w=width;
	h=height;

	
	drawer->DrawText(x,y,w,h,text.c_str(),resourceManager.fonts[font.family+"__"+std::to_string(font.size)],this->text_color.red,text_color.green, text_color.blue);
	
	//draw kids
	CQMLGUI::Element::Draw();
}


void Rectangle::Draw()
{
	int x,y,w,h;
	Rectangle* me=(Rectangle* )this;
	
#ifdef USESDL
	//SDL_Rect sdlRect;
#endif

	x=Left();
	y=Top();
	w=width;
	h=height;

	
	drawer->DrawFilledRectangle(x,y,w,h,me->color.red*255,me->color.green*255,me->color.blue*255);
	drawer->DrawRectangle(x,y,w,h,0,0,0);

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
	CQMLGUI::Element::Draw();
}

void mGUI_Element_InsertChild(Element *self,Element *child)
{
	Element ** oldChildren;
	int i;
	oldChildren=(*self).children;
	(*self).children=(Element **) malloc(((*self).childrenCount+1)*sizeof(Element *));
	
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


QML_Context * acQML_Context(CQMLGUI::Component * g, CQMLGUI::Element * e)
{
	QML_Context * context;
	context = (QML_Context *)malloc(sizeof(context));
	context->root=g;
	context->self=e;
	return context;
}



};