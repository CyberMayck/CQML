#pragma once
#define DIR_UP (3)
#define DIR_DOWN (1)
#define DIR_LEFT (2)
#define DIR_RIGHT (0)

bool CanMove(int x, int y, int status);

void WindowLimit(int w, int h);
void PrintNumber(int a);
extern int meta;