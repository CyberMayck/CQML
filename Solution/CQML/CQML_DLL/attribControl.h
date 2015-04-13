#pragma once

#include <string.h>
#include <stdlib.h>

#include "dll_export.h"


struct ClassHashTable
{
	char ** keys; // m
	int * T1; // m
	int * T2; // m
	int * g; // n
	int m;
	int n;
};

CQML_API void InitClassesSize(ClassHashTable*& tabs,int cnt);
CQML_API void InitHashTab(ClassHashTable * tab, int n, int m);
CQML_API void QMLInitHashes();


CQML_API void SetInitHashTabs(void (*fptr)(ClassHashTable*));
CQML_API int GetHash(long classID, const char* name);
