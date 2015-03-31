#pragma once


struct DrawIFace
{
	virtual void DrawRectangle(int x,int y,int w,int h,float r, float g, float b)=0;
	virtual void DrawFilledRectangle(int x,int y,int w,int h,float r, float g, float b)=0;
	virtual void DrawLine(int x1,int y1,int x2,int y2,float r, float g, float b)=0;
	virtual void DrawPoint(int x,int y,float r, float g, float b)=0;
	virtual void DrawArc(int x,int y,int w,int h, float angle1, float angle2, float r, float g, float b)=0;
	virtual void DrawFilledArc(int x,int y,int w,int h, float angle1, float angle2, float r, float g, float b)=0;
	virtual void DrawText(int x, int y, int w, int h, const char* text, void* font, float r, float g, float b)=0;
};
extern DrawIFace * drawer;
void SetDrawIFace(DrawIFace * dr);
