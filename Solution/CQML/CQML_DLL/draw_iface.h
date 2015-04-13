#pragma once


#include "dll_export.h"

struct DrawIFace
{
	virtual void DrawRectangle(int x,int y,int w,int h,float r, float g, float b)=0;
	virtual void DrawFilledRectangle(int x,int y,int w,int h,float r, float g, float b)=0;
	virtual void DrawFilledBorderedRectangle(int x,int y,int w,int h,float r, float g, float b, float border, float br, float bg, float bb)=0;
	virtual void DrawLine(int x1,int y1,int x2,int y2,float r, float g, float b)=0;
	virtual void DrawPoint(int x,int y,float r, float g, float b)=0;
	virtual void DrawArc(int x,int y,int w,int h, float angle1, float angle2, float r, float g, float b)=0;
	virtual void DrawFilledArc(int x,int y,int w,int h, float angle1, float angle2, float r, float g, float b)=0;
	virtual void DrawText(int x, int y, int w, int h, const char* text, void* font, float r, float g, float b)=0;
	virtual void DrawImage(int x, int y, int w, int h, void* image)=0;
	virtual void DrawImageSegment(int x, int y, int w, int h, void* image, int iX, int iY, int iW, int iH)=0;
};
extern DrawIFace * drawer;
CQML_API void SetDrawIFace(DrawIFace * dr);
