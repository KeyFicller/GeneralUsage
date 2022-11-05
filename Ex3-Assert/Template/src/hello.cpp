#include "hello.h"
#include <iostream>

int main()
{
	Predefined::InitLog();

	_TRACE("Hello {0}", 1);

	_TRACE("Value of Ptr Adress is {0:x}", reinterpret_cast<long long>(&Predefined::GetLogger));

	_TRACE("Value of Ptr Adress is {0:d}", reinterpret_cast<long long>(&Predefined::GetLogger));

	return 0;
}