#include<iostream>
#include<string>
using namespace std;
class Gun
{
public:
	void shoot()
	{
		cout << "使用武器开始杀人" << endl;
	}
};
class Killer
{
private:
	Gun* gun;
public:
	void kill()
	{
		gun->shoot();
	}
	void setGun(Gun* temp_gun)
	{
		this->gun = temp_gun;
		cout << "杀手拿起了武器"<< endl;
	}
};

class AK47:public Gun
{
public:
	void tutututu()
	{
		cout<<"AK47狠狠的扫"<<endl;
	}
};
class Grenade :public Gun
{
public:
	void boom()
	{
		cout << "手雷炸了" << endl;
	}
};