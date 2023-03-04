#pragma once 
#include<iostream>
#include"bulider.h"
using namespace std;

class Command
{
private:
	Bulider* builder;
public:
	Command(Bulider* builder)
	{
		this->builder = builder;
	}
	Bike* package()
	{
		builder->BuildFrame();
		builder->BulidSeat();
		return builder->createBike();
	}
	void setBuilder(Bulider* builder)
	{
		this->builder = builder;
	}

};