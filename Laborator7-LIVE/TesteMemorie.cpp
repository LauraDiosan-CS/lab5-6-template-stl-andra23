#include"Aplicatie.h";
#include "Repo.h"
#include<iostream>
#include<assert.h>
void test1()
{
	Repo<AplicatieManagement> r;
	r.loadFromFile("Teste.txt");
	assert(r.getSize() == 0);
	map<int, AplicatieManagement> elemente;
	AplicatieManagement a1("ArgumentePRO", 2000, "ram");
	AplicatieManagement a2("MeisterTask", 3200, "ram");
	r.addAplicatieManagement(a1);
	r.addAplicatieManagement(a2);
	elemente = r.getAll();
	assert(r.getSize() == 2);
	AplicatieManagement a3("InstaWork",20000000000, "ram");
	r.addAplicatieManagement(a3);
	assert(r.getSize() == 2);
	r.clearFile();
}
void test2()
{
	Repo<AplicatieManagement> r;
	r.loadFromFile("Teste.txt");
	assert(r.getSize() == 0);
	map<int, AplicatieManagement> elemente;
	AplicatieManagement a1("ArgumentePRO", 2000, "ram");
	AplicatieManagement a2("MeisterTask", 3200, "ram");
	r.addAplicatieManagement(a1);
	r.addAplicatieManagement(a2);
	elemente = r.getAll();
	assert(r.getSize() == 2);
	AplicatieManagement a3("InstaWork", 20, "ram");
	r.addAplicatieManagement(a3);
	assert(r.getSize() == 3);
	r.clearFile();
}