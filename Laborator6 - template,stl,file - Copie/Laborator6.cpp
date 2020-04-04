// Laborator6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<istream>
#include "TesteEntitate.h"
#include "RepoTeste.h"
#include "UI.h"
using namespace std;


int main()
{
	UI u;

	teste();
	testAdd();
	testGetAll();
	testDelete();
	testUpdate();
	
	
	
	u.PrintMenu();
}



