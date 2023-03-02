#pragma once
#include<iostream>
#include"abstractfactory.h"
#include"abstractcoffee.h"
using namespace std;
//¿§·Èµê
class CoffeeStore
{
private:
	AbstractFactory* af;
public:
	AbstractCoffee* orderCoffee(AbstractFactory* af)
	{
		this->af = af;
		return this->af->createCoffee();
		
	}
};