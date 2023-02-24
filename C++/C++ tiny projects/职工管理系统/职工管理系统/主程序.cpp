//有很多没有完善，懒得搞了

#include<iostream>
using namespace std;

#include"running.h"		//进行增删改查的头文件

int main()
{
	int select(0);				//用来管理菜单的选项
	Running running;			//调用管理类的指针
	/*这里我原本是写成了 Running* running = NULL;	
	想用指针来的，结果后面全部报错：this 是nullptr
	切记不能用指针*/

	running.readFile();
	while (true)
	{
		running.menu();

		cout << "您需要的服务是" << endl;
		cin >> select;


		switch (select)
		{
		case 0://退出员工系统
			running.close();
			break;

		case 1://增加员工信息  
			running.add();
			break;

		case 2://显示员工信息
			running.show();
			break;

		case 3://删除员工信息
			running.del();
			break;
		case 4://修改员工信息
			running.modify();
			break;

		case 5://查找员工信息
			running.find();
			break;

		case 6://按照编号排序
			running.mySort();
			break;

		case 7://清空所有信息
			running.empty();
			break;

		}
		system("pause");
		system("cls");
	}


}