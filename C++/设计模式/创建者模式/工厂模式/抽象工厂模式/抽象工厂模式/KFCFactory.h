#pragma once
#include<iostream>
#include"Factory.h"
#include"Drink.h"
#include"Food.h"
#include"KFCHambuger.h"
#include"KFCCoco.h"
class KFCFactory :public Factory
{
public:
	Food* createFood()
	{
		return new KFCHambuger();
	}
	Drink* createDrink()
	{
		return new KFCCoco();
	}
};