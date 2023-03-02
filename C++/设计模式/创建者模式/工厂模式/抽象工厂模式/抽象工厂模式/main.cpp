#include<iostream>
#include"Factory.h"
#include"Food.h"
#include"Drink.h"
#include"MacDonaldFactory.h"
#include"KFCFactory.h"
using namespace std;

int main()
{
	//两家餐厅
	Factory* macdonald = new MacDonaldFactory();
	Factory* kfc = new KFCFactory();

	//在麦当劳点餐
	cout << "去麦当劳吃饭" << endl;
	Food* food=macdonald->createFood();
	Drink* drink = macdonald->createDrink();

	cout << "主食是:" << food->getname()<<endl;
	cout << "饮料是:" << drink->getname() << endl;

	cout << "===================" << endl;
	cout << "麦当劳好难吃，不如疯狂星期四" << endl;
	//丢掉麦当劳的食物（清除指针）
	delete food;
	delete drink;

	//在KFC点餐
	food = new KFCHambuger();
	drink = new KFCCoco();

	cout << "主食是:" << food->getname() << endl;
	cout << "饮料是:" << drink->getname() << endl;

}