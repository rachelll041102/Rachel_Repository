#pragma once 
#include<iostream>
#include"bike.h"
#include"bulider.h"

class MoBikeBuilder:public Bulider
{
public:
	void BuildFrame()
	{
		bike->setframe("MoBike_frame");
	}
	void BulidSeat()
	{
		bike->setseat("MoBike_seat");
	}
	Bike* createBike()
	{
		return this->bike;
	}
};