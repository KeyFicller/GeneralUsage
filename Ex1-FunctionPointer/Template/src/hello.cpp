#include "hello.h"

#include <iostream>
#include <map>
#include <string>
#include <functional>
#define LOG(x) std::cout << (x) << std::endl

void print(int a)
{
	std::cout << "int : " << a << std::endl;
}

using func = void(*)(int);

using OnInputHandlerChanged = void(*)(const std::string& str);

std::map<std::string, OnInputHandlerChanged> funcs;

#if 0
	#define HZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
    template<typename T, typename F>
    bool Dispatch(const F& func)
    {
        if (m_Event.GetEventType() == T::GetStaticType())
        {
            m_Event.Handled = func(static_cast<T&>(m_Event));
            return true;
        }
        return false;
    }
#endif


class Dispather
{
public:
	Dispather(const std::string& str)
		: m_HandlerName(str) {}

	template<typename T, typename F>
	void Dispatch(const T& HandlerName, const F& func)
	{
		if (m_HandlerName == HandlerName)
		{
			func();
		}
	}

private:
	std::string m_HandlerName;
};

class Editor
{
public:
	void OnUpdate()
	{
		Dispather dispathcer("HandlerA");
		dispathcer.Dispatch("HandlerA", std::bind(&Editor::printIfHandlerA, this, std::placeholders::_1));
	}
private:
    void printIfHandlerA()
    {
        LOG("HandlerA Dispatched");
    }
};

int main()
{
	void(*pFuc)(int);
	pFuc = print;
	pFuc(2);

	func pFuc2;
	pFuc2 = print;
	pFuc2(3);

	funcs.insert(std::make_pair(
		"test str", [](const std::string& str) -> void {
			std::cout << str << std::endl;
		}
	));

	funcs["test str"]("instance");



	return 0;
}