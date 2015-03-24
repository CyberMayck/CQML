#pragma once
#include <type_traits>

struct CQMLObject;

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
	TYPE_CQMLOBJECT

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
		CQMLObject* v_r_CQMLObject;
		//#include all_types.h
	} value;
	//template<typename T>
	//T AS()(const T& obj) { this->AS}

	template<typename T>
	typename std::enable_if<std::is_arithmetic<T>::value, T>::type As() const;
	
	Variant(int);
	Variant(long);
	Variant(long long);
	Variant(unsigned int);
	Variant(unsigned long);
	Variant(unsigned long long);
	Variant(float);
	Variant(double);
	Variant(long double);
	Variant(void*);
	Variant(CQMLObject*);

	Variant Get(char *);
	//#include all_types_constructor.h

	const Variant& operator=(Variant & rhs);
	const Variant& operator+=(Variant & rhs);
	const Variant& operator-=(Variant & rhs);
	const Variant& operator*=(Variant & rhs);
	const Variant& operator/=(Variant & rhs);
	const Variant& operator%=(Variant & rhs);
	const Variant operator+(Variant & rhs) const;
	const Variant operator-(Variant & rhs) const;
	const Variant operator*(Variant & rhs) const;
	const Variant operator/(Variant & rhs) const;
	const Variant operator%(Variant & rhs) const;

};

// SFINAE


template<typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type Variant::As() const
{
	switch(typeID)
	{
	case TYPE_INT:
		return value.v_int;
		break;
	case TYPE_LONG:
		return value.v_long;
		break;
	case TYPE_LONG_LONG:
		return value.v_long_long;
		break;
	case TYPE_UNSIGNED_INT:
		return value.v_unsigned_int;
		break;
	case TYPE_UNSIGNED_LONG:
		return value.v_unsigned_long;
		break;
	case TYPE_UNSIGNED_LONG_LONG:
		return value.v_unsigned_long_long;
		break;
	case TYPE_FLOAT:
		return value.v_float;
		break;
	case TYPE_DOUBLE:
		return value.v_double;
		break;
	case TYPE_LONG_DOUBLE:
		return value.v_long_double;
		break;
	default:
		throw 0;
		break;
	}
	return 0;
}


