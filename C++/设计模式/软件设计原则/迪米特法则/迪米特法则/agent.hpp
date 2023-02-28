#include<iostream>
#include"company.hpp"
#include"fans.hpp"
#include"star.hpp"
using namespace std;
/*
	迪米特法则:
		如果两个软件实体无须直接通信，那么就不应当发生直接的相互调用，
		可以通过第三方转发该调用。

	这是个经纪人，明星，粉丝和公司之间关系的例子

	由于明星与粉丝，公司并不认识，	明星只与他的经纪人认识
		明星与粉丝的见面，需要通过经纪人当中间项
		明星与公司的合作，需要通过经纪人当中间项


*/
class Agent
{
private:
	Star* star;
	Fans* fans;
	Company* company;
public:
	void setstar(Star* star)
	{
		this->star = star;
	}
	void setcompany(Company* company)
	{
		this->company = company;
	}
	void setfans(Fans* fans)
	{
		this->fans = fans;
	}
	void meeting()
	{
		cout << "经纪人让明星  " << star->getname() 
			 << "  跟粉丝  " << fans->getname() << "  见面" << endl;
	}
	void business()
	{
		cout << "经纪人让明星  " << star->getname()
			<< "  跟公司  " << company->getname() << "  进行商务合作" << endl;
	}
};