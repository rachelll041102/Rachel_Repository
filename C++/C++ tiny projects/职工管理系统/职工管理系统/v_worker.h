#pragma once
#include<iostream>
using namespace std;

class worker
{
public:
	string number;
	string name;
	int job;
	
	virtual void do_what()=0;	//��ʾԱ��ְ��
	virtual void get_job()=0;	//��ʾԱ����λ		jobΪint�ͣ��ô˺���ת����string��
	virtual void show_info() = 0;	//��ӡԱ����Ϣ
};