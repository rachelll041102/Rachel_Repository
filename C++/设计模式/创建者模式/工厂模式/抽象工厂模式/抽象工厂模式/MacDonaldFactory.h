#pragma once
#include<iostream>
#include"Factory.h"
#include"MacDonaldHambuger.h"
#include"MacDonaldCoco.h"
using namespace std;

class MacDonaldFactory:public Factory
{
public:
	Food* createFood()
	{
		return new MacDonaldHambuger();
	}
	Drink* createDrink()
	{
		return new MacDonaldCoco();
	}
};