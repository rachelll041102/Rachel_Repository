#include<iostream>
#include"company.hpp"
#include"fans.hpp"
#include"star.hpp"
using namespace std;
/*
	�����ط���:
		����������ʵ������ֱ��ͨ�ţ���ô�Ͳ�Ӧ������ֱ�ӵ��໥���ã�
		����ͨ��������ת���õ��á�

	���Ǹ������ˣ����ǣ���˿�͹�˾֮���ϵ������

	�����������˿����˾������ʶ��	����ֻ�����ľ�������ʶ
		�������˿�ļ��棬��Ҫͨ�������˵��м���
		�����빫˾�ĺ�������Ҫͨ�������˵��м���


*/
class Agent
{
private:
	Star* star;
	Fans* fans;
	Company* company;
public:
	void setstar(Star* star)
	{
		this->star = star;
	}
	void setcompany(Company* company)
	{
		this->company = company;
	}
	void setfans(Fans* fans)
	{
		this->fans = fans;
	}
	void meeting()
	{
		cout << "������������  " << star->getname() 
			 << "  ����˿  " << fans->getname() << "  ����" << endl;
	}
	void business()
	{
		cout << "������������  " << star->getname()
			<< "  ����˾  " << company->getname() << "  �����������" << endl;
	}
};