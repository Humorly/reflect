#pragma once

// add by humorly 2018/7/25
// make class type reflection

#ifndef __H_REFLECT_H__
#define __H_REFLECT_H__

#include <string>

// set special template index type
using __factor_type = std::size_t;

// make special template __factor_value
constexpr __factor_type __factor_value(const char * val)
{
	__factor_type num = 0;
	while (*val) num += *val++;
	return num;
}

// reflect template
template <__factor_type N>
class reflect
{
public:
	reflect() {};
	virtual ~reflect() {}
};

// special template
#define register_type(__class)		template <>\
									class reflect<__factor_value(#__class)>\
									{\
									public:\
										reflect() {};\
										virtual ~reflect() {}\
										typedef __class type;\
									};

// register pod type
register_type(bool);
register_type(char);
register_type(unsigned char);
register_type(unsigned short);
register_type(short);
register_type(unsigned int);
register_type(int);
register_type(float);
register_type(unsigned long);
register_type(long);
register_type(double);
register_type(std::string);

// register pod point type 
register_type(bool *);
register_type(char *);
register_type(unsigned char *);
register_type(unsigned short *);
register_type(short *);
register_type(unsigned int *);
register_type(int *);
register_type(float *);
register_type(unsigned long *);
register_type(long *);
register_type(double *);
register_type(std::string *);

// make class
#define get_register_type(x) reflect<__factor_value(x)>::type();

template <__factor_type N>
auto get_class_type()
{
	return reflect<N>::type();
}

#endif // !__H_REFLECT_H__