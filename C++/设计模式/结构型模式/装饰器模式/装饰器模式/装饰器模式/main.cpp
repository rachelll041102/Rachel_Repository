#include<iostream>
#include"Beverage.h"
#include"Coffee.h"
#include"Milk.h"
#include"sugar.h"
using namespace std;
void Cilent(Beverage* beverage)
{
	cout << "The result is:" + beverage->operation() << endl;
}
int main()
{
	cout << "get a coffee:";
	Beverage* coffee = new Coffee();
	Cilent(coffee);

	cout << "add some milk:";
	Beverage* milk = new Milk(coffee);
	Cilent(milk);

	cout << "add some sugar:";
	Beverage* sugar = new Sugar(milk);
	Cilent(sugar);
}