#include "hello.h"
#include <iostream>

int main()
{
	Predefined::InitLog();

	_TRACE("Hello {0}", 1);

	return 0;
}