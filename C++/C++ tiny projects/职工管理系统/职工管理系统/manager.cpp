#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"manager.h"
using namespace std;

void manager::do_what()
{
	cout << "处理上级发下的任务，并把任务分配给员工";
}

void manager::get_job()
{
	cout << "经理";
}

void manager::show_info()
{
	cout << "员工编号: " << number;
	cout << "      员工姓名: " << name;
	cout << "     员工岗位: ";			 this->get_job();
	cout << "     员工职责: ";			 this->do_what();
	cout << endl;
}

manager::manager(string nums, string temp_n, int temp_j)
{
	number = nums;
	name = temp_n;
	this->job = temp_j;
}