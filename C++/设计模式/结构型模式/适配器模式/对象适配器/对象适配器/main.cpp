#include<iostream>
#include"Adapter.h"
#include"JSON.h"
#include"XML.h"
#include"Cilent.h"

int main()
{
	XML* xml = new XML();
	JSON* json = new JSON();
	Adapter* adapter = new Adapter(xml);

	Cilent cl;
	cl.testing(json);
	cl.testing(adapter);
	//cl.testing(xml);
}