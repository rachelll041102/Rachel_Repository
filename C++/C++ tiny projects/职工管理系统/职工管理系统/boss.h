#pragma once
#include<iostream>
#include"v_worker.h"		//包含抽象类的头文件


class boss :public worker
{
public:
	boss(string nums, string temp_n, int temp_j);
	void get_job();
	void do_what();
	void show_info();
};