#pragma once

struct CQMLObject;

struct Variant
{
	long typeID;
	union
	{
		int v_int;
		long v_long;
		long long v_long_long;
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
	Variant(float);
	Variant(double);
	Variant(long double);
	Variant(void*);
	Variant(CQMLObject*);

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
