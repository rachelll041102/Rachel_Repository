#include<iostream>
using namespace std;
//���󹤳���
class AbstractFactory
{
public:
	virtual AbstractCoffee* createCoffee() = 0;
};