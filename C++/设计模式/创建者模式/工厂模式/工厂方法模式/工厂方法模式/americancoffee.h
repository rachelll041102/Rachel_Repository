#pragma once
#include<iostream>
#include"abstractcoffee.h"
using namespace std;
//��ʽ������
class AmericanCoffee:public AbstractCoffee
{
public:
	string getname()
	{
		return "��ʽ����";
	}
};