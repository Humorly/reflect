#pragma once

// add by humorly 2018/7/25
// make class type reflection

#ifndef __H_REFLECT_H__
#define __H_REFLECT_H__

// set special template index type
using __value_type = std::size_t;

// make special template __value
constexpr __value_type __value(const char * val)
{
	__value_type num = 0;
	while (*val) num += *val++;
	return num;
}

// reflect template
template <__value_type N>
class reflect
{
public:
	reflect() {};
	virtual ~reflect() {}
};

// special template
#define register_class(__class) template <>\
								class reflect<__value(#__class)>\
								{\
								public:\
									reflect() {};\
									virtual ~reflect() {}\
									typedef __class type;\
								};

// make class
#define get_class(x) reflect<__value(x)>::type();

#endif // !__H_REFLECT_H__