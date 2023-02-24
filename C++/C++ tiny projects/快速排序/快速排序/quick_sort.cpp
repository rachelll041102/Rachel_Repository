#include"quick_sort.h"

int become_twice(vector<int>& nums, int left, int right)
{
	//找一个基准base，这里是找了最前面的数，即nums[0]

	//i是指向最左边的，j是指向最右边的
	int i = left, j = right;

	/*
		i从最左边开始找  大于base的数
		j从最右边开始找  小于base的数
	*/
	while (i < j)
	{
		while (i < j && nums[j] >= nums[left])//最右边  
			j--;								//碰到大的数会继续，直到找到小的
		while (i < j && nums[i] <= nums[left])
			i++;

		//然后把找到的数进行交换
		myswap(nums, i, j);
	}
	//交换完之后，i/j在的位置，左边就是小于base的数，右边就是大于base的数
	//此时把最前面的base和此刻i/j的位置进行交换
	myswap(nums, left, i);

	//把这个界限return回去
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
	//如果left不是小于right，说明这数组只有一个长度
	//就可以直接返回
	if (left >= right)return;
	
	//中间的
	int mid = become_twice(nums, left, right);

	//递归调用分治
	//这是左边的数组
	quick_sort(nums, left, mid - 1);
	//这是右边的数组
	quick_sort(nums, mid + 1, right);

}