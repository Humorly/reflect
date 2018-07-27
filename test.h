#pragma once

#ifndef __H_TEST_H__
#define __H_TEST_H__

#include <iostream>
#include "reflect.h"

class test;
register_type(test);
class test
{
public:
	test() {}
	virtual ~test() {}
	void print() { std::cout << "test" << std::endl; }
};

class test1;
register_type(test1);
class test1
{
public:
	test1() {}
	virtual ~test1() {}
	void print() { std::cout << "test1" << std::endl; }
};

class test2;
register_type(test2);
class test2
{
public:
	test2() {}
	virtual ~test2() {}
	void print() { std::cout << "test2" << std::endl; }
};

#endif // !__H_TEST_H__
