#include<iostream>
#include"running.h"		//进行增删改查的头文件
using namespace std;
#include"employee.h"
#include"manager.h"
#include"boss.h"

//显示菜单界面
void Running::menu()
{
	cout << "*****************************************" << endl;
	cout << "*****     欢迎使用员工管理系统      *****" << endl;
	cout << "*****                               *****" << endl;
	cout << "*****     1、增加员工信息           *****" << endl;
	cout << "*****     2、显示员工信息           *****" << endl;
	cout << "*****     3、删除员工信息           *****" << endl;
	cout << "*****     4、修改员工信息           *****" << endl;
	cout << "*****     5、查找员工信息           *****" << endl;
	cout << "*****     6、按照编号排序           *****" << endl;
	cout << "*****     7、清空所有信息           *****" << endl;
	cout << "*****     0、退出管理系统           *****" << endl;
	cout << "*****                               *****" << endl;
	cout << "*****************************************" << endl;
}






//退出员工系统
void Running::close()
{
	cout << "感谢你的使用!!!!" << endl;
	system("pause");
	exit(0);
}








//增加员工信息
void Running::add()
{
	int newsize = num + 1;
	worker** newspace = new worker * [newsize];

	//把 原堆区的数据 拷贝到 新堆区
	if (this->workerarray!=NULL)
	{
		for (int i = 0; i < num; i++)
		{
			newspace[i] = workerarray[i];
		}
	}
	string temp_name, temp_num;
	int temp_job;

	while (true)
	{
		cout << "请输入员工的编号：";
		cin >> temp_num;
		cout << "请输入员工的姓名：";
		cin >> temp_name;
		cout << "请输入员工的工作：" << endl
			<< "1、普通员工" << endl << "2、经理" << endl << "3、老板"<<endl;
		cin >> temp_job;

		num++;
		if (temp_job == 1)
		{
			newspace[num-1]=new employee(temp_num, temp_name, temp_job);
			storage(newspace[num - 1]);
			cout << endl<<"输入成功"<<endl;
			break;
		}
		else if (temp_job == 2)
		{
			newspace[num - 1] = new manager(temp_num, temp_name, temp_job);
			storage(newspace[num - 1]);
			cout << endl << "输入成功" << endl;
			break;
		}
		else if (temp_job == 3)
		{
			newspace[num - 1] = new boss(temp_num, temp_name, temp_job);
			storage(newspace[num - 1]);
			cout << endl << "输入成功" << endl;
			break;
		}
		else
		{
			cout << "你输入的值有误";
		}
		
	}
	delete[] this->workerarray;
	workerarray = newspace;
}







Running::Running()
{
	num = 0;
	workerarray = NULL;
}








//显示员工信息
void Running::show()
{
	if (num != 0)
	{
		for (int i = 0; i < num; i++)
		{
			workerarray[i]->show_info();
			
		}
	}
	else cout << "没有信息";
	return;
}






Running::~Running()
{
	delete[] workerarray;
	workerarray = NULL;
}





void Running::storage(worker* wk)
{
	ofstream ofs;
	ofs.open("file.txt", ios::app);

	/*关于为什么最前面是endl？
		原本我把endl放到了末尾，但是endl会在文件下再转一行，
		此时n份数据，会读取成n+1份数据，所以为了避免系统混淆
		我把它放到了开头
		至于为什么输入流读取不会被最开始的endl影响，我不懂*/

	ofs << endl << wk->number << ' '  << wk->name << ' ' << wk->job ;
	ofs.close();

}




//用来读取文件里面的内容
void Running::readFile()
{
	/*这里是因为空文件里面，输入流需要读取一次，才能判定是否到了文件最末尾
		如果到文件最末尾，说明是空文件，直接返回就好了*/
	char null;
	ifstream ifs;
	ifs.open("file.txt", ios::in);
	ifs >> null;
	if (ifs.eof())return;


	//ios::in   不会创建一个文件，所以这里需要判定
	if (!ifs.is_open())
	{
		cout << "初次使用，没有内容" << endl;
		return;
	}

	//如果上面没有返回，说明文件里面有内容，但是输入流的文件指针已经读取了一次，
	//需要回到最开头。
	//这里调用了seekg()函数
	//seekg(第几个位置,从哪里开始算)	beg是begin，最开头的地方
	ifs.seekg(0, ios::beg);
	while (1)
	{
		if (ifs.eof())break;//如果读到末尾，就返回

		worker** newspace = new worker * [num + 1];
		if (workerarray != NULL)
		{
			for (int i = 0; i < num; i++)
			{
				newspace[i] = workerarray[i];
			}
		}
		
		string temp_name, temp_number;
		int temp_job;

		ifs >> temp_number >> temp_name >> temp_job;
		++num;
		if (temp_job == 1)
		{
			newspace[num-1] = new employee(temp_number, temp_name, temp_job);
		}
		else if (temp_job == 2)
		{
			newspace[num - 1] = new manager(temp_number, temp_name, temp_job);
		}
		else if (temp_job == 3)
		{
			newspace[num - 1] = new boss(temp_number, temp_name, temp_job);
		}
		/*这样直接赋值的情况下，newspace[num - 1]会指向0xcdcdcdcdcdcdcdcd;
		此时newspace[num - 1]是没有初始化的
		ifs >> newspace[num - 1]->number;
		ifs >> newspace[num - 1]->name;
		ifs >> newspace[num - 1]->job;*/

		if(workerarray!=NULL)delete[] workerarray;
		workerarray = newspace;

	}
	ifs.close();


}




//查找指定员工
void Running::find()
{
	cout << "请问是按编号查找还是姓名查找" << endl;
	cout << "1、编号查找" << endl;
	cout << "2、姓名查找" << endl;

	string which;	//这是输入查找内容的
	int how;		//这是选择菜单的
					//tmd一开始自己写的代码还搞混了
		
	while (true)
	{
		cin >> how;

		if (how == 1)
		{
			cout << "请输入查找的编号:";
			cin >> which;
			for (int i = 0; i < num; i++)
			{
				if (workerarray[i]->number ==which)
				{
					workerarray[i]->show_info();
				}
			}
			break;
		}
		else if (how == 2)
		{
			cout << "请输入查找的姓名";
			cin >> which;
			for (int i = 0; i < num; i++)
			{
				if (workerarray[i]->name == which)
				{
					workerarray[i]->show_info();
				}
			}
			break;
		}
		else cout << "请重新输入" << endl;

		
	}
	

}





//删除指定员工
void Running::del()
{
	cout << "按编号删除还是姓名删除:" << endl;
	cout << "1、编号" << endl;
	cout << "2、姓名" << endl;
	int how;
	string which;
	int sure;

	while (true)
	{
		cin >> how;
		if (how == 1)
		{
			cout << "按编号查找：" << endl;
			cout << "请输入编号" << endl;
			cin >> which;
			for (int i = 0; i < num; ++i)
			{
				if (workerarray[i]->number == which)
				{
					workerarray[i]->show_info();
					cout << "是否删除(1、是   2、否)" << endl;
					cin >>sure;
					if (sure == 1)
					{
						delete workerarray[i];
						for (int j = i; j < num-1; j++)
						{
							workerarray[j] = workerarray[j + 1];
						}
						workerarray[num - 1]=NULL;
						num--;
					}
				}
				
			}
			break;
		}
		else if (how == 2)
		{
			cout << "按姓名查找：" << endl;
			cout << "请输入姓名" << endl;
			cin >> which;
			for (int i = 0; i < num; ++i)
			{
				if (workerarray[i]->name == which)
				{
					workerarray[i]->show_info();
					cout << "是否删除(1、是   2、否)" << endl;
					cin >> sure;
					if (sure == 1)
					{
						delete workerarray[i];
						for (int j = i; j < num - 1; j++)
						{
							workerarray[j] = workerarray[j + 1];
						}
						workerarray[num - 1] = NULL;
						num--;
					}
				}
				
			}
			break;
		}
		else
		{
			cout << "请重新输入" << endl;
		}


	}
	//改文件	emmm思路是直接覆盖
	if (num != 0)
	{
		ofstream ofs;
		ofs.open("file.txt", ios::out);
		for (int k = 0; k < num; k++)
		{
			ofs << endl << workerarray[k]->number << ' ' 
				<< workerarray[k]->name << ' ' << workerarray[k]->job;
			ofs.close();
		}

		ofs.close();
	}
	else if (num == 0)
	{
		ofstream ofs;
		ofs.open("file.txt", ios::out);
		ofs.close();
	}

}





void Running::modify()
{
	//感觉也就是把删除的函数CV过来就行了
	cout << "按编号查找还是姓名查找:" << endl;
	cout << "1、编号" << endl;
	cout << "2、姓名" << endl;
	int how;
	string which;



	while (true)
	{
		cin >> how;
		if (how == 1)
		{
			cout << "按编号查找：" << endl;
			cout << "请输入编号" << endl;
			cin >> which;
			for (int i = 0; i < num; ++i)
			{
				if (workerarray[i]->number == which)
				{
					workerarray[i]->show_info();
					
					cout << "请重新输入员工的编号：";
					cin >> workerarray[i]->number;
					cout << "请重新输入员工的姓名：";
					cin >> workerarray[i]->name;
					

					/*cout << "请重新输入员工的工作：" << endl
						<< "1、普通员工" << endl << "2、经理" << endl << "3、老板" << endl;
					cin >> workerarray[i]->job;
					
					职位需要删除原指针，创建新的另一个类别的指针
					懒得搞了
					
					*/
				}

			}
			break;
		}
		else if (how == 2)
		{
			cout << "按姓名查找：" << endl;
			cout << "请输入姓名" << endl;
			cin >> which;
			for (int i = 0; i < num; ++i)
			{
				if (workerarray[i]->name == which)
				{
					workerarray[i]->show_info();
					
					cout << "请重新输入员工的编号：";
					cin >> workerarray[i]->number;
					cout << "请重新输入员工的姓名：";
					cin >> workerarray[i]->name;
					/*cout << "请重新输入员工的工作：" << endl
						<< "1、普通员工" << endl << "2、经理" << endl << "3、老板" << endl;
					cin >> workerarray[i]->job;*/
				}

			}
			break;
		}
		else
		{
			cout << "请重新输入" << endl;
		}
	}
	
	
	//改文件	emmm思路是直接覆盖
	if (num != 0)
	{
		ofstream ofs;
		ofs.open("file.txt", ios::out);
		for (int k = 0; k < num; k++)
		{
			ofs << endl << workerarray[k]->number << ' '
				<< workerarray[k]->name << ' ' << workerarray[k]->job;
			
		}

		ofs.close();
	}
	else if (num == 0)
	{
		ofstream ofs;
		ofs.open("file.txt", ios::out);
		ofs.close();
	}
}



//清空信息
void Running::empty()
{
	int sure;
	cout << "请确认是否删除:" << endl;
	cout << "1、确认删除" << endl;
	cout << "2、取消删除" << endl;
	cin >> sure;
	while (true)
	{
		if (sure == 1)
		{
			delete[] workerarray;
			num = 0;
			break;
		}
		else if (sure == 2)
		{
			cout << "取消删除" << endl;
			return;
		}
		else
		{
			cout << "请重新输入" << endl;
		}
	}
	ofstream ofs;
	ofs.open("file.txt", ios::out);
	ofs.close();

}


void Running::mySort()
{
	//这里排序我没去判定数字的长度的比较，懒得整了
	//懒
	int how;

	int temp_ij;
	worker* temp;
	cout << "请问是按编号升序还是编号降序" << endl;
	cout << "1、按编号升序" << endl;
	cout << "2、按编号降序" << endl;
	cin >> how;
	while (true)
	{
		if (how == 1)
		{
			for (int i = 0; i < num; i++)
			{
				temp_ij = i;
				for (int j = i + 1; j < num; j++)
				{
					if (workerarray[i]->number.compare(workerarray[j]->number)>0)
					{
						temp_ij = j;
					}
				}
				temp = workerarray[i];
				workerarray[i] = workerarray[temp_ij];
				workerarray[temp_ij] = temp;
			}
			break;
		}
		else if (how == 2)
		{
			for (int i = 0; i < num - 1; i++)
			{
				temp_ij = i;
				for (int j = i + 1; j < num; j++)
				{
					if (workerarray[i]->number.compare(workerarray[j]->number)<0)
					{
						temp_ij = j;
					}
				}
				temp = workerarray[i];
				workerarray[i] = workerarray[temp_ij];
				workerarray[temp_ij] = temp;
			}
			break;
		}
		else
		{
			cout << "请重新输入" << endl;
		}
	}
	ofstream ofs;
	ofs.open("file.txt", ios::out);
	for (int i = 0; i < num; i++)
	{
		ofs << endl << workerarray[i]->number<<' '
			<< workerarray[i]->name << ' ' << workerarray[i]->job;
	}
	ofs.close();
}