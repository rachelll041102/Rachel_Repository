#include<iostream>
#include"class.h"
using namespace std;
/*
	接口隔离原则：
		客户端不应该被迫依赖于它不使用的方法；
		一个类对另一个类的依赖应该建立在最小的接口上。

	此例子中，三防门有三个属性：防火防水防盗
			  双防门只有两个属性：防火防水(不使用防盗)
*/
int main()
{
	cout << "三防门" << endl;
	three_guard_door* threegd = new three_guard_door();
	threegd->fireproofing();
	threegd->guard_against_theft();
	threegd->waterproofing();

	cout << "============================" << endl;

	cout << "双防门" << endl;
	two_guard_door* twogd = new two_guard_door();
	twogd->fireproofing();
	twogd->waterproofing();

}