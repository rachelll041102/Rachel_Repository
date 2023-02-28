#include<iostream>
#include"agent.hpp"
using namespace std;

int main()
{
	Agent agent;								//经纪人
	Company* tencent = new Company("腾讯");		//公司
	Star* star = new Star("刀哥");				//明星
	Fans * fans = new Fans("孙笑川");			//粉丝

	agent.setcompany(tencent);
	agent.setstar(star);
	agent.setfans(fans);

	agent.business();
	agent.meeting();
}