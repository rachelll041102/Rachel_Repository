#include<iostream>
#include"class.h"
using namespace std;
/*
			����ʽ
	ע����ȱ���
		���ܱ�֤���̵߳İ�ȫ��
*/
int main()
{
	SingletonLazy* test1 = SingletonLazy::getClass();
	SingletonLazy* test2 = SingletonLazy::getClass();
	if (test1 == test2)
	{
		cout << "���Ǹ�����ģʽ" << endl;
	}
	else
		cout << "�ⲻ�ǵ���ģʽ" << endl;
}