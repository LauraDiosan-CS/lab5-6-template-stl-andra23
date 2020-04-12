#include<iostream>
#include "Aplicatie.h"
#include "Service.h"


void Service::addAplicatieManagement(AplicatieManagement a) {

	map<int, AplicatieManagement> elemente;
	elemente = r.getAll();
	for (auto it = elemente.begin(); it != elemente.end(); ++it) {
		if (strcmp((it->second).getName(), a.getName()) == 0)
			throw std::exception("Exista deja o aplicatie cu acest nume.");
	}
	v.validareDate(a);
	
	if (strcmp(a.getStatus(), "ram") == 0) {
		if (addInMemory(a) == 0) {
			r.addElem(a);
		}
		else throw std::exception("Nu s-a putut adauga aplicatia in memoria RAM. Memorie RAM totala: 12000Kb.");
	}
	else 
		r.addElem(a);

}
map<int,AplicatieManagement> Service::showAplicatiiManagement() {

	return r.getAll();
}
void Service::delElem(int i)
{
	if (strcmp(r.find(i).getStatus(), "ram") == 0) {
		fromSwapInRam(i);
	}
	else
	r.delElem(i);
}
void Service:: updateElem(int i, AplicatieManagement a) {

	r.updateElem(i,a);
}
int Service::getSize() {

	return r.getSize();
}
int Service::addInMemory(AplicatieManagement a) {
	int memorie = 12000;
	map<int, AplicatieManagement> elemente = r.getAll();
	for (auto it = elemente.begin(); it != elemente.end(); it++)
	{
		if (strcmp(it->second.getStatus(), "ram") == 0) {
			memorie = memorie - (it->second.getConsumMemorieKb());
		}
	}
	if (a.getConsumMemorieKb() >12000) {
		throw std::exception("Aplicatia depasteste memoria RAM totala a cumputerului.");
	}
	else if(a.getConsumMemorieKb() <= memorie)
			return 0;
	else {

		for (auto it = elemente.begin(); it != elemente.end(); it++) {
			if (a.getConsumMemorieKb() > memorie)
				if (strcmp(it->second.getStatus(), "ram") == 0) {
					it->second.setStatus("swap");
					memorie = memorie + it->second.getConsumMemorieKb();
				}

		}
		int i = 0;
		for (auto it = elemente.begin(); it != elemente.end(); it++) {
			r.updateElem(i, it->second);
			i++;
		}
	}
	if (a.getConsumMemorieKb() <= memorie)
		return 0;
	return -1;	
}

int Service::returnMemory1()
{
	int memorieC = 0;
	map<int, AplicatieManagement> elemente = r.getAll();
	for (auto it = elemente.begin(); it != elemente.end(); it++)
	{	
		if (strcmp(it->second.getStatus(), "ram") == 0)
			memorieC = memorieC + it->second.getConsumMemorieKb();

	}
	return memorieC;

}

void Service::fromSwapInRam(int i) {
	map<int, AplicatieManagement> elemente =r.getAll();
	auto it = elemente.find(i);
	int consumMemorieKb = it->second.getConsumMemorieKb();
	r.delElem(i);
	int memorie = 12000 - returnMemory1();
	memorie = memorie + consumMemorieKb;
	elemente = r.getAll();
	for (auto itr = elemente.begin(); itr != elemente.end(); itr++) {
		if ((strcmp(itr->second.getStatus() ,"swap")==0) && itr->second.getConsumMemorieKb() <= memorie)
		{
			itr->second.setStatus("ram");
					r.updateElem(itr->first,itr->second);
					
			memorie = memorie - itr->second.getConsumMemorieKb();
		}
	}

}








