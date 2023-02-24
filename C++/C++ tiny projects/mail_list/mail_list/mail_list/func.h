#pragma once

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct mail_list
{
    string name;
    string sex;
    int age;
    long long  number;
    string address;
};

void first_open(struct mail_list book[], int* length)
{
    ifstream temp;
    temp.open("mail_list.txt", ios::in);
    for (int i = 0; i < 1000; ++i)
    {
        temp >> book[*length].name >> book[*length].sex >> book[*length].age
            >> book[*length].number >> book[*length].address;
        (*length)++;
        if (temp.eof())break;
    }
    //���еĴ����
    /*while (!temp==EOF)
    {
        temp >> book[*length].name >> book[*length].sex >> book[*length].age
            >> book[*length].number >> book[*length].address;
        (*length)++;
    }*/
}
void menu(int* run)
{
    //�������Ա����䣬��ϵ�绰����ͥסַ
    cout << "�����ϵ��:1" << endl;
    cout << "��ʾ��ϵ��:2" << endl;
    cout << "ɾ����ϵ��:3" << endl;
    cout << "������ϵ��:4" << endl;
    cout << "�޸���ϵ��:5" << endl;
    cout << "�����ϵ��:6" << endl;
    cout << "�˳�ͨѶ¼:0" << endl;
    cout << "��������Ĺ���:";
    cin >> *run;
}
//�����ϵ��
void add(struct mail_list* book,int* length)
{
    cout << "������";
    cin >> book[*length].name;
    cout << "�Ա�";
    cin >> book[*length].sex;
    cout << "���䣺";
    cin >> book[*length].age;
    cout << "�绰���룺";
    cin >> book[*length].number;
    cout << "��ַ��";
    cin >> book[*length].address;
    

    ofstream temp;
    temp.open("mail_list.txt", ios::app);
    temp << book[*length].name << endl;
    temp <<book[*length].sex << endl;
    temp << book[*length].age << endl;
    temp << book[*length].number << endl;
    temp << book[*length].address <<endl;
    temp.close();
    (* length)++;
}
//��ʾ��ϵ��
void read(struct mail_list* book,int* length)
{
    for (int i = 0; i < *length; i++)
    {
        cout << " ������ " << book[i].name
            << " �Ա� " << book[i].sex
            << " ���䣺 " << book[i].age
            << " �绰���룺 " << book[i].number
            << " סַ�� " << book[i].address
            << endl<<endl;
        
    }
    system("pause");
}
//ɾ����ϵ��
void del(struct mail_list* book,int* length)
{
    string temp;
    cout << "�������Ҫɾ��������" << endl;
    cin >> temp;
    for (int i = 0; i < *length; i++)
    {
        if (book[i].name == temp)
        {
            for (int j = i; j < *length; j++)
            {
                book[j].name = book[j + 1].name;
                book[j].sex = book[j + 1].sex;
                book[j].number = book[j + 1].number;
                book[j].age = book[j + 1].age;
                book[j].address = book[j + 1].address;
                
            }
            (* length)--;
            i--;
        }
    }
    ofstream other_temp;
    other_temp.open("mail_list.txt", ios::out);
    for (int i = 0; i < (*length); i++)
    {
        other_temp << book[i].name <<endl
            << book[i].sex << endl
            << book[i].age << endl
            << book[i].number << endl
            << book[i].address << endl;
    }
    other_temp.close();
    cout << "ɾ���ɹ�" << endl;
    system("pause");
}

void find(struct mail_list* book,int* length)
{
    string temp;
    cout << "��������ҪѰ�ҵ���ϵ�ˣ�";
    cin >> temp;

    for (int i = 0; i < *length; i++)
    {
        if (temp == book[i].name||temp+'\n'==book[i].name)
        {
            cout << " ������ " << book[i].name
                << " �Ա� " << book[i].sex
                << " ���䣺 " << book[i].age
                << " �绰���룺 " << book[i].number
                << " סַ�� " << book[i].address
                << endl << endl;
        }

    }
    cout << "�������" << endl;
    system("pause");

}

void re_add(struct mail_list* book, int* length)
{
    cout << "��������Ҫ�޸ĵ���ϵ�˵�����" << endl;
    string temp;
    cin >> temp;
    for (int i = 0; i < (*length); i++)
    {
        if (temp == book[i].name)
        {
            cout << " ������ " << book[i].name
                << " �Ա� " << book[i].sex
                << " ���䣺 " << book[i].age
                << " �绰���룺 " << book[i].number
                << " סַ�� " << book[i].address
                << endl << endl;
            cout << "������Ҫ�޸ĵ���Ϣ" << endl;
            cout << "����:";                cin >> book[i].age;
            cout << endl << "�绰����:";    cin >> book[i].number;
            cout << endl << "��ַ";         cin >> book[i].address;
        }
        else
        {
            cout << "���������Ϣ����" << endl;
            system("pause");
        }
    }

    ofstream other_temp;
    other_temp.open("mail_list.txt", ios::out);
    for (int i = 0; i < (*length); i++)
    {
        other_temp << book[i].name << endl
            << book[i].sex << endl
            << book[i].age << endl
            << book[i].number << endl
            << book[i].address << endl;
    }
    other_temp.close();
}

void del_all(struct mail_list* book, int* length)
{
    //memset(ָ��,�������,����С)
    memset(book, 0, sizeof(book));
    *length = 0;

    //����ļ�������
    ofstream temp;
    temp.open("mail_list.txt", ios::out);
    temp.close();
    cout << "������" << endl;
    system("pause");
}

void get_out()
{
    cout << "��л���ʹ��" << endl;
    system("pause");
    exit(0);
}
