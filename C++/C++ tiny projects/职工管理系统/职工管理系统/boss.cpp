#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"boss.h"
using namespace std;

void boss::do_what()
{
	cout << "���ѹեԱ��";
}

void boss::get_job()
{
	cout << "�ϰ�";
}

void boss::show_info()
{
	cout << "Ա�����: " << number;
	cout << "      Ա������: " << name;
	cout << "     Ա����λ: ";			 this->get_job();
	cout << "     Ա��ְ��: ";			 this->do_what();
	cout << endl;
}

boss::boss(string nums, string temp_n, int temp_j)
{
	number = nums;
	name = temp_n;
	this->job = temp_j;
}