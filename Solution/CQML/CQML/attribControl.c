#include "attribControl.h"
//#include "struct_definition_macros.h"

static int classCnt;
static AttributeCheck * classes;

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



