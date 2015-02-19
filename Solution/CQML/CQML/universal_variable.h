#pragma once

class UniversalVar;

class AnyTypeVal
{
public:
	long typeId;

	virtual AnyTypeVal* operationAddR(const UniversalVar& rhs);
	virtual AnyTypeVal* operationSubR(const UniversalVar& rhs);
	virtual AnyTypeVal* operationMulR(const UniversalVar& rhs);
	virtual AnyTypeVal* operationDivR(const UniversalVar& rhs);
	virtual AnyTypeVal* operationModR(const UniversalVar& rhs);
	
	virtual AnyTypeVal* operationAddR(int rhs);
	virtual AnyTypeVal* operationSubR(int rhs);
	virtual AnyTypeVal* operationMulR(int rhs);
	virtual AnyTypeVal* operationDivR(int rhs);
	virtual AnyTypeVal* operationModR(int rhs);
	
	virtual AnyTypeVal* operationAddL(int lhs);
	virtual AnyTypeVal* operationSubL(int lhs);
	virtual AnyTypeVal* operationMulL(int lhs);
	virtual AnyTypeVal* operationDivL(int lhs);
	virtual AnyTypeVal* operationModL(int lhs);
};


class AnyTypeVal_Int
	: public AnyTypeVal
{
public:
	int value;

	virtual AnyTypeVal* operationAddR(const UniversalVar& rhs);
	virtual AnyTypeVal* operationSubR(const UniversalVar& rhs);
	virtual AnyTypeVal* operationMulR(const UniversalVar& rhs);
	virtual AnyTypeVal* operationDivR(const UniversalVar& rhs);
	virtual AnyTypeVal* operationModR(const UniversalVar& rhs);
	
	virtual AnyTypeVal* operationAddR(int rhs);
	virtual AnyTypeVal* operationSubR(int rhs);
	virtual AnyTypeVal* operationMulR(int rhs);
	virtual AnyTypeVal* operationDivR(int rhs);
	virtual AnyTypeVal* operationModR(int rhs);
	
	virtual AnyTypeVal* operationAddL(int lhs);
	virtual AnyTypeVal* operationSubL(int lhs);
	virtual AnyTypeVal* operationMulL(int lhs);
	virtual AnyTypeVal* operationDivL(int lhs);
	virtual AnyTypeVal* operationModL(int lhs);
};

/*
class AnyTypeVal_UnsignedLongLong
	: public AnyTypeVal
{
	unsigned long long value;

	virtual AnyTypeVal operator+(const AnyTypeVal& rhs) const;
};

class AnyTypeVal_LongLong
{
	long long value;
};
class AnyTypeVal_UnsignedLong
{
	unsigned long value;
};
class AnyTypeVal_Long
{
	long value;
};
class AnyTypeVal_UnsignedInt
{
	unsigned int value;
};
class AnyTypeVal_Int
{
	int value;
};
class AnyTypeVal_LongDouble
{
	long double value;
};
class AnyTypeVal_Double
{
	double value;
};
class AnyTypeVal_Float
{
	float value;
};*/

class UniversalVar
{
public:
	AnyTypeVal* value;

	UniversalVar(AnyTypeVal* v);

	UniversalVar operator=(const UniversalVar& rhs);
	UniversalVar operator-() const;


	UniversalVar friend operator+(const UniversalVar& lhs, const UniversalVar& rhs);
	UniversalVar friend operator-(const UniversalVar& lhs, const UniversalVar& rhs);
	UniversalVar friend operator*(const UniversalVar& lhs, const UniversalVar& rhs);
	UniversalVar friend operator/(const UniversalVar& lhs, const UniversalVar& rhs);
	UniversalVar friend operator%(const UniversalVar& lhs, const UniversalVar& rhs);

	UniversalVar friend operator+(const UniversalVar& lhs, int);
	UniversalVar friend operator-(const UniversalVar& lhs, int);
	UniversalVar friend operator*(const UniversalVar& lhs, int);
	UniversalVar friend operator/(const UniversalVar& lhs, int);
	UniversalVar friend operator%(const UniversalVar& lhs, int);

	UniversalVar friend operator+(int, const UniversalVar& rhs);
	UniversalVar friend operator-(int, const UniversalVar& rhs);
	UniversalVar friend operator*(int, const UniversalVar& rhs);
	UniversalVar friend operator/(int, const UniversalVar& rhs);
	UniversalVar friend operator%(int, const UniversalVar& rhs);
};