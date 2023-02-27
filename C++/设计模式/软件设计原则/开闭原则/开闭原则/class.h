#pragma once
#include<iostream>
using namespace std;
//Ƥ���ĳ�����
class AbstractSkin
{
public:
	virtual void display() =0;
};

class SougouInput
{
private:
	AbstractSkin* skin;
public:
	void setskin(AbstractSkin* skin)
	{
		this->skin = skin;
	}
	void display()
	{
		this->skin->display();
	}
};






//Ƥ���������ࣺĬ��Ƥ��
class DefaultSkin:public AbstractSkin
{
public:
	void display()
	{
		cout << "����Ĭ��Ƥ��" << endl;
	}
};
//Ƥ���������ࣺ����Ƥ��
class HeimaSkin :public AbstractSkin
{
public:
	void display()
	{
		cout << "���Ǻ���Ƥ��" << endl;
	}
};