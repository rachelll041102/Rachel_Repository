#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"employee.h"
using namespace std;

void employee::do_what()
{
	cout << "用心完成经理发布的任务";
}

void employee::get_job()
{
	cout << "普通员工";
}

void employee::show_info()
{
	cout << "员工编号: "<<number;
	cout <<"      员工姓名: "<< name ;
	cout << "     员工岗位: ";			 this->get_job();
	cout << "     员工职责: ";			 this->do_what();
	cout << endl;
}

employee::employee(string nums, string temp_n, int temp_j)
{
	number = nums;
	name = temp_n ;
	this->job = temp_j;
}