#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <unordered_map>
//#include "lex.yy.c"
//#include "cqml_grammar.tab.c"
//#include "cqml_grammar.tab.h"
#include "cqml_grammar.tab.h"
#include "parser_tree.h"
typedef struct yy_buffer_state *YY_BUFFER_STATE;

void PrintNodeToFile(SrcNode* node);

class GUIElement;
class GUIElementAttribute;


class GraphNode
{
public:
	std::string key;
	std::vector<int> nextNodes;
};

std::unordered_map<std::string, int> keyMap;
std::vector<GraphNode*> graphNodes;

class GUIElement
{
public:
	int id;
	int parentId;
	char * name;
	GUIElement ** children;
	GUIElementAttribute * attributes;
	int childrenCount;
	int attributeCount;
};

class GUIElementAttribute
{
public:
	char * name;
	SrcNode * expression;
	int graphInd;
};

GUIElement * elements;
int elementCount;

ParserList* elementTree;
std::unordered_map<std::string, int> idMap;

extern "C"
{
YY_BUFFER_STATE yy_scan_string(char *);
YY_BUFFER_STATE yyrestart(FILE * file);
YY_BUFFER_STATE yyparse();
}

FILE *file;
int id;

int * identifiersIds;
char ** identifiers;
int identifiersCount;
int identifiersMax;

int rootElements[100];
int rootElementCount;




#include <stack>
std::stack<int> tStack;
int tInd=0;
int compInd=0;

int* gIndex;
int* gLink;
int* stackCnts;
int* compInds;
void tarjanRecursion(int ind);


char * firstIDrec(SrcNode* node)
{
	int i;
	char * txt;
	if((*node).text!=0)
	{
		return (*node).text;
	}
	
	for(i=0;i<(*node).childrenCount;i++)
	{
		txt=firstIDrec((*node).children[i]);
		if(txt!=0)
			return txt;
	}
	return 0;
}


void PrintNode(SrcNode* node)
{
	int i;
	if((*node).text!=0)// && (*node).type==NODE_TYPE_ID)
	{
		printf("id: %s",(*node).text);
	}
	for(i=0;i<(*node).childrenCount;i++)
	{
		PrintNode((*node).children[i]);
	}
}



void printAttributes()
{
	int i;
	ParserAttribute* att;
	int currentId;
	currentId=id;

	for(int k=compInd-1;k>=0;k--)
	{
		for(int i=0;i<elementCount;i++)
		{
			for(int j=0;j<elements[i].attributeCount;j++)
			{
				GUIElementAttribute* att=&elements[i].attributes[j];
				if(compInds[att->graphInd]!=k)
				{
					continue;
				}
				if(strcmp("id",att->name)==0)
				{
					continue;
				}
				fprintf(file, "_QML_element%d->%s=",i,att->name);
				
				PrintNodeToFile(att->expression);
				fprintf(file, ";\n");
			}
		}
	}
}


void recursionDeclaration()
{
	for(int i=0;i<elementCount;i++)
	{
		fprintf(file, "GUI_Element* _QML_element%d;\n",i);
	}
}

void recursionInit()
{
	for(int i=0;i<elementCount;i++)
	{
		fprintf(file, "_QML_element%d = (GUI_Element*)acGUI_%s();\n",i,elements[i].name);
	}
	for(int i=0;i<elementCount;i++)
	{
	//	fprintf(file, "_QML_element%d = (GUI_Element*)acGUI_%s();\n",i,elements[i].name);
		for(int j=0;j<elements[i].childrenCount;j++)
		{
			fprintf(file, "mGUI_Element_InsertChild((GUI_Element*)_QML_element%d, (GUI_Element*)_QML_element%d);\n",i,elements[i].children[j]->id);
		}
	}
}

bool * visited;
bool * processed;

bool recursionDetectCycle(GraphNode * node, int ind)
{
	if(visited[ind])
		return true;
	processed[ind]=true;
	visited[ind]=true;
	for(int i=0;i<node->nextNodes.size();i++)
	{
		if(recursionDetectCycle(graphNodes[node->nextNodes[i]],node->nextNodes[i]))
			return true;
	}
	visited[ind]=false;
	return false;
}

void sortTopologically()
{
	gIndex=new int[graphNodes.size()];
	gLink=new int[graphNodes.size()];
	stackCnts=new int[graphNodes.size()];
	compInds=new int[graphNodes.size()];
	for(int i=0;i<graphNodes.size();i++)
	{
		gIndex[i]=-1;
		stackCnts[i]=0;
	}
	for(int i=0;i<graphNodes.size();i++)
	{
		if(gIndex[i]==-1)
		{
			tarjanRecursion(i);
		}
	}
}

void tarjanRecursion(int ind)
{
	gIndex[ind]=tInd;
	gLink[ind]=tInd;
	tInd++;
	tStack.push(ind);
	stackCnts[ind]++;

	for(int i=0;i<graphNodes[ind]->nextNodes.size();i++)
	{
		int ind2=graphNodes[ind]->nextNodes[i];
		if(gIndex[ind2]==-1)
		{
			tarjanRecursion(ind2);
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
			compInds[ind2]=compInd;
			
			if(ind==ind2)
				break;
		}
		compInd++;
	}
}

bool detectCycle()
{
	visited=new bool[graphNodes.size()];
	processed=new bool[graphNodes.size()];
	for(int i=0,j=graphNodes.size();i<j;i++)
	{
		visited[i]=false;
		processed[i]=false;
	}
	for(int i=0;i<graphNodes.size();i++)
	{
		if(!processed[i])
		{
			if(recursionDetectCycle(graphNodes[i],i))
				return true;
		}
	}
	return false;
}

void makeSource()
{
	//ParserList* list;
	int i;
	//list=(ParserList*)l;

	//printf("\n");
	//return;
	file = fopen("parser_output.c","w");
	
	fprintf(file, "GUI_Element* root;\n");
	id=0;

	recursionDeclaration();
	fprintf(file, "\n");
	
	id=0;
	fprintf(file,"void _QML_Init()\n{\n");
	fprintf(file, "root = (GUI_Element*) acGUI_Element();\n");
	recursionInit();
	
	for(int i=0;i<rootElementCount;i++)
	{
		fprintf(file, "mGUI_Element_InsertChild((GUI_Element*)root, (GUI_Element*)_QML_element%d);\n",rootElements[i]);
	}

	bool cycle=detectCycle();

	if(cycle)
	{
		printf("Cycle Detected\n");
	}
	sortTopologically();

	printAttributes();


	fprintf(file,"\n}\n");

	fclose(file);
}



GUIElement * recursionProcessTree(ParserGUIElement * element)
{
	int i;
	elements[id]=GUIElement();
	GUIElement * instance=&elements[id];

	int childCnt=0;
	int attribCnt=0;
	if(element->list!=0)
	{
		for(i=0;i<element->list->memberCount;i++)
		{
			if(element->list->members[i]->type==TYPE_GUI_ELEMENT)
			{
				childCnt++;
			}
			else if(element->list->members[i]->type==TYPE_ATTRIBUTE)
			{
				attribCnt++;
			}
		}
	}
	instance->attributeCount=attribCnt;
	instance->attributes=new GUIElementAttribute[attribCnt];
	instance->childrenCount=childCnt;
	instance->children=new GUIElement*[childCnt];
	instance->id=id;
	instance->name=element->name;


	id++;
	childCnt=0;
	attribCnt=0;
	if(element->list!=0)
	{
		for(i=0;i<element->list->memberCount;i++)
		{
			if(element->list->members[i]->type==TYPE_GUI_ELEMENT)
			{
				instance->children[childCnt]=recursionProcessTree((ParserGUIElement *)element->list->members[i]);
				instance->children[childCnt]->parentId=instance->id;
				childCnt++;
			}
			else if(element->list->members[i]->type==TYPE_ATTRIBUTE)
			{
				instance->attributes[attribCnt]=GUIElementAttribute();
				instance->attributes[attribCnt].name=((ParserAttribute *)element->list->members[i])->name;
				instance->attributes[attribCnt].expression=((ParserAttribute *)element->list->members[i])->expression;
				attribCnt++;
			}
		}
	}

	return instance;
}

void recursionCount(ParserGUIElement * element)
{
	elementCount++;
	if((*element).list!=0)
	{
		for(int i=0;i<(*(*element).list).memberCount;i++)
		{
			if((*(*(*element).list).members[i]).type==TYPE_GUI_ELEMENT)
				recursionCount((ParserGUIElement *)(*(*element).list).members[i]);
		}
	}
}
bool processSrcDots(SrcNode * node, int currentElementId, int graphInd);

void processSrcReferences(SrcNode * node, int currentId, bool leftMostFound, bool dotNodePassed, int graphInd)
{
	char str[100];
			if(node->type==NODE_TYPE_DOT)
			{
				dotNodePassed=true;
			}
			else if(node->type==NODE_TYPE_ID)
			{
				bool isOtherId=idMap.count(std::string(node->text))!=0;
				//if(leftMostFound)
				{
					if(isOtherId)
					{
						int otherId=idMap[std::string(node->text)];
						free(node->text);
						sprintf(str,"(*_QML_element%d)",otherId);
						node->text=new char[strlen(str)+1];
						strcpy(node->text,str);
					}
					else
					{
						if(strcmp("parent",node->text)==0)
						{
							free(node->text);
							sprintf(str,"(*_QML_element%d->parent)",currentId);
							node->text=new char[strlen(str)+1];
							strcpy(node->text,str);
						}
						else// if(is valid att?) //complete
						{
							sprintf(str,"(*_QML_element%d).%s",currentId,node->text);

							std::string key=std::to_string(static_cast<long long>(currentId))+std::string(".")+std::string(node->text);

							free(node->text);
							node->text=new char[strlen(str)+1];
							strcpy(node->text,str);

							if(keyMap.count(key)!=0)
							{
								graphNodes[keyMap[key]]->nextNodes.push_back(graphInd);
							}
							else
							{
								GraphNode* graphNode=new GraphNode();
								graphNode->key=key;
								graphNode->nextNodes.push_back(graphInd);
								keyMap[key]=graphNodes.size();
								graphNodes.push_back(graphNode);
								//graphNodespush_back();
							}



						}
						//else //nothing
					}
				}
			}
	if(!dotNodePassed)
	{
		for(int i=0;i<node->childrenCount;i++)
		{
			processSrcReferences(node->children[i],currentId,leftMostFound,dotNodePassed, graphInd);
		}
	}
	else
	{
		if(processSrcDots(node, currentId, graphInd))
		{
			node->type=NODE_TYPE_DOT_PROCESSED;
		}
	}
}
//class 
int countDotIds(SrcNode * node)
{
	if(node->type==NODE_TYPE_LEAF)
		return -1;
	if(node->type==NODE_TYPE_ID)
		return 1;

	int cnt=0;
	int val=0;
	for(int i=0;i<node->childrenCount;i++)
	{
		if(node->type==NODE_TYPE_DOT && i==1)
			continue;
		
		val=countDotIds(node->children[i]);
		if(val<0)
			return -1;
		cnt+=val;
	}
	return cnt;
}

int fillIds(SrcNode * node, std::string* identifiers, int ind)
{
	if(node->type==NODE_TYPE_ID)
	{
		identifiers[ind]=std::string(node->text);
		ind++;
	}
	else
	{
		for(int i=0;i<node->childrenCount;i++)
		{		
			ind=fillIds(node->children[i],identifiers, ind);
		}
	}
	return ind;
}

bool processSrcDots(SrcNode * node, int currentElementId, int graphInd)
{
	int cnt=countDotIds(node);
	if(cnt<1)
		return false;

	std::string* identifiers = new std::string[cnt];
	fillIds(node,identifiers,0);

	//bool prevParam=false;
	bool prevElement=false;
	bool isOtherId=idMap.count(identifiers[0])!=0;
	int curId=currentElementId;
	if(isOtherId)
	{
		curId=idMap[identifiers[0]];
	}
	else
	{
		if(identifiers[0]==std::string("parent"))
		{
			prevElement=true;
			curId=elements[curId].parentId;
		}
		else //if(is valid param identifiers[0])
		{
			prevElement=false;
		}
	}
	std::string attribs("");
	for(int i=1;i<cnt;i++)
	{
		if(prevElement)
		{
			if(identifiers[i]==std::string("parent"))
			{
				prevElement=true;
				curId=elements[curId].parentId;
			}
			else
			{
				attribs+="."+identifiers[i];
				prevElement=false;
			}
		}
		else
		{
			if(identifiers[i]==std::string("parent"))
			{
				return false;
			}
			attribs+="."+identifiers[i];
		}
	}
	
	std::string key=std::to_string(static_cast<long long>(curId))+attribs;
	//std::unordered_map<std::string, int> keyMap;
	//std::vector<GraphNode*> graphNodes;
	
	if(keyMap.count(key)!=0)
	{
		graphNodes[keyMap[key]]->nextNodes.push_back(graphInd);
	}
	else
	{
		GraphNode* graphNode=new GraphNode();
		graphNode->key=key;
		graphNode->nextNodes.push_back(graphInd);
		keyMap[key]=graphNodes.size();
		graphNodes.push_back(graphNode);
		//graphNodespush_back();
	}
	//attribs;
	//curId ///vex

	attribs=std::string("(*_QML_element")+std::to_string(static_cast<long long>(curId))+std::string(")")+attribs;
	//attribs
	node->text=new char[attribs.length()+1];
	std::strcpy(node->text,attribs.c_str());

	return true;
}




void PrintNodeToFile(SrcNode* node)
{
	int i;
	if((*node).text!=0)
	{
		fprintf(file, "%s",node->text);
	}
	if(node->type!=NODE_TYPE_DOT_PROCESSED)
	{
		for(i=0;i<(*node).childrenCount;i++)
		{
			PrintNodeToFile(node->children[i]);
		}
	}
	else
	{
		printf("");
	}
}

std::string expressionToStr(SrcNode * node)
{
	if(node->text!=0)// && (*node).type==NODE_TYPE_ID)
	{
		if(node->text)
			return std::string(node->text);
	}
	std::string str("");
	for(int i=0;i<node->childrenCount;i++)
	{
		str+=expressionToStr(node->children[i]);
	}
	return str;
}

void processTree(ParserList* root)
{
	//int id=0;
	elementCount=0;
	for(int i=0;i<elementTree->memberCount;i++)
	{
		recursionCount((ParserGUIElement*)elementTree->members[i]);
	}
	elements=new GUIElement[elementCount];
	
	id=0;
	for(int i=0;i<elementTree->memberCount;i++)
	{
		rootElements[rootElementCount]=id;
		recursionProcessTree((ParserGUIElement*)elementTree->members[i]);
		elements[rootElements[rootElementCount]].parentId=-1;
		rootElementCount++;
	}

	// create ids
	for(int i=0;i<elementCount;i++)
	{
		for(int j=0;j<elements[i].attributeCount;j++)
		{
			GUIElementAttribute * att=&elements[i].attributes[j];
			if(strcmp(att->name,"id")==0)
			{
				//char * getString() error
				idMap[expressionToStr(att->expression)]=i;
			}
			break; // should check for duplicities !!!
		}
	}

	// process expressions
	for(int i=0;i<elementCount;i++)
	{
		for(int j=0;j<elements[i].attributeCount;j++)
		{
			GUIElementAttribute * att=&elements[i].attributes[j];
			// should check for duplicities !!!

			if(strcmp(att->name,"id")==0)
				continue;
			std::string key=std::to_string(static_cast<long long>(i))+"."+std::string(att->name);
			int graphInd;
			
			if(keyMap.count(key)!=0)
			{
				graphInd=keyMap[key];//->nextNodes.push_back(graphInd);
			}
			else
			{
				GraphNode* graphNode=new GraphNode();
				graphNode->key=key;
				graphInd=graphNodes.size();
				keyMap[key]=graphInd;
				graphNodes.push_back(graphNode);
				//graphNodespush_back();
			}
			att->graphInd=graphInd;
			
			processSrcReferences(att->expression,i,false,false,graphInd);
		}
	}
}



int node(int a, char b, int c, char * d)
{
	//printf("\n a%s",d);
	if(b=='l' || b=='L')
	{
		printf("\n%d List %d \n",a,c);
		return 77;
	}
	else
	{
		printf("\n%d Node %d \n",a,c);
		printf("%s\n",d);

		return 33;
	}
}

void outputFile()
{
	FILE *file;
	file = fopen("file.c","w");
	fprintf(file,"%s","stuff");
	fclose(file);
}

int main()
{
	FILE *srcFile;
	int a=0;
	id=0;
	srcFile = fopen("src4.cqml","r");
	
	identifiersCount=0;
	identifiersMax=100;
	identifiers=(char**)malloc(sizeof(char*)*identifiersMax);
	identifiersIds=(int*)malloc(sizeof(int)*identifiersMax);
	

    yyrestart(srcFile);
	//yy_scan_string("Rectangle { Rectangle { Rectangle { }; }; Rectangle { }; }");
	
	if(yyparse())
	{
		a=1;//eror
	}
	processTree(elementTree);
	makeSource();
	fclose(srcFile);
	printf("\n%d\n",compInd);
	scanf("%d",&a);

	return 0;
}