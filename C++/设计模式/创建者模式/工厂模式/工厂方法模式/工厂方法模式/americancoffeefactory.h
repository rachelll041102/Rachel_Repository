#pragma once
#include<iostream>
#include"abstractfactory.h"
#include"americancoffee.h"
//美式咖啡工厂类
class AmericanCoffeeFactory:public AbstractFactory
{
public:
	AbstractCoffee* createCoffee()
	{
		return new AmericanCoffee();
	}
};