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


