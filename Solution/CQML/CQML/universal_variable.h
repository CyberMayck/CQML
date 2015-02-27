#pragma once

struct CQMLObject;
#define TYPE_INT (1)
#define TYPE_LONG (2)
#define TYPE_LONG_LONG (3)
#define TYPE_UNSIGNED_INT (4)
#define TYPE_UNSIGNED_LONG (5)
#define TYPE_UNSIGNED_LONG_LONG (6)
#define TYPE_FLOAT (7)
#define TYPE_DOUBLE (8)
#define TYPE_LONG_DOUBLE (9)
#define TYPE_CQMLOBJECT (10)

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
	
	template<typename T> T AS()
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

	//int As_int();
	//long As_long();
	//long long As_long_long();
	//float As_float();
	//double As_double();
	//long double As_long_double();
};
