#include<iostream>
#include"class.h"
using namespace std;
/*
			懒汉式
	注：有缺点的
		不能保证多线程的安全性
*/
int main()
{
	SingletonLazy* test1 = SingletonLazy::getClass();
	SingletonLazy* test2 = SingletonLazy::getClass();
	if (test1 == test2)
	{
		cout << "这是个单例模式" << endl;
	}
	else
		cout << "这不是单例模式" << endl;
}