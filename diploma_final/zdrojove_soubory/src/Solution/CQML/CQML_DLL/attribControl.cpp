#include "dll_export.h"

#include "attribControl.h"
//#include "struct_definition_macros.h"
#include "gui.h"



static int classCnt;
static ClassHashTable * classHashTables;

/**
 * Checks compatibility of pointers
 * 
 *
 * @param left class ID
 * @param right class ID
 *
 * @return true if compatible, false otherwise
 */
bool IsCompatible(long lID,long rID)
{
	if(lID==rID)
		return true;
	if(classHashTables[rID].parentID==-1)
		return false;
	return IsCompatible(lID,classHashTables[rID].parentID);
}

/**
 * Checks if class is of value type
 * 
 *
 * @param class ID
 *
 * @return true if is value type, false otherwise
 */
bool IsValueType(long classID)
{
	return classHashTables[classID].isValueType==1;
}

/**
 * Function calculating table index from string.
 * 
 *
 * @param String
 * @param Table
 * @param n
 *
 * @return table index
 */
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

/**
 * Hash function.
 * Calculates hash.
 *
 * @param string
 * @param n
 * @param m
 * @param table T1
 * @param table T2
 * @param graph node values
 *
 * @return hash value
 */
int hash(const char* s, int n,int m, int* T1, int* T2, int* g)
{
	int u=f1(s,T1,n);
	int v=f1(s,T2,n);
	int a=g[u];
	int b=g[v];
	int retVal=(g[u]+g[v])%m;
	return retVal;
}

/**
 * Hash function.
 * Calculates hash.
 *
 * @param string
 * @param n
 * @param m
 * @param table T1
 * @param table T2
 * @param graph node values
 *
 * @return hash value
 */
int h(const char * s, int n,int m, int * T1, int *T2, int*g)
{
	int u=f1(s,T1,n);
	int v=f1(s,T2,n);
	int a=g[u];
	int b=g[v];
	int retVal=(g[u]+g[v])%m;
	return retVal;
}


/**
 * Hash function for a class.
 * Gets hash.
 *
 * @param class ID
 * @param attribute name
 *
 * @return -1 if invalid hash, value of hash otherwise.
 */
int GetHash(long classID, const char* name)
{
	ClassHashTable * hashTab=&classHashTables[classID];
	int len=strlen(name);
	if(len>hashTab->maxT)
		return -1;
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
void InitDefaultHashTabs(ClassHashTable * hashTabs);


/**
 * 
 * Initializes of tables for hashing.
 *
 * @param hash table pointer
 * @param number of tables
 */
void InitClassesSize(ClassHashTable *&classHashTables ,int cnt)
{
	classCnt=cnt;
	//classes=(AttributeCheck*)malloc(classCnt*sizeof(AttributeCheck));
	
	classHashTables=(ClassHashTable*)malloc(classCnt*sizeof(ClassHashTable));
	InitDefaultHashTabs(classHashTables);
}

/**
 * Initializes a hash funtion table
 * 
 *
 * @param table
 * @param n
 * @param m
 */
void InitHashTab(ClassHashTable * tab, int n, int m, int maxT)
{
	tab->n=n;
	tab->m=m;
	tab->keys=(char **)malloc(sizeof(char*)*m);
	tab->T1=(int *)malloc(sizeof(int)*maxT);
	tab->T2=(int *)malloc(sizeof(int)*maxT);
	tab->g=(int *)malloc(sizeof(int)*n);
}

void (*InitHashTabs)(ClassHashTable*&);

/**
 * Sets hash function initialization.
 * 
 *
 * @param function pointer.
 */
void SetInitHashTabs(void (*fptr)(ClassHashTable*&))
{
	InitHashTabs=fptr;
}

/**
 * Hash function initialization.
 *  Initializes hash function.
 */
void CQMLInitHashes()
{
	InitHashTabs(classHashTables);
}


