#include "dll_export.h"

#include "variant.h"


Variant::Variant(int a)
{
	value.v_int=a;
	typeID=TYPE_INT;
}
Variant::Variant(long a)
{
	value.v_long=a;
	typeID=TYPE_LONG;
}
Variant::Variant(long long a)
{
	value.v_long_long=a;
	typeID=TYPE_LONG_LONG;
}
Variant::Variant(unsigned int a)
{
	value.v_unsigned_int=a;
	typeID=TYPE_UNSIGNED_INT;
}
Variant::Variant(unsigned long a)
{
	value.v_unsigned_long=a;
	typeID=TYPE_UNSIGNED_LONG;
}
Variant::Variant(unsigned long long a)
{
	value.v_unsigned_long_long=a;
	typeID=TYPE_UNSIGNED_LONG_LONG;
}
Variant::Variant(float a)
{
	value.v_float=a;
	typeID=TYPE_FLOAT;
}
Variant::Variant(double a)
{
	value.v_double=a;
	typeID=TYPE_DOUBLE;
}
Variant::Variant(long double a)
{
	value.v_long_double=a;
	typeID=TYPE_LONG_DOUBLE;
}
Variant::Variant(const char * a)
{
	value.v_string=new char[strlen(a)+1];
	strcpy(value.v_string, a);
	typeID=TYPE_STRING;
}
Variant::Variant(std::string a)
{
	value.v_string=new char[a.length()+1];
	strcpy(value.v_string, a.c_str());
	typeID=TYPE_STRING;
}
Variant::Variant(void * a)
{
	value.v_r_void = a;
	typeID=TYPE_VOID_PTR;
}
Variant::Variant(CQMLObject * a)
{
	value.v_r_CQMLObject = a;
	typeID=TYPE_CQMLOBJECT;
}
Variant::~Variant()
{
	if(typeID==TYPE_STRING)
		delete value.v_string;
}

//#include all_constructors
#include "CQMLObject.h"

Variant& Variant::Get(char * s)
{
	if(this->typeID!=TYPE_CQMLOBJECT)
	{
		throw 0;
	//	return 0;
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
		v.value.v_int=v.value.v_int OP rhs.As<int>(); \
		break; \
	case TYPE_LONG: \
		v.value.v_long=v.value.v_long OP rhs.As<long>(); \
		break; \
	case TYPE_LONG_LONG: \
		v.value.v_long_long=v.value.v_long_long OP rhs.As<long long>(); \
		break; \
	case TYPE_UNSIGNED_INT: \
		v.value.v_unsigned_int=v.value.v_unsigned_int OP rhs.As<unsigned int>(); \
		break; \
	case TYPE_UNSIGNED_LONG: \
		v.value.v_unsigned_long=v.value.v_unsigned_long OP rhs.As<unsigned long>(); \
		break; \
	case TYPE_UNSIGNED_LONG_LONG: \
		v.value.v_unsigned_long_long=v.value.v_unsigned_long_long OP rhs.As<unsigned long long>(); \
		break; \
	case TYPE_FLOAT: \
		v.value.v_float=v.value.v_float OP rhs.As<float>(); \
		break; \
	case TYPE_DOUBLE: \
		v.value.v_double=v.value.v_double OP rhs.As<double>(); \
		break; \
	case TYPE_LONG_DOUBLE: \
		v.value.v_long_double=v.value.v_long_double OP rhs.As<long double>(); \
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
		v.value.v_int=v.value.v_int OP rhs.As<int>(); \
		break; \
	case TYPE_LONG: \
		v.value.v_long=v.value.v_long OP rhs.As<long>(); \
		break; \
	case TYPE_LONG_LONG: \
		v.value.v_long_long=v.value.v_long_long OP rhs.As<long long>(); \
		break; \
	case TYPE_UNSIGNED_INT: \
		v.value.v_unsigned_int=v.value.v_unsigned_int OP rhs.As<unsigned int>(); \
		break; \
	case TYPE_UNSIGNED_LONG: \
		v.value.v_unsigned_long=v.value.v_unsigned_long OP rhs.As<unsigned long>(); \
		break; \
	case TYPE_UNSIGNED_LONG_LONG: \
		v.value.v_unsigned_long_long=v.value.v_unsigned_long_long OP rhs.As<unsigned long long>(); \
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
		v.value.v_int=v.value.v_int+rhs.As<int>();
		break;
	case TYPE_LONG:
		v.value.v_long=v.value.v_long+rhs.As<long>();
		break;
	case TYPE_LONG_LONG:
		v.value.v_long_long=v.value.v_long_long+rhs.As<long long>();
		break;
	case TYPE_UNSIGNED_INT:
		v.value.v_unsigned_int=v.value.v_unsigned_int+rhs.As<unsigned int>();
		break;
	case TYPE_UNSIGNED_LONG:
		v.value.v_unsigned_long=v.value.v_unsigned_long+rhs.As<unsigned long>();
		break;
	case TYPE_UNSIGNED_LONG_LONG:
		v.value.v_unsigned_long_long=v.value.v_unsigned_long_long+rhs.As<unsigned long long>();
		break;
	case TYPE_FLOAT:
		v.value.v_float=v.value.v_float+rhs.As<float>();
		break;
	case TYPE_DOUBLE:
		v.value.v_double=v.value.v_double+rhs.As<double>();
		break;
	case TYPE_LONG_DOUBLE:
		v.value.v_long_double=v.value.v_long_double+rhs.As<long double>();
		break;

	default:
		throw 0;
		break;
	}
	return v;
}*/