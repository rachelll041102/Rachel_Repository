#pragma once
#include<iostream>
#include"abstractcoffee.h"
using namespace std;
//美式咖啡类
class AmericanCoffee:public AbstractCoffee
{
public:
	string getname()
	{
		return "美式咖啡";
	}
};