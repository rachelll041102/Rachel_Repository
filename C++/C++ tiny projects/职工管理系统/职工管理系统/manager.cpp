#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"manager.h"
using namespace std;

void manager::do_what()
{
	cout << "�����ϼ����µ����񣬲�����������Ա��";
}

void manager::get_job()
{
	cout << "����";
}

void manager::show_info()
{
	cout << "Ա�����: " << number;
	cout << "      Ա������: " << name;
	cout << "     Ա����λ: ";			 this->get_job();
	cout << "     Ա��ְ��: ";			 this->do_what();
	cout << endl;
}

manager::manager(string nums, string temp_n, int temp_j)
{
	number = nums;
	name = temp_n;
	this->job = temp_j;
}