// print default constructors;
CQMLGUI::Color::Color()
{
	classID=0;
	red=0;
	red_Update=0;
	green=0;
	green_Update=0;
	blue=0;
	blue_Update=0;
	Init();
}
CQMLGUI::Font::Font()
{
	classID=1;
	capital=0;
	capital_Update=0;
	italic=0;
	italic_Update=0;
	bold=0;
	bold_Update=0;
	size=0;
	size_Update=0;
	family="";
	family_Update=0;
	Init();
}
CQMLGUI::Element::Element()
{
	classID=2;
	root=0;
	parent=0;
	children=0;
	childrenCount=0;
	flags=0;
	x=0;
	x_Update=0;
	y=0;
	y_Update=0;
	width=0;
	width_Update=0;
	height=0;
	height_Update=0;
	CustomMouseClicked=0;
	CustomMousePressed=0;
	CustomMouseReleased=0;
	CustomMouseMoved=0;
	CustomMouseEntered=0;
	CustomMouseExited=0;
	CustomMouseScrolled=0;
	Init();
}
CQMLGUI::Rectangle::Rectangle()
{
	classID=3;
	color_Update=0;
	Init();
}
CQMLGUI::Anchor::Anchor()
{
	classID=4;
	top=0;
	top_Update=0;
	bottom=0;
	bottom_Update=0;
	left=0;
	left_Update=0;
	right=0;
	right_Update=0;
	Init();
}
CQMLGUI::Text::Text()
{
	classID=5;
	text_color_Update=0;
	text="";
	text_Update=0;
	font_Update=0;
	Init();
}
CQMLGUI::TextInput::TextInput()
{
	classID=6;
	Init();
}
Variant CQMLGUI::Color::Get(const char* s)
{
	int hash=GetHash(classID,s);
	if(hash<0) return Variant(0);
	switch(hash)
	{
	case 0:
		return Variant(red);
	case 1:
		return Variant(green);
	case 2:
		return Variant(blue);
	default: break;
	}
	return Variant(0);
}
Variant CQMLGUI::Font::Get(const char* s)
{
	int hash=GetHash(classID,s);
	if(hash<0) return Variant(0);
	switch(hash)
	{
	case 0:
		return Variant(capital);
	case 1:
		return Variant(italic);
	case 2:
		return Variant(bold);
	case 3:
		return Variant(size);
	case 4:
		return Variant(family);
	default: break;
	}
	return Variant(0);
}
Variant CQMLGUI::Element::Get(const char* s)
{
	int hash=GetHash(classID,s);
	if(hash<0) return Variant(0);
	switch(hash)
	{
	case 0:
		return Variant(&root);
	case 1:
		return Variant(&parent);
	case 2:
		return Variant(&children);
	case 3:
		return Variant(childrenCount);
	case 4:
		return Variant(flags);
	case 5:
		return Variant(x);
	case 6:
		return Variant(y);
	case 7:
		return Variant(width);
	case 8:
		return Variant(height);
	default: break;
	}
	return Variant(0);
}
Variant CQMLGUI::Rectangle::Get(const char* s)
{
	int hash=GetHash(classID,s);
	if(hash<0) return Variant(0);
	switch(hash)
	{
	case 0:
		return Variant(&color);
	case 1:
		return Variant(&root);
	case 2:
		return Variant(&parent);
	case 3:
		return Variant(&children);
	case 4:
		return Variant(childrenCount);
	case 5:
		return Variant(flags);
	case 6:
		return Variant(x);
	case 7:
		return Variant(y);
	case 8:
		return Variant(width);
	case 9:
		return Variant(height);
	default: break;
	}
	return Variant(0);
}
Variant CQMLGUI::Anchor::Get(const char* s)
{
	int hash=GetHash(classID,s);
	if(hash<0) return Variant(0);
	switch(hash)
	{
	case 0:
		return Variant(&top);
	case 1:
		return Variant(&bottom);
	case 2:
		return Variant(&left);
	case 3:
		return Variant(&right);
	default: break;
	}
	return Variant(0);
}
Variant CQMLGUI::Text::Get(const char* s)
{
	int hash=GetHash(classID,s);
	if(hash<0) return Variant(0);
	switch(hash)
	{
	case 0:
		return Variant(&text_color);
	case 1:
		return Variant(text);
	case 2:
		return Variant(&font);
	case 3:
		return Variant(&color);
	case 4:
		return Variant(&root);
	case 5:
		return Variant(&parent);
	case 6:
		return Variant(&children);
	case 7:
		return Variant(childrenCount);
	case 8:
		return Variant(flags);
	case 9:
		return Variant(x);
	case 10:
		return Variant(y);
	case 11:
		return Variant(width);
	case 12:
		return Variant(height);
	default: break;
	}
	return Variant(0);
}
Variant CQMLGUI::TextInput::Get(const char* s)
{
	int hash=GetHash(classID,s);
	if(hash<0) return Variant(0);
	switch(hash)
	{
	case 0:
		return Variant(&text_color);
	case 1:
		return Variant(text);
	case 2:
		return Variant(&font);
	case 3:
		return Variant(&color);
	case 4:
		return Variant(&root);
	case 5:
		return Variant(&parent);
	case 6:
		return Variant(&children);
	case 7:
		return Variant(childrenCount);
	case 8:
		return Variant(flags);
	case 9:
		return Variant(x);
	case 10:
		return Variant(y);
	case 11:
		return Variant(width);
	case 12:
		return Variant(height);
	default: break;
	}
	return Variant(0);
}
using namespace CQMLGUI;
void Rectangle::Update()
{
	if(color_Update)color_Update(color_context);
	else
	{
		if(color.red_Update)color.red_Update(color.red_context);
		if(color.green_Update)color.green_Update(color.green_context);
		if(color.blue_Update)color.blue_Update(color.blue_context);
	}
	 Element::Update();
DefaultUpdate();
}
void Text::Update()
{
	if(text_color_Update)text_color_Update(text_color_context);
	else
	{
		if(text_color.red_Update)text_color.red_Update(text_color.red_context);
		if(text_color.green_Update)text_color.green_Update(text_color.green_context);
		if(text_color.blue_Update)text_color.blue_Update(text_color.blue_context);
	}
	if(text_Update)text_Update(text_context);
	if(font_Update)font_Update(font_context);
	else
	{
		if(font.capital_Update)font.capital_Update(font.capital_context);
		if(font.italic_Update)font.italic_Update(font.italic_context);
		if(font.bold_Update)font.bold_Update(font.bold_context);
		if(font.size_Update)font.size_Update(font.size_context);
		if(font.family_Update)font.family_Update(font.family_context);
	}
	 Rectangle::Update();
DefaultUpdate();
}
void TextInput::Update()
{
	 Text::Update();
DefaultUpdate();
}
