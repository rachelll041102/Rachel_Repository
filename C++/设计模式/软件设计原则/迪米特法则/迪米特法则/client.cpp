#include<iostream>
#include"agent.hpp"
using namespace std;

int main()
{
	Agent agent;								//������
	Company* tencent = new Company("��Ѷ");		//��˾
	Star* star = new Star("����");				//����
	Fans * fans = new Fans("��Ц��");			//��˿

	agent.setcompany(tencent);
	agent.setstar(star);
	agent.setfans(fans);

	agent.business();
	agent.meeting();
}