#include<iostream>
using namespace std;

class SingletonLazy
{
private:
	SingletonLazy(){}//˽�л����캯��
	static SingletonLazy* sl;//ָ������ľ�ָ̬��
public:
	static SingletonLazy* getClass()//�ṩ��þ�ָ̬��Ľӿ�
	{
		/*
			�˴�������ж��̱߳�̣�����ȫ
			���ڶ��̵߳Ĺ�ϵ�����ܵ������ڷ����ڴ�����Ժ󣬻�û���ü���ʼ����Ա������
			�ͽ����߳��л�������һ���߳��õ�����Ȩ�������ڴ��Ѿ������ˣ�
			���Ǳ�����ʼ����û���У���˻�ȡ��Ա���������ֵ�ᷢ����һ������
		*/
		if (sl == NULL)		//ʹ�õ�ʱ���ٽ��г�ʼ��
		{
			sl = new SingletonLazy();
		}
		return sl;
	}
};
SingletonLazy* SingletonLazy::sl =NULL;