#pragma once
#include<iostream>
#include"abstractcoffee.h"
using namespace std;
//���󹤳���
class AbstractFactory
{
public:
	virtual AbstractCoffee* createCoffee() = 0;
};