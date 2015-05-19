#pragma once
#include <vector>
class GraphNode;
void sortTopologically(std::vector<GraphNode*> &graphNodes);
bool detectCycle(std::vector<GraphNode*> &graphNodes);