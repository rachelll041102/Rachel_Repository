#include<iostream>
#include"class.h"
using namespace std;
/*
	�ӿڸ���ԭ��
		�ͻ��˲�Ӧ�ñ�������������ʹ�õķ�����
		һ�������һ���������Ӧ�ý�������С�Ľӿ��ϡ�

	�������У����������������ԣ������ˮ����
			  ˫����ֻ���������ԣ������ˮ(��ʹ�÷���)
*/
int main()
{
	cout << "������" << endl;
	three_guard_door* threegd = new three_guard_door();
	threegd->fireproofing();
	threegd->guard_against_theft();
	threegd->waterproofing();

	cout << "============================" << endl;

	cout << "˫����" << endl;
	two_guard_door* twogd = new two_guard_door();
	twogd->fireproofing();
	twogd->waterproofing();

}