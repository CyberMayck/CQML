#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <assert.h>

//#include "lex.yy.c"
//#include "cqml_grammar.tab.c"
//#include "cqml_grammar.tab.h"

#include "parser_tree.h"
#include "parameter_handling.h"
#include "src_processor.h"
#include "elements.h"
#include "output_printing.h"
#include "tree_processor.h"
#include "import_processor.h"
#include "tarjan.h"



std::unordered_map<std::string, int> keyMap;
std::vector<GUIInclude> includes;

int importCnt=0;

std::unordered_map<std::string, bool> importsProcessed;
std::vector<GUIImport> imports;
// path to fileIndex
std::unordered_map<std::string, int> importMap;
std::vector<GraphNode*> importGraph;

// import to import index in array
std::unordered_map<std::string, int> importToKeyMaps[100];

// import to name of the class in output
std::unordered_map<std::string, std::string> importPathToName;



GUIElement * elementGroups[100];
int elementGroupSizes[100];
int customClassCnt=0;

std::unordered_map<std::string, int> idMaps[100];

int * identifiersIds;
char ** identifiers;
int identifiersCount;
int identifiersMax;

int rootElements[100];
int rootElementCount;

int* compInds;
int compCnt=0;


ParserList * elementTrees[100];
int elementTreeGInds[100];
int elementTreeCnt=0;




/**
 * Main function.
 * Calls functions for loading files, processing them and generating output source.
 *
 * @param commandline arguments count
 * @param commandline argument strings
 *
 * @return 0
 */
int main(int argc, char ** argv)
{
	processBasicTypes();

	const char * fileName;
	if(argc<2)
	{
		printf("not enough parameters\nuse --help for more info\n");
		return  0;
	}
	if(strcmp(argv[1],"--help")==0)
	{
		PrintHelp();
		return 0;
	}
	else
	{
		fileName=argv[1];
	}
	
	identifiersCount=0;
	identifiersMax=1000;
	identifiers=(char**)malloc(sizeof(char*)*identifiersMax);
	identifiersIds=(int*)malloc(sizeof(int)*identifiersMax);

	// parse tree creation and import files detection
	if(!processFile(fileName))
	{
		printf("Failed to process file: %s\nexiting...\n",fileName);
		return 0;
	}

	int importInd=0;
	while(importInd<importCnt)
	{
		if(importsProcessed[imports.at(importInd).path])
		{
			imports.at(importInd).processed=true;
		}
		else
		{
			if(!processFile(imports.at(importInd).path.c_str()))
			{
				printf("Failed to process file: %s\nexiting...\n",imports.at(importInd).path.c_str());
				return 0;
			}
			importsProcessed[imports.at(importInd).path]=true;
		}
		importInd++;
	}
	// import dependencies cycle detection
	if(detectCycle(importGraph))
	{
		printf("Cyclic dependency in imports detected.");
		return 0;
	}
	// topological sort of import files
	sortTopologically(importGraph);

	int * importCompInds=compInds;

	// processing parser trees (in topological order of the files)
	for(int k=compCnt-1,kM=0;k>=kM;k--)
	{
		for(int i=0;i<elementTreeCnt;i++)
		{
			if(compInds[elementTreeGInds[i]]==k)
			{
				int elementCount;
				GUIElement * elements;
				processTree(elementTrees[i],i,elementCount,elements);
				elementGroups[i]=elements;
				elementGroupSizes[i]=elementCount;
			}
		}
	}

	
	MakeAllHashes();

	// source generation
	for(int i=0;i<elementTreeCnt;i++)
	{
		makeSource(std::string("output")+std::to_string(static_cast<long long>(i)),i,elementGroups[i],elementGroupSizes[i]);
	}
	makeMainSource(elementTreeCnt);

	printOutputListFile(elementTreeCnt);

	return 0;
}
