#include<iostream>
#include"class.h"
using namespace std;
/*
				����ʽ
*/
int main()
{
	SingletonHungry* sh1 = SingletonHungry::getClass();
	SingletonHungry* sh2 = SingletonHungry::getClass();

	if (sh1 == sh2)
	{
		cout << "���Ǹ�����ģʽ" << endl;
	}
	else
	{
		cout << "�ⲻ�ǵ���ģʽ" << endl;
	}
}