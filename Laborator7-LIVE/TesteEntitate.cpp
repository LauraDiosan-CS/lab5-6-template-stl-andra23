#include "TesteEntitate.h"
#include "Aplicatie.h"
#include<iostream>
#include<assert.h>
using namespace std;
void teste() {
	AplicatieManagement a("MeisterTask",2000,"ram");
	a.setName("ArgumentePRO");
	char* nume;
	nume = a.getName();
	assert(a.getName() == nume);
	a.setConsumMemorieKb(2300);
	assert(a.getConsumMemorieKb() == 2300);
	a.setStatus("swap");
	char* status;
	status = a.getStatus();
	assert(a.getStatus() == status);
	
	AplicatieManagement a2 = a;                      //copy constructor
	AplicatieManagement a3;			                 //implicit constructor
	a3 = a2;
	assert(a3 == a2);
	//assign op or implicit assign op beacuse memebr data are of elementary type => a new ob
	//(implicit) assign op => self assign


}