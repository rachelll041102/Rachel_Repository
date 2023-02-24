#include<iostream>
#include"running.h"		//������ɾ�Ĳ��ͷ�ļ�
using namespace std;
#include"employee.h"
#include"manager.h"
#include"boss.h"

//��ʾ�˵�����
void Running::menu()
{
	cout << "*****************************************" << endl;
	cout << "*****     ��ӭʹ��Ա������ϵͳ      *****" << endl;
	cout << "*****                               *****" << endl;
	cout << "*****     1������Ա����Ϣ           *****" << endl;
	cout << "*****     2����ʾԱ����Ϣ           *****" << endl;
	cout << "*****     3��ɾ��Ա����Ϣ           *****" << endl;
	cout << "*****     4���޸�Ա����Ϣ           *****" << endl;
	cout << "*****     5������Ա����Ϣ           *****" << endl;
	cout << "*****     6�����ձ������           *****" << endl;
	cout << "*****     7�����������Ϣ           *****" << endl;
	cout << "*****     0���˳�����ϵͳ           *****" << endl;
	cout << "*****                               *****" << endl;
	cout << "*****************************************" << endl;
}






//�˳�Ա��ϵͳ
void Running::close()
{
	cout << "��л���ʹ��!!!!" << endl;
	system("pause");
	exit(0);
}








//����Ա����Ϣ
void Running::add()
{
	int newsize = num + 1;
	worker** newspace = new worker * [newsize];

	//�� ԭ���������� ������ �¶���
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
		cout << "������Ա���ı�ţ�";
		cin >> temp_num;
		cout << "������Ա����������";
		cin >> temp_name;
		cout << "������Ա���Ĺ�����" << endl
			<< "1����ͨԱ��" << endl << "2������" << endl << "3���ϰ�"<<endl;
		cin >> temp_job;

		num++;
		if (temp_job == 1)
		{
			newspace[num-1]=new employee(temp_num, temp_name, temp_job);
			storage(newspace[num - 1]);
			cout << endl<<"����ɹ�"<<endl;
			break;
		}
		else if (temp_job == 2)
		{
			newspace[num - 1] = new manager(temp_num, temp_name, temp_job);
			storage(newspace[num - 1]);
			cout << endl << "����ɹ�" << endl;
			break;
		}
		else if (temp_job == 3)
		{
			newspace[num - 1] = new boss(temp_num, temp_name, temp_job);
			storage(newspace[num - 1]);
			cout << endl << "����ɹ�" << endl;
			break;
		}
		else
		{
			cout << "�������ֵ����";
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








//��ʾԱ����Ϣ
void Running::show()
{
	if (num != 0)
	{
		for (int i = 0; i < num; i++)
		{
			workerarray[i]->show_info();
			
		}
	}
	else cout << "û����Ϣ";
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

	/*����Ϊʲô��ǰ����endl��
		ԭ���Ұ�endl�ŵ���ĩβ������endl�����ļ�����תһ�У�
		��ʱn�����ݣ����ȡ��n+1�����ݣ�����Ϊ�˱���ϵͳ����
		�Ұ����ŵ��˿�ͷ
		����Ϊʲô��������ȡ���ᱻ�ʼ��endlӰ�죬�Ҳ���*/

	ofs << endl << wk->number << ' '  << wk->name << ' ' << wk->job ;
	ofs.close();

}




//������ȡ�ļ����������
void Running::readFile()
{
	/*��������Ϊ���ļ����棬��������Ҫ��ȡһ�Σ������ж��Ƿ����ļ���ĩβ
		������ļ���ĩβ��˵���ǿ��ļ���ֱ�ӷ��ؾͺ���*/
	char null;
	ifstream ifs;
	ifs.open("file.txt", ios::in);
	ifs >> null;
	if (ifs.eof())return;


	//ios::in   ���ᴴ��һ���ļ�������������Ҫ�ж�
	if (!ifs.is_open())
	{
		cout << "����ʹ�ã�û������" << endl;
		return;
	}

	//�������û�з��أ�˵���ļ����������ݣ��������������ļ�ָ���Ѿ���ȡ��һ�Σ�
	//��Ҫ�ص��ͷ��
	//���������seekg()����
	//seekg(�ڼ���λ��,�����￪ʼ��)	beg��begin���ͷ�ĵط�
	ifs.seekg(0, ios::beg);
	while (1)
	{
		if (ifs.eof())break;//�������ĩβ���ͷ���

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
		/*����ֱ�Ӹ�ֵ������£�newspace[num - 1]��ָ��0xcdcdcdcdcdcdcdcd;
		��ʱnewspace[num - 1]��û�г�ʼ����
		ifs >> newspace[num - 1]->number;
		ifs >> newspace[num - 1]->name;
		ifs >> newspace[num - 1]->job;*/

		if(workerarray!=NULL)delete[] workerarray;
		workerarray = newspace;

	}
	ifs.close();


}




//����ָ��Ա��
void Running::find()
{
	cout << "�����ǰ���Ų��һ�����������" << endl;
	cout << "1����Ų���" << endl;
	cout << "2����������" << endl;

	string which;	//��������������ݵ�
	int how;		//����ѡ��˵���
					//tmdһ��ʼ�Լ�д�Ĵ��뻹�����
		
	while (true)
	{
		cin >> how;

		if (how == 1)
		{
			cout << "��������ҵı��:";
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
			cout << "��������ҵ�����";
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
		else cout << "����������" << endl;

		
	}
	

}





//ɾ��ָ��Ա��
void Running::del()
{
	cout << "�����ɾ����������ɾ��:" << endl;
	cout << "1�����" << endl;
	cout << "2������" << endl;
	int how;
	string which;
	int sure;

	while (true)
	{
		cin >> how;
		if (how == 1)
		{
			cout << "����Ų��ң�" << endl;
			cout << "��������" << endl;
			cin >> which;
			for (int i = 0; i < num; ++i)
			{
				if (workerarray[i]->number == which)
				{
					workerarray[i]->show_info();
					cout << "�Ƿ�ɾ��(1����   2����)" << endl;
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
			cout << "���������ң�" << endl;
			cout << "����������" << endl;
			cin >> which;
			for (int i = 0; i < num; ++i)
			{
				if (workerarray[i]->name == which)
				{
					workerarray[i]->show_info();
					cout << "�Ƿ�ɾ��(1����   2����)" << endl;
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
			cout << "����������" << endl;
		}


	}
	//���ļ�	emmm˼·��ֱ�Ӹ���
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
	//�о�Ҳ���ǰ�ɾ���ĺ���CV����������
	cout << "����Ų��һ�����������:" << endl;
	cout << "1�����" << endl;
	cout << "2������" << endl;
	int how;
	string which;



	while (true)
	{
		cin >> how;
		if (how == 1)
		{
			cout << "����Ų��ң�" << endl;
			cout << "��������" << endl;
			cin >> which;
			for (int i = 0; i < num; ++i)
			{
				if (workerarray[i]->number == which)
				{
					workerarray[i]->show_info();
					
					cout << "����������Ա���ı�ţ�";
					cin >> workerarray[i]->number;
					cout << "����������Ա����������";
					cin >> workerarray[i]->name;
					

					/*cout << "����������Ա���Ĺ�����" << endl
						<< "1����ͨԱ��" << endl << "2������" << endl << "3���ϰ�" << endl;
					cin >> workerarray[i]->job;
					
					ְλ��Ҫɾ��ԭָ�룬�����µ���һ������ָ��
					���ø���
					
					*/
				}

			}
			break;
		}
		else if (how == 2)
		{
			cout << "���������ң�" << endl;
			cout << "����������" << endl;
			cin >> which;
			for (int i = 0; i < num; ++i)
			{
				if (workerarray[i]->name == which)
				{
					workerarray[i]->show_info();
					
					cout << "����������Ա���ı�ţ�";
					cin >> workerarray[i]->number;
					cout << "����������Ա����������";
					cin >> workerarray[i]->name;
					/*cout << "����������Ա���Ĺ�����" << endl
						<< "1����ͨԱ��" << endl << "2������" << endl << "3���ϰ�" << endl;
					cin >> workerarray[i]->job;*/
				}

			}
			break;
		}
		else
		{
			cout << "����������" << endl;
		}
	}
	
	
	//���ļ�	emmm˼·��ֱ�Ӹ���
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



//�����Ϣ
void Running::empty()
{
	int sure;
	cout << "��ȷ���Ƿ�ɾ��:" << endl;
	cout << "1��ȷ��ɾ��" << endl;
	cout << "2��ȡ��ɾ��" << endl;
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
			cout << "ȡ��ɾ��" << endl;
			return;
		}
		else
		{
			cout << "����������" << endl;
		}
	}
	ofstream ofs;
	ofs.open("file.txt", ios::out);
	ofs.close();

}


void Running::mySort()
{
	//����������ûȥ�ж����ֵĳ��ȵıȽϣ���������
	//��
	int how;

	int temp_ij;
	worker* temp;
	cout << "�����ǰ���������Ǳ�Ž���" << endl;
	cout << "1�����������" << endl;
	cout << "2������Ž���" << endl;
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
			cout << "����������" << endl;
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