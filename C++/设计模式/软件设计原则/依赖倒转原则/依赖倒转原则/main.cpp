#include<iostream>
#include"class.h"
using namespace std;
/*
	������תԭ��
		Computer�಻�����������Cpu��Memory��Fan��
		��Ӧ���������ǵĳ�����

		�������Ը�����Ҫ������ͬ�����

		��һ�������⣺
			������תԭ��Ϳ���ԭ�����ศ��ɵģ�
*/
int main()
{
	//�������
	InterlCpu* interl = new InterlCpu();
	CheapFan* cheapfan = new CheapFan();
	KingshitonMemory* ksd = new KingshitonMemory();

	//ʵ��������
	Computer* c = new Computer();
	c->setCpu(interl)  ;
	c->setFan(cheapfan);
	c->setMemory(ksd);

	c->work();

	cout << "=================żȻ��·�߼�̫���ܷ���===============" << endl;
	SolarPowerFan* spfan = new SolarPowerFan();
	c->setFan(spfan);
	c->work();
}