#pragma once
#include<iostream>
using namespace std;
//皮肤的抽象类
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






//皮肤的派生类：默认皮肤
class DefaultSkin:public AbstractSkin
{
public:
	void display()
	{
		cout << "这是默认皮肤" << endl;
	}
};
//皮肤的派生类：黑马皮肤
class HeimaSkin :public AbstractSkin
{
public:
	void display()
	{
		cout << "这是黑马皮肤" << endl;
	}
};