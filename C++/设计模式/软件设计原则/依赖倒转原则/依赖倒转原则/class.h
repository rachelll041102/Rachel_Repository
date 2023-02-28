#pragma once
#include<iostream>
using namespace std;

class Cpu
{
public:
	virtual void calculate()
	{
		cout << "cpu��ʼ����" << endl;
	}
};
class Memory
{
public:
	virtual void save()
	{
		cout << "�ڴ濪ʼ��ȡ" << endl;
	}
};
class Fan
{
public:
	virtual void run()
	{
		cout << "���ȿ�ʼ����" << endl;
	}
};


class InterlCpu :public Cpu
{
public:
	void calculate()
	{
		cout << "intel��cpu��ʼ����" << endl;
	}
};
class KingshitonMemory :public Memory
{
public:
	void save()
	{
		cout << "��ʿ�ٵ��ڴ�����ʼ��ȡ" << endl;
	}
};
class CheapFan :public Fan
{
public:
	void run()
	{
		cout << "·�߼�ķ�����������" << endl;
	}
};
class SolarPowerFan:public Fan
{
public:
	void run()
	{
		cout << "̫���ܷ��Ⱥ�����ת������" << endl;
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
		cout << "���Կ�������ʼ����" << endl;
		cpu->calculate();
		memory->save();
		fan->run();
	}
};