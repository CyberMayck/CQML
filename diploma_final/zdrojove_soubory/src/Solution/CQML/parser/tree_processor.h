#pragma once
class GUIElement;
struct ParserList;
void processTree(ParserList* elementTree, int treeInd, int& elementCountOut, GUIElement * &elementsOut);