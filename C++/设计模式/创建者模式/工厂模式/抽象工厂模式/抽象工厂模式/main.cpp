#include<iostream>
#include"Factory.h"
#include"Food.h"
#include"Drink.h"
#include"MacDonaldFactory.h"
#include"KFCFactory.h"
using namespace std;

int main()
{
	//���Ҳ���
	Factory* macdonald = new MacDonaldFactory();
	Factory* kfc = new KFCFactory();

	//�����͵��
	cout << "ȥ���ͳԷ�" << endl;
	Food* food=macdonald->createFood();
	Drink* drink = macdonald->createDrink();

	cout << "��ʳ��:" << food->getname()<<endl;
	cout << "������:" << drink->getname() << endl;

	cout << "===================" << endl;
	cout << "���ͺ��ѳԣ�������������" << endl;
	//�������͵�ʳ����ָ�룩
	delete food;
	delete drink;

	//��KFC���
	food = new KFCHambuger();
	drink = new KFCCoco();

	cout << "��ʳ��:" << food->getname() << endl;
	cout << "������:" << drink->getname() << endl;

}