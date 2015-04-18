#include "dll_export.h"

#define CQML_DLL
#include "gui.h"
#include "resource_manager.h"



CQMLGUI::Element * focused;
CQMLGUI::Element * lastPressed;


namespace CQMLGUI
{
	extern CQMLGUI::Element* root;
	Element* acElement()
	{
		Element * a;
		return new Element();
	}
	Text* acText()
	{
		Text * t=new Text();
		return t;
	}
	TextInput* acTextInput()
	{
		TextInput * t=new TextInput();
		return t;
	}
	
	MouseArea* acMouseArea()
	{
		MouseArea * t=new MouseArea();
		return t;
	}
	Image* acImage()
	{
		Image * t=new Image();
		return t;
	}
	ScaledImage* acScaledImage()
	{
		ScaledImage * t=new ScaledImage();
		return t;
	}

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
		if(x_Update) x_Update(x_context);
		if(y_Update) y_Update(y_context);
		if(width_Update) width_Update(width_context);
		if(height_Update) height_Update(height_context);

		for(i=0;i<childrenCount;i++)
		{
			children[i]->Update();
		}
		return;
	}

	void GetQMLWindow(int &w,int &h)
	{
		w=root->width;
		h=root->height;
	}

	void Element::Draw()
	{
		int i;

		for(i=0;i<childrenCount;i++)
		{
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

	int Element::KeyPressed(int key)
	{
		int i;
		int processed=0;
		for(i=0;i<childrenCount;i++)
		{
			processed+=children[i]->KeyPressed(key);
		}
		if(processed==0 && CustomKeyPressed!=0)
		{
			QMLKeyboardEvent e;
			e.action=KEY_PRESSED;
			e.key=key;
			CustomKeyPressed(CustomKeyPressed_context, e);
		}
		return processed;
	}
	int TextInput::KeyPressed(int key)
	{
		if(focus)
		{
			
			if(key>=32 && key<=126)
				text=text+static_cast<char>(key);
			if(key==8 && text.length()>0)
				text=text.substr(0,text.length()-1);
				
		}
		return 1;
	}
	int TextInput::KeyReleased(int key)
	{
		return 1;
	}
	int Element::KeyReleased(int key)
	{
		int i;
		int processed=0;
		for(i=0;i<childrenCount;i++)
		{
			processed+=children[i]->KeyReleased(key);
		}
		if(processed==0 && CustomKeyReleased!=0)
		{
			QMLKeyboardEvent e;
			e.action=KEY_RELEASED;
			e.key=key;
			CustomKeyReleased(CustomKeyReleased_context, e);
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

	void ChangeFocus(Element * e)
	{
		if(focused!=0) focused->focus=0;
		focused=e;
		focused->focus=1;
	}

	int TextInput::MouseClicked(int x, int y,int button)
	{
		int x1,y1,w,h;
	
		//int processed=Element::MouseClicked(x,y,button);
		//if(processed!=0)
		//	return processed;

		x1=Left();
		y1=Top();
		w=width;
		h=height;
	
		if(x1<x && x<x1+w && y1<y && y<y1+h)
		{
			ChangeFocus(this);
			return 1;
		}

		return 0;
	}

	int MouseArea::MouseClicked(int x, int y,int button)
	{
		int x1,y1,w,h;
		Rectangle* me;
	
		//int processed=Element::MouseClicked(x,y,button);
		//if(processed!=0)
		//	return processed;
		me=(Rectangle* )this;
		x1=Left();
		y1=Top();
		w=width;
		h=height;
	
		if(x1<x && x<x1+w && y1<y && y<y1+h)
		{
			if(CustomMouseClicked!=0)
			{
				QMLMouseEvent e;
				e.x=x;
				e.y=y;
				e.button=button;
				CustomMouseClicked(this->CustomMouseClicked_context, e);
			}

			return 1;
		}

		return 0;
	}


	void InitGUI()
	{
		lastPressed=0;
		focused=0;
	}

	int MouseArea::MousePressed(int x, int y, int button)
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
			{
				QMLMouseEvent e;
				e.x=x;
				e.y=y;
				e.button=button;
				CustomMousePressed(this->CustomMousePressed_context, e);
			}

			return 1;
		}

		return 0;
	}

	int MouseArea::MouseReleased(int x, int y, int button)
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
			{
				QMLMouseEvent e;
				e.x=x;
				e.y=y;
				e.button=button;
				CustomMouseReleased(this->CustomMousePressed_context, e);
			}

			if(lastPressed==this && CustomMouseClicked!=0)
			{
				QMLMouseEvent e;
				e.x=x;
				e.y=y;
				e.button=button;
				CustomMouseClicked(this->CustomMouseClicked_context, e);
			}

			return 1;
		}

		return 0;
	}

	int MouseArea::MouseMoved(int x, int y, int relx, int rely)
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
				{
					QMLMouseEvent e;
					e.x=x;
					e.y=y;
					e.relativeX=relx;
					e.relativeY=rely;
					CustomMouseEntered(this->CustomMouseEntered_context, e);
				}
			}
			if(CustomMouseMoved!=0)
			{
				QMLMouseEvent e;
				e.x=x;
				e.y=y;
				e.relativeX=relx;
				e.relativeY=rely;
				CustomMouseMoved(this->CustomMouseMoved_context, e);
			}

		}
		else
		{
			if(CustomMouseExited!=0)
			{
				if(x1<xold && xold<x1+w && y1<yold && yold<y1+h)
				{
					QMLMouseEvent e;
					e.x=x;
					e.y=y;
					e.relativeX=relx;
					e.relativeY=rely;
					CustomMouseExited(this->CustomMouseExited_context, e);
				}
			}
		}

		return 0;
	}

	int MouseArea::MouseScrolled(int x, int y, int relx, int rely)
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
			{
				QMLMouseEvent e;
				e.x=x;
				e.y=y;
				e.relativeX=relx;
				e.relativeY=rely;
				CustomMouseScrolled(this->CustomMouseScrolled_context, e);
			}
			return 1;
		}

		return 0;
	}
	void TextInput::Init()
	{
	}
	void TextInput::DefaultUpdate()
	{
		resourceManager.TryLoadFont(font.family,font.size);
	}

	void TextInput::Draw()
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

	void Text::Init()
	{
	}
	void Text::DefaultUpdate()
	{
		resourceManager.TryLoadFont(font.family,font.size);
	}
	
	void Image::Init()
	{
	}
	void ScaledImage::Init()
	{
	}
	void Image::DefaultUpdate()
	{
		resourceManager.TryLoadImage(img.src);
	}
	void ScaledImage::DefaultUpdate()
	{
		resourceManager.TryLoadImage(img.src);
	}

	void Image::Draw()
	{
		int x,y,w,h;
		x=Left();
		y=Top();
		w=width;
		h=height;

		drawer->DrawImage(x,y,w,h,resourceManager.images[img.src].img);

		//draw kids
		CQMLGUI::Element::Draw();
	}
	void ScaledImage::Draw()
	{
		int x,y,w,h;
		x=Left();
		y=Top();
		w=width;
		h=height;

		ImageData image=resourceManager.images[img.src];
		int iW=image.width;
		int iH=image.width;
		
		//corners
		drawer->DrawImageSegment(x,y,leftBorder,topBorder,image.img, 0,0,leftBorder,topBorder);
		drawer->DrawImageSegment(x+w-rightBorder,y,rightBorder,topBorder,image.img, iW-rightBorder,0,rightBorder,topBorder);
		
		drawer->DrawImageSegment(x,y+h-bottomBorder,leftBorder,bottomBorder,image.img, 0,iH-bottomBorder,leftBorder,bottomBorder);
		drawer->DrawImageSegment(x+w-rightBorder,y+h-bottomBorder,rightBorder,bottomBorder,image.img, iW-rightBorder,iH-bottomBorder,rightBorder,bottomBorder);
		// sides
		drawer->DrawImageSegment(x+leftBorder,y,w-(leftBorder+rightBorder),topBorder,image.img, leftBorder,0,iW-(leftBorder+rightBorder),topBorder);
		drawer->DrawImageSegment(x+leftBorder,y+h-bottomBorder,w-(leftBorder+rightBorder),bottomBorder,image.img, leftBorder,iH-bottomBorder,iW-(leftBorder+rightBorder),bottomBorder);
		
		drawer->DrawImageSegment(x,y+topBorder,leftBorder,h-(topBorder+bottomBorder),image.img, 0,topBorder,leftBorder,iH-(topBorder+bottomBorder));
		drawer->DrawImageSegment(x+w-rightBorder,y+topBorder,rightBorder,h-(topBorder+bottomBorder), image.img, iW-rightBorder,topBorder,rightBorder,iH-(topBorder+bottomBorder));
		
		drawer->DrawImageSegment(x+leftBorder,y+topBorder,w-(leftBorder+rightBorder),h-(topBorder+bottomBorder),image.img, leftBorder,topBorder,iW-(leftBorder+rightBorder),iH-(topBorder+bottomBorder));


		CQMLGUI::Element::Draw();
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

		x=Left();
		y=Top();
		w=width;
		h=height;

	
		if(border==0)
			drawer->DrawFilledRectangle(x,y,w,h,me->color.red*255,me->color.green*255,me->color.blue*255);
		else
			drawer->DrawFilledBorderedRectangle(x,y,w,h,me->color.red*255,me->color.green*255,me->color.blue*255,border,borderColor.red,borderColor.green,borderColor.blue);

		//drawer->DrawRectangle(x,y,w,h,0,0,0);

		//cairo draw


		//draw kids
		CQMLGUI::Element::Draw();
	}

	void PreUpdate()
	{
		processEvents();
	}
	void PostUpdate()
	{
		resourceManager.LoadFonts();
		resourceManager.LoadImages();
	}
	void PreDraw()
	{
	}
	void PostDraw()
	{
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