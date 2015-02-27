#include "universal_variable.h"

Variant::Variant(int a)
{
	value.v_int=a;
}
Variant::Variant(long a)
{
	value.v_long=a;
}
Variant::Variant(long long a)
{
	value.v_long_long=a;
}
Variant::Variant(unsigned int a)
{
	value.v_unsigned_int=a;
}
Variant::Variant(unsigned long a)
{
	value.v_unsigned_long=a;
}
Variant::Variant(unsigned long long a)
{
	value.v_unsigned_long_long=a;
}
Variant::Variant(float a)
{
	value.v_float=a;
}
Variant::Variant(double a)
{
	value.v_double=a;
}
Variant::Variant(long double a)
{
	value.v_long_double=a;
}
Variant::Variant(void * a)
{
	value.v_r_void = a;
}
Variant::Variant(CQMLObject * a)
{
	value.v_r_CQMLObject = a;
}

//#include all_constructors
#include "CQMLObject.h"

Variant Variant::Get(char * s)
{
	if(this->typeID!=TYPE_CQMLOBJECT)
	{
		throw 0;
		return 0;
	}
	return value.v_r_CQMLObject->Get(s);

	//return *this;
}


const Variant& Variant::operator=(Variant & rhs)
{
	typeID=rhs.typeID;
	value=rhs.value;
	return *this;
}


#define VARIANT_SIMPLE_OPERATOR(OP) \
const Variant Variant::operator##OP (Variant & rhs) const \
{ \
	Variant v(*this); \
	switch(typeID) \
	{ \
	case TYPE_INT: \
		v.value.v_int=v.value.v_int OP rhs.AS<int>(); \
		break; \
	case TYPE_LONG: \
		v.value.v_long=v.value.v_long OP rhs.AS<long>(); \
		break; \
	case TYPE_LONG_LONG: \
		v.value.v_long_long=v.value.v_long_long OP rhs.AS<long long>(); \
		break; \
	case TYPE_UNSIGNED_INT: \
		v.value.v_unsigned_int=v.value.v_unsigned_int OP rhs.AS<unsigned int>(); \
		break; \
	case TYPE_UNSIGNED_LONG: \
		v.value.v_unsigned_long=v.value.v_unsigned_long OP rhs.AS<unsigned long>(); \
		break; \
	case TYPE_UNSIGNED_LONG_LONG: \
		v.value.v_unsigned_long_long=v.value.v_unsigned_long_long OP rhs.AS<unsigned long long>(); \
		break; \
	case TYPE_FLOAT: \
		v.value.v_float=v.value.v_float OP rhs.AS<float>(); \
		break; \
	case TYPE_DOUBLE: \
		v.value.v_double=v.value.v_double OP rhs.AS<double>(); \
		break; \
	case TYPE_LONG_DOUBLE: \
		v.value.v_long_double=v.value.v_long_double OP rhs.AS<long double>(); \
		break; \
	default: \
		throw 0; \
		break; \
	} \
	return v; \
}


#define VARIANT_INTEGER_OPERATOR(OP) \
const Variant Variant::operator##OP (Variant & rhs) const \
{ \
	Variant v(*this); \
	switch(typeID) \
	{ \
	case TYPE_INT: \
		v.value.v_int=v.value.v_int OP rhs.AS<int>(); \
		break; \
	case TYPE_LONG: \
		v.value.v_long=v.value.v_long OP rhs.AS<long>(); \
		break; \
	case TYPE_LONG_LONG: \
		v.value.v_long_long=v.value.v_long_long OP rhs.AS<long long>(); \
		break; \
	case TYPE_UNSIGNED_INT: \
		v.value.v_unsigned_int=v.value.v_unsigned_int OP rhs.AS<unsigned int>(); \
		break; \
	case TYPE_UNSIGNED_LONG: \
		v.value.v_unsigned_long=v.value.v_unsigned_long OP rhs.AS<unsigned long>(); \
		break; \
	case TYPE_UNSIGNED_LONG_LONG: \
		v.value.v_unsigned_long_long=v.value.v_unsigned_long_long OP rhs.AS<unsigned long long>(); \
		break; \
	default: \
		throw 0; \
		break; \
	} \
	return v; \
}

VARIANT_SIMPLE_OPERATOR(+)
VARIANT_SIMPLE_OPERATOR(-)
VARIANT_SIMPLE_OPERATOR(*)
VARIANT_SIMPLE_OPERATOR(/)
VARIANT_INTEGER_OPERATOR(%)




/*
const Variant Variant::operator+(Variant & rhs) const
{
	Variant v(*this);
	switch(typeID)
	{
	case TYPE_INT:
		v.value.v_int=v.value.v_int+rhs.AS<int>();
		break;
	case TYPE_LONG:
		v.value.v_long=v.value.v_long+rhs.AS<long>();
		break;
	case TYPE_LONG_LONG:
		v.value.v_long_long=v.value.v_long_long+rhs.AS<long long>();
		break;
	case TYPE_UNSIGNED_INT:
		v.value.v_unsigned_int=v.value.v_unsigned_int+rhs.AS<unsigned int>();
		break;
	case TYPE_UNSIGNED_LONG:
		v.value.v_unsigned_long=v.value.v_unsigned_long+rhs.AS<unsigned long>();
		break;
	case TYPE_UNSIGNED_LONG_LONG:
		v.value.v_unsigned_long_long=v.value.v_unsigned_long_long+rhs.AS<unsigned long long>();
		break;
	case TYPE_FLOAT:
		v.value.v_float=v.value.v_float+rhs.AS<float>();
		break;
	case TYPE_DOUBLE:
		v.value.v_double=v.value.v_double+rhs.AS<double>();
		break;
	case TYPE_LONG_DOUBLE:
		v.value.v_long_double=v.value.v_long_double+rhs.AS<long double>();
		break;

	default:
		throw 0;
		break;
	}
	return v;
}*/