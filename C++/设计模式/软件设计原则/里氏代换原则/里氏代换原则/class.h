#include<iostream>
#include<string>
using namespace std;
class Gun
{
public:
	void shoot()
	{
		cout << "ʹ��������ʼɱ��" << endl;
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
		cout << "ɱ������������"<< endl;
	}
};

class AK47:public Gun
{
public:
	void tutututu()
	{
		cout<<"AK47�ݺݵ�ɨ"<<endl;
	}
};
class Grenade :public Gun
{
public:
	void boom()
	{
		cout << "����ը��" << endl;
	}
};