#include<iostream>
#include"class.h"
using namespace std;
/*
	里氏替换原则：
		有个杀手，杀手有个行为是拿枪，有个行为是杀人

		不同的武器诸如AK47，手雷都是枪的子类，杀手都可以拿起来使用
		并且子类（不同的武器）可以完全替换父类（枪类）
		且不同的子类拥有不同的特点
*/
int main()
{
	Killer killer;//创建一个杀手类
	AK47 ak;//创建一个枪类
	Grenade grenade;
	Gun gun;

	killer.getGun(&ak);//杀手拿枪
	killer.kill();//杀手杀人
	cout << "===========================" << endl;
	killer.getGun(&grenade);
	killer.kill();
	cout << "===========================" << endl;
	killer.getGun(&gun);
	killer.kill();
}
/*
 
运行结果：
 
	杀手拿起了步枪AK47
	举起AK47开始射击
	===========================
	杀手拿起了手雷
	把手雷扔出去
	===========================
	杀手拿起了枪
	举起枪开始射击

*/