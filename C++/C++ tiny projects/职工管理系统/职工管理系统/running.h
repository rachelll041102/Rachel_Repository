#pragma once
#include<iostream>
#include"v_worker.h"
#include<fstream>
using namespace std;

//����������ɾ�Ĳ����
class Running
{
public:
	int num;		//����Ա��������
	worker** workerarray;	//����ָ����Ա����Ϣ

	//���캯��
	Running();

	//��������
	~Running();
	//��ʾ�˵�����
	void menu();

	//�˳�Ա��ϵͳ
	void close();

	//����Ա����Ϣ
	void add();

	//��ʾԱ����Ϣ
	void show();

	//�洢�����ļ�����
	void storage(worker* wk);

	//ϵͳ��ʼ�����ļ���ȡ����
	void readFile();

	//����ָ��Ա��
	void find();

	//ɾ��ָ��Ա��
	void del();

	//����Ա����Ϣ
	void modify();

	//���������Ϣ
	void empty();

	//����
	void mySort();
};