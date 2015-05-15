#include "hashing.h"
#include "parameter_handling.h"
#include <vector>
#include <unordered_map>

struct Edge
{
	int a;
	int b;
	string str;
};

/**
 * Function used for calculating index from table, for use in hash function.
 * 
 *
 * @param key
 * @param table of indices
 * @param number of nodes
 *
 * @return 
 */
int f1(string s, int * T, int n)
{
	int sum=0;
	for(unsigned int i=0;i<s.length();i++)
	{
		sum+=T[i]*(unsigned char)s[i];
	}
	sum=sum%n;
	return sum;
}

/**
 * Gets key representing an edge.
 * 
 *
 * @param index of first node
 * @param index of second node
 * @param number of nodes
 * @param number of edges
 * @param array of edges
 *
 * @return key representing the edge, or "" if invalid.
 */
string getEdgeStr(int u, int v, int n, int m, Edge * edges)
{
	for(int i=0;i<n;i++)
	{
		if((edges[i].a==u && edges[i].b==v) || (edges[i].b==u && edges[i].a==v))
			return edges[i].str;
	}
	return "";
}

/**
 * Gets index of an edge.
 * 
 *
 * @param index of first node
 * @param index of second node
 * @param number of nodes
 * @param number of edges
 * @param array of edges
 *
 * @return edge index, or -1 if invalid.
 */
int getEdgeInd(int u, int v, int n, int m, Edge * edges)
{
	for(int i=0;i<n;i++)
	{
		if((edges[i].a==u && edges[i].b==v) || (edges[i].b==u && edges[i].a==v))
			return i;
	}
	return -1;
}

/**
 * Calculates hash value for a key.
 * 
 *
 * @param key
 * @param node count
 * @param key count
 * @param table T1
 * @param table T2
 * @param values of graph nodes
 *
 * @return hash value
 */
int h(string s, int n,int m, int * T1, int *T2, int*g)
{
	int u=f1(s,T1,n);
	int v=f1(s,T2,n);
	int a=g[u];
	int b=g[v];
	int retVal=(g[u]+g[v])%m;
	return retVal;
}

/**
 * Recurent function that assigns values to graph, used for calculating hash function.
 * 
 * @param current node index
 * @param number of nodes
 * @param number of keys
 * @param pointer to array determing if node was visited
 * @param arrays of neighbours of each node.
 * @param array of graph edges.
 * @param array of values of nodes.
 */
void traverse(int ind, int n, int m, bool * visited, vector<int>* &neighbours, Edge * edges, int*g)
{
	visited[ind]=true;
	for(unsigned int i=0;i<neighbours[ind].size();i++)
	{
		if(visited[neighbours[ind][i]])
			continue;
		int gInd=neighbours[ind][i];
		int a=g[ind];
		//g[neighbours[ind][i]]= (h(getEdgeStr(ind,neighbours[ind][i],n,m),n,m)-g[ind])%m;
		g[neighbours[ind][i]]= ((getEdgeInd(ind,neighbours[ind][i],n,m,edges)-g[ind])+m)%m;

		int meh=g[neighbours[ind][i]];
		traverse(neighbours[ind][i],n,m,visited,neighbours,edges,g);
	}
}

/**
 * Recurent function for depth-first search for checking acyclicity
 * 
 *
 * @param index of node
 * @param first node visited in depth search
 * @param number of nodes
 * @param pointer to array determing if node was visited
 * @param arrays of neighbours of each node.
 * 
 * @return false if graph cannot be acyclic, true otherwise
 */
bool traverseAc(int ind, int origin, int n, bool * visited, vector<int>* &neighbours)
{
	if(visited[ind])
		return false;
	visited[ind]=true;
	bool originVisited=false;
	for(unsigned int j=0;j<neighbours[ind].size();j++)
	{
		if(neighbours[ind][j]==origin)
		{
			if(originVisited)
				return false;
			else
				originVisited=true;
			continue;
		}
		bool retVal=traverseAc(neighbours[ind][j],ind,n,visited,neighbours);
		if(!retVal)
			return false;
	}
	visited[ind]=false;
	return true;
}

/**
 * Checks acyclicity of graph used for generating hash function.
 * 
 *
 * @param number of nodes
 * @param pointer to array determing if node was visited
 * @param arrays of neighbours of each node.
 *
 * @return true if acyclic, false otherwise
 */
bool checkAcyclicity(int n, bool * visited, vector<int>* &neighbours)
{
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<n;i++)
	{
		//if(visited[i])
		//	continue;
		visited[i]=true;
		for(unsigned int j=0;j<neighbours[i].size();j++)
		{
			bool retVal=traverseAc(neighbours[i][j],i,n,visited,neighbours);
			if(!retVal)
				return false;
		}
		visited[i]=false;
	}
	return true;
}


/**
 * Calculates perfect hash function.
 * 
 *
 * @param array of keys.
 * @param number of keys.
 *
 * @return hash function data.
 */
PerfectHashData * makePerfectHash(vector<string> & strs, int cnt)
{
	int n=3*cnt; // or alphabet size
	bool *visited= new bool[n];
	vector<int>*neighbours;
	
	Edge * edges;
	
	unsigned int max=0;
	for(int i=0;i<cnt;i++)
	{
		//visited[i]=false;
		//g[i]=0;
		if(max<strs[i].length())
			max=strs[i].length();
	}
	int * T1=new int[max];
	int * T2=new int[max];

	int hhh=0;
	int treshold=100;

	while(true)
	{
		if(hhh<treshold)
		{
			hhh++;
		}
		else
		{
			n++;
			hhh=0;
			delete visited;
			visited=new bool[n];
		}
		for(unsigned int i=0;i<max;i++)
		{
			T1[i] = rand() % n;
			T2[i] = rand() % n;
		}

		neighbours=new vector<int>[n];
		edges = new Edge[cnt];
		for(int i=0;i<cnt;i++)
		{
			int v1=f1(strs[i],T1,n);
			int v2=f1(strs[i],T2,n);
			neighbours[v1].push_back(v2);
			neighbours[v2].push_back(v1);
			edges[i].a=v1;
			edges[i].b=v2;
			edges[i].str=strs[i];
			//cout << v1 << "   " << v2 << endl;
		}
		//cout << endl;

		if(checkAcyclicity(n,visited,neighbours))
			break;
		delete [] neighbours;
		delete [] edges;
	}
	int * g=new int[n];

	for(int i=0;i<n;i++)
	{
		visited[i]=false;
		g[i]=0;
	}
	int m=cnt;
	for(int i=0;i<n;i++)
	{
		if(visited[i])
			continue;
		g[i]=0;
		traverse(i,n,m,visited,neighbours,edges,g);
	}
	
	for(int i=0;i<cnt;i++)
	{
		//cout << strs[i] << "\t" << h(strs[i],n,m) << endl;
	}
	PerfectHashData * data=new PerfectHashData();
	data->g=g;
	data->keys = new string[m];
	for(int i=0;i<cnt;i++)
	{
		data->keys[h(strs[i],n,m,T1,T2,g)]=strs[i];
	}
	data->T1=T1;
	data->T2=T2;
	data->n=n;
	data->m=m;
	data->maxT=max;

	delete[] edges;
	delete[] visited;
	delete [] neighbours;

	return data;

}

/**
 * Calculates hash function for class reprezented by class container.
 * 
 *
 * @param class container
 *
 * @return hash function data
 */
PerfectHashData * makeHashFromClass(ClassContainer * cont)
{
	vector<string> names;
	ClassContainer * curCont=cont;
	while(true)
	{
		for(unsigned int i=0;i<curCont->props.size();i++)
		{
			if(curCont->props[i].isDefault)
				continue;
			names.push_back(curCont->props[i].name);
		}

		curCont=curCont->GetAncestor();
		if(curCont==0)
		{
			break;
		}
	}
	return makePerfectHash(names,names.size());
}

extern vector<ClassContainer*> defaultClasses;
extern unordered_map<string, int> defaultClassMap;
extern vector<ClassContainer*> classes[100];
extern unordered_map<string, int> classMaps[100];
extern vector<PrimitiveType*> primitiveTypes;
extern unordered_map<string, int> primitiveTypeMap;
extern int totalClassCnt;
extern int elementTreeCnt;

/**
 * 
 * Calculates all hash function for all classes.
 */
void MakeAllHashes()
{
	for(unsigned int j=0;j<defaultClasses.size();j++)
	{
		defaultClasses[j]->hashData=makeHashFromClass(defaultClasses[j]);
	}

	for(int j=0;j<elementTreeCnt;j++)
	{
		for(unsigned int k=0;k<classes[j].size();k++)
		{
			classes[j][k]->hashData= makeHashFromClass(classes[j][k]);
		}
	}
}