#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"boss.h"
using namespace std;

void boss::do_what()
{
	cout << "疯狂压榨员工";
}

void boss::get_job()
{
	cout << "老板";
}

void boss::show_info()
{
	cout << "员工编号: " << number;
	cout << "      员工姓名: " << name;
	cout << "     员工岗位: ";			 this->get_job();
	cout << "     员工职责: ";			 this->do_what();
	cout << endl;
}

boss::boss(string nums, string temp_n, int temp_j)
{
	number = nums;
	name = temp_n;
	this->job = temp_j;
}