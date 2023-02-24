#include<iostream>
#include<string>
#include"func.h"

using namespace std;



struct mail_list book[1000];

int main()

{
    system("title mail_list(ͨѶ¼");//不清楚为什么会变成这样
                                    //可能是文件存储的原因，原内容是"(通讯录"
    int length=0;
    int run;
    first_open(book,&length);
    length--;
    while (1)
    {

        system("cls");
        menu(&run);

        switch (run)
        {
        case 1:add(book,&length); break;
        case 2:read(book,&length); break;
        case 3:del(book, &length); break;
        case 4:find(book,&length); break;
        case 5:re_add(book, &length); break;
        case 6:del_all(book, &length); break;
        case 0:get_out(); break;
        }
    }
}