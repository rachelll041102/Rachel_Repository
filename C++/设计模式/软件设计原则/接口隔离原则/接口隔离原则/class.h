#include<iostream>
using namespace std;
/*
	������������ӿ���
*/
class FireProofing//����ӿ�
{
public:
	virtual void fireproofing() = 0;
};
class WaterProofing//��ˮ�ӿ�
{
public:
	virtual void waterproofing() = 0;
};
class Guard_Against_Theft//�����ӿ�
{
public:
	virtual void guard_against_theft() = 0;
};

/*
	������������
*/
class three_guard_door :public FireProofing, WaterProofing, Guard_Against_Theft
{
public:
	void fireproofing()
	{
		cout << "������" << endl;
	}
	void waterproofing()
	{
		cout << "��ˮ����" << endl;
	}
	void guard_against_theft()
	{
		cout << "��������" << endl;
	}
};

/*
	����˫������
*/
class two_guard_door :public FireProofing, WaterProofing
{
public:
	void fireproofing()
	{
		cout << "������" << endl;
	}
	void waterproofing()
	{
		cout << "��ˮ����" << endl;
	}
};