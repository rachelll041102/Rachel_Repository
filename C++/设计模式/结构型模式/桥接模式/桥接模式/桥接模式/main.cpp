#include<iostream>
using namespace std;
//抽象的设备类
class Device
{
public:
	virtual string turnOn()=0;
	virtual string turnOff()=0;
	virtual string turnMute()=0;
};
//具体设备：radio
class Radio:public Device

{
public:
	string turnOn()
	{
		return "Radio:turn on";
	}
	string turnOff()
	{
		return "Radio:turn off";
	}
	string turnMute()
	{
		return "Radio:turn mute";
	}
};
//具体设备：tv
class TV:public Device
{
public:
	string turnOn()
	{
		return "TV:turn on";
	}
	string turnOff()
	{
		return "TV:turn off";
	}
	string turnMute()
	{
		return "TV:turn mute";
	}
};
//基础遥控器
class AbstractRemoteController
{
protected:
	Device* device;
public:
	AbstractRemoteController(Device* getdevice):device(getdevice)
	{

	}
	virtual void sendTurnOn()
	{
		cout<<"remote controller:"<<device->turnOn()<<endl;
	}
	virtual void sendTurnOff()
	{
		cout << "remote controller:" << device->turnOff()<<endl;
	}

};
//改进遥控器
class AdvanceRemoteController:public AbstractRemoteController
{
public:
	AdvanceRemoteController(Device* temp):AbstractRemoteController(temp)
	{

	}
	virtual void sendTurnOn()
	{
		cout << "advance remote controller:" << device->turnOn() << endl;
	}
	virtual void sendTurnOff()
	{
		cout << "advance remote controller:" << device->turnOff() << endl;
	}
	void sendMute()
	{
		cout << "advance remote controller:" << device->turnMute() << endl;
	}
};

int main()
{
	Device* radio = new Radio();
	AbstractRemoteController* baseCL = new AbstractRemoteController(radio);

	baseCL->sendTurnOn();
	baseCL->sendTurnOff();

	cout << "==========================================" << endl;
	TV* tv = new TV();
	AdvanceRemoteController* advanceCL = new AdvanceRemoteController(tv);
	advanceCL->sendTurnOn();
	advanceCL->sendMute();
	advanceCL->sendTurnOff();
}