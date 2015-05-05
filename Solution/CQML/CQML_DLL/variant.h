#pragma once

#include "dll_export.h"

#include <iostream>
#include <type_traits>

struct CQMLObject;
struct Variant;
namespace CQMLGUI
{
	struct QML_Context;
};

	// enum here

enum type_variant
{
	TYPE_INT,
	TYPE_LONG,
	TYPE_LONG_LONG,
	TYPE_UNSIGNED_INT,
	TYPE_UNSIGNED_LONG,
	TYPE_UNSIGNED_LONG_LONG,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_LONG_DOUBLE,
	TYPE_VOID_PTR,
	TYPE_STRING,
	TYPE_CQMLOBJECT,
	TYPE_CQMLOBJECT_VALUE,
	TYPE_INVALID
};

struct VariantRef
{
	CQML_API VariantRef();
	CQML_API VariantRef(int&, void (**r)(CQMLGUI::QML_Context*));
	CQML_API VariantRef(long&, void (**r)(CQMLGUI::QML_Context*));
	CQML_API VariantRef(long long&, void (**r)(CQMLGUI::QML_Context*));
	CQML_API VariantRef(unsigned int&, void (**r)(CQMLGUI::QML_Context*));
	CQML_API VariantRef(unsigned long&, void (**r)(CQMLGUI::QML_Context*));
	CQML_API VariantRef(unsigned long long&, void (**r)(CQMLGUI::QML_Context*));
	CQML_API VariantRef(float&, void (**r)(CQMLGUI::QML_Context*));
	CQML_API VariantRef(double&, void (**r)(CQMLGUI::QML_Context*));
	CQML_API VariantRef(long double&, void (**r)(CQMLGUI::QML_Context*));
	//CQML_API VariantRef(const char*);
	CQML_API VariantRef(std::string&, void (**r)(CQMLGUI::QML_Context*));
	CQML_API VariantRef(void*&, void (**r)(CQMLGUI::QML_Context*));
	CQML_API VariantRef(CQMLObject*, void (**r)(CQMLGUI::QML_Context*));
	CQML_API VariantRef(CQMLObject**, void (**r)(CQMLGUI::QML_Context*));
	long typeID;
	union
	{
		int* v_int;
		long* v_long;
		long long* v_long_long;
		unsigned int* v_unsigned_int;
		unsigned long* v_unsigned_long;
		unsigned long long* v_unsigned_long_long;
		float* v_float;
		double* v_double;
		long double* v_long_double;
		void** v_r_void;
		std::string* v_string;
		CQMLObject* v_CQMLObject;
		CQMLObject** v_r_CQMLObject;
	} value;
	void (**updaterP)(CQMLGUI::QML_Context*);

	CQML_API VariantRef Get(const char *);
	CQML_API void SetUpdater(void (*r)(CQMLGUI::QML_Context*));

	CQML_API const VariantRef& operator=(const Variant & rhs);
	CQML_API const VariantRef& operator+=(const Variant & rhs);
	CQML_API const VariantRef& operator-=(const Variant & rhs);
	CQML_API const VariantRef& operator*=(const Variant & rhs);
	CQML_API const VariantRef& operator/=(const Variant & rhs);
	CQML_API const VariantRef& operator%=(const Variant & rhs);
	CQML_API bool operator==(const Variant & rhs) const;
	CQML_API const Variant operator+(const Variant & rhs) const;
	CQML_API const Variant operator-(const Variant & rhs) const;
	CQML_API const Variant operator*(const Variant & rhs) const;
	CQML_API const Variant operator/(const Variant & rhs) const;
	CQML_API const Variant operator%(const Variant & rhs) const;

	
	template<typename T> 
	typename T As() const;
	
};

struct Variant
{
	long typeID;
	union
	{
		int v_int;
		long v_long;
		long long v_long_long;
		unsigned int v_unsigned_int;
		unsigned long v_unsigned_long;
		unsigned long long v_unsigned_long_long;
		float v_float;
		double v_double;
		long double v_long_double;
		void* v_r_void;
		//char* v_string;
		std::string* v_string;
		CQMLObject* v_r_CQMLObject;
		//#include all_types.h
	} value;
	//template<typename T>
	//T AS()(const T& obj) { this->AS}

	//template<typename T>
	//typename std::enable_if<std::is_arithmetic<T>::value, T>::type As() const;
	template<typename T>
	typename std::enable_if<std::is_arithmetic<T>::value, T>::type As() const;
	template<typename T>
	typename std::enable_if<std::is_same<T,std::string>::value, T>::type As() const;
	template<typename T>
	typename std::enable_if<std::is_same<T,CQMLObject*>::value, T>::type As() const;
	template<typename T>
	typename std::enable_if<!(std::is_arithmetic<T>::value ||std::is_same<T,std::string>::value || std::is_same<T,CQMLObject*>::value), T>::type As() const;
	

	CQML_API Variant(int);
	CQML_API Variant(long);
	CQML_API Variant(long long);
	CQML_API Variant(unsigned int);
	CQML_API Variant(unsigned long);
	CQML_API Variant(unsigned long long);
	CQML_API Variant(float);
	CQML_API Variant(double);
	CQML_API Variant(long double);
	CQML_API Variant(const char*);
	CQML_API Variant(std::string);
	CQML_API Variant(void*);
	CQML_API Variant(CQMLObject*);
	CQML_API Variant(const VariantRef&);

	CQML_API ~Variant();

	CQML_API VariantRef Get(const char *);
	//#include all_types_constructor.h

	CQML_API const Variant& operator=(const Variant & rhs);
	CQML_API const Variant& operator+=(const Variant & rhs);
	CQML_API const Variant& operator-=(const Variant & rhs);
	CQML_API const Variant& operator*=(const Variant & rhs);
	CQML_API const Variant& operator/=(const Variant & rhs);
	CQML_API const Variant& operator%=(const Variant & rhs);
	CQML_API bool operator==(const Variant & rhs) const;
	CQML_API const Variant operator+(const Variant & rhs) const;
	CQML_API const Variant operator-(const Variant & rhs) const;
	CQML_API const Variant operator*(const Variant & rhs) const;
	CQML_API const Variant operator/(const Variant & rhs) const;
	CQML_API const Variant operator%(const Variant & rhs) const;

};

struct ElementVariant
	: Variant
{
	CQMLObject * object;
	int hash;
};

// SFINAE
//#define CQML_DLL_EXPORTS
//#ifdef CQML_DLL_EXPORTS

template<typename T>
typename std::enable_if<std::is_same<T,CQMLObject*>::value, T>::type Variant::As() const
{
	switch(typeID)
	{
	case TYPE_CQMLOBJECT:
		return value.v_r_CQMLObject;
	default:
		throw 0;
		return 0;
	}
}

template<typename T>
typename std::enable_if<std::is_same<T,std::string>::value, T>::type Variant::As() const
{
	std::string a="";
	switch(typeID)
	{
	case TYPE_INT:
		a+=value.v_int;
		break;
	case TYPE_LONG:
		a+=value.v_long;
		break;
	case TYPE_LONG_LONG:
		a+=value.v_long_long;
		break;
	case TYPE_UNSIGNED_INT:
		a+=value.v_unsigned_int;
		break;
	case TYPE_UNSIGNED_LONG:
		a+=value.v_unsigned_long;
		break;
	case TYPE_UNSIGNED_LONG_LONG:
		a+=value.v_unsigned_long_long;
		break;
	case TYPE_FLOAT:
		a+= value.v_float;
		break;
	case TYPE_DOUBLE:
		a+=value.v_double;
		break;
	case TYPE_LONG_DOUBLE:
		a+= value.v_long_double;
		break;
	case TYPE_STRING:
		a+= value.v_string;
	default:
		throw 0;
		break;
	}
	return a;
}


template<typename T>
typename std::enable_if<!(std::is_arithmetic<T>::value ||std::is_same<T,std::string>::value || std::is_same<T,CQMLObject*>::value), T>::type Variant::As() const
{
	throw(0);
}

template<typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type Variant::As() const
{
	switch(typeID)
	{
	case TYPE_INT:
		return (T) value.v_int;
		break;
	case TYPE_LONG:
		return (T) value.v_long;
		break;
	case TYPE_LONG_LONG:
		return (T) value.v_long_long;
		break;
	case TYPE_UNSIGNED_INT:
		return (T) value.v_unsigned_int;
		break;
	case TYPE_UNSIGNED_LONG:
		return (T) value.v_unsigned_long;
		break;
	case TYPE_UNSIGNED_LONG_LONG:
		return (T) value.v_unsigned_long_long;
		break;
	case TYPE_FLOAT:
		return (T) value.v_float;
		break;
	case TYPE_DOUBLE:
		return (T) value.v_double;
		break;
	case TYPE_LONG_DOUBLE:
		return (T) value.v_long_double;
		break;
	default:
		throw 0;
		break;
	}
	return 0;
}


template<typename T> 
T VariantRef::As() const
{
	return Variant(*this).As<T>();
}




//#endif