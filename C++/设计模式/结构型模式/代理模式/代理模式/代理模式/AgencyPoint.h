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
		cout << "代理点收取服务费" << endl;
		trainstation->selltickets();
	}
};