#pragma once
#include<iostream>
#include"Food.h"
#include"Drink.h"
using namespace std;

class Factory
{
public:
	virtual Drink* createDrink() = 0;
	virtual Food* createFood() = 0;
};