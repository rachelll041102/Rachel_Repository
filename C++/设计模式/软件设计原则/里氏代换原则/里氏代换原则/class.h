#include<iostream>
#include<string>
using namespace std;
class Gun
{
public:
	virtual void shoot()
	{
		cout << "����ǹ��ʼ���" << endl;
	}
	virtual string getname()
	{
		return "ǹ";
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
	void getGun(Gun* temp_gun)//��ǹ
	{
		this->gun = temp_gun;
		cout << "ɱ��������"<<gun->getname() << endl;
	}
};

class AK47:public Gun
{
private:
	string name;
public:
	void shoot()
	{
		cout << "����AK47��ʼ���" << endl;
	}
	string getname()
	{
		return "��ǹAK47";
	}
};
class Grenade :public Gun
{
public:
	void shoot()
	{
		cout << "�������ӳ�ȥ" << endl;
	}
	string getname()
	{
		return "����";
	}
};