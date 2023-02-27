#include<iostream>
#include<string>
using namespace std;
class Gun
{
public:
	virtual void shoot()
	{
		cout << "举起枪开始射击" << endl;
	}
	virtual string getname()
	{
		return "枪";
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
	void getGun(Gun* temp_gun)//拿枪
	{
		this->gun = temp_gun;
		cout << "杀手拿起了"<<gun->getname() << endl;
	}
};

class AK47:public Gun
{
private:
	string name;
public:
	void shoot()
	{
		cout << "举起AK47开始射击" << endl;
	}
	string getname()
	{
		return "步枪AK47";
	}
};
class Grenade :public Gun
{
public:
	void shoot()
	{
		cout << "把手雷扔出去" << endl;
	}
	string getname()
	{
		return "手雷";
	}
};