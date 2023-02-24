#pragma once
#include<iostream>
using namespace std;

class worker
{
public:
	string number;
	string name;
	int job;
	
	virtual void do_what()=0;	//显示员工职责
	virtual void get_job()=0;	//显示员工岗位		job为int型，用此函数转换成string型
	virtual void show_info() = 0;	//打印员工信息
};