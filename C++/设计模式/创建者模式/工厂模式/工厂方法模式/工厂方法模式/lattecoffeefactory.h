#pragma once
#include<iostream>
#include"abstractfactory.h"
#include"lattecoffee.h"
using namespace std;

class LatterCoffeeFactory :public AbstractFactory
{
public:
	AbstractCoffee* createCoffee()
	{
		return new LatteCoffee();
	}
};