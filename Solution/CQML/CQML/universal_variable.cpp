#include "universal_variable.h"



UniversalVar::UniversalVar(AnyTypeVal* v)
{
	this->value=v;
}

UniversalVar UniversalVar::operator=(const UniversalVar& rhs)
{
	*this->value=*rhs.value;
	return *this;
}

// change to do by macros

UniversalVar operator+(const UniversalVar& lhs, const UniversalVar& rhs)
{
	lhs.value->operationAddR(rhs);
}

UniversalVar operator-(const UniversalVar& lhs, const UniversalVar& rhs)
{
	lhs.value->operationSubR(rhs);
}

UniversalVar operator*(const UniversalVar& lhs, const UniversalVar& rhs)
{
	lhs.value->operationMulR(rhs);
}

UniversalVar operator/(const UniversalVar& lhs, const UniversalVar& rhs)
{
	lhs.value->operationDivR(rhs);
}

UniversalVar operator%(const UniversalVar& lhs, const UniversalVar& rhs)
{
	lhs.value->operationModR(rhs);
}


UniversalVar operator+(const UniversalVar& lhs, int rhs)
{
	lhs.value->operationAddR(rhs);
}
UniversalVar operator-(const UniversalVar& lhs, int rhs)
{
	lhs.value->operationSubR(rhs);
}
UniversalVar operator*(const UniversalVar& lhs, int rhs)
{
	lhs.value->operationMulR(rhs);
}
UniversalVar operator/(const UniversalVar& lhs, int rhs)
{
	lhs.value->operationDivR(rhs);
}
UniversalVar operator%(const UniversalVar& lhs, int rhs)
{
	lhs.value->operationModR(rhs);
}



UniversalVar operator+(int lhs, const UniversalVar& rhs)
{
	rhs.value->operationAddL(lhs);
}
UniversalVar operator-(int lhs, const UniversalVar& rhs)
{
	rhs.value->operationSubL(lhs);
}
UniversalVar operator*(int lhs, const UniversalVar& rhs)
{
	rhs.value->operationMulL(lhs);
}
UniversalVar operator/(int lhs, const UniversalVar& rhs)
{
	rhs.value->operationDivL(lhs);
}
UniversalVar operator%(int lhs, const UniversalVar& rhs)
{
	rhs.value->operationModL(lhs);
}




///////////////////////////////////////////////////////////

AnyTypeVal* AnyTypeVal_Int::operationAddR(const UniversalVar& rhs)
{
	return rhs.value->operationAddL(value);
}
AnyTypeVal* AnyTypeVal_Int::operationSubR(const UniversalVar& rhs)
{
	return rhs.value->operationSubL(value);
}
AnyTypeVal* AnyTypeVal_Int::operationMulR(const UniversalVar& rhs)
{
	return rhs.value->operationMulL(value);
}
AnyTypeVal* AnyTypeVal_Int::operationDivR(const UniversalVar& rhs)
{
	return rhs.value->operationDivL(value);
}
AnyTypeVal* AnyTypeVal_Int::operationModR(const UniversalVar& rhs)
{
	return rhs.value->operationModL(value);
}


AnyTypeVal* AnyTypeVal_Int::operationAddR(int rhs)
{
	AnyTypeVal_Int* a= new AnyTypeVal_Int();

	a->value=value+rhs;

	return a;
}
AnyTypeVal* AnyTypeVal_Int::operationSubR(int rhs)
{
	AnyTypeVal_Int* a= new AnyTypeVal_Int();

	a->value=value-rhs;

	return a;
}
AnyTypeVal* AnyTypeVal_Int::operationMulR(int rhs)
{
	AnyTypeVal_Int* a= new AnyTypeVal_Int();

	a->value=value*rhs;

	return a;
}
AnyTypeVal* AnyTypeVal_Int::operationDivR(int rhs)
{
	AnyTypeVal_Int* a= new AnyTypeVal_Int();

	a->value=value/rhs;

	return a;
}
AnyTypeVal* AnyTypeVal_Int::operationModR(int rhs)
{
	AnyTypeVal_Int* a= new AnyTypeVal_Int();

	a->value=value%rhs;

	return a;
}

AnyTypeVal* AnyTypeVal_Int::operationAddL(int lhs)
{
	AnyTypeVal_Int* a= new AnyTypeVal_Int();

	a->value=lhs+value;

	return a;
}
AnyTypeVal* AnyTypeVal_Int::operationSubL(int lhs)
{
	AnyTypeVal_Int* a= new AnyTypeVal_Int();

	a->value=lhs-value;

	return a;
}
AnyTypeVal* AnyTypeVal_Int::operationMulL(int lhs)
{
	AnyTypeVal_Int* a= new AnyTypeVal_Int();

	a->value=lhs*value;

	return a;
}
AnyTypeVal* AnyTypeVal_Int::operationDivL(int lhs)
{
	AnyTypeVal_Int* a= new AnyTypeVal_Int();

	a->value=lhs/value;

	return a;
}
AnyTypeVal* AnyTypeVal_Int::operationModL(int lhs)
{
	AnyTypeVal_Int* a= new AnyTypeVal_Int();

	a->value=lhs%value;

	return a;
}