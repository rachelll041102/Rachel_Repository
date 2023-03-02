#pragma once
#include<iostream>
#include"Food.h"
using namespace std;

class KFCHambuger :public Food
{
public:
	string getname()
	{
		return "KFCHambuger";
	}
};
