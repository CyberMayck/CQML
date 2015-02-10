#include "attribControl.h"
//#include "struct_definition_macros.h"

static int classCnt;
static AttributeCheck * classes;
static ClassHashTable * classHashTables;


int f1(const char* s, int * T, int n)
{
	int sum=0;
	for(int i=0,len=strlen(s);i<len;i++)
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

int setterV(value_type setted,const char* name,value_type value)
{
}
int setterE(void * setted,const char* name,value_type value)
{
}
int getterV(value_type getted,const char* name,value_type &outValue)
{
}
int getterE(void * getted,const char* name,value_type &outValue)
{
}

int setter(const char* attName,value_type val)
{
	// check existence


}

int setTypeByID()
{
}

int getter(const char* attName,value_type val)
{
}

int checkAttributeInd(int classInd, int attHash)
{
	int i;
	for(i=0;i<classes[classInd].attributCnt;i++)
	{
		if(classes[classInd].attributs[i].hash==attHash)
			//exists
			return i;
	}
	return -1;
}

int checkAttributeExistence(int classInd, int attHash)
{
	int returnVal=0;
	while(1)
	{
		if(checkAttributeInd(classInd,attHash)==-1)
		{
			if(classes[classInd].parentInd==-1)
				break;
		}
		else
		{
			returnVal=1;
			break;
		}
	}

	return returnVal;
}

void InitClassesSize(int cnt)
{
	classCnt=cnt;
	classes=(AttributeCheck*)malloc(classCnt*sizeof(AttributeCheck));

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

void Init()
{
}

void InitAttribCnt(int classInd,int cnt, int parentInd)
{
	classes[classInd].attributs=(AttributeHash *) malloc(cnt*sizeof(AttributeHash));
	classes[classInd].attributCnt=0;
	classes[classInd].parentInd=parentInd;
}

void AddAttribute(int classInd, long nameHash, int offset, char*typeName, int typeSize)
{
	AttributeHash * hash=&classes[classInd].attributs[classes[classInd].attributCnt];
	hash->hash=nameHash;
	hash->offset=offset;
	hash->type=(char *)malloc((strlen(typeName)+1)*sizeof(char));
	strcpy(hash->type,typeName);
	hash->size=typeSize;

	classes[classInd].attributCnt++;
}

void InitHashTabs(ClassHashTable*);
void QMLInitHashes()
{
	InitHashTabs(classHashTables);
}

