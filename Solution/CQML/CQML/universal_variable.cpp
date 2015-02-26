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



const Variant& Variant::operator=(Variant & rhs)
{
	typeID=rhs.typeID;
	value=rhs.value;
}

#define TYPE_INT (1)
#define TYPE_LONG (2)
#define TYPE_LONG_LONG (3)
#define TYPE_UNSIGNED_INT (4)
#define TYPE_UNSIGNED_LONG (5)
#define TYPE_UNSIGNED_LONG_LONG (6)
#define TYPE_FLOAT (7)
#define TYPE_DOUBLE (8)
#define TYPE_LONG_DOUBLE (9)

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