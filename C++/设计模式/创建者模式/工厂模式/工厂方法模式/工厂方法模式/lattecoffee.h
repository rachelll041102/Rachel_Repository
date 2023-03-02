#pragma once
#include<iostream>
#include"lattecoffeefactory.h"
#include"abstractcoffee.h"
class LatteCoffee :public AbstractCoffee
{
public:
	string getname()
	{
		return "ÄÃÌú¿§·È";
	}
};