/*
	开闭原则：
		对拓展开放，对修改关闭
		如果新加入一个皮肤，可以多写一个拓展
		而不是修改已有代码
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