#include "hello.h"
#include <iostream>

void* test() {
	_TRACE("{0}", __FUNCTION__);
	return nullptr;
}

const void* test() {
    _TRACE("{0}", __FUNCTION__);
    return nullptr;
}

int main()
{
	Predefined::InitLog();

	const void* ptr = test();

	return 0;
}