#include"quick_sort.h"

int become_twice(vector<int>& nums, int left, int right)
{
	//��һ����׼base��������������ǰ���������nums[0]

	//i��ָ������ߵģ�j��ָ�����ұߵ�
	int i = left, j = right;

	/*
		i������߿�ʼ��  ����base����
		j�����ұ߿�ʼ��  С��base����
	*/
	while (i < j)
	{
		while (i < j && nums[j] >= nums[left])//���ұ�  
			j--;								//����������������ֱ���ҵ�С��
		while (i < j && nums[i] <= nums[left])
			i++;

		//Ȼ����ҵ��������н���
		myswap(nums, i, j);
	}
	//������֮��i/j�ڵ�λ�ã���߾���С��base�������ұ߾��Ǵ���base����
	//��ʱ����ǰ���base�ʹ˿�i/j��λ�ý��н���
	myswap(nums, left, i);

	//���������return��ȥ
	return i;
}

void myswap(vector<int>& nums, int i, int j)
{
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}
void quick_sort(vector<int>& nums, int left, int right)
{
	//���left����С��right��˵��������ֻ��һ������
	//�Ϳ���ֱ�ӷ���
	if (left >= right)return;
	
	//�м��
	int mid = become_twice(nums, left, right);

	//�ݹ���÷���
	//������ߵ�����
	quick_sort(nums, left, mid - 1);
	//�����ұߵ�����
	quick_sort(nums, mid + 1, right);

}