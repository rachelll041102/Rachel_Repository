#pragma once
#include<iostream>
using namespace std;

class Cpu
{
public:
	virtual void calculate()
	{
		cout << "cpu开始计算" << endl;
	}
};
class Memory
{
public:
	virtual void save()
	{
		cout << "内存开始读取" << endl;
	}
};
class Fan
{
public:
	virtual void run()
	{
		cout << "风扇开始运行" << endl;
	}
};


class InterlCpu :public Cpu
{
public:
	void calculate()
	{
		cout << "intel的cpu开始运行" << endl;
	}
};
class KingshitonMemory :public Memory
{
public:
	void save()
	{
		cout << "金士顿的内存条开始读取" << endl;
	}
};
class CheapFan :public Fan
{
public:
	void run()
	{
		cout << "路边捡的风扇拿来运行" << endl;
	}
};
class SolarPowerFan:public Fan
{
public:
	void run()
	{
		cout << "太阳能风扇呼呼的转了起来" << endl;
	}
};


class Computer
{
private:
	Cpu* cpu;
	Memory* memory;
	Fan* fan;
public:
	void setCpu(Cpu* cpu)
	{
		this->cpu = cpu;
	}
	void setMemory(Memory* memory)
	{
		this->memory = memory;
	}
	void setFan(Fan* fan)
	{
		this->fan = fan;
	}
	void work()
	{
		cout << "电脑开机，开始运行" << endl;
		cpu->calculate();
		memory->save();
		fan->run();
	}
};