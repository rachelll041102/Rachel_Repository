#pragma once
#include<iostream>
#include"Food.h"


class MacDonaldHambuger:public Food
{
public:
	string getname()
	{
		return "MacDonaldHambuger";
	}
};