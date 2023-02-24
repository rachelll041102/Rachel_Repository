#pragma once
#include<iostream>
#include"v_worker.h"		//包含抽象类的头文件


class employee :public worker
{
public:
	employee(string nums,string temp_n,int temp_j);
	void get_job();
	void do_what();
	void show_info();
};