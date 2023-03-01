#include<iostream>
using namespace std;

class SingletonHungry
{
private:
	SingletonHungry(){}//私有化构造函数
	static SingletonHungry* sh;//静态指针指向本身
public:
	static SingletonHungry* getClass()//静态接口 让外面获得静态指针
	{
		return sh;
	}
};
SingletonHungry* SingletonHungry::sh = new SingletonHungry();