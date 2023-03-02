#include<iostream>
#include"coffeestore.h"
#include"abstractfactory.h"
#include"americancoffeefactory.h"
#include"lattecoffeefactory.h"
/*
	工厂方法模式：

	点餐直接在咖啡厅点

	咖啡厅把需求发给工厂，工厂进行创建咖啡

	此后如果推出了新的咖啡，只需要再创建一个咖啡工厂类，一个咖啡类，并且各自继承抽象类
	符合开闭原则


*/
using namespace std;
/*
	工厂方法模式
*/
int main()
{
	//创建一个咖啡厅
	CoffeeStore* coffeestore = new CoffeeStore();
	//创建一个美式咖啡工厂
	AbstractFactory* af = new AmericanCoffeeFactory();
	//点餐
	AbstractCoffee* coffee=coffeestore->orderCoffee(af);

	cout << coffee->getname();

	cout <<endl<< "=======================" << endl;

	af = new LatterCoffeeFactory();
	coffee = coffeestore->orderCoffee(af);
	cout << coffee->getname();
}