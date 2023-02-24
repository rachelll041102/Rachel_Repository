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
    //不行的代码↓
    /*while (!temp==EOF)
    {
        temp >> book[*length].name >> book[*length].sex >> book[*length].age
            >> book[*length].number >> book[*length].address;
        (*length)++;
    }*/
}
void menu(int* run)
{
    //姓名，性别，年龄，联系电话，家庭住址
    cout << "添加联系人:1" << endl;
    cout << "显示联系人:2" << endl;
    cout << "删除联系人:3" << endl;
    cout << "查找联系人:4" << endl;
    cout << "修改联系人:5" << endl;
    cout << "清空联系人:6" << endl;
    cout << "退出通讯录:0" << endl;
    cout << "请输入你的功能:";
    cin >> *run;
}
//添加联系人
void add(struct mail_list* book,int* length)
{
    cout << "姓名：";
    cin >> book[*length].name;
    cout << "性别：";
    cin >> book[*length].sex;
    cout << "年龄：";
    cin >> book[*length].age;
    cout << "电话号码：";
    cin >> book[*length].number;
    cout << "地址：";
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
//显示联系人
void read(struct mail_list* book,int* length)
{
    for (int i = 0; i < *length; i++)
    {
        cout << " 姓名： " << book[i].name
            << " 性别： " << book[i].sex
            << " 年龄： " << book[i].age
            << " 电话号码： " << book[i].number
            << " 住址： " << book[i].address
            << endl<<endl;
        
    }
    system("pause");
}
//删除联系人
void del(struct mail_list* book,int* length)
{
    string temp;
    cout << "请输出你要删除的姓名" << endl;
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
    cout << "删除成功" << endl;
    system("pause");
}

void find(struct mail_list* book,int* length)
{
    string temp;
    cout << "请输入你要寻找的联系人：";
    cin >> temp;

    for (int i = 0; i < *length; i++)
    {
        if (temp == book[i].name||temp+'\n'==book[i].name)
        {
            cout << " 姓名： " << book[i].name
                << " 性别： " << book[i].sex
                << " 年龄： " << book[i].age
                << " 电话号码： " << book[i].number
                << " 住址： " << book[i].address
                << endl << endl;
        }

    }
    cout << "查找完毕" << endl;
    system("pause");

}

void re_add(struct mail_list* book, int* length)
{
    cout << "请输入你要修改的联系人的姓名" << endl;
    string temp;
    cin >> temp;
    for (int i = 0; i < (*length); i++)
    {
        if (temp == book[i].name)
        {
            cout << " 姓名： " << book[i].name
                << " 性别： " << book[i].sex
                << " 年龄： " << book[i].age
                << " 电话号码： " << book[i].number
                << " 住址： " << book[i].address
                << endl << endl;
            cout << "请输入要修改的信息" << endl;
            cout << "年龄:";                cin >> book[i].age;
            cout << endl << "电话号码:";    cin >> book[i].number;
            cout << endl << "地址";         cin >> book[i].address;
        }
        else
        {
            cout << "你输入的信息有误" << endl;
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
    //memset(指针,填充内容,填充大小)
    memset(book, 0, sizeof(book));
    *length = 0;

    //清除文件内内容
    ofstream temp;
    temp.open("mail_list.txt", ios::out);
    temp.close();
    cout << "清除完毕" << endl;
    system("pause");
}

void get_out()
{
    cout << "感谢你的使用" << endl;
    system("pause");
    exit(0);
}
