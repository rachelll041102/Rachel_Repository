#include<iostream>
#include"class.h"
using namespace std;
/*
	依赖倒转原则：
		Computer类不能依赖具体的Cpu，Memory，Fan类
		而应该依赖他们的抽象类

		这样可以根据需要更换不同的零件

		（一点个人理解：
			依赖倒转原则和开闭原则是相辅相成的）
*/
int main()
{
	//三个插件
	InterlCpu* interl = new InterlCpu();
	CheapFan* cheapfan = new CheapFan();
	KingshitonMemory* ksd = new KingshitonMemory();

	//实例化电脑
	Computer* c = new Computer();
	c->setCpu(interl)  ;
	c->setFan(cheapfan);
	c->setMemory(ksd);

	c->work();

	cout << "=================偶然在路边捡到太阳能风扇===============" << endl;
	SolarPowerFan* spfan = new SolarPowerFan();
	c->setFan(spfan);
	c->work();
}