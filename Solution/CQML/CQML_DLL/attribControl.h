#pragma once

#include <string.h>
#include <stdlib.h>

#include "dll_export.h"


struct ClassHashTable
{
	char ** keys; // m
	int * T1; // maxT
	int * T2; // maxT
	int * g; // n
	int m;
	int n;
	int maxT;
	int isValueType;
	int parentID;
};

CQML_API void InitClassesSize(ClassHashTable*& tabs,int cnt);
CQML_API void InitHashTab(ClassHashTable * tab, int n, int m);
CQML_API void CQMLInitHashes();


CQML_API void SetInitHashTabs(void (*fptr)(ClassHashTable*&));
CQML_API int GetHash(long classID, const char* name);
CQML_API bool IsValueType(long classID);
CQML_API bool IsCompatible(long lID,long rID);

