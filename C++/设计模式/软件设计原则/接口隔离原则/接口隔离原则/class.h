#include<iostream>
using namespace std;
/*
	这是三个抽象接口类
*/
class FireProofing//防火接口
{
public:
	virtual void fireproofing() = 0;
};
class WaterProofing//防水接口
{
public:
	virtual void waterproofing() = 0;
};
class Guard_Against_Theft//防盗接口
{
public:
	virtual void guard_against_theft() = 0;
};

/*
	这是三防门类
*/
class three_guard_door :public FireProofing, WaterProofing, Guard_Against_Theft
{
public:
	void fireproofing()
	{
		cout << "防火功能" << endl;
	}
	void waterproofing()
	{
		cout << "防水功能" << endl;
	}
	void guard_against_theft()
	{
		cout << "防盗功能" << endl;
	}
};

/*
	这是双防门类
*/
class two_guard_door :public FireProofing, WaterProofing
{
public:
	void fireproofing()
	{
		cout << "防火功能" << endl;
	}
	void waterproofing()
	{
		cout << "防水功能" << endl;
	}
};