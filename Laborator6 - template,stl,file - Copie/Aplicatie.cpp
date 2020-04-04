#include "Aplicatie.h"
#include"Repo.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
#include<sstream>
using namespace std;

AplicatieManagement::AplicatieManagement() {
	//cout << "const implicit";
	this->name = NULL;
	this->consumMemorieKb = 0;
	this->status = NULL;
	
}
AplicatieManagement::AplicatieManagement(const char* name, int consumMemorieKb,const  char* status) {
	//cout << "constructor with param" << endl;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->consumMemorieKb = consumMemorieKb;
	this->status = new char[strlen(status) + 1];
	strcpy_s(this->status, strlen(status) + 1, status);
	
}

AplicatieManagement::AplicatieManagement(const AplicatieManagement& a) {
	//cout << "copy constructor" << endl;
	this->name = new char[strlen(a.name) + 1];
	strcpy_s(this->name, strlen(a.name) + 1, a.name);
	this->consumMemorieKb = a.consumMemorieKb;
	this->status = new char[strlen(a.status) + 1];
	strcpy_s(this->status, strlen(a.status) + 1, a.status);
	
}
//CONSTRUCTOR DE CONVERSIE
AplicatieManagement::AplicatieManagement(string linie) {

	std::istringstream iss(linie);
	string tok1, tok2, tok3;
	iss >> tok1 >> tok2>>tok3;
	name = new char[tok1.length() + 1];
	strcpy_s(name, tok1.length() + 1, tok1.c_str());
	consumMemorieKb = stoi(tok2);
	status = new char[tok3.length() + 1];
	strcpy_s(status, tok3.length() + 1, tok3.c_str());
}

AplicatieManagement::~AplicatieManagement() {
	//cout << "Destructor";
	if (this->name) {
		delete[] this->name;
		this->name = NULL;
	}
	consumMemorieKb = 0;
	if (this->status) {
		delete[] this->status;
		this->status = NULL;
	}

}
char* AplicatieManagement::getName() {
	return this->name;
}
int AplicatieManagement::getConsumMemorieKb() {
	return this->consumMemorieKb;
}
char* AplicatieManagement::getStatus() {
	return this->status;
}

void AplicatieManagement::setName(const char* name) {
	if (this->name) {
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];

	strcpy_s(this->name, strlen(name) + 1, name);


}
void AplicatieManagement::setConsumMemorieKb(int consumMemorieKb) {
	this->consumMemorieKb = consumMemorieKb;
}


void AplicatieManagement::setStatus(const char* status) {
	if (this->status) {
		delete[] this->status;
	}
	this->status = new char[strlen(status) + 1];

	strcpy_s(this->status, strlen(status) + 1, status);


}

AplicatieManagement& AplicatieManagement::operator=(const AplicatieManagement& a) {
	this->setName(a.name);
	this->setConsumMemorieKb(a.consumMemorieKb);
	this->setStatus(a.status);
	
	return *this;
}

bool AplicatieManagement::operator==(const AplicatieManagement& a) {
	return (strcmp(this->name, a.name) == 0) && (this->consumMemorieKb == a.consumMemorieKb) && (strcmp(this->status, a.status) == 0);
}
ostream& operator<<(ostream& os, const AplicatieManagement& a)
{
	os << a.name << " " << a.consumMemorieKb << " " << a.status;
	return os;
}
istream& operator>>(istream& is, AplicatieManagement& a)
{
	cout << "Dati numele: ";
	char* nume = new char[10];
	is >> nume;
	cout << "Dati consumMemorieKb: ";
	int c;
	cin >> c;
	cout << "Dati status:";
	char* status = new char[10];
	is >> status;
	a.setName(nume);
	a.setConsumMemorieKb(c);
	a.setStatus(status);
	delete[] nume;
	delete[] status;
	return is;
}



