# reflect
用以实现编译期的c++任意类型反射。

#1:在需要实现反射的类型声明之时注册该类型

// 包含反射头文件

#include "reflect.h"

// 注册类class

class test;

register_type(test);

class test 
{
	  ...
}

#2:在需要获取class test的地方调用get_class("test")获取之

auto t = get_register_type("test");
