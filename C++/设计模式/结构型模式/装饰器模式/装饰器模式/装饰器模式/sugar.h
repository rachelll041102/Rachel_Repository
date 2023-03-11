#pragma once
#include<iostream>
#include"Add.h"
using namespace std;
class Sugar :public Add
{
public:
	Sugar(Beverage* beverage) :Add(beverage) {}
	string operation()
	{
		return "Sugar(" + Add::operation() + ")";
	}
};