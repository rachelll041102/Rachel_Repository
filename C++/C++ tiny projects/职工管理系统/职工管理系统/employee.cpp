#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"employee.h"
using namespace std;

void employee::do_what()
{
	cout << "������ɾ�����������";
}

void employee::get_job()
{
	cout << "��ͨԱ��";
}

void employee::show_info()
{
	cout << "Ա�����: "<<number;
	cout <<"      Ա������: "<< name ;
	cout << "     Ա����λ: ";			 this->get_job();
	cout << "     Ա��ְ��: ";			 this->do_what();
	cout << endl;
}

employee::employee(string nums, string temp_n, int temp_j)
{
	number = nums;
	name = temp_n ;
	this->job = temp_j;
}