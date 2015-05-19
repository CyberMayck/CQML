#pragma once
#include <string>
class GUIElement;
void printOutputListFile(int cnt);
void PrintHelp();
void makeSource(std::string name, int treeInd, GUIElement* elements, int elementCount);
void makeMainSource(int elementTreeCnt);