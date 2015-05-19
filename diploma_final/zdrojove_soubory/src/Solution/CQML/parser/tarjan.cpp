#include "tarjan.h"
#include <vector>

#include "elements.h"

int* gIndex;
int* gLink;
int* stackCnts;
bool * visited;
bool * processed;
extern int* compInds;
extern int compCnt;
int tInd=0;

#include <stack>
std::stack<int> tStack;

void tarjanRecursion(std::vector<GraphNode*> &graphNodes,int ind);


/**
 * Recurent function for cycle detection in oriented graph
 * 
 *
 * @param neighbour table
 * @param current node
 * @index of current node
 *
 * @return false if cycle not detected, true otherwise
 */
bool recursionDetectCycle(std::vector<GraphNode*> &graphNodes,GraphNode * node, int ind)
{
	if(visited[ind])
		return true;
	processed[ind]=true;
	visited[ind]=true;
	for(unsigned int i=0;i<node->nextNodes.size();i++)
	{
		if(recursionDetectCycle(graphNodes,graphNodes[node->nextNodes[i]],node->nextNodes[i]))
			return true;
	}
	visited[ind]=false;
	return false;
}

/**
 * Sorts components of graph topologically
 * 
 *
 * @param neighbour table
 */
void sortTopologically(std::vector<GraphNode*> &graphNodes)
{
	tInd=0;
	compCnt=0;
	gIndex=new int[graphNodes.size()];
	gLink=new int[graphNodes.size()];
	stackCnts=new int[graphNodes.size()];
	compInds=new int[graphNodes.size()];
	for(unsigned int i=0;i<graphNodes.size();i++)
	{
		gIndex[i]=-1;
		stackCnts[i]=0;
	}
	for(unsigned int i=0;i<graphNodes.size();i++)
	{
		if(gIndex[i]==-1)
		{
			tarjanRecursion(graphNodes, i);
		}
	}
}

/**
 * Recurent function for tarjan algorithm
 * 
 *
 * @param table of neighbours
 * @param current node index
 */
void tarjanRecursion(std::vector<GraphNode*> &graphNodes,int ind)
{
	gIndex[ind]=tInd;
	gLink[ind]=tInd;
	tInd++;
	tStack.push(ind);
	stackCnts[ind]++;

	for(unsigned int i=0;i<graphNodes[ind]->nextNodes.size();i++)
	{
		int ind2=graphNodes[ind]->nextNodes[i];
		if(gIndex[ind2]==-1)
		{
			tarjanRecursion(graphNodes,ind2);
			if(gLink[ind]>gLink[ind2])
				gLink[ind]=gLink[ind2];
		}
		else if(stackCnts[ind2]>0)
		{
			if(gLink[ind]>gIndex[ind2])
				gLink[ind]=gIndex[ind2];
		}
	}

	if(gLink[ind]==gIndex[ind])
	{
		while(true)
		{
			int ind2=tStack.top();
			tStack.pop();
			stackCnts[ind2]--;
			compInds[ind2]=compCnt;
			
			if(ind==ind2)
				break;
		}
		compCnt++;
	}
}

/**
 * Function for cycle detection in graph.
 * 
 *
 * @param table of neighbours
 *
 * @return true if cycle exists, false otherwise
 */
bool detectCycle(std::vector<GraphNode*> &graphNodes)
{
	visited=new bool[graphNodes.size()];
	processed=new bool[graphNodes.size()];
	for(int i=0,j=graphNodes.size();i<j;i++)
	{
		visited[i]=false;
		processed[i]=false;
	}
	for(unsigned int i=0;i<graphNodes.size();i++)
	{
		if(!processed[i])
		{
			if(recursionDetectCycle(graphNodes,graphNodes[i],i))
				return true;
		}
	}
	return false;
}