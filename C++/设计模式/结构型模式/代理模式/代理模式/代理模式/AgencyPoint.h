#pragma once
#include<iostream>
#include"TrainStation.h"
using namespace std;
class AgencyPoint:public sellTickets
{
	TrainStation* trainstation = new TrainStation();
public:
	void selltickets()
	{
		cout << "�������ȡ�����" << endl;
		trainstation->selltickets();
	}
};