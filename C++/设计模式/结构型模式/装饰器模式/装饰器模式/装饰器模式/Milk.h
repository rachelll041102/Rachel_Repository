#pragma once
#include<iostream>
#include"Add.h"
using namespace std;
class Milk:public Add
{
public:
	Milk(Beverage* beverage) :Add(beverage) {}
	//���д��뺬�壺
	//Beverage* beverage�Ǹ�������ԣ�
	//����Add��beverage���ǰ�Milk(Beverage* beverage)�еĴ�������beverage���ݽ������вι���
	string operation()
	{
		return "Milk(" + Add::operation() + ")";
	}
};