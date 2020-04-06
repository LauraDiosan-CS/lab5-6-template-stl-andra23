#include<iostream>
#include "Aplicatie.h"
#include "Service.h"

Service::Service(){

}

Service::Service(const Repo<AplicatieManagement>& repo){

	r = repo;
}

void Service::setRepo(const Repo<AplicatieManagement>& repo){

	r = repo;
}
void Service::addAplicatieManagement(AplicatieManagement a) {
	
	map<int, AplicatieManagement> elemente;
	elemente = r.getAll();
	for (auto it = elemente.begin(); it != elemente.end(); ++it) {
		if (strcmp((it->second).getName(), a.getName()) == 0)
			throw std::exception("Exista deja o aplicatie cu acest nume.");
	}
	v.validareDate(a);
	r.addAplicatieManagement(a);
	
}
map<int,AplicatieManagement> Service::showAplicatiiManagement() {

	return r.getAll();
}
void Service::delElem(int i)
{
	r.delElem(i);
}
void Service:: updateElem(int i, char* nume, int consumMemorieKb, char* status) {

	r.updateElem(i, nume, consumMemorieKb, status);
}
int Service::getSize() {

	return r.getSize();
}
bool Service::findOne(int i){

	return r.findElem(i);
}
void Service::initService() {
	
	r.loadFromFile("AplicatiiManagement.txt");
	setRepo(r);
}
int Service::VerificareMemorie(AplicatieManagement a) {

	map<int, AplicatieManagement> elem;
	elem = r.getAll();
	for (auto i = elem.begin(); i != elem.end(); i++)
	{
		if (strcmp(i->second.getStatus(), "ram") == 0) {
			Memorie = Memorie - (i->second.getConsumMemorieKb());
		}
	}
	for (auto i = elem.begin(); i != elem.end(); i++)
	{
		if (strcmp(i->second.getStatus(), "swap") == 0)
			return -1;
	}
	if (a.getConsumMemorieKb() > Memorie)
		return 0;
	
}
int Service::AdaugareLaRam(AplicatieManagement a)
{
	if (a.getConsumMemorieKb() < Memorie) {
		return 0;
	}
	else return -1;
}

int Service::adaugare(AplicatieManagement a)
{
	map<int, AplicatieManagement> elem;
	elem = r.getAll();
	for (auto i = elem.rbegin(); i != elem.rend(); ++i)
	{
		while (a.getConsumMemorieKb() > Memorie) {
			if (strcmp(i->second.getStatus(), "ram") == 0) {
				i->second.setStatus("swap");
				Memorie = Memorie + (i->second.getConsumMemorieKb());

			}

		}
	}
	if (a.getConsumMemorieKb() < Memorie)
		return 0;
	return -1;
	
}
int Service::memorie() {
	return Memorie;
}

