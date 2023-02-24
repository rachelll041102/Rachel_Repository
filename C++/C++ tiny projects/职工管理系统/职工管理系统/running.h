#pragma once
#include<iostream>
#include"v_worker.h"
#include<fstream>
using namespace std;

//创建管理增删改查的类
class Running
{
public:
	int num;		//计算员工的数量
	worker** workerarray;	//二级指针存放员工信息

	//构造函数
	Running();

	//析构函数
	~Running();
	//显示菜单界面
	void menu();

	//退出员工系统
	void close();

	//增加员工信息
	void add();

	//显示员工信息
	void show();

	//存储进入文件里面
	void storage(worker* wk);

	//系统初始化从文件读取内容
	void readFile();

	//查找指定员工
	void find();

	//删除指定员工
	void del();

	//更改员工信息
	void modify();

	//清空所有信息
	void empty();

	//排序
	void mySort();
};