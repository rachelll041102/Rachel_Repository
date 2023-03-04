#pragma once 
#include<iostream>
#include"bike.h"
#include"bulider.h"

class OFOBulider:public Bulider
{
public:
	void BuildFrame()
	{
		bike->setframe("OFO_Frame");
	}
	void BulidSeat()
	{
		bike->setseat("OFO_Seat");
	}
	Bike* createBike()
	{
		return bike;
	}
};