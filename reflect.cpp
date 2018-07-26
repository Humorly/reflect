// reflect.cpp: 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <iostream>

#include "reflect.h"
#include "test.h"

int main()
{
	auto t = get_class("test");
	t.print();
	
	return 0;
}

