#include<iostream>
using namespace std;

class SingletonLazy
{
private:
	SingletonLazy(){}//私有化构造函数
	static SingletonLazy* sl;//指向自身的静态指针
public:
	static SingletonLazy* getClass()//提供获得静态指针的接口
	{
		/*
			此处如果进行多线程编程，不安全
			由于多线程的关系，可能当我们在分配内存好了以后，还没来得急初始化成员变量，
			就进行线程切换，另外一个线程拿到所有权后，由于内存已经分配了，
			但是变量初始化还没进行，因此获取成员变量的相关值会发生不一致现象。
		*/
		if (sl == NULL)		//使用的时候再进行初始化
		{
			sl = new SingletonLazy();
		}
		return sl;
	}
};
SingletonLazy* SingletonLazy::sl =NULL;