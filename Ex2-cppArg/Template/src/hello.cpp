#include "hello.h"

#include <iostream>
#include <vector>
#define LOG(x) std::cout << (x) << std::endl

#define EXAMPLE_5

#ifdef EXAMPLE_1
template<typename... T>
void f(T... args)
{
	std::cout << sizeof...(args) << std::endl;
}


int main()
{
	f();
	f(1, 2);
	return 0;
}
#endif

#ifdef EXAMPLE_2
// µÝ¹éÖÕÖ¹º¯Êý
void print()
{
	std::cout << "empty" << std::endl;
}
template<typename T, class ...Args>
void print(T head, Args... rest)
{
	std::cout << "parameter: " << head << std::endl;
	print(rest...);
}

int main()
{
	print(1, 2, 3, 4);
	return 0;
}
#endif

#ifdef EXAMPLE_3
template<typename T>
T sum(T t)
{
	return t;
}
template<typename T, typename ...Args>
T sum(T first, Args... rest)
{
	return first + sum<T>(rest...);
}

int main()
{
	LOG(sum(1, 2, 3, 4));
	return 0;
}
#endif

#ifdef EXAMPLE_4
struct A
{
	A(int) {}
	void log() {
		LOG("this has int");
	}
};

struct B
{
    B(int, double) {}
    void log() {
        LOG("this has int");
        LOG("this has double");
    }
};

template<typename T, typename... Args>
T* Instance(Args&&... args)
{
	return new T(std::forward<Args>(args)...);
}

int main()
{
	A* pa = Instance<A>(1);
	B* pb = Instance<B>(1, 2.0);
	pa->log();
	pb->log();
	return 0;
}

#endif

#ifdef EXAMPLE_5

void add(std::vector<int>& vec)
{
	for (auto value : vec) {
		LOG(value);
	}
	vec.clear();
}
template<typename ...Args>
void add(std::vector<int>& vec, int first, Args... rest)
{
	vec.push_back(first);
	add(vec, rest...);
}

int main()
{
	std::vector<int> test;
	add(test, 1, 2, 3);
	add(test, 3, 4, 5);
}

#endif
