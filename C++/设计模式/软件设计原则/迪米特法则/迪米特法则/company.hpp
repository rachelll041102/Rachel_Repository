#include<iostream>
using namespace std;

class Company
{
private:
	string name;
public:
	Company(string name)
	{
		this->name = name;
	}
	string getname()
	{
		return this->name;
	}
};