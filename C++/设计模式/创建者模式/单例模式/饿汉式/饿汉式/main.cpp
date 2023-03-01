#include<iostream>
#include"class.h"
using namespace std;
/*
				饿汉式
*/
int main()
{
	SingletonHungry* sh1 = SingletonHungry::getClass();
	SingletonHungry* sh2 = SingletonHungry::getClass();

	if (sh1 == sh2)
	{
		cout << "这是个单例模式" << endl;
	}
	else
	{
		cout << "这不是单例模式" << endl;
	}
}