#pragma once
#include<iostream>
#include"Add.h"
using namespace std;
class Milk:public Add
{
public:
	Milk(Beverage* beverage) :Add(beverage) {}
	//此行代码含义：
	//Beverage* beverage是父类的属性，
	//所以Add（beverage）是把Milk(Beverage* beverage)中的传递来的beverage传递进父类有参构造
	string operation()
	{
		return "Milk(" + Add::operation() + ")";
	}
};