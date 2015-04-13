#include "dll_export.h"

#include "attribControl.h"
//#include "struct_definition_macros.h"
#include "gui.h"

static int classCnt;
static ClassHashTable * classHashTables;


int f1(const char * s, int * T, int n)
{
	int sum=0;
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		sum+=T[i]*(unsigned char)s[i];
	}
	sum=sum%n;
	return sum;
}

int hash(const char* s, int n,int m, int* T1, int* T2, int* g)
{
	int u=f1(s,T1,n);
	int v=f1(s,T2,n);
	int a=g[u];
	int b=g[v];
	int retVal=(g[u]+g[v])%m;
	return retVal;
}

typedef union value_type
{
	//include alltypes.h
} value_type;


int h(const char * s, int n,int m, int * T1, int *T2, int*g)
{
	int u=f1(s,T1,n);
	int v=f1(s,T2,n);
	int a=g[u];
	int b=g[v];
	int retVal=(g[u]+g[v])%m;
	return retVal;
}


int GetHash(long classID, const char* name)
{
	ClassHashTable * hashTab=&classHashTables[classID];
	int index= h(name,hashTab->n,hashTab->m,hashTab->T1,hashTab->T2,hashTab->g);
	if(strcmp(hashTab->keys[index],name)==0)
	{
		return index;
	}
	else
	{
		return -1;
	}
}

void InitClassesSize(ClassHashTable *&classHashTables ,int cnt)
{
	classCnt=cnt;
	//classes=(AttributeCheck*)malloc(classCnt*sizeof(AttributeCheck));

	classHashTables=(ClassHashTable*)malloc(classCnt*sizeof(ClassHashTable));
}

void InitHashTab(ClassHashTable * tab, int n, int m)
{
	tab->n=n;
	tab->m=m;
	tab->keys=(char **)malloc(sizeof(char*)*m);
	tab->T1=(int *)malloc(sizeof(int)*m);
	tab->T2=(int *)malloc(sizeof(int)*m);
	tab->g=(int *)malloc(sizeof(int)*n);
}

void (*InitHashTabs)(ClassHashTable*);

void SetInitHashTabs(void (*fptr)(ClassHashTable*))
{
	InitHashTabs=fptr;
}

void QMLInitHashes()
{
	InitHashTabs(classHashTables);
}


