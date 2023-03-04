#pragma once 
#include<iostream>
using namespace std;

class Bike
{
private:
	string m_frame;
	string m_seat;
public:
	void setseat(string seat)
	{
		this->m_seat = seat;

	}
	string getseat()
	{
		return this->m_seat;
	}
	void setframe(string frame)
	{
		this->m_frame = frame;
	}
	string getframe()
	{
		return this->m_frame;
	}
};