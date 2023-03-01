#include<iostream>
using namespace std;
//抽象工厂类
class AbstractFactory
{
public:
	virtual AbstractCoffee* createCoffee() = 0;
};