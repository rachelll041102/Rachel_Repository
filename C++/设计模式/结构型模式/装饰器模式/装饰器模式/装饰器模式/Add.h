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
		//���Ĵ��룬�������������า�ǵ�
		return m_beverage->operation();
	}
};