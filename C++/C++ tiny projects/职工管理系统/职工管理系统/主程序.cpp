//�кܶ�û�����ƣ����ø���

#include<iostream>
using namespace std;

#include"running.h"		//������ɾ�Ĳ��ͷ�ļ�

int main()
{
	int select(0);				//��������˵���ѡ��
	Running running;			//���ù������ָ��
	/*������ԭ����д���� Running* running = NULL;	
	����ָ�����ģ��������ȫ������this ��nullptr
	�мǲ�����ָ��*/

	running.readFile();
	while (true)
	{
		running.menu();

		cout << "����Ҫ�ķ�����" << endl;
		cin >> select;


		switch (select)
		{
		case 0://�˳�Ա��ϵͳ
			running.close();
			break;

		case 1://����Ա����Ϣ  
			running.add();
			break;

		case 2://��ʾԱ����Ϣ
			running.show();
			break;

		case 3://ɾ��Ա����Ϣ
			running.del();
			break;
		case 4://�޸�Ա����Ϣ
			running.modify();
			break;

		case 5://����Ա����Ϣ
			running.find();
			break;

		case 6://���ձ������
			running.mySort();
			break;

		case 7://���������Ϣ
			running.empty();
			break;

		}
		system("pause");
		system("cls");
	}


}