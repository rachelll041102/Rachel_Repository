#pragma once
#include<iostream>
#include"JSON.h"
#include"Adapter.h"

class Cilent
{
public:
	void testing(JSON* json)
	{
		std::cout << "json:" + json->Json_info() << std::endl;
	}
};