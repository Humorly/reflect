#pragma once

// add by humorly 2018/7/25
// make class type reflection

#ifndef __H_REFLECT_H__
#define __H_REFLECT_H__

#include <string>

// set special template index type
using __factor_type = std::size_t;

// make special template __factor_value
constexpr __factor_type type_container(const char * val)
{
	__factor_type num = 0;
	while (*val) num += *val++;
	return num;
}

namespace wstd 
{
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
									class wstd::reflect<type_container(#__class)>\
									{\
									public:\
										wstd::reflect() {};\
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

	// with params
	template <__factor_type N, typename ... T>
	auto get_class_type(T ... params)
	{
		std::cout << "params count = " << sizeof...(params) << std::endl;
		return wstd::reflect<N>::type(params ...);
	}
}

#endif // !__H_REFLECT_H__