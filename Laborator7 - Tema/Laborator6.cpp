// Laborator6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<istream>
#include "TesteEntitate.h"
#include "RepoTeste.h"
#include "UI.h"
#include "TesteMemorie.h"
using namespace std;


int main()
{
	RepoFile r("AplicatiiManagement.txt");
	//Repo<AplicatieManagement> r;
	Service s(r);
	UI u(s);
	teste();
	testAdd();
	testGetAll();
	testDelete();
	testUpdate();
	test1();
	test2();
	test3();
	u.PrintMenu();
}



