#pragma once 
#include<iostream>
#include"Beverage.h"

class Coffee:public Beverage
{
public:
	string operation()
	{
		return "coffee";
	}
};