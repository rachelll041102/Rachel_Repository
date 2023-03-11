#pragma once
#include<iostream>
#include"Beverage.h"

class Add:public Beverage
{
protected:
	Beverage* m_beverage;
public:
	Add(Beverage* beverage) :m_beverage(beverage){}
	string operation()
	{
		//核心代码，不是用来被基类覆盖的
		return m_beverage->operation();
	}
};