#include<iostream>
#include"class.h"
using namespace std;
/*
	里氏替换原则：
		有个杀手，杀手有个行为是拿武器，有个行为是杀人

		不同的武器诸如AK47，手雷都是武器的子类，杀手都可以拿起来使用
		并且子类（不同的武器）可以完全替换父类（武器类）
		且不同的子类拥有不同的特点


		子类**不能**重写父类的行为，但是可以拥有自己的特点（自己的行为）
*/
int main()
{
	Killer killer;//创建一个杀手类
	AK47 ak;//创建一个武器类
	Grenade grenade;
	Gun gun;

	killer.setGun(&ak);//杀手拿武器
	killer.kill();//杀手杀人
	ak.tutututu();
	cout << "===========================" << endl;
	killer.setGun(&grenade);
	killer.kill();
	grenade.boom();
	cout << "===========================" << endl;
	killer.setGun(&gun);
	killer.kill();
}
/*
 
运行结果：
 
	杀手拿起了武器
	使用武器开始杀人
	AK47狠狠的扫
	===========================
	杀手拿起了武器
	使用武器开始杀人
	手雷炸了
	===========================
	杀手拿起了武器
	使用武器开始杀人

其中：
	《杀手拿起了武器》
	《使用武器开始杀人》
		这两个都是父类的函数，子类没有重写，直接进行调用
	其他的都是子类自己的特点


*/