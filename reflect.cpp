
#include <iostream>
#include <string>

#include "reflect.h"
#include "test.h"

constexpr char class_[][10] = { "test", "test1", "test2" };

template <int N>
void print()
{
	auto t = get_register_type(class_[N - 1]);
	t.print();
	print<N - 1>();
}

template <> void print<0>() {}

int main()
{
	print<3>();
	auto n1 = get_register_type("int");

	return 0;
}

