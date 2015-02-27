#include "attribControl.h"
//#include "struct_definition_macros.h"
#include "gui.h"

static int classCnt;
static AttributeCheck * classes;

static ClassHashTable * classHashTables;
static ClassAttributeTable * classAttTables;


/*int f1(const char* s, int * T, int n)
{
	int sum=0;
	for(int i=0,len=strlen(s);i<len;i++)
	{
		sum+=T[i]*(unsigned char)s[i];
	}
	sum=sum%n;
	return sum;
}*/
int f1(const char * s, int * T, int n);

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

int h(const char * s, int n,int m, int * T1, int *T2, int*g)
{
	int u=f1(s,T1,n);
	int v=f1(s,T2,n);
	int a=g[u];
	int b=g[v];
	int retVal=(g[u]+g[v])%m;
	return retVal;
}

TableRecord* GetTableRecord(long classID, const char* name)
{
	ClassHashTable * hashTab=&classHashTables[classID];
	int index= h(name,hashTab->n,hashTab->m,hashTab->T1,hashTab->T2,hashTab->g);
	if(strcmp(hashTab->keys[index],name)==0)
	{
		return &classAttTables[classID].records[index];
	}
	else
	{
		return 0;
	}
}




//UniversalVar CreateUniversalVarFromElement(TableRecord * record,void * obj)
//{
	//unsigned char* pointer= (unsigned char*)obj;
	//pointer+=record->offset;

	//UniversalVar v(factories[record->typeId]((void*) pointer));
	//return v;
//}

//QVGET(_QVar8,"rah3",_QVar9)
/*int getterE(void * sourceElement, const char* name, UniversalVar& outValue)
{
	GUI_Element* element=(GUI_Element*)sourceElement;
	long classID = element->classID;
	// get class ID

	TableRecord* record= GetTableRecord(classID,name);
	// check class table for attribute handler - with hash of name
	if(record==0)
		return 0;

	// now we have type of atribute and offset

	// with type id we get struct with operations for certain types
	// or we construct universal variable
	//outValue= CreateUniversalVar(record);

	return 1;
}*/

int setterE(void * modifiedElement,const char* name,value_type value)
{
	GUI_Element* element=(GUI_Element*)modifiedElement;
	long classID = element->classID;
	return 1;
}


int setterV(value_type setted,const char* name,value_type value)
{
	return 1;
}
int getterV(value_type getted,const char* name,value_type &outValue)
{
	return 1;
}
int getterE(void * getted,const char* name,value_type &outValue)
{
	return 1;
}




void SetAttribute(void * obj,ClassAttribute* att, float a)
{
	unsigned char* pointer= (unsigned char*)obj;
	pointer+=att->offset;

	float * memberPointer=(float *)pointer;
	*pointer=a;
}

int setter(const char* attName,value_type val)
{
	// check existence
	return 1;

}

int setTypeByID()
{
	return 1;
}

int getter(const char* attName,value_type val)
{
	return 1;
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


