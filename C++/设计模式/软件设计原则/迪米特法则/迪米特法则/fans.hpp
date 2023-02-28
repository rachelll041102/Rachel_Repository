#include<iostream>
using namespace std;

class Fans
{
private:
	string name;
public:
	Fans(string name)
	{
		this->name = name;
	}
	string getname()
	{
		return this->name;
	}
};