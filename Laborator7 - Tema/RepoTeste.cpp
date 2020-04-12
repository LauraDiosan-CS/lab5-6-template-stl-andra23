#include "RepoTeste.h"
#include "Repo.h"
#include "RepoFile.h"
#include<assert.h>
#include<iostream>

	void testAdd(){
	RepoFile  r;
	r.loadFromFile("Teste.txt");
	r.clearFile();
	assert(r.getSize() == 0);
	AplicatieManagement a("ArgumentePRO",2000,"ram");
	r.addElem(a);
	assert(r.getSize() == 1);
	r.clearFile();
}

void testGetAll(){
	
	RepoFile r("Teste.txt");
	assert(r.getSize() == 0);
	map<int,AplicatieManagement> elemente;
	AplicatieManagement a1("ArgumentePRO",2000,"ram");
	AplicatieManagement a2("MeisterTask", 3200, "swap");
	r.addElem(a1);
	r.addElem(a2);
	elemente = r.getAll();
	assert(r.getSize() == 2);
	r.clearFile();
	}
void testDelete() {

	RepoFile r("Teste.txt");
	assert(r.getSize() == 0);
	AplicatieManagement a1("ArgumentePRO", 2000, "ram");
	AplicatieManagement a2("MeisterTask", 3200, "swap");
	r.addElem(a1);
	r.addElem(a2);
	assert(r.getSize() == 2);
	r.delElem(1);
	assert(r.getSize() == 1);
	r.clearFile();
	
}

void testUpdate() {

	RepoFile r("Teste.txt");	
	map<int, AplicatieManagement> elemente;
	assert(r.getSize() == 0);
	AplicatieManagement a1("ArgumentePRO", 2000, "ram");
	AplicatieManagement a2("MeisterTask", 3200, "swap");
	r.addElem(a1);
	r.addElem(a2);
	AplicatieManagement a((char*)"SourceA", 2000, (char*)"ram");
	r.updateElem(0,a);
	elemente = r.getAll();
	map<int, AplicatieManagement> ::iterator itr = elemente.find(0);
	assert(strcmp((itr->second).getName(), "SourceA") == 0);
	r.clearFile();
	
}








