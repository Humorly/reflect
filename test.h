#pragma once

#ifndef __H_TEST_H__
#define __H_TEST_H__

#include <iostream>
#include "reflect.h"

class test;
register_class(test);
class test
{
public:
	test() {}
	virtual ~test() {}
	void print() { std::cout << "test" << std::endl; }
};

#endif // !__H_TEST_H__
