// print default constructors;
CQMLGUI::Color::Color()
{
	classID=0;
	red=0;
	red_Update=0;
	red_context=0;
	green=0;
	green_Update=0;
	green_context=0;
	blue=0;
	blue_Update=0;
	blue_context=0;
	Init();
}
CQMLGUI::Font::Font()
{
	classID=1;
	capital=0;
	capital_Update=0;
	capital_context=0;
	italic=0;
	italic_Update=0;
	italic_context=0;
	bold=0;
	bold_Update=0;
	bold_context=0;
	size=0;
	size_Update=0;
	size_context=0;
	family="";
	family_Update=0;
	family_context=0;
	Init();
}
CQMLGUI::Img::Img()
{
	classID=2;
	src="";
	src_Update=0;
	src_context=0;
	Init();
}
CQMLGUI::Element::Element()
{
	classID=3;
	root=0;
	parent=0;
	children=0;
	childrenCount=0;
	flags=0;
	x=0;
	x_Update=0;
	x_context=0;
	y=0;
	y_Update=0;
	y_context=0;
	width=0;
	width_Update=0;
	width_context=0;
	height=0;
	height_Update=0;
	height_context=0;
	visible=1;
	visible_Update=0;
	visible_context=0;
	enabled=1;
	enabled_Update=0;
	enabled_context=0;
	focus=0;
	CustomKeyPressed=0;
	CustomKeyPressed_context=0;
	CustomKeyReleased=0;
	CustomKeyReleased_context=0;
	Init();
}
CQMLGUI::Rectangle::Rectangle()
{
	classID=4;
	borderColor_Update=0;
	borderColor_context=0;
	border=0;
	border_Update=0;
	border_context=0;
	color_Update=0;
	color_context=0;
	Init();
}
CQMLGUI::MouseArea::MouseArea()
{
	classID=5;
	CustomMouseClicked=0;
	CustomMouseClicked_context=0;
	CustomMousePressed=0;
	CustomMousePressed_context=0;
	CustomMouseReleased=0;
	CustomMouseReleased_context=0;
	CustomMouseMoved=0;
	CustomMouseMoved_context=0;
	CustomMouseEntered=0;
	CustomMouseEntered_context=0;
	CustomMouseExited=0;
	CustomMouseExited_context=0;
	CustomMouseScrolled=0;
	CustomMouseScrolled_context=0;
	Init();
}
CQMLGUI::Anchor::Anchor()
{
	classID=6;
	top=0;
	top_Update=0;
	top_context=0;
	bottom=0;
	bottom_Update=0;
	bottom_context=0;
	left=0;
	left_Update=0;
	left_context=0;
	right=0;
	right_Update=0;
	right_context=0;
	Init();
}
CQMLGUI::Text::Text()
{
	classID=7;
	textColor_Update=0;
	textColor_context=0;
	text="";
	text_Update=0;
	text_context=0;
	font_Update=0;
	font_context=0;
	Init();
}
CQMLGUI::TextInput::TextInput()
{
	classID=8;
	InputChange=0;
	InputChange_context=0;
	Init();
}
CQMLGUI::Image::Image()
{
	classID=9;
	img_Update=0;
	img_context=0;
	Init();
}
CQMLGUI::ScaledImage::ScaledImage()
{
	classID=10;
	leftBorder=0;
	leftBorder_Update=0;
	leftBorder_context=0;
	bottomBorder=0;
	bottomBorder_Update=0;
	bottomBorder_context=0;
	rightBorder=0;
	rightBorder_Update=0;
	rightBorder_context=0;
	topBorder=0;
	topBorder_Update=0;
	topBorder_context=0;
	Init();
}
CQMLObject* CQMLGUI::Color::Copy()
{
	return new CQMLGUI::Color(*this);
}

CQMLObject* CQMLGUI::Font::Copy()
{
	return new CQMLGUI::Font(*this);
}

CQMLObject* CQMLGUI::Img::Copy()
{
	return new CQMLGUI::Img(*this);
}

CQMLObject* CQMLGUI::Element::Copy()
{
	return new CQMLGUI::Element(*this);
}

CQMLObject* CQMLGUI::Rectangle::Copy()
{
	return new CQMLGUI::Rectangle(*this);
}

CQMLObject* CQMLGUI::MouseArea::Copy()
{
	return new CQMLGUI::MouseArea(*this);
}

CQMLObject* CQMLGUI::Anchor::Copy()
{
	return new CQMLGUI::Anchor(*this);
}

CQMLObject* CQMLGUI::Text::Copy()
{
	return new CQMLGUI::Text(*this);
}

CQMLObject* CQMLGUI::TextInput::Copy()
{
	return new CQMLGUI::TextInput(*this);
}

CQMLObject* CQMLGUI::Image::Copy()
{
	return new CQMLGUI::Image(*this);
}

CQMLObject* CQMLGUI::ScaledImage::Copy()
{
	return new CQMLGUI::ScaledImage(*this);
}

VariantRef CQMLGUI::Color::Get(const char* s)
{
	int hash=GetHash(classID,s);
	if(hash<0) 
	{
		throw(0); 
		return VariantRef();
	}
	switch(hash)
	{
	case 0:
		return VariantRef(red,&red_Update);
	case 1:
		return VariantRef(green,&green_Update);
	case 2:
		return VariantRef(blue,&blue_Update);
	default: break;
	}
	return VariantRef();
}
VariantRef CQMLGUI::Font::Get(const char* s)
{
	int hash=GetHash(classID,s);
	if(hash<0) 
	{
		throw(0); 
		return VariantRef();
	}
	switch(hash)
	{
	case 0:
		return VariantRef(capital,&capital_Update);
	case 1:
		return VariantRef(italic,&italic_Update);
	case 2:
		return VariantRef(bold,&bold_Update);
	case 3:
		return VariantRef(size,&size_Update);
	case 4:
		return VariantRef(family,&family_Update);
	default: break;
	}
	return VariantRef();
}
VariantRef CQMLGUI::Img::Get(const char* s)
{
	int hash=GetHash(classID,s);
	if(hash<0) 
	{
		throw(0); 
		return VariantRef();
	}
	switch(hash)
	{
	case 0:
		return VariantRef(src,&src_Update);
	default: break;
	}
	return VariantRef();
}
VariantRef CQMLGUI::Element::Get(const char* s)
{
	int hash=GetHash(classID,s);
	if(hash<0) 
	{
		throw(0); 
		return VariantRef();
	}
	switch(hash)
	{
	case 0:
		return VariantRef(x,&x_Update);
	case 1:
		return VariantRef(y,&y_Update);
	case 2:
		return VariantRef(width,&width_Update);
	case 3:
		return VariantRef(height,&height_Update);
	case 4:
		return VariantRef(visible,&visible_Update);
	case 5:
		return VariantRef(enabled,&enabled_Update);
	default: break;
	}
	return VariantRef();
}
VariantRef CQMLGUI::Rectangle::Get(const char* s)
{
	int hash=GetHash(classID,s);
	if(hash<0) 
	{
		throw(0); 
		return VariantRef();
	}
	switch(hash)
	{
	case 0:
		return VariantRef((CQMLObject*)&borderColor,&borderColor_Update);
	case 1:
		return VariantRef(border,&border_Update);
	case 2:
		return VariantRef((CQMLObject*)&color,&color_Update);
	case 3:
		return VariantRef(x,&x_Update);
	case 4:
		return VariantRef(y,&y_Update);
	case 5:
		return VariantRef(width,&width_Update);
	case 6:
		return VariantRef(height,&height_Update);
	case 7:
		return VariantRef(visible,&visible_Update);
	case 8:
		return VariantRef(enabled,&enabled_Update);
	default: break;
	}
	return VariantRef();
}
VariantRef CQMLGUI::MouseArea::Get(const char* s)
{
	int hash=GetHash(classID,s);
	if(hash<0) 
	{
		throw(0); 
		return VariantRef();
	}
	switch(hash)
	{
	case 0:
		return VariantRef(x,&x_Update);
	case 1:
		return VariantRef(y,&y_Update);
	case 2:
		return VariantRef(width,&width_Update);
	case 3:
		return VariantRef(height,&height_Update);
	case 4:
		return VariantRef(visible,&visible_Update);
	case 5:
		return VariantRef(enabled,&enabled_Update);
	default: break;
	}
	return VariantRef();
}
VariantRef CQMLGUI::Anchor::Get(const char* s)
{
	int hash=GetHash(classID,s);
	if(hash<0) 
	{
		throw(0); 
		return VariantRef();
	}
	switch(hash)
	{
	case 0:
		return VariantRef((CQMLObject**)&top,&top_Update);
	case 1:
		return VariantRef((CQMLObject**)&bottom,&bottom_Update);
	case 2:
		return VariantRef((CQMLObject**)&left,&left_Update);
	case 3:
		return VariantRef((CQMLObject**)&right,&right_Update);
	default: break;
	}
	return VariantRef();
}
VariantRef CQMLGUI::Text::Get(const char* s)
{
	int hash=GetHash(classID,s);
	if(hash<0) 
	{
		throw(0); 
		return VariantRef();
	}
	switch(hash)
	{
	case 0:
		return VariantRef((CQMLObject*)&textColor,&textColor_Update);
	case 1:
		return VariantRef(text,&text_Update);
	case 2:
		return VariantRef((CQMLObject*)&font,&font_Update);
	case 3:
		return VariantRef((CQMLObject*)&borderColor,&borderColor_Update);
	case 4:
		return VariantRef(border,&border_Update);
	case 5:
		return VariantRef((CQMLObject*)&color,&color_Update);
	case 6:
		return VariantRef(x,&x_Update);
	case 7:
		return VariantRef(y,&y_Update);
	case 8:
		return VariantRef(width,&width_Update);
	case 9:
		return VariantRef(height,&height_Update);
	case 10:
		return VariantRef(visible,&visible_Update);
	case 11:
		return VariantRef(enabled,&enabled_Update);
	default: break;
	}
	return VariantRef();
}
VariantRef CQMLGUI::TextInput::Get(const char* s)
{
	int hash=GetHash(classID,s);
	if(hash<0) 
	{
		throw(0); 
		return VariantRef();
	}
	switch(hash)
	{
	case 0:
		return VariantRef((CQMLObject*)&textColor,&textColor_Update);
	case 1:
		return VariantRef(text,&text_Update);
	case 2:
		return VariantRef((CQMLObject*)&font,&font_Update);
	case 3:
		return VariantRef((CQMLObject*)&borderColor,&borderColor_Update);
	case 4:
		return VariantRef(border,&border_Update);
	case 5:
		return VariantRef((CQMLObject*)&color,&color_Update);
	case 6:
		return VariantRef(x,&x_Update);
	case 7:
		return VariantRef(y,&y_Update);
	case 8:
		return VariantRef(width,&width_Update);
	case 9:
		return VariantRef(height,&height_Update);
	case 10:
		return VariantRef(visible,&visible_Update);
	case 11:
		return VariantRef(enabled,&enabled_Update);
	default: break;
	}
	return VariantRef();
}
VariantRef CQMLGUI::Image::Get(const char* s)
{
	int hash=GetHash(classID,s);
	if(hash<0) 
	{
		throw(0); 
		return VariantRef();
	}
	switch(hash)
	{
	case 0:
		return VariantRef((CQMLObject*)&img,&img_Update);
	case 1:
		return VariantRef(x,&x_Update);
	case 2:
		return VariantRef(y,&y_Update);
	case 3:
		return VariantRef(width,&width_Update);
	case 4:
		return VariantRef(height,&height_Update);
	case 5:
		return VariantRef(visible,&visible_Update);
	case 6:
		return VariantRef(enabled,&enabled_Update);
	default: break;
	}
	return VariantRef();
}
VariantRef CQMLGUI::ScaledImage::Get(const char* s)
{
	int hash=GetHash(classID,s);
	if(hash<0) 
	{
		throw(0); 
		return VariantRef();
	}
	switch(hash)
	{
	case 0:
		return VariantRef(leftBorder,&leftBorder_Update);
	case 1:
		return VariantRef(bottomBorder,&bottomBorder_Update);
	case 2:
		return VariantRef(rightBorder,&rightBorder_Update);
	case 3:
		return VariantRef(topBorder,&topBorder_Update);
	case 4:
		return VariantRef((CQMLObject*)&img,&img_Update);
	case 5:
		return VariantRef(x,&x_Update);
	case 6:
		return VariantRef(y,&y_Update);
	case 7:
		return VariantRef(width,&width_Update);
	case 8:
		return VariantRef(height,&height_Update);
	case 9:
		return VariantRef(visible,&visible_Update);
	case 10:
		return VariantRef(enabled,&enabled_Update);
	default: break;
	}
	return VariantRef();
}
using namespace CQMLGUI;
void Rectangle::Update()
{
	if(!enabled)
		return;
	if(borderColor_Update)borderColor_Update(borderColor_context);
	else
	{
		if(borderColor.red_Update)borderColor.red_Update(borderColor.red_context);
		if(borderColor.green_Update)borderColor.green_Update(borderColor.green_context);
		if(borderColor.blue_Update)borderColor.blue_Update(borderColor.blue_context);
	}
	if(border_Update)border_Update(border_context);
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
void MouseArea::Update()
{
	if(!enabled)
		return;
	 Element::Update();
DefaultUpdate();
}
void Text::Update()
{
	if(!enabled)
		return;
	if(textColor_Update)textColor_Update(textColor_context);
	else
	{
		if(textColor.red_Update)textColor.red_Update(textColor.red_context);
		if(textColor.green_Update)textColor.green_Update(textColor.green_context);
		if(textColor.blue_Update)textColor.blue_Update(textColor.blue_context);
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
	if(!enabled)
		return;
	 Text::Update();
DefaultUpdate();
}
void Image::Update()
{
	if(!enabled)
		return;
	if(img_Update)img_Update(img_context);
	else
	{
		if(img.src_Update)img.src_Update(img.src_context);
	}
	 Element::Update();
DefaultUpdate();
}
void ScaledImage::Update()
{
	if(!enabled)
		return;
	if(leftBorder_Update)leftBorder_Update(leftBorder_context);
	if(bottomBorder_Update)bottomBorder_Update(bottomBorder_context);
	if(rightBorder_Update)rightBorder_Update(rightBorder_context);
	if(topBorder_Update)topBorder_Update(topBorder_context);
	 Image::Update();
DefaultUpdate();
}
void InitDefaultHashTabs(ClassHashTable * hashTabs)
{
ClassHashTable * data;
data=&hashTabs[0];
InitHashTab(data,9,3,5);
data->maxT=5;
data->keys[0]=(char *)malloc(sizeof(char) * 4);
strcpy_s(data->keys[0],4,"red");
data->keys[1]=(char *)malloc(sizeof(char) * 6);
strcpy_s(data->keys[1],6,"green");
data->keys[2]=(char *)malloc(sizeof(char) * 5);
strcpy_s(data->keys[2],5,"blue");

data->T1[0]=8;
data->T1[1]=7;
data->T1[2]=7;
data->T1[3]=7;
data->T1[4]=3;

data->T2[0]=2;
data->T2[1]=6;
data->T2[2]=5;
data->T2[3]=8;
data->T2[4]=0;

data->g[0]=0;
data->g[1]=0;
data->g[2]=0;
data->g[3]=0;
data->g[4]=0;
data->g[5]=2;
data->g[6]=0;
data->g[7]=1;
data->g[8]=0;


data=&hashTabs[1];
InitHashTab(data,15,5,7);
data->maxT=7;
data->keys[0]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[0],8,"capital");
data->keys[1]=(char *)malloc(sizeof(char) * 7);
strcpy_s(data->keys[1],7,"italic");
data->keys[2]=(char *)malloc(sizeof(char) * 5);
strcpy_s(data->keys[2],5,"bold");
data->keys[3]=(char *)malloc(sizeof(char) * 5);
strcpy_s(data->keys[3],5,"size");
data->keys[4]=(char *)malloc(sizeof(char) * 7);
strcpy_s(data->keys[4],7,"family");

data->T1[0]=6;
data->T1[1]=2;
data->T1[2]=7;
data->T1[3]=6;
data->T1[4]=8;
data->T1[5]=2;
data->T1[6]=11;

data->T2[0]=9;
data->T2[1]=3;
data->T2[2]=7;
data->T2[3]=11;
data->T2[4]=5;
data->T2[5]=6;
data->T2[6]=3;

data->g[0]=0;
data->g[1]=0;
data->g[2]=0;
data->g[3]=0;
data->g[4]=1;
data->g[5]=3;
data->g[6]=0;
data->g[7]=0;
data->g[8]=0;
data->g[9]=0;
data->g[10]=0;
data->g[11]=2;
data->g[12]=0;
data->g[13]=1;
data->g[14]=0;


data=&hashTabs[2];
InitHashTab(data,3,1,3);
data->maxT=3;
data->keys[0]=(char *)malloc(sizeof(char) * 4);
strcpy_s(data->keys[0],4,"src");

data->T1[0]=0;
data->T1[1]=2;
data->T1[2]=1;

data->T2[0]=1;
data->T2[1]=1;
data->T2[2]=0;

data->g[0]=0;
data->g[1]=0;
data->g[2]=0;


data=&hashTabs[3];
InitHashTab(data,18,6,7);
data->maxT=7;
data->keys[0]=(char *)malloc(sizeof(char) * 2);
strcpy_s(data->keys[0],2,"x");
data->keys[1]=(char *)malloc(sizeof(char) * 2);
strcpy_s(data->keys[1],2,"y");
data->keys[2]=(char *)malloc(sizeof(char) * 6);
strcpy_s(data->keys[2],6,"width");
data->keys[3]=(char *)malloc(sizeof(char) * 7);
strcpy_s(data->keys[3],7,"height");
data->keys[4]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[4],8,"visible");
data->keys[5]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[5],8,"enabled");

data->T1[0]=0;
data->T1[1]=0;
data->T1[2]=16;
data->T1[3]=17;
data->T1[4]=6;
data->T1[5]=2;
data->T1[6]=11;

data->T2[0]=10;
data->T2[1]=14;
data->T2[2]=14;
data->T2[3]=10;
data->T2[4]=3;
data->T2[5]=1;
data->T2[6]=10;

data->g[0]=0;
data->g[1]=0;
data->g[2]=0;
data->g[3]=3;
data->g[4]=1;
data->g[5]=0;
data->g[6]=2;
data->g[7]=0;
data->g[8]=0;
data->g[9]=0;
data->g[10]=0;
data->g[11]=0;
data->g[12]=0;
data->g[13]=5;
data->g[14]=4;
data->g[15]=0;
data->g[16]=0;
data->g[17]=0;


data=&hashTabs[4];
InitHashTab(data,27,9,11);
data->maxT=11;
data->keys[0]=(char *)malloc(sizeof(char) * 12);
strcpy_s(data->keys[0],12,"borderColor");
data->keys[1]=(char *)malloc(sizeof(char) * 7);
strcpy_s(data->keys[1],7,"border");
data->keys[2]=(char *)malloc(sizeof(char) * 6);
strcpy_s(data->keys[2],6,"color");
data->keys[3]=(char *)malloc(sizeof(char) * 2);
strcpy_s(data->keys[3],2,"x");
data->keys[4]=(char *)malloc(sizeof(char) * 2);
strcpy_s(data->keys[4],2,"y");
data->keys[5]=(char *)malloc(sizeof(char) * 6);
strcpy_s(data->keys[5],6,"width");
data->keys[6]=(char *)malloc(sizeof(char) * 7);
strcpy_s(data->keys[6],7,"height");
data->keys[7]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[7],8,"visible");
data->keys[8]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[8],8,"enabled");

data->T1[0]=26;
data->T1[1]=6;
data->T1[2]=0;
data->T1[3]=22;
data->T1[4]=24;
data->T1[5]=18;
data->T1[6]=2;
data->T1[7]=26;
data->T1[8]=5;
data->T1[9]=6;
data->T1[10]=20;

data->T2[0]=3;
data->T2[1]=17;
data->T2[2]=11;
data->T2[3]=12;
data->T2[4]=21;
data->T2[5]=11;
data->T2[6]=3;
data->T2[7]=17;
data->T2[8]=10;
data->T2[9]=24;
data->T2[10]=21;

data->g[0]=0;
data->g[1]=0;
data->g[2]=0;
data->g[3]=0;
data->g[4]=0;
data->g[5]=7;
data->g[6]=0;
data->g[7]=0;
data->g[8]=0;
data->g[9]=0;
data->g[10]=0;
data->g[11]=0;
data->g[12]=0;
data->g[13]=0;
data->g[14]=4;
data->g[15]=3;
data->g[16]=0;
data->g[17]=0;
data->g[18]=1;
data->g[19]=0;
data->g[20]=0;
data->g[21]=1;
data->g[22]=8;
data->g[23]=6;
data->g[24]=1;
data->g[25]=0;
data->g[26]=0;


data=&hashTabs[5];
InitHashTab(data,18,6,7);
data->maxT=7;
data->keys[0]=(char *)malloc(sizeof(char) * 2);
strcpy_s(data->keys[0],2,"x");
data->keys[1]=(char *)malloc(sizeof(char) * 2);
strcpy_s(data->keys[1],2,"y");
data->keys[2]=(char *)malloc(sizeof(char) * 6);
strcpy_s(data->keys[2],6,"width");
data->keys[3]=(char *)malloc(sizeof(char) * 7);
strcpy_s(data->keys[3],7,"height");
data->keys[4]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[4],8,"visible");
data->keys[5]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[5],8,"enabled");

data->T1[0]=3;
data->T1[1]=16;
data->T1[2]=3;
data->T1[3]=7;
data->T1[4]=13;
data->T1[5]=15;
data->T1[6]=5;

data->T2[0]=16;
data->T2[1]=10;
data->T2[2]=5;
data->T2[3]=15;
data->T2[4]=11;
data->T2[5]=15;
data->T2[6]=17;

data->g[0]=0;
data->g[1]=0;
data->g[2]=2;
data->g[3]=0;
data->g[4]=0;
data->g[5]=0;
data->g[6]=0;
data->g[7]=0;
data->g[8]=0;
data->g[9]=0;
data->g[10]=1;
data->g[11]=0;
data->g[12]=0;
data->g[13]=0;
data->g[14]=3;
data->g[15]=3;
data->g[16]=0;
data->g[17]=1;


data=&hashTabs[6];
InitHashTab(data,12,4,6);
data->maxT=6;
data->keys[0]=(char *)malloc(sizeof(char) * 4);
strcpy_s(data->keys[0],4,"top");
data->keys[1]=(char *)malloc(sizeof(char) * 7);
strcpy_s(data->keys[1],7,"bottom");
data->keys[2]=(char *)malloc(sizeof(char) * 5);
strcpy_s(data->keys[2],5,"left");
data->keys[3]=(char *)malloc(sizeof(char) * 6);
strcpy_s(data->keys[3],6,"right");

data->T1[0]=1;
data->T1[1]=5;
data->T1[2]=2;
data->T1[3]=2;
data->T1[4]=9;
data->T1[5]=0;

data->T2[0]=2;
data->T2[1]=0;
data->T2[2]=10;
data->T2[3]=10;
data->T2[4]=8;
data->T2[5]=11;

data->g[0]=0;
data->g[1]=0;
data->g[2]=0;
data->g[3]=0;
data->g[4]=0;
data->g[5]=3;
data->g[6]=0;
data->g[7]=1;
data->g[8]=3;
data->g[9]=0;
data->g[10]=3;
data->g[11]=0;


data=&hashTabs[7];
InitHashTab(data,36,12,11);
data->maxT=11;
data->keys[0]=(char *)malloc(sizeof(char) * 10);
strcpy_s(data->keys[0],10,"textColor");
data->keys[1]=(char *)malloc(sizeof(char) * 5);
strcpy_s(data->keys[1],5,"text");
data->keys[2]=(char *)malloc(sizeof(char) * 5);
strcpy_s(data->keys[2],5,"font");
data->keys[3]=(char *)malloc(sizeof(char) * 12);
strcpy_s(data->keys[3],12,"borderColor");
data->keys[4]=(char *)malloc(sizeof(char) * 7);
strcpy_s(data->keys[4],7,"border");
data->keys[5]=(char *)malloc(sizeof(char) * 6);
strcpy_s(data->keys[5],6,"color");
data->keys[6]=(char *)malloc(sizeof(char) * 2);
strcpy_s(data->keys[6],2,"x");
data->keys[7]=(char *)malloc(sizeof(char) * 2);
strcpy_s(data->keys[7],2,"y");
data->keys[8]=(char *)malloc(sizeof(char) * 6);
strcpy_s(data->keys[8],6,"width");
data->keys[9]=(char *)malloc(sizeof(char) * 7);
strcpy_s(data->keys[9],7,"height");
data->keys[10]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[10],8,"visible");
data->keys[11]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[11],8,"enabled");

data->T1[0]=32;
data->T1[1]=30;
data->T1[2]=24;
data->T1[3]=2;
data->T1[4]=5;
data->T1[5]=1;
data->T1[6]=24;
data->T1[7]=34;
data->T1[8]=26;
data->T1[9]=10;
data->T1[10]=2;

data->T2[0]=0;
data->T2[1]=30;
data->T2[2]=32;
data->T2[3]=17;
data->T2[4]=26;
data->T2[5]=13;
data->T2[6]=6;
data->T2[7]=16;
data->T2[8]=23;
data->T2[9]=29;
data->T2[10]=35;

data->g[0]=0;
data->g[1]=0;
data->g[2]=0;
data->g[3]=0;
data->g[4]=0;
data->g[5]=9;
data->g[6]=0;
data->g[7]=0;
data->g[8]=0;
data->g[9]=11;
data->g[10]=1;
data->g[11]=11;
data->g[12]=0;
data->g[13]=4;
data->g[14]=0;
data->g[15]=0;
data->g[16]=0;
data->g[17]=0;
data->g[18]=6;
data->g[19]=0;
data->g[20]=7;
data->g[21]=0;
data->g[22]=0;
data->g[23]=0;
data->g[24]=6;
data->g[25]=0;
data->g[26]=1;
data->g[27]=0;
data->g[28]=0;
data->g[29]=0;
data->g[30]=7;
data->g[31]=0;
data->g[32]=0;
data->g[33]=3;
data->g[34]=2;
data->g[35]=0;


data=&hashTabs[8];
InitHashTab(data,36,12,11);
data->maxT=11;
data->keys[0]=(char *)malloc(sizeof(char) * 10);
strcpy_s(data->keys[0],10,"textColor");
data->keys[1]=(char *)malloc(sizeof(char) * 5);
strcpy_s(data->keys[1],5,"text");
data->keys[2]=(char *)malloc(sizeof(char) * 5);
strcpy_s(data->keys[2],5,"font");
data->keys[3]=(char *)malloc(sizeof(char) * 12);
strcpy_s(data->keys[3],12,"borderColor");
data->keys[4]=(char *)malloc(sizeof(char) * 7);
strcpy_s(data->keys[4],7,"border");
data->keys[5]=(char *)malloc(sizeof(char) * 6);
strcpy_s(data->keys[5],6,"color");
data->keys[6]=(char *)malloc(sizeof(char) * 2);
strcpy_s(data->keys[6],2,"x");
data->keys[7]=(char *)malloc(sizeof(char) * 2);
strcpy_s(data->keys[7],2,"y");
data->keys[8]=(char *)malloc(sizeof(char) * 6);
strcpy_s(data->keys[8],6,"width");
data->keys[9]=(char *)malloc(sizeof(char) * 7);
strcpy_s(data->keys[9],7,"height");
data->keys[10]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[10],8,"visible");
data->keys[11]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[11],8,"enabled");

data->T1[0]=15;
data->T1[1]=4;
data->T1[2]=2;
data->T1[3]=8;
data->T1[4]=24;
data->T1[5]=10;
data->T1[6]=11;
data->T1[7]=25;
data->T1[8]=12;
data->T1[9]=29;
data->T1[10]=26;

data->T2[0]=28;
data->T2[1]=27;
data->T2[2]=6;
data->T2[3]=3;
data->T2[4]=2;
data->T2[5]=26;
data->T2[6]=29;
data->T2[7]=18;
data->T2[8]=12;
data->T2[9]=30;
data->T2[10]=3;

data->g[0]=0;
data->g[1]=0;
data->g[2]=0;
data->g[3]=0;
data->g[4]=0;
data->g[5]=0;
data->g[6]=0;
data->g[7]=0;
data->g[8]=3;
data->g[9]=8;
data->g[10]=0;
data->g[11]=0;
data->g[12]=6;
data->g[13]=0;
data->g[14]=0;
data->g[15]=7;
data->g[16]=0;
data->g[17]=0;
data->g[18]=0;
data->g[19]=0;
data->g[20]=0;
data->g[21]=0;
data->g[22]=0;
data->g[23]=1;
data->g[24]=0;
data->g[25]=0;
data->g[26]=2;
data->g[27]=2;
data->g[28]=0;
data->g[29]=0;
data->g[30]=9;
data->g[31]=0;
data->g[32]=11;
data->g[33]=1;
data->g[34]=0;
data->g[35]=0;


data=&hashTabs[9];
InitHashTab(data,21,7,7);
data->maxT=7;
data->keys[0]=(char *)malloc(sizeof(char) * 4);
strcpy_s(data->keys[0],4,"img");
data->keys[1]=(char *)malloc(sizeof(char) * 2);
strcpy_s(data->keys[1],2,"x");
data->keys[2]=(char *)malloc(sizeof(char) * 2);
strcpy_s(data->keys[2],2,"y");
data->keys[3]=(char *)malloc(sizeof(char) * 6);
strcpy_s(data->keys[3],6,"width");
data->keys[4]=(char *)malloc(sizeof(char) * 7);
strcpy_s(data->keys[4],7,"height");
data->keys[5]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[5],8,"visible");
data->keys[6]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[6],8,"enabled");

data->T1[0]=4;
data->T1[1]=8;
data->T1[2]=4;
data->T1[3]=14;
data->T1[4]=17;
data->T1[5]=3;
data->T1[6]=11;

data->T2[0]=8;
data->T2[1]=0;
data->T2[2]=8;
data->T2[3]=2;
data->T2[4]=11;
data->T2[5]=10;
data->T2[6]=9;

data->g[0]=0;
data->g[1]=0;
data->g[2]=2;
data->g[3]=0;
data->g[4]=0;
data->g[5]=0;
data->g[6]=6;
data->g[7]=0;
data->g[8]=0;
data->g[9]=0;
data->g[10]=0;
data->g[11]=0;
data->g[12]=0;
data->g[13]=0;
data->g[14]=0;
data->g[15]=4;
data->g[16]=0;
data->g[17]=5;
data->g[18]=4;
data->g[19]=0;
data->g[20]=3;


data=&hashTabs[10];
InitHashTab(data,33,11,12);
data->maxT=12;
data->keys[0]=(char *)malloc(sizeof(char) * 11);
strcpy_s(data->keys[0],11,"leftBorder");
data->keys[1]=(char *)malloc(sizeof(char) * 13);
strcpy_s(data->keys[1],13,"bottomBorder");
data->keys[2]=(char *)malloc(sizeof(char) * 12);
strcpy_s(data->keys[2],12,"rightBorder");
data->keys[3]=(char *)malloc(sizeof(char) * 10);
strcpy_s(data->keys[3],10,"topBorder");
data->keys[4]=(char *)malloc(sizeof(char) * 4);
strcpy_s(data->keys[4],4,"img");
data->keys[5]=(char *)malloc(sizeof(char) * 2);
strcpy_s(data->keys[5],2,"x");
data->keys[6]=(char *)malloc(sizeof(char) * 2);
strcpy_s(data->keys[6],2,"y");
data->keys[7]=(char *)malloc(sizeof(char) * 6);
strcpy_s(data->keys[7],6,"width");
data->keys[8]=(char *)malloc(sizeof(char) * 7);
strcpy_s(data->keys[8],7,"height");
data->keys[9]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[9],8,"visible");
data->keys[10]=(char *)malloc(sizeof(char) * 8);
strcpy_s(data->keys[10],8,"enabled");

data->T1[0]=2;
data->T1[1]=16;
data->T1[2]=16;
data->T1[3]=4;
data->T1[4]=2;
data->T1[5]=10;
data->T1[6]=22;
data->T1[7]=10;
data->T1[8]=0;
data->T1[9]=28;
data->T1[10]=30;
data->T1[11]=5;

data->T2[0]=16;
data->T2[1]=8;
data->T2[2]=9;
data->T2[3]=24;
data->T2[4]=15;
data->T2[5]=25;
data->T2[6]=22;
data->T2[7]=13;
data->T2[8]=13;
data->T2[9]=29;
data->T2[10]=22;
data->T2[11]=1;

data->g[0]=0;
data->g[1]=0;
data->g[2]=0;
data->g[3]=0;
data->g[4]=0;
data->g[5]=0;
data->g[6]=0;
data->g[7]=0;
data->g[8]=8;
data->g[9]=5;
data->g[10]=0;
data->g[11]=0;
data->g[12]=0;
data->g[13]=0;
data->g[14]=4;
data->g[15]=0;
data->g[16]=0;
data->g[17]=0;
data->g[18]=9;
data->g[19]=0;
data->g[20]=8;
data->g[21]=10;
data->g[22]=6;
data->g[23]=0;
data->g[24]=0;
data->g[25]=1;
data->g[26]=0;
data->g[27]=0;
data->g[28]=0;
data->g[29]=3;
data->g[30]=0;
data->g[31]=0;
data->g[32]=7;


}

void AssignCQMLValue(CQMLObject * l,CQMLObject * rhs)
{
	switch(l->classID)
	{	case 0:
		*((Color*)l)=*((Color*)rhs);
		break;
	case 1:
		*((Font*)l)=*((Font*)rhs);
		break;
	case 2:
		*((Img*)l)=*((Img*)rhs);
		break;
	case 6:
		*((Anchor*)l)=*((Anchor*)rhs);
		break;
	default:
		throw 0;
		break;
	}
}

