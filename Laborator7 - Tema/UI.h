#pragma once
#include "Service.h"
class UI {
private:
	
	Service &s;
public:
	UI(Service &serv) :s(serv) {};
	void display();
	void PrintMenu();



};

