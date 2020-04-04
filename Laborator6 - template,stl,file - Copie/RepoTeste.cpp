#include "RepoTeste.h"
#include "Repo.h"
#include<assert.h>
#include<iostream>

	void testAdd(){
	Repo<AplicatieManagement> r;
	r.loadFromFile("Teste.txt");
	r.clearFile();
	assert(r.getSize() == 0);
	AplicatieManagement a("ArgumentePRO",2000,"ram");
	r.addAplicatieManagement(a);
	assert(r.getSize() == 1);
	
	r.clearFile();
}

void testGetAll(){

	Repo<AplicatieManagement> r;
	r.loadFromFile("Teste.txt");
	assert(r.getSize() == 0);
	map<int,AplicatieManagement> elemente;
	AplicatieManagement a1("ArgumentePRO",2000,"ram");
	AplicatieManagement a2("MeisterTask", 3200, "swap");
	r.addAplicatieManagement(a1);
	r.addAplicatieManagement(a2);
	elemente = r.getAll();
	assert(r.getSize() == 2);
	AplicatieManagement a3;
	AplicatieManagement a4;
	a3 = a1;
	a4 = a2;
	assert(elemente[0] == a3);
	assert(elemente[1] == a4); 
	
	r.clearFile();
	}
void testDelete() {
	Repo<AplicatieManagement> r;
	r.loadFromFile("Teste.txt");
	assert(r.getSize() == 0);
	AplicatieManagement a1("ArgumentePRO", 2000, "ram");
	AplicatieManagement a2("MeisterTask", 3200, "swap");
	r.addAplicatieManagement(a1);
	r.addAplicatieManagement(a2);
	assert(r.getSize() == 2);
	r.delElem(0);
	assert(r.getSize() == 1);
	r.clearFile();
	
}
void testUpdate() {
	Repo<AplicatieManagement> r;	
	r.loadFromFile("Teste.txt");
	map<int, AplicatieManagement> elemente;
	assert(r.getSize() == 0);
	AplicatieManagement a1("ArgumentePRO", 2000, "ram");
	AplicatieManagement a2("MeisterTask", 3200, "swap");
	r.addAplicatieManagement(a1);
	r.addAplicatieManagement(a2);
	r.updateElem(0,(char*)"SourceA", 2000, (char*)"ram");
	elemente = r.getAll();
	map<int, AplicatieManagement> ::iterator itr = elemente.find(0);
	assert(strcmp((itr->second).getName(), "SourceA") == 0);
	r.clearFile();
	
}






