// reflect.cpp: �������̨Ӧ�ó������ڵ㡣

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

