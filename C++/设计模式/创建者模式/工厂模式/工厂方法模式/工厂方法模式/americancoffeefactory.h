#pragma once
#include<iostream>
#include"abstractfactory.h"
#include"americancoffee.h"
//��ʽ���ȹ�����
class AmericanCoffeeFactory:public AbstractFactory
{
public:
	AbstractCoffee* createCoffee()
	{
		return new AmericanCoffee();
	}
};