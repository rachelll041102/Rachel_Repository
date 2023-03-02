#include<iostream>
#include"coffeestore.h"
#include"abstractfactory.h"
#include"americancoffeefactory.h"
#include"lattecoffeefactory.h"
/*
	��������ģʽ��

	���ֱ���ڿ�������

	�����������󷢸��������������д�������

	�˺�����Ƴ����µĿ��ȣ�ֻ��Ҫ�ٴ���һ�����ȹ����࣬һ�������࣬���Ҹ��Լ̳г�����
	���Ͽ���ԭ��


*/
using namespace std;
/*
	��������ģʽ
*/
int main()
{
	//����һ��������
	CoffeeStore* coffeestore = new CoffeeStore();
	//����һ����ʽ���ȹ���
	AbstractFactory* af = new AmericanCoffeeFactory();
	//���
	AbstractCoffee* coffee=coffeestore->orderCoffee(af);

	cout << coffee->getname();

	cout <<endl<< "=======================" << endl;

	af = new LatterCoffeeFactory();
	coffee = coffeestore->orderCoffee(af);
	cout << coffee->getname();
}