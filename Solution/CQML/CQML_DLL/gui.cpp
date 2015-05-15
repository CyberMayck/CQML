#include "dll_export.h"

#define CQML_DLL
#include "gui.h"
#include "resource_manager.h"



CQMLGUI::Element * focused;
CQMLGUI::Element * lastPressed;


namespace CQMLGUI
{
	vector<Element*> pressedElements;
	vector<Element*> drawnElements;
	extern CQMLGUI::Element* root;
	
/**
 * Allocates instance of Element
 * 
 *
 * @return allocated instance.
 */
	Element* acElement()
	{
		return new Element();
	}
/**
 * Allocates instance of Text
 * 
 *
 * @return allocated instance.
 */
	Text* acText()
	{
		Text * t=new Text();
		return t;
	}
/**
 * Allocates TextInput
 * 
 *
 * @return allocated instance.
 */
	TextInput* acTextInput()
	{
		TextInput * t=new TextInput();
		return t;
	}
	
/**
 * Allocates MouseArea
 * 
 *
 * @return allocated instance.
 */
	MouseArea* acMouseArea()
	{
		MouseArea * t=new MouseArea();
		return t;
	}
/**
 * Allocates Image
 * 
 *
 * @return allocated instance.
 */
	Image* acImage()
	{
		Image * t=new Image();
		return t;
	}
/**
 * Allocates scaled image.
 * 
 *
 * @return allocated instance.
 */
	ScaledImage* acScaledImage()
	{
		ScaledImage * t=new ScaledImage();
		return t;
	}
	
/**
 * Allocates Rectangle.
 * 
 *
 * @return allocated instance.
 */
	Rectangle* acRectangle()
	{
		return new Rectangle();
	}
	
/**
 * Returns vertical coordinate of top border.
 * 
 *
 * @return y coordinate
 */
	int Element::Top()
	{
		if(parent!=0)
		{
			return parent->Top()+y;
		}
		return y;
	}
	
/**
 * Returns horizontal coordinate of left border.
 * 
 *
 * @return x coordinate.
 */
	int Element::Left()
	{
		if(parent!=0)
		{
			return parent->Left()+x;
		}
		return x;
	}
	
/**
 * Main drawing function.
 * Puts all drawn elements to queue and draws them.
 */
	void MainDraw()
	{
		drawnElements.push_back(root);
		for(unsigned int i=0;i<drawnElements.size();i++)
		{
			drawnElements[i]->Draw();
		}
		drawnElements.clear();
	}
	
/**
 * Updates the values in GUI.
 * 
 */
	void MainUpdate()
	{
		root->Update();
	}

	
/**
 * Updates values of attributes.
 * Updates values and its children.
 */
	void Element::Update()
	{
		if(!enabled)
			return;
		int i;
		if(x_Update) x_Update(x_context);
		if(y_Update) y_Update(y_context);
		if(width_Update) width_Update(width_context);
		if(height_Update) height_Update(height_context);
		if(visible_Update) visible_Update(visible_context);
		if(enabled_Update) enabled_Update(enabled_context);

		for(i=0;i<childrenCount;i++)
		{
			children[i]->Update();
		}
		return;
	}
	
/**
 * Gets window size
 * 
 *
 * @param width
 * @param height
 */
	void GetCQMLWindow(int &w,int &h)
	{
		w=root->width;
		h=root->height;
	}
	
/**
 * Draws children of element.
 * 
 */
	void Element::Draw()
	{
		if(!visible)
			return;
		int i;

		for(i=0;i<childrenCount;i++)
		{
			drawnElements.push_back(children[i]);
			//children[i]->Draw();
		}
		return;
	}
	
/**
 * Mouse Pressed event
 * 
 *
 * @param x coordinate
 * @param y coordinate
 * @param button code
 *
 * @return 1 if event was sucessfully processed and caught, 0 otherwise
 */
	int Element::MousePressed(int x, int y, int button)
	{
		if(!enabled)
			return 0;
		int i;
		int processed=0;
		for(i=0;i<childrenCount;i++)
		{
			processed+=children[i]->MousePressed(x,y,button);
		}
		
		return processed;
	}
	
/**
 * Key pressed event.
 * 
 *
 * @param key code
 *
 * @return 1 if event was sucessfully processed and caught, 0 otherwise
 */
	int Element::KeyPressed(int key)
	{
		if(!enabled)
			return 0;
		int i;
		int processed=0;
		for(i=0;i<childrenCount;i++)
		{
			processed+=children[i]->KeyPressed(key);
		}
		if(processed==0 && CustomKeyPressed!=0)
		{
			CQMLKeyboardEvent e;
			e.action=KEY_PRESSED;
			e.key=key;
			CustomKeyPressed(CustomKeyPressed_context, e);
		}
		return processed;
	}
/**
 * Key Pressed event
 * 
 *
 * @param key code
 *
 * @return 1 if event was sucessfully processed and caught, 0 otherwise
 */
	int TextInput::KeyPressed(int key)
	{
		if(!enabled)
			return 0;
		if(focus)
		{
			
			if(key>=32 && key<=126)
				text=text+static_cast<char>(key);
			if(key==8 && text.length()>0)
				text=text.substr(0,text.length()-1);
				
		}
		return 1;
	}
/**
 * Key release event
 * 
 *
 * @param key code
 *
 * @return 1 if event was sucessfully processed and caught, 0 otherwise
 */
	int TextInput::KeyReleased(int key)
	{
		if(!enabled)
			return 0;
		return 1;
	}
/**
 * Key release event
 * 
 *
 * @param key code
 *
 * @return 1 if event was sucessfully processed and caught, 0 otherwise
 */
	int Element::KeyReleased(int key)
	{
		if(!enabled)
			return 0;
		int i;
		int processed=0;
		for(i=0;i<childrenCount;i++)
		{
			processed+=children[i]->KeyReleased(key);
		}
		if(processed==0 && CustomKeyReleased!=0)
		{
			CQMLKeyboardEvent e;
			e.action=KEY_RELEASED;
			e.key=key;
			CustomKeyReleased(CustomKeyReleased_context, e);
		}
		return processed;
	}
	
/**
 * Mouse released event
 * 
 *
 * @param x coordinat
 * @param y coordinate
 * @param button code
 *
 * @return 1 if event was sucessfully processed and caught, 0 otherwise
 */
	int Element::MouseReleased(int x, int y, int button)
	{
		if(!enabled)
			return 0;
		for(unsigned int i=0;i<pressedElements.size();i++)
		{
			pressedElements[i]->MouseReleased(x,y,button);
		}
		pressedElements.clear();
		return 0;
	}
	
/**
 * Mouse Moved event
 * 
 *
 * @param x coordinate
 * @param y coordinate
 * @param relative x movement
 * @param relative y movement
 *
 * @return 1 if event was sucessfully processed and caught, 0 otherwise
 */
	int Element::MouseMoved(int x, int y, int relx, int rely)
	{
		if(!enabled)
			return 0;
		int i;
		int processed=0;
		for(i=0;i<childrenCount;i++)
		{
			processed+=children[i]->MouseMoved(x,y,relx,rely);
		}
		return processed;
	}
	
/**
 * Mouse scrolled event
 * 
 *
 * @param x coordinate
 * @param y coordinate
 * @param relative x scroll
 * @param relative y scroll
 *
 * @return 1 if event was sucessfully processed and caught, 0 otherwise
 */
	int Element::MouseScrolled(int x, int y, int relx, int rely)
	{
		if(!enabled)
			return 0;
		int i;
		int processed=0;
		for(i=0;i<childrenCount;i++)
		{
			processed+=children[i]->MouseScrolled(x,y,relx,rely);
		}
		return processed;
	}
	
/**
 * Mouse clicked event
 * 
 *
 * @param x coordinat
 * @param y coordinate
 * @param button code
 *
 * @return 1 if event was sucessfully processed and caught, 0 otherwise
 */
	int Element::MouseClicked(int x, int y, int button)
	{
		if(!enabled)
			return 0;
		int i;
		int processed=0;
		for(i=0;i<childrenCount;i++)
		{
			//processed+=(*(*self).children[i]).Clicked((*self).children[i],x,y);
		}
		return processed;
	}
	
/**
 * Changes focus of element
 * 
 *
 * @param element
 */
	void ChangeFocus(Element * e)
	{
		if(focused!=0) focused->focus=0;
		focused=e;
		focused->focus=1;
	}
	
/**
 * Mouse clicked event
 * 
 *
 * @param x coordinat
 * @param y coordinate
 * @param button code
 *
 * @return 1 if event was sucessfully processed and caught, 0 otherwise
 */
	int TextInput::MouseClicked(int x, int y,int button)
	{
		if(!enabled)
			return 0;
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
	
/**
 * Mouse clicked event
 * 
 *
 * @param x coordinat
 * @param y coordinate
 * @param button code
 *
 * @return 1 if event was sucessfully processed and caught, 0 otherwise
 */
	int MouseArea::MouseClicked(int x, int y,int button)
	{
		if(!enabled)
			return 0;
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
				CQMLMouseEvent e;
				e.x=x;
				e.y=y;
				e.button=button;
				CustomMouseClicked(this->CustomMouseClicked_context, e);
			}

			return 1;
		}

		return 0;
	}

	
/**
 * Initializes GUI
 * 
 */
	void InitGUI()
	{
		lastPressed=0;
		focused=0;
	}
	
/**
 * Mouse pressed event
 * 
 *
 * @param x coordinat
 * @param y coordinate
 * @param button code
 *
 * @return  1 if event was sucessfully processed and caught, 0 otherwise
 */
	int MouseArea::MousePressed(int x, int y, int button)
	{
		if(!enabled)
			return 0;
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
			pressedElements.push_back(this);
			lastPressed=this;
			if(CustomMousePressed!=0)
			{
				CQMLMouseEvent e;
				e.x=x;
				e.y=y;
				e.button=button;
				CustomMousePressed(this->CustomMousePressed_context, e);
			}

			return 1;
		}

		return 0;
	}
	
/**
 * Mouse Released event
 * 
 *
 * @param x coordinat
 * @param y coordinate
 * @param button code
 *
 * @return 1 if event was sucessfully processed and caught, 0 otherwise
 */
	int MouseArea::MouseReleased(int x, int y, int button)
	{
		if(!enabled)
			return 0;
		int x1,y1,w,h;
		Rectangle* me;
	
		//int processed=Element::MouseReleased(x,y,button);
		//if(processed!=0)
		//	return processed;
		me=(Rectangle* )this;
		x1=Left();
		y1=Top();
		w=width;
		h=height;
			
		if(CustomMouseReleased!=0)
		{
			CQMLMouseEvent e;
			e.x=x;
			e.y=y;
			e.button=button;
			CustomMouseReleased(this->CustomMouseReleased_context, e);
		}
	
		if(x1<x && x<x1+w && y1<y && y<y1+h)
		{

			if(CustomMouseClicked!=0)
			{
				CQMLMouseEvent e;
				e.x=x;
				e.y=y;
				e.button=button;
				CustomMouseClicked(this->CustomMouseClicked_context, e);
			}

			return 1;
		}

		return 0;
	}

	
/**
 * Mouse Moved Event
 * 
 *
 * @param x coordinate
 * @param y coordinate
 * @param relative x movement
 * @param relative y movement
 *
 * @return 1 if event was sucessfully processed and caught, 0 otherwise
 */
	int MouseArea::MouseMoved(int x, int y, int relx, int rely)
	{
		if(!enabled)
			return 0;
		int x1,y1,w,h;
		int xold, yold;
		Rectangle* me;
		//int processed=Element::MouseMoved(x,y,relx,rely);
		//if(processed!=0)
		//	return processed;
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
					CQMLMouseEvent e;
					e.x=x;
					e.y=y;
					e.relativeX=relx;
					e.relativeY=rely;
					CustomMouseEntered(this->CustomMouseEntered_context, e);
				}
			}
			if(CustomMouseMoved!=0)
			{
				CQMLMouseEvent e;
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
					CQMLMouseEvent e;
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
	
/**
 * Mouse scrolled event
 * 
 *
 * @param x coordinate
 * @param y coordinate
 * @param relative x scroll
 * @param relative y scroll
 *
 * @return 1 if event was sucessfully processed and caught, 0 otherwise
 */
	int MouseArea::MouseScrolled(int x, int y, int relx, int rely)
	{
		if(!enabled)
			return 0;
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
				CQMLMouseEvent e;
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

/**
 * Empty init.
 * 
 */
	void TextInput::Init()
	{
	}
/**
 * Default update
 * tries to load font
 */
	void TextInput::DefaultUpdate()
	{
		resourceManager.TryLoadFont(font.family,font.size);
	}
	
/**
 * Draw text input
 * 
 */
	void TextInput::Draw()
	{
		if(!visible)
			return;
		int x,y,w,h;
		x=Left();
		y=Top();
		w=width;
		h=height;

	
		drawer->DrawText(x,y,w,h,text.c_str(),resourceManager.fonts[font.family+"__"+std::to_string(font.size)],this->textColor.red,textColor.green, textColor.blue);
	
		//draw kids
		CQMLGUI::Element::Draw();
	}
	
/**
 * Empty init
 * 
 */
	void Text::Init()
	{
	}
/**
 * Default update
 * tries to load font
 */
	void Text::DefaultUpdate()
	{
		resourceManager.TryLoadFont(font.family,font.size);
	}
	
/**
 * Empty init
 * 
 */
	void Image::Init()
	{
	}
/**
 * Empty init
 * 
 */
	void ScaledImage::Init()
	{
	}
/**
 * Default update
 * tries to load image data
 */
	void Image::DefaultUpdate()
	{
		resourceManager.TryLoadImage(img.src);
	}
/**
 * Default update
 * tries to load image data
 */
	void ScaledImage::DefaultUpdate()
	{
		resourceManager.TryLoadImage(img.src);
	}
	
/**
 * Draws image
 * 
 */
	void Image::Draw()
	{
		if(!visible)
			return;
		int x,y,w,h;
		x=Left();
		y=Top();
		w=width;
		h=height;

		drawer->DrawImage(x,y,w,h,resourceManager.images[img.src].img);

		//draw kids
		CQMLGUI::Element::Draw();
	}
/**
 * Draws ScaledImage
 * 
 */
	void ScaledImage::Draw()
	{
		if(!visible)
			return;
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
	
/**
 * DrawsText
 * 
 */
	void Text::Draw()
	{
		if(!visible)
			return;
		int x,y,w,h;
		x=Left();
		y=Top();
		w=width;
		h=height;

	
		drawer->DrawText(x,y,w,h,text.c_str(),resourceManager.fonts[font.family+"__"+std::to_string(font.size)],this->textColor.red,textColor.green, textColor.blue);
	
		//draw kids
		CQMLGUI::Element::Draw();
	}

	
/**
 * Draws Rectangle
 * 
 */
	void Rectangle::Draw()
	{
		if(!visible)
			return;
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

		


		//draw kids
		CQMLGUI::Element::Draw();
	}
	
/**
 * Pre update function
 * Processes input events
 * 
 */
	void PreUpdate()
	{
		processEvents();
	}
/**
 * Post update function
 * loads font and image data
 */
	void PostUpdate()
	{
		resourceManager.LoadFonts();
		resourceManager.LoadImages();
	}
/**
 * Pre draw function
 * does nothing
 */
	void PreDraw()
	{
	}
/**
 * Post draw function
 * does nothing
 */
	void PostDraw()
	{
	}
	
/**
 * 
 * 
 *
 * @param 
 */
	void CopyChildren(Element *self,Element *src)
	{
		for(int i=0;i<(*src).childrenCount;i++)
		{
			mGUI_Element_InsertChild(self,src->children[i]);
		}
		(*src).childrenCount=0;
		delete src->children;
	}
	
/**
 * 
 * 
 *
 * @param 
 */
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

	
/**
 * 
 * 
 *
 * @param 
 *
 * @return 
 */
	CQML_Context * acCQML_Context(CQMLGUI::Component * g, CQMLGUI::Element * e)
	{
		CQML_Context * context;
		context = (CQML_Context *)malloc(sizeof(context));
		context->root=g;
		context->self=e;
		return context;
	}



};