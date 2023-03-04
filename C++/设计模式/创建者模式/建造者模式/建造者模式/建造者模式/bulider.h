#pragma once 
#include<iostream>
#include"bike.h"

class Bulider
{
protected:
	Bike* bike=new Bike();
public:
	virtual void BuildFrame()=0;
	virtual void BulidSeat() = 0;
	virtual Bike* createBike() = 0;
};