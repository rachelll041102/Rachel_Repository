#include<iostream>
#include<vector>
#include"quick_sort.h"
using namespace std;

int main()
{
	vector<int>arr;
	arr.push_back(99);
	arr.push_back(67);
	arr.push_back(38);
	arr.push_back(55);
	arr.push_back(42);
	arr.push_back(103);

	cout << "交换前";
	for (auto num : arr)cout << num << ' ';

	quick_sort(arr, 0, 5);
	
	cout << endl << "交换后:";
	for (auto num : arr)cout << num << ' ';
}