// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <functional>
#include <windows.h>

//class base
//{
//public:
//	virtual base* func() {};
//};
//
////class derive1 final: public base
////{
////public:
////	void func() override final;
////};
//
////void derive1::func() {}
//
//class derive2 : public base
//{
//public:
//	derive2* func() override;
//};
//
//derive2* derive2::func()
//{
//	return NULL;
//}
//
//int final = 2;
//
//struct Demo
//{
//	void print(int a, int b)
//	{
//		std::cout << "Demo " << a << " " << b << " " << a_ << std::endl;
//	};
//	int a_ = 1;
//};
//
//int add(int& a, int& b)
//{
//	a++;
//	b++;
//	std::cout << "add " << a << " " << b << std::endl;
//	return a + b;
//}
//
//struct PrintDemo
//{
//	void operator()(int i) const
//	{
//		std::cout << "PrintDemo " << i << std::endl;
//	}
//};

int main()
{
	//using namespace std::placeholders;

	//{
	//	int a = 1;
	//	int b = 2;
	//	// 存储普通函数
	//	std::function<int(int&, int&)> f = add; // 方式1
	//	// std::function<int(int&, int&)> f = std::bind(add, _1, _2); // 方式2

	//	f(a, b); // output： add 2 3
	//}

	//{
	//	// 绑定lambda
	//	std::function<void()> f = []()
	//	{
	//		std::cout << "hello" << std::endl;
	//	};
	//}

	//{
	//	Demo demo;
	//	// 存储成员函数
	//	std::function<void(Demo&, int, int)> f1 = &Demo::print; // 方式1
	//	// std::function<void(int, int)> f1 = std::bind(&Demo::print, &demo, _1, 10); // 方式2

	//	// 存储成员变量
	//	std::function<int(Demo&)> f2 = &Demo::a_; // 方式1
	//	// std::function<int(Demo&, int)> f2 = std::bind(&Demo::a_, _1); // 方式1

	//	f1(demo, 10, 20); // output: Demo 10 20 1
	//	std::cout << f2(demo); // output: 1
	//}
	//{
	//	// 存储仿函数
	//	std::function<void(int)> f = PrintDemo();
	//	f(100); // output: PrintDemo 100
	//}

	//-------------------------------------
	// test coupling

	typedef int(*tt)(void);
	HINSTANCE hDll = LoadLibraryA("desktop_coupling.dll");


	//根据函数名获取dll地址
	tt f = (tt)GetProcAddress(hDll, "tt");
	std::cout << "f() " << f() << std::endl;

	system("pause");
	return 0;
}

