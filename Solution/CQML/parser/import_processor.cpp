#include "import_processor.h"

#include "output_printing.h"
#include "elements.h"
#include "parameter_handling.h"
#include "src_processor.h"
#include "parser_tree.h"

#include "cqml_grammar.tab.h"

typedef struct yy_buffer_state *YY_BUFFER_STATE;
extern "C"
{
YY_BUFFER_STATE yy_scan_string(char *);
YY_BUFFER_STATE yyrestart(FILE * file);
YY_BUFFER_STATE yyparse();
}

extern std::unordered_map<std::string, int> idMaps[100];

extern std::vector<GUIInclude> includes;

extern int importCnt;
extern std::unordered_map<std::string, bool> importsProcessed;
extern std::vector<GUIImport> imports;
// path to fileIndex
extern std::unordered_map<std::string, int> importMap;
extern std::vector<GraphNode*> importGraph;

// import to import index in array
extern std::unordered_map<std::string, int> importToKeyMaps[100];

// import to name of the class in output
extern std::unordered_map<std::string, std::string> importPathToName;

extern ParserList * elementTrees[100];
extern int elementTreeGInds[100];
extern int elementTreeCnt;
ParserList* elementTree;

void processTreeImports(ParserList* elementTree, int importGInd);

/**
 * Processes an CQML FILE
 * 
 *
 * @param path to file
 */
bool processFile(const char * name)
{
	printf("\n");
	FILE *srcFile;
	fopen_s(&srcFile,name,"r");
	if(!srcFile)
	{
		printf("failed to open file...\n");
		return false;
	}
	
    yyrestart(srcFile);
	if(yyparse())
	{
		return false;
	}

	int graphInd;
	std::string key=std::string(name);
			
	if(importMap.count(key)!=0)
	{
		graphInd=importMap[key];
	}
	else
	{
		GraphNode* graphNode=new GraphNode();
		graphNode->key=key;
		graphInd=importGraph.size();
		importMap[key]=graphInd;
		importGraph.push_back(graphNode);
	}

	importPathToName[std::string(name)]=std::string("output")+std::to_string(static_cast<long long>(elementTreeCnt));

	processTreeImports(elementTree, graphInd);
	elementTrees[elementTreeCnt]=elementTree;
	elementTreeGInds[elementTreeCnt]=graphInd;
	elementTreeCnt++;

	fclose(srcFile);
	return true;
}


/**
 * Processes imports from syntax tree
 * 
 *
 * @param syntax tree
 * @param index of file
 */
void processTreeImports(ParserList* elementTree, int importGInd)
{
	for(int i=0;i<elementTree->memberCount;i++)
	{
		if(elementTree->members[i]->type==TYPE_INCLUDE)
		{
			GUIInclude include;
			include.path=std::string(((ParserInclude*)elementTree->members[i])->path);
			include.treeInd=elementTreeCnt;
			includes.push_back(include);
		}
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
			}
			importToKeyMaps[elementTreeCnt][import.name]=importCnt;

			importCnt++;
			continue;
		}
	}
}