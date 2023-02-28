#include<iostream>
using namespace std;

class Star
{
private:
	string name;
public:
	Star(string name)
	{
		this->name = name;
	}
	string getname()
	{
		return this->name;
	}
};