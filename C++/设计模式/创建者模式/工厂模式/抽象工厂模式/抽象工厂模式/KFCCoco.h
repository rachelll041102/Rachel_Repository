#pragma once
#include<iostream>
#include"Drink.h"
using namespace std;

class KFCCoco :public Drink
{
public:
	string getname()
	{
		return "KFCCoco";
	}
};