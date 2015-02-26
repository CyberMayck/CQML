#pragma once

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

	int As_int();
	long As_long();
	long long As_long_long();
	float As_float();
	double As_double();
	long double As_long_double();
};
