#pragma once

typedef struct AttributeCheck AttributeCheck;
typedef struct AttributeHash AttributeHash;

struct AttributeHash
{
	long hash;
	//type
};

struct AttributeCheck
{
	int attributCnt;
	AttributeHash* attributs;
};