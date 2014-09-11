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

void PrintNodeToFile(FILE* file, SrcNode* node);

class GUIElement;
class GUIElementAttribute;
class GUIElementProperty;
class GUIElementHandler;
class GUIImport;

class GUIImport
{
public:
	bool processed;
	GUIImport(){processed=false;}
	std::string name;
	std::string path;
	int treeInd;
};

class GraphNode
{
public:
	std::string key;
	std::vector<int> nextNodes;
};

std::unordered_map<std::string, int> keyMap;
std::vector<GraphNode*> graphNodes;

std::unordered_map<std::string, bool> importsProcessed;
std::vector<GUIImport> imports;

int importCnt=0;

std::unordered_map<std::string, int> importMap;
std::vector<GraphNode*> importGraph;


std::unordered_map<std::string, int> importToKeyMaps[100];
std::unordered_map<std::string, std::string> importPathToName;

class GUIElement
{
public:
	int id;
	int parentId;
	char * name;
	char * origClassName;
	bool hasCustomClass;
	GUIElement ** children;
	GUIElementAttribute * attributes;
	GUIElementProperty * properties;
	GUIElementHandler * handlers;
	int childrenCount;
	int attributeCount;
	int handlerCount;
	int propertiesCount;
	GUIElement();
};

GUIElement::GUIElement()
{
	hasCustomClass=false;
}

class GUIElementProperty
{
public:
	char * typeName;
	char * name;
	//int graphInd;
};

class GUIElementAttribute
{
public:
	char * name;
	SrcNode * expression;
	int graphInd;
};


class GUIElementHandler
{
public:
	char * name;
	SrcNode * code;
	int graphInd;
};

GUIElement * elements;
int elementCount;

GUIElement * elementGroups[100];
int elementGroupSizes[100];

ParserList* elementTree;
std::unordered_map<std::string, int> idMaps[100];

extern "C"
{
YY_BUFFER_STATE yy_scan_string(char *);
YY_BUFFER_STATE yyrestart(FILE * file);
YY_BUFFER_STATE yyparse();
}

FILE *file;
FILE *file_classes;
FILE *file_classes2;
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
void tarjanRecursion(std::vector<GraphNode*> &graphNodes,int ind);


ParserList * elementTrees[100];
int elementTreeGInds[100];
int elementTreeCnt=0;


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

void printHandlerAssignment()
{
	int i;

	int currentId;
	currentId=id;

	for(int k=compInd-1;k>=0;k--)
	{
		for(int i=0;i<elementCount;i++)
		{
			for(int j=0;j<elements[i].handlerCount;j++)
			{
				GUIElementHandler* handler=&elements[i].handlers[j];
				if(compInds[handler->graphInd]!=k)
				{
					continue;
				}
				fprintf(file_classes2, "self->_QML_element%d->Custom%s=_QML_element%d_%s;\n",i,handler->name,i,handler->name);
			}
		}
	}
}

void printHandlers()
{
	int i;

	int currentId;
	currentId=id;

	for(int k=compInd-1;k>=0;k--)
	{
		for(int i=0;i<elementCount;i++)
		{
			for(int j=0;j<elements[i].handlerCount;j++)
			{
				GUIElementHandler* handler=&elements[i].handlers[j];
				if(compInds[handler->graphInd]!=k)
				{
					continue;
				}
				fprintf(file_classes2, "static void _QML_element%d_%s(GUI_Element * self, QMLEvent Event)\n{\n",i,handler->name);
				
				PrintNodeToFile(file_classes2,handler->code);
				fprintf(file_classes2, "\n}\n");
			}
		}
	}
}


void printAttributes()
{
	int i;
	//ParserAttribute* att;
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
				fprintf(file_classes2, "self->_QML_element%d->%s=",i,att->name);
				
				PrintNodeToFile(file_classes2,att->expression);
				fprintf(file_classes2, ";\n");
			}
		}
	}
}

void classDeclaration(const char* rootName)
{
	int customClassCount=0;
	fprintf(file_classes,"typedef struct GUI_Root%s GUI_Root%s;\n\n",rootName,rootName);

	for(int i=0;i<elementCount;i++)
	{
		if(!elements[i].hasCustomClass)
			continue;

		
		char * customClassName= new char[100];
		sprintf(customClassName,"%sCustom%d",elements[i].name,customClassCount);
		customClassCount++;
		//clear?
		elements[i].origClassName=elements[i].name;
		elements[i].name=customClassName;
		
		fprintf(file_classes,"typedef struct GUI_%s GUI_%s;\n\n",elements[i].name,elements[i].name);
	}
	for(int i=0;i<elementCount;i++)
	{
		if(!elements[i].hasCustomClass)
			continue;
		
		fprintf(file_classes,"struct GUI_%s\n{\n",elements[i].name);
		fprintf(file_classes,"GUI_%s original;\n",elements[i].origClassName);

		for(int j=0;j<elements[i].propertiesCount;j++)
		{
			GUIElementProperty * prop= &elements[i].properties[j];
			fprintf(file_classes,"%s %s;\n",prop->typeName,prop->name);
		}
		fprintf(file_classes,"};\n");

		fprintf(file_classes,"GUI_%s* acGUI_%s();\n",elements[i].name,elements[i].name);

		fprintf(file_classes2,"GUI_%s* acGUI_%s()\n{\n",elements[i].name,elements[i].name);
		fprintf(file_classes2,"GUI_%s * pointer;\npointer=(GUI_%s*)malloc(sizeof(GUI_%s));\n",elements[i].name,elements[i].name,elements[i].name);

		fprintf(file_classes2,"pointer->original=cGUI_%s();\n",elements[i].origClassName);
		fprintf(file_classes2,"return pointer;\n");

		fprintf(file_classes2,"}\n");
	}


}

void recursionDeclaration(const char * rootName)
{
	fprintf(file_classes,"struct GUI_Root%s\n{\n",rootName);
	fprintf(file_classes,"GUI_Element base;\n");
	for(int i=0;i<elementCount;i++)
	{
		
		//fprintf(file, "GUI_Element* _QML_element%d;\n",i);
		fprintf(file_classes, "GUI_Element* _QML_element%d;\n",i);
	}
	fprintf(file_classes,"};\n");
}

void recursionInit(const char * rootName, int treeInd)
{
	
		fprintf(file_classes,"GUI_Root%s* acGUI_Root%s();\n",rootName,rootName);
		fprintf(file_classes,"GUI_Root%s cGUI_Root%s();\n",rootName,rootName);

		fprintf(file_classes2,"GUI_Root%s* acGUI_Root%s()\n{\n",rootName,rootName);
		fprintf(file_classes2,"GUI_Root%s * pointer;\npointer=(GUI_Root%s*)malloc(sizeof(GUI_Root%s));\n",rootName,rootName,rootName);

		//fprintf(file_classes2,"pointer->original=cGUI_Root();\n",elements[i].origClassName);
		fprintf(file_classes2,"*pointer=cGUI_Root%s((GUI_Element *)pointer);\n",rootName);
		fprintf(file_classes2, "mGUI_Element_InsertChild((GUI_Element*)pointer, (GUI_Element*)pointer->_QML_element0);\n");
		fprintf(file_classes2,"return pointer;\n");

		fprintf(file_classes2,"}\n");
		
		fprintf(file_classes2,"GUI_Root%s cGUI_Root%s(GUI_Element * pointer)\n{\n",rootName,rootName);
		fprintf(file_classes2,"GUI_Root%s s;\n",rootName);
		fprintf(file_classes2,"GUI_Root%s * self=&s;\n",rootName);
		fprintf(file_classes2,"self->base=cGUI_Element();\n");
		fprintf(file_classes2,"self->base.root=(GUI_Element*)self;\n");

	for(int i=0;i<elementCount;i++)
	{
		bool isImportName=importToKeyMaps[treeInd].count(std::string(elements[i].name))!=0;
		if(isImportName)
		{
			const char *nam= importPathToName[imports[importToKeyMaps[treeInd][std::string(elements[i].name)]].path].c_str();
			fprintf(file_classes2, "self->_QML_element%d = (GUI_Element*)acGUI_Root%s();\n",i,nam);
		}
		else
			fprintf(file_classes2, "self->_QML_element%d = (GUI_Element*)acGUI_%s();\n",i,elements[i].name);
		fprintf(file_classes2, "self->_QML_element%d->root=pointer;\n",i);
	}
	for(int i=0;i<elementCount;i++)
	{
	//	fprintf(file, "_QML_element%d = (GUI_Element*)acGUI_%s();\n",i,elements[i].name);
		for(int j=0;j<elements[i].childrenCount;j++)
		{
			fprintf(file_classes2, "mGUI_Element_InsertChild((GUI_Element*)self->_QML_element%d, (GUI_Element*)self->_QML_element%d);\n",i,elements[i].children[j]->id);
		}
	}
}



bool * visited;
bool * processed;

bool recursionDetectCycle(std::vector<GraphNode*> &graphNodes,GraphNode * node, int ind)
{
	if(visited[ind])
		return true;
	processed[ind]=true;
	visited[ind]=true;
	for(int i=0;i<node->nextNodes.size();i++)
	{
		if(recursionDetectCycle(graphNodes,graphNodes[node->nextNodes[i]],node->nextNodes[i]))
			return true;
	}
	visited[ind]=false;
	return false;
}

void sortTopologically(std::vector<GraphNode*> &graphNodes)
{
	tInd=0;
	compInd=0;
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
			tarjanRecursion(graphNodes, i);
		}
	}
}

void tarjanRecursion(std::vector<GraphNode*> &graphNodes,int ind)
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
			compInds[ind2]=compInd;
			
			if(ind==ind2)
				break;
		}
		compInd++;
	}
}

bool detectCycle(std::vector<GraphNode*> &graphNodes)
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
			if(recursionDetectCycle(graphNodes,graphNodes[i],i))
				return true;
		}
	}
	return false;
}


FILE **files;
//FILE *files;
//FILE *files;

void makeMainSource()
{
	file = fopen("parser_output.c","w");
	fprintf(file,"#include \"output0outer.h\"\n\n#include \"qml_includes.h\"\n");
	fprintf(file,"void _QML_Update();\n");
	fprintf(file,"GUI_Element* root;\n");
	fprintf(file,"\nvoid _QML_Init()\n{\nroot = (GUI_Element*) acGUI_Rootoutput0();\n_QML_Update();\n}\n");
	fprintf(file,"\nvoid _QML_Update()\n{\nroot->Update(root);\n}\n");
	fclose(file);
}

void makeSource(std::string name, int treeInd)
{
	//ParserList* list;
	//int i;
	std::string name1 = name+std::string(".h");
	std::string name2 = name+std::string(".c");
	std::string name3 = name+std::string("outer.h");

	//files=new FILE*[3*elementTreeCnt];
	//for(int i=0;i<elementTreeCnt;i++)
	{
		//file = fopen("parser_output.c","w");
		//file_classes= fopen("custom_classes.h","w");
		//file_classes2= fopen("custom_classes.c","w");

		//file = fopen("parser_output.c","w");
		file = fopen(name3.c_str(),"w");
		file_classes= fopen(name1.c_str(),"w");
		file_classes2= fopen(name2.c_str(),"w");

		//makeSource(elementTrees[i]);
	}
	//list=(ParserList*)l;

	//printf("\n");
	//return;
	//file = fopen("parser_output.c","w");
	//file_classes= fopen("custom_classes.h","w");
	//file_classes2= fopen("custom_classes.c","w");
	
	fprintf(file_classes,"#include \"qml_includes.h\"\n");
	fprintf(file_classes2,"#include \"%s\"\n\n#include \"qml_includes.h\"\n",name1.c_str());
	for(int i=0;i<importCnt;i++)
	{
		if(imports[i].treeInd==treeInd)
		{
			fprintf(file_classes2,"#include \"%souter.h\"\n",importPathToName[imports[i].path].c_str());
		}
	}

	//fprintf(file, "GUI_Element* root;\n");
	id=0;

	//fprintf(file,"#include \"custom_classes.h\"\n#include \"qml_includes.h\"\n\nvoid _QML_Update();\n");

	classDeclaration(name.c_str());

	
	fprintf(file,"typedef struct GUI_Root%s GUI_Root%s;\n\n",name.c_str(),name.c_str());
	fprintf(file,"GUI_Root%s* acGUI_Root%s();\n",name.c_str(),name.c_str());
	//here

	recursionDeclaration(name.c_str());
	fprintf(file, "\n");
	
	bool cycle=detectCycle(graphNodes);
	sortTopologically(graphNodes);
	
	
	fprintf(file_classes2,"static void _QML_Update(GUI_Element *s);\n\n");

	printHandlers();
	

	//fprintf(file,"void _QML_Init()\n{\n");
	id=0;
	recursionInit(name.c_str(), treeInd);
	//fprintf(file, "root = (GUI_Element*) acGUI_Element();\n");
	
	for(int i=0;i<rootElementCount;i++)
	{
		//fprintf(file, "mGUI_Element_InsertChild((GUI_Element*)root, (GUI_Element*)_QML_element%d);\n",rootElements[i]);
	}

	printHandlerAssignment();


	if(cycle)
	{
		printf("Cycle Detected\n");
	}

	//fprintf(file,"_QML_Update();\n}\n");
	//fprintf(file,"void _QML_Update()\n{\n");
	//printAttributes();
	fprintf(file_classes2,"self->base.Update=_QML_Update;\n");
	fprintf(file_classes2,"_QML_Update((GUI_Element *)self);\n");
	
	fprintf(file_classes2,"self->base.root=pointer;\n");
	fprintf(file_classes2,"return *self;\n}\n");
	


	fprintf(file_classes2,"static void _QML_Update(GUI_Element *s)\n{\nGUI_Root%s * self=(GUI_Root%s *)s;\n",name.c_str(),name.c_str());
	printAttributes();

	fprintf(file_classes2,"mGUI_Element_Update((GUI_Element *)self);\n}\n");

	//printhand

	//fprintf(file,"\n}\n");

	fclose(file);
	fclose(file_classes);
	fclose(file_classes2);
}



GUIElement * recursionProcessTree(ParserGUIElement * element)
{
	int i;
	elements[id]=GUIElement();
	GUIElement * instance=&elements[id];

	int childCnt=0;
	int attribCnt=0;
	int handlerCnt=0;
	int propertyCnt=0;

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
			else if(element->list->members[i]->type==TYPE_HANDLER)
			{
				handlerCnt++;
			}
			else if(element->list->members[i]->type==TYPE_PROPERTY)
			{
				if(((ParserProperty*)element->list->members[i])->attribute!=0)
					attribCnt++;
				propertyCnt++;
			}
			
		}
	}
	instance->attributeCount=attribCnt;
	instance->attributes=new GUIElementAttribute[attribCnt];
	instance->handlerCount=handlerCnt;
	instance->handlers=new GUIElementHandler[handlerCnt];
	instance->childrenCount=childCnt;
	instance->children=new GUIElement*[childCnt];
	instance->propertiesCount=propertyCnt;
	instance->hasCustomClass=propertyCnt>0;
	instance->properties=new GUIElementProperty[propertyCnt];
	instance->id=id;
	instance->name=element->name;



	id++;
	childCnt=0;
	attribCnt=0;
	propertyCnt=0;
	handlerCnt=0;
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
			else if(element->list->members[i]->type==TYPE_HANDLER)
			{
				instance->handlers[handlerCnt]=GUIElementHandler();
				instance->handlers[handlerCnt].name=((ParserHandler *)element->list->members[i])->name;
				instance->handlers[handlerCnt].code=((ParserHandler *)element->list->members[i])->code;
				handlerCnt++;
			}
			else if(element->list->members[i]->type==TYPE_PROPERTY)
			{
				ParserProperty * prop=(ParserProperty *)element->list->members[i];
				instance->properties[propertyCnt]=GUIElementProperty();
				instance->properties[propertyCnt].name=prop->attName;
				instance->properties[propertyCnt].typeName=prop->typeName;
				
				if(prop->attribute!=0)
				{
					instance->attributes[attribCnt]=GUIElementAttribute();
					instance->attributes[attribCnt].name=prop->attribute->name;
					instance->attributes[attribCnt].expression=prop->attribute->expression;
				
					attribCnt++;
				}
				propertyCnt++;
			}
		}
	}

	return instance;
}

/*void recursionCount(ParserGUIElement * element)
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
}*/

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

bool processSrcDots(SrcNode * node, int treeInd, int currentElementId, int graphInd);

void processSrcReferences(SrcNode * node, int treeInd, int currentId, bool leftMostFound, bool dotNodePassed, int graphInd)
{
	char str[100];
			if(node->type==NODE_TYPE_DOT)
			{
				dotNodePassed=true;
			}
			else if(node->type==NODE_TYPE_ID)
			{
				bool isOtherId=idMaps[treeInd].count(std::string(node->text))!=0;
				bool isImportName=importToKeyMaps[treeInd].count(std::string(node->text))!=0;
				//if(leftMostFound)
				{
					if(isOtherId)
					{
						int otherId=idMaps[treeInd][std::string(node->text)];
						free(node->text);
						sprintf(str,"(*((GUI_Rootoutput%d *)((GUI_Element*)self)->root)->_QML_element%d)",treeInd,otherId);
						//sprintf(str,"(*self->localGroup->members[%d])",otherId);
						node->text=new char[strlen(str)+1];
						strcpy(node->text,str);
					}
					else if(isImportName)
					{
						int otherId=importToKeyMaps[treeInd][std::string(node->text)];
						
						free(node->text); //here
						sprintf(str,"GUI_Root%s",importPathToName[imports[otherId].path].c_str());
						//sprintf(str,"(*self->localGroup->members[%d])",otherId);
						node->text=new char[strlen(str)+1];
						strcpy(node->text,str);
					}
					else
					{
						if(strcmp("parent",node->text)==0)
						{
							free(node->text);
							sprintf(str,"(*((GUI_Rootoutput%d *)((GUI_Element*)self)->root)->_QML_element%d->parent)",treeInd,currentId);
							//sprintf(str,"(*self->localGroup->members[%d]->parent)",currentId);
							node->text=new char[strlen(str)+1];
							strcpy(node->text,str);
						}
						else if(strcmp("MakeNewThing",node->text)==0) // temporary - because of missing valid att
						{
						}
						else// if(is valid att?) //complete
						{
							sprintf(str,"(*((GUI_Rootoutput%d *)((GUI_Element*)self)->root)->_QML_element%d).%s",treeInd,currentId,node->text);
							//sprintf(str,"(*self->localGroup->members[%d]).%s",currentId,node->text);
							
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
			processSrcReferences(node->children[i],treeInd,currentId,leftMostFound,dotNodePassed, graphInd);
		}
	}
	else
	{
		if(processSrcDots(node, treeInd,currentId, graphInd))
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

bool processSrcDots(SrcNode * node, int treeInd,int currentElementId, int graphInd)
{
	int cnt=countDotIds(node);
	if(cnt<1)
		return false;

	std::string* identifiers = new std::string[cnt];
	fillIds(node,identifiers,0);

	//bool prevParam=false;
	bool prevElement=false;
	bool isOtherId=idMaps[treeInd].count(identifiers[0])!=0;
	int curId=currentElementId;
	int startInd=1;
	if(isOtherId)
	{
		prevElement=true;
		curId=idMaps[treeInd][identifiers[0]];
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
			startInd=0; //
		}
	}
	std::string attribs("");
	for(int i=startInd;i<cnt;i++)
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
	if(startInd==1)
		attribs=std::string("(*((GUI_Rootoutput")+std::to_string(static_cast<long long>(treeInd))+std::string(" *)((GUI_Element*)self)->root)->_QML_element")+std::to_string(static_cast<long long>(curId))+std::string(")")+attribs;
	else
		attribs=std::string("(*(GUI_")+std::string(elements[curId].name)+std::string("*)((GUI_Rootoutput")+std::to_string(static_cast<long long>(treeInd))+std::string(" *)((GUI_Element*)self)->root)->_QML_element")+std::to_string(static_cast<long long>(curId))+std::string(")")+attribs;
		
	//attribs
	node->text=new char[attribs.length()+1];
	std::strcpy(node->text,attribs.c_str());

	return true;
}




void PrintNodeToFile(FILE* file, SrcNode* node)
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
			PrintNodeToFile(file, node->children[i]);
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

void processTreeImports(ParserList* elementTree, int importGInd)
{
	for(int i=0;i<elementTree->memberCount;i++)
	{
		if(elementTree->members[i]->type==TYPE_IMPORT)
		{
			GUIImport import;
			import.name=std::string(((ParserImport*)elementTree->members[i])->name);
			import.path=std::string(((ParserImport*)elementTree->members[i])->path);
			import.path=import.path.substr(1,import.path.length()-2);
			import.treeInd=elementTreeCnt;
			imports.push_back(import);
			if(importsProcessed.count(import.path)<1)
				importsProcessed[import.path]=false;
			
			if(importMap.count(import.path)!=0)
			{
				importGraph[importMap[import.path]]->nextNodes.push_back(importGInd);
			}
			else
			{
				GraphNode* graphNode=new GraphNode();
				graphNode->key=import.path;
				graphNode->nextNodes.push_back(importGInd);
				importMap[import.path]=importGraph.size();
				importGraph.push_back(graphNode);
				//graphNodespush_back();
			}
			importToKeyMaps[elementTreeCnt][import.name]=importCnt;

			importCnt++;
			continue;
			//((ParserImport*)element->list->members[i])->name;
			//((ParserImport*)element->list->members[i])->path;
		}

		// just one element
		/*rootElements[rootElementCount]=id;
		recursionProcessTree((ParserGUIElement*)elementTree->members[i]);
		elements[rootElements[rootElementCount]].parentId=-1;
		rootElementCount++;*/
	}
}

void processTree(ParserList* elementTree, int treeInd)
{
	//int id=0;
	elementCount=0;
	for(int i=0;i<elementTree->memberCount;i++)
	{
		if(elementTree->members[i]->type==TYPE_IMPORT)
		{
			continue;
		}
		recursionCount((ParserGUIElement*)elementTree->members[i]);
	}
	elements=new GUIElement[elementCount];
	
	id=0;
	for(int i=0;i<elementTree->memberCount;i++)
	{
		if(elementTree->members[i]->type==TYPE_IMPORT)
		{
			/*importCnt++;
			GUIImport import;
			import.name=std::string(((ParserImport*)elementTree->members[i])->name);
			import.path=std::string(((ParserImport*)elementTree->members[i])->path);
			imports.push_back(import);
			if(importsProcessed.count(import.path)<1)
				importsProcessed[import.path]=false;*/
			continue;
			//((ParserImport*)element->list->members[i])->name;
			//((ParserImport*)element->list->members[i])->path;
		}

		// just one element
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
				idMaps[treeInd][expressionToStr(att->expression)]=i;
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
			
			processSrcReferences(att->expression,treeInd,i,false,false,graphInd);
		}

		for(int j=0;j<elements[i].handlerCount;j++)
		{
			GUIElementHandler * handler=&elements[i].handlers[j];

			
			std::string key=std::to_string(static_cast<long long>(i))+"."+std::string(handler->name);
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
			handler->graphInd=graphInd;

			processSrcReferences(handler->code,treeInd,i,false,false,graphInd);
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



bool processFile(const char * name)
{
	FILE *srcFile;
	srcFile = fopen(name,"r");
	
    yyrestart(srcFile);
	if(yyparse())
	{
		return false;
	}

	int graphInd;
	std::string key=std::string(name);
			
	if(importMap.count(key)!=0)
	{
		graphInd=importMap[key];//->nextNodes.push_back(graphInd);
	}
	else
	{
		GraphNode* graphNode=new GraphNode();
		graphNode->key=key;
		graphInd=importGraph.size();
		importMap[key]=graphInd;
		importGraph.push_back(graphNode);
		//graphNodespush_back();
	}

	importPathToName[std::string(name)]=std::string("output")+std::to_string(static_cast<long long>(elementTreeCnt));

	processTreeImports(elementTree, graphInd);
	elementTrees[elementTreeCnt]=elementTree;
	elementTreeGInds[elementTreeCnt]=graphInd;
	elementTreeCnt++;
	//processTree(elementTree);
	//makeSource();
	fclose(srcFile);
	return true;
}

int main()
{
	FILE *srcFile;
	int a=0;
	id=0;
	//srcFile = fopen("src4.cqml","r");
	
	identifiersCount=0;
	identifiersMax=1000;
	identifiers=(char**)malloc(sizeof(char*)*identifiersMax);
	identifiersIds=(int*)malloc(sizeof(int)*identifiersMax);

	processFile("src4.cqml");

	int importInd=0;
	while(importInd<importCnt)
	{
		if(importsProcessed[imports.at(importInd).path])
		{
			imports.at(importInd).processed=true;
		}
		else
		{
			processFile(imports.at(importInd).path.c_str());
			importsProcessed[imports.at(importInd).path]=true;
		}
		importInd++;
	}
	detectCycle(importGraph);
	sortTopologically(importGraph);

	int * importCompInds=compInds;

	for(int k=0,kM=compInd-1;k<=kM;k++)
	{
		for(int i=0;i<elementTreeCnt;i++)
		{
			if(compInds[elementTreeGInds[i]]==k)
			{
				processTree(elementTrees[i],i);
				elementGroups[i]=elements;
				elementGroupSizes[i]=elementCount;
			}
		}
	}
	//importMap[import.path]

	//processTreeImports(elementTree);
	//elementTrees[elementTreeCnt]=elementTree;
	//elementTreeCnt

	for(int i=0;i<elementTreeCnt;i++)
	{
		elements=elementGroups[i];
		elementCount=elementGroupSizes[i];

		makeSource(std::string("output")+std::to_string(static_cast<long long>(i)),i);
//		processTree(elementTrees[i]);
	//	elementGroups[i]=elements;
		//elementGroupSizes[i]=elementCount;
	}

	makeMainSource();

	//for(int i=0;)
	

    //yyrestart(srcFile);
	
	//if(yyparse())
	{
		a=1;//eror
	}
	//processTree(elementTree);
	//makeSource();
	//fclose(srcFile);
	printf("\n%d\n",compInd);
	scanf("%d",&a);

	return 0;
}
