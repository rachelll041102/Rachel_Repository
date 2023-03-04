#include<iostream>
#include"command.h"
#include"bike.h"
#include"OFOBulider.h"
#include"MoBikeBuilder.h"
int main()
{
	Command command(new OFOBulider());
	Bike* bike=command.package();

	cout << bike->getframe() << endl << bike->getseat() << endl;
	cout << "==============================" << endl;

	command.setBuilder(new MoBikeBuilder());
	bike = command.package();

	cout << bike->getframe() << endl << bike->getseat();
}