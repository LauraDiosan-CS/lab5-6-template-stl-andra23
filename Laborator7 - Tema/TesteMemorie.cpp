#include"Aplicatie.h";
#include "Service.h"
#include "RepoFile.h"
#include<iostream>
#include<assert.h>
void test1(){	

	RepoFile r("Teste.txt");
	Service s (r);
	map<int, AplicatieManagement> elemente;                     //Memorie totala predefinita: 12000Kb                                                    
	AplicatieManagement a1("ArgumentePRO", 2300,"ram");
	AplicatieManagement a2("MeisterTask", 3400, "ram");         // total consumat 5700kb
	s.addAplicatieManagement(a1);
	s.addAplicatieManagement(a2);
	AplicatieManagement a3("InstaWork",6400, "ram");           // total ramas: 12000-5700=6300 kb <6400kb =>
	s.addAplicatieManagement(a3);                        // a1->swap total ramas: 6300+2300=8600kb >6400kb
	elemente = s.showAplicatiiManagement();
	assert(s.getSize() == 3);
	map<int, AplicatieManagement> ::iterator itr = elemente.find(0);
	assert(strcmp(itr->second.getStatus(), "swap") == 0);             // memorie ramasa dupa adaugare: 2200kb
	r.clearFile();
}

void test2(){

	RepoFile r("Teste.txt");
	Service s(r);
	assert(s.getSize() == 0);
	AplicatieManagement a1("ArgumentePRO", 2000, "ram");
	AplicatieManagement a2("MeisterTask", 3200, "ram");
	s.addAplicatieManagement(a1);
	s.addAplicatieManagement(a2);
	assert(s.getSize() == 2);
	AplicatieManagement a3("InstaWork", 20000000, "ram");
	bool exceptionThrown = false;
	try {
		s.addAplicatieManagement(a3);
	}
	catch (exception e)
	{
		exceptionThrown = true;
	}
	assert(exceptionThrown);
	assert(s.getSize() == 2);
	r.clearFile();
}
void test3() {
	RepoFile r("Teste.txt");
	Service s(r);
	assert(s.getSize() == 0);
	AplicatieManagement a1("ArgumentePRO",2300, "ram");
	AplicatieManagement a2("MeisterTask", 10000, "swap");    // a2->ram ( 10000< 12000)
	AplicatieManagement a3("InstaWork", 6400, "swap");       // total ramasa: 2000kb
	s.addAplicatieManagement(a1);                            // 6400 > 2000 => a3->swap
	s.addAplicatieManagement(a2);
	s.addAplicatieManagement(a3);
	assert(s.getSize() == 3);
	s.delElem(0);
	map<int, AplicatieManagement> elemente=s.showAplicatiiManagement();
	map<int, AplicatieManagement> ::iterator itr = elemente.find(1);
	assert(strcmp(itr->second.getStatus(), "ram") == 0);
	itr = elemente.find(2);
	assert(strcmp(itr->second.getStatus(), "swap") == 0);
	r.clearFile();
}




