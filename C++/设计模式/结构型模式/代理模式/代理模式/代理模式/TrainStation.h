#pragma once 
#include<iostream>
#include"sellTickets.h"
using namespace std;

class TrainStation :public sellTickets
{
public:
	void selltickets()
	{
		cout << "��վ������Ʊ" << endl;
	}
};