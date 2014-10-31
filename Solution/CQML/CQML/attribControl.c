#include "attribControl.h"
#include "struct_definition_macros.h"

AttributeCheck classes[1000];

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
	if(checkAttributeInd(classInd,attHash)==-1)
		return 0;
	return 1;
}


