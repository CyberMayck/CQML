#ifndef DRAWIFACE_H
#define DRAWIFACE_H

typedef struct DrawIFace DrawIFace;

struct DrawIFace
{
	void (*DrawRectangle)(int x,int y,int w,int h,float r, float g, float b);
	void (*DrawFilledRectangle)(int x,int y,int w,int h,float r, float g, float b);
	void (*DrawLine)(int x1,int y1,int x2,int y2,float r, float g, float b);
	void (*DrawPoint)(int x,int y,float r, float g, float b);
	void (*DrawArc)(int x,int y,int w,int h, float angle1, float angle2, float r, float g, float b);
	void (*DrawFilledArc)(int x,int y,int w,int h, float angle1, float angle2, float r, float g, float b);
};
extern DrawIFace * drawer;
void SetDrawIFace(DrawIFace * dr);

#endif