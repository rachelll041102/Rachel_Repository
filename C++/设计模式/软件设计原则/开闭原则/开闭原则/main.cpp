/*
	����ԭ��
		����չ���ţ����޸Ĺر�
		����¼���һ��Ƥ�������Զ�дһ����չ
		�������޸����д���
*/
#include<iostream>
#include"class.h"
using namespace std;

int main()
{
	SougouInput mytest ;
	DefaultSkin skin;
	mytest.setskin(&skin);
	mytest.display();
}