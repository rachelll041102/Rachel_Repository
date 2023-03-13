#include<iostream>
using namespace std;

class VideoSystem
{
public:
	string initial()
	{
		return "Video:Ready\n";
	}
	string play()
	{
		return "Video:Play	";
	}
	string mute()
	{
		return "mute";
	}
};
class RadioSystem
{
public:
	string init()
	{
		return "Radio:Ready\n";
	}
	string start()
	{
		return "Radio:Start	";
	}
};
class Appearance
{
private:
	RadioSystem* m_radio;
	VideoSystem* m_video;
public:
	Appearance(RadioSystem* radio=nullptr, VideoSystem* video=nullptr)
	{
		m_radio = radio ? radio : new RadioSystem();
		m_video = video ? video : new VideoSystem();
		cout << radio->init() << video->initial() << endl;
	}
	void  play()
	{
		cout << "Begin playing:\n";
		cout<< m_radio->start() + m_video->play();
	}
	string mute()
	{
		return m_video->mute();
	}
};
int main()
{
	VideoSystem* video = new VideoSystem();
	RadioSystem* radio = new RadioSystem();

	Appearance* appearance = new Appearance(radio, video);

	appearance->play();
}