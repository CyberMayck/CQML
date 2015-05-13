#include "dll_export.h"

#include "variant.h"
#include "attribControl.h"
#include "CQMLObject.h"

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
	value.v_string=new std::string(a);
	typeID=TYPE_STRING;
}
Variant::Variant(std::string a)
{
	value.v_string=new std::string(a);
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
Variant::Variant(const VariantRef& rhs)
{
	typeID=rhs.typeID;
	switch(typeID)
	{
	case TYPE_INT:
		value.v_int=*rhs.value.v_int;
		break;
	case TYPE_LONG:
		value.v_long=*rhs.value.v_long;
		break;
	case TYPE_LONG_LONG:
		value.v_long_long=*rhs.value.v_long_long;
		break;
	case TYPE_UNSIGNED_INT:
		value.v_unsigned_int=*rhs.value.v_unsigned_int;
		break;
	case TYPE_UNSIGNED_LONG:
		value.v_unsigned_long=*rhs.value.v_unsigned_long;
		break;
	case TYPE_UNSIGNED_LONG_LONG:
		value.v_unsigned_long_long=*rhs.value.v_unsigned_long_long;
		break;
	case TYPE_FLOAT:
		value.v_float=*rhs.value.v_float;
		break;
	case TYPE_DOUBLE:
		value.v_double=*rhs.value.v_double;
		break;
	case TYPE_LONG_DOUBLE:
		value.v_long_double=*rhs.value.v_long_double;
		break;
	case TYPE_VOID_PTR:
		value.v_r_void=*rhs.value.v_r_void;
		break;
	case TYPE_STRING:
		value.v_string= new std::string(*rhs.value.v_string);
		break;
	case TYPE_CQMLOBJECT:
		if(IsValueType(value.v_r_CQMLObject->classID))
			value.v_r_CQMLObject=(*rhs.value.v_r_CQMLObject)->Copy();
		else
			value.v_r_CQMLObject= *rhs.value.v_r_CQMLObject;
		break;
	default:
		throw 0;
		break;
	}
}

Variant::~Variant()
{
	if(typeID==TYPE_STRING)
		delete value.v_string;
	if(typeID==TYPE_CQMLOBJECT && IsValueType(value.v_r_CQMLObject->classID))
	{
		delete value.v_r_CQMLObject;
	}
}

//#include all_constructors
#include "CQMLObject.h"




VariantRef::VariantRef(int& a, void (**r)(CQMLGUI::CQML_Context*))
{
	value.v_int=&a;
	typeID=TYPE_INT;
	updaterP=r;
}
VariantRef::VariantRef(long& a, void (**r)(CQMLGUI::CQML_Context*))
{
	value.v_long=&a;
	typeID=TYPE_LONG;
	updaterP=r;
}
VariantRef::VariantRef(long long& a, void (**r)(CQMLGUI::CQML_Context*))
{
	value.v_long_long=&a;
	typeID=TYPE_LONG_LONG;
	updaterP=r;
}
VariantRef::VariantRef(unsigned int& a, void (**r)(CQMLGUI::CQML_Context*))
{
	value.v_unsigned_int=&a;
	typeID=TYPE_UNSIGNED_INT;
	updaterP=r;
}
VariantRef::VariantRef(unsigned long& a, void (**r)(CQMLGUI::CQML_Context*))
{
	value.v_unsigned_long=&a;
	typeID=TYPE_UNSIGNED_LONG;
	updaterP=r;
}
VariantRef::VariantRef(unsigned long long& a, void (**r)(CQMLGUI::CQML_Context*))
{
	value.v_unsigned_long_long=&a;
	typeID=TYPE_UNSIGNED_LONG_LONG;
	updaterP=r;
}
VariantRef::VariantRef(float& a, void (**r)(CQMLGUI::CQML_Context*))
{
	value.v_float=&a;
	typeID=TYPE_FLOAT;
	updaterP=r;
}
VariantRef::VariantRef(double& a, void (**r)(CQMLGUI::CQML_Context*))
{
	value.v_double=&a;
	typeID=TYPE_DOUBLE;
	updaterP=r;
}
VariantRef::VariantRef(long double& a, void (**r)(CQMLGUI::CQML_Context*))
{
	value.v_long_double=&a;
	typeID=TYPE_LONG_DOUBLE;
	updaterP=r;
}
/*VariantRef::VariantRef(const char * a)
{
	value.v_string=new std::string(a);
	typeID=TYPE_STRING;
}*/
VariantRef::VariantRef(std::string& a, void (**r)(CQMLGUI::CQML_Context*))
{
	value.v_string=&std::string(a);
	typeID=TYPE_STRING;
	updaterP=r;
}
VariantRef::VariantRef(void *& a, void (**r)(CQMLGUI::CQML_Context*))
{
	value.v_r_void = &a;
	typeID=TYPE_VOID_PTR;
	updaterP=r;
}
VariantRef::VariantRef(CQMLObject ** a, void (**r)(CQMLGUI::CQML_Context*))
{
	value.v_r_CQMLObject = a;
	typeID=TYPE_CQMLOBJECT;
	updaterP=r;
}
VariantRef::VariantRef(CQMLObject* a, void (**r)(CQMLGUI::CQML_Context*))
{
	value.v_CQMLObject = a;
	typeID=TYPE_CQMLOBJECT_VALUE;
	updaterP=r;
}


VariantRef::VariantRef()
{
	typeID=TYPE_INVALID;
	value.v_int=0;
	updaterP=0;
}
VariantRef VariantRef::Get(const char * s)
{
	if(this->typeID!=TYPE_CQMLOBJECT)
	{
		throw 0;
	}
	return (*value.v_r_CQMLObject)->Get(s);
}
void VariantRef::SetUpdater(void (*r)(CQMLGUI::CQML_Context*))
{
	if(updaterP!=0)
		(*updaterP)=r;
}

VariantRef Variant::Get(const char * s)
{
	if(this->typeID!=TYPE_CQMLOBJECT)
	{
		throw 0;
	//	return 0;
	}
	return value.v_r_CQMLObject->Get(s);

	//return *this;
}

void TryAssignCQMLReference(CQMLObject ** l,CQMLObject * rhs)
{
	if((*l)!=0 && !IsCompatible((*l)->classID,rhs->classID))
	{
		throw 0;
		return;
	}
	// check if is same or parent type
	*l=rhs;
}
void AssignCQMLValue(CQMLObject * l,CQMLObject * rhs);
void TryAssignCQMLValue(CQMLObject * l,CQMLObject * rhs)
{
	if(l->classID!=rhs->classID)
	{
		throw (0);
		return;
	}
	// assign as if same type
	AssignCQMLValue(l,rhs);
}

#define VARIANT_TO_VARIANTREF(rhs) \
	if(typeID==rhs.typeID)\
	{\
		switch(typeID)\
		{\
		case TYPE_INT:\
			*value.v_int=rhs.value.v_int;\
			break;\
		case TYPE_LONG:\
			*value.v_long=rhs.value.v_long;\
			break;\
		case TYPE_LONG_LONG:\
			*value.v_long_long=rhs.value.v_long_long;\
			break;\
		case TYPE_UNSIGNED_INT:\
			*value.v_unsigned_int=rhs.value.v_unsigned_int;\
			break;\
		case TYPE_UNSIGNED_LONG:\
			*value.v_unsigned_long=rhs.value.v_unsigned_long;\
			break;\
		case TYPE_UNSIGNED_LONG_LONG:\
			*value.v_unsigned_long_long=rhs.value.v_unsigned_long_long;\
			break;\
		case TYPE_FLOAT:\
			*value.v_float=rhs.value.v_float;\
			break;\
		case TYPE_DOUBLE:\
			*value.v_double= rhs.value.v_double;\
			break;\
		case TYPE_LONG_DOUBLE:\
			*value.v_long_double= rhs.value.v_long_double;\
			break;\
		case TYPE_VOID_PTR:\
			*value.v_r_void= rhs.value.v_r_void;\
			break;\
		case TYPE_STRING:\
			*value.v_string= *rhs.value.v_string;\
			break;\
		case TYPE_CQMLOBJECT:\
			TryAssignCQMLReference(value.v_r_CQMLObject,rhs.value.v_r_CQMLObject); \
			break;\
		case TYPE_CQMLOBJECT_VALUE:\
			TryAssignCQMLValue(value.v_CQMLObject,rhs.value.v_r_CQMLObject);\
			break;\
		default:\
			throw 0;\
			break;\
		}\
	}\
	else\
	{\
		throw 0;\
	}

const VariantRef & VariantRef::operator=(const Variant & rhs)
{
	/*typeID=rhs.typeID;
	switch(typeID)
	{
	case TYPE_INT:
		*value.v_int=rhs.value.v_int;
		break;
	case TYPE_LONG:
		*value.v_long=rhs.value.v_long;
		break;
	case TYPE_LONG_LONG:
		*value.v_long_long=rhs.value.v_long_long;
		break;
	case TYPE_UNSIGNED_INT:
		*value.v_unsigned_int=rhs.value.v_unsigned_int;
		break;
	case TYPE_UNSIGNED_LONG:
		*value.v_unsigned_long=rhs.value.v_unsigned_long;
		break;
	case TYPE_UNSIGNED_LONG_LONG:
		*value.v_unsigned_long_long=rhs.value.v_unsigned_long_long;
		break;
	case TYPE_FLOAT:
		*value.v_float=rhs.value.v_float;
		break;
	case TYPE_DOUBLE:
		*value.v_double= rhs.value.v_double;
		break;
	case TYPE_LONG_DOUBLE:
		*value.v_long_double= rhs.value.v_long_double;
		break;
	case TYPE_VOID_PTR:
		*value.v_r_void= rhs.value.v_r_void;
		break;
	case TYPE_STRING:
		*value.v_string= *rhs.value.v_string;
		break;
	case TYPE_CQMLOBJECT:
		*value.v_r_CQMLObject= rhs.value.v_r_CQMLObject;
		break;
	default:
		throw 0;
		break;
	}*/

	//VARIANT_TO_VARIANTREF(rhs)
	
	if(typeID==rhs.typeID)
	{
		switch(typeID)
		{
		case TYPE_INT:
			*value.v_int=rhs.value.v_int;
			break;
		case TYPE_LONG:
			*value.v_long=rhs.value.v_long;
			break;
		case TYPE_LONG_LONG:
			*value.v_long_long=rhs.value.v_long_long;
			break;
		case TYPE_UNSIGNED_INT:
			*value.v_unsigned_int=rhs.value.v_unsigned_int;
			break;
		case TYPE_UNSIGNED_LONG:
			*value.v_unsigned_long=rhs.value.v_unsigned_long;
			break;
		case TYPE_UNSIGNED_LONG_LONG:
			*value.v_unsigned_long_long=rhs.value.v_unsigned_long_long;
			break;
		case TYPE_FLOAT:
			*value.v_float=rhs.value.v_float;
			break;
		case TYPE_DOUBLE:
			*value.v_double= rhs.value.v_double;
			break;
		case TYPE_LONG_DOUBLE:
			*value.v_long_double= rhs.value.v_long_double;
			break;
		case TYPE_VOID_PTR:
			*value.v_r_void= rhs.value.v_r_void;
			break;
		case TYPE_STRING:
			*value.v_string= *rhs.value.v_string;
			break;
		case TYPE_CQMLOBJECT:
			TryAssignCQMLReference(value.v_r_CQMLObject,rhs.value.v_r_CQMLObject); 
			break;
		case TYPE_CQMLOBJECT_VALUE:
			TryAssignCQMLValue(value.v_CQMLObject,rhs.value.v_r_CQMLObject);
			break;
		default:
			throw 0;
			break;
		}
	}
	else
	{
		throw 0;
	}
	//typeID=rhs.typeID;
	return *this;
}

const Variant& Variant::operator=(const Variant & rhs)
{
	typeID=rhs.typeID;
	value=rhs.value;
	return *this;
}

#define VARIANTREF_ASSIGN_OPERATOR(OP) \
const VariantRef& VariantRef::operator##OP##=(const Variant & rhs) \
{ \
	Variant out= Variant(*this) OP rhs; \
	VARIANT_TO_VARIANTREF(out) \
	return *this; \
}

#define VARIANTREF_SIMPLE_OPERATOR(OP) \
const Variant VariantRef::operator##OP (const Variant & rhs) const \
{ \
	return Variant(*this) OP rhs; \
}

#define VARIANTREF_SIMPLE_OPERATOR_BOOL(OP) \
bool VariantRef::operator##OP (const Variant & rhs) const \
{ \
	return Variant(*this) OP rhs; \
}

#define VARIANT_SIMPLE_OPERATOR(OP) \
const Variant Variant::operator##OP (const Variant & rhs) const \
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


#define VARIANT_SIMPLE_OPERATOR_BOOL(OP) \
bool Variant::operator##OP (const Variant & rhs) const \
{ \
	Variant v(*this); \
	switch(typeID) \
	{ \
	case TYPE_INT: \
		return v.value.v_int OP rhs.As<int>(); \
		break; \
	case TYPE_LONG: \
		v.value.v_long=v.value.v_long OP rhs.As<long>(); \
		break; \
	case TYPE_LONG_LONG: \
		return v.value.v_long_long OP rhs.As<long long>(); \
		break; \
	case TYPE_UNSIGNED_INT: \
		return v.value.v_unsigned_int OP rhs.As<unsigned int>(); \
		break; \
	case TYPE_UNSIGNED_LONG: \
		return v.value.v_unsigned_long OP rhs.As<unsigned long>(); \
		break; \
	case TYPE_UNSIGNED_LONG_LONG: \
		return v.value.v_unsigned_long_long OP rhs.As<unsigned long long>(); \
		break; \
	case TYPE_FLOAT: \
		return v.value.v_float OP rhs.As<float>(); \
		break; \
	case TYPE_DOUBLE: \
		return v.value.v_double OP rhs.As<double>(); \
		break; \
	case TYPE_LONG_DOUBLE: \
		return v.value.v_long_double OP rhs.As<long double>(); \
		break; \
	default: \
		throw 0; \
		break; \
	} \
	return false; \
}

#define VARIANT_INTEGER_OPERATOR(OP) \
const Variant Variant::operator##OP (const Variant & rhs) const \
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

VARIANT_SIMPLE_OPERATOR_BOOL(==)

VARIANTREF_SIMPLE_OPERATOR(+)
VARIANTREF_SIMPLE_OPERATOR(-)
VARIANTREF_SIMPLE_OPERATOR(*)
VARIANTREF_SIMPLE_OPERATOR(/)
VARIANTREF_SIMPLE_OPERATOR(%)


VARIANTREF_SIMPLE_OPERATOR_BOOL(==)

VARIANTREF_ASSIGN_OPERATOR(+)
VARIANTREF_ASSIGN_OPERATOR(-)
VARIANTREF_ASSIGN_OPERATOR(*)
VARIANTREF_ASSIGN_OPERATOR(/)
VARIANTREF_ASSIGN_OPERATOR(%)

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