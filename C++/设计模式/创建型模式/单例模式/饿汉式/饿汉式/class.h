#include<iostream>
using namespace std;

class SingletonHungry
{
private:
	SingletonHungry(){}//˽�л����캯��
	static SingletonHungry* sh;//��ָ̬��ָ����
public:
	static SingletonHungry* getClass()//��̬�ӿ� �������þ�ָ̬��
	{
		return sh;
	}
};
SingletonHungry* SingletonHungry::sh = new SingletonHungry();