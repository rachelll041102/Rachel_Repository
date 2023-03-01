#include<iostream>
#include"coffeestore.h"
#include"abstractfactory.h"
#include"americancoffeefactory.h"
using namespace std;
/*
	��������ģʽ
*/
int main()
{
	CoffeeStore* coffeestore = new CoffeeStore();

	AbstractFactory* af = new AmericanCoffeeFactory();

	AbstractCoffee* coffee=coffeestore->orderCoffee(af);

	cout << coffee->getname();
}