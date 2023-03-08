#pragma once 
#include<iostream>
#include"JSON.h"
#include"XML.h"

class Adapter:public JSON
{
	XML* m_xml;
public:
	Adapter(XML* xml)
	{
		this->m_xml = xml;
	}
	std::string Json_info()override
	{
		return m_xml->xml_info()+"change into json";
	}
};