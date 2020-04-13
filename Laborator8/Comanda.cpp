/*#include"Comanda.h"
#include"Repo.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
#include<sstream>
Comanda::Comanda() {
	//cout << "const implicit";
	this->numeClient = NULL;
	this->adresaClient = NULL;

}
Comanda::Comanda(const char* numeClient, const  char* adresaClient) {
	//cout << "constructor with param" << endl;
	this->numeClient = new char[strlen(numeClient) + 1];
	strcpy_s(this->numeClient, strlen(numeClient) + 1, numeClient);
	
	this->adresaClient = new char[strlen(adresaClient) + 1];
	strcpy_s(this->adresaClient, strlen(adresaClient) + 1, adresaClient);

}
Comanda::Comanda(const Comanda& c) {
	//cout << "copy constructor" << endl;
	this->numeClient = new char[strlen(c.numeClient) + 1];
	strcpy_s(this->numeClient, strlen(c.numeClient) + 1, c.numeClient);
	this->adresaClient = new char[strlen(c.adresaClient) + 1];
	strcpy_s(this->adresaClient, strlen(c.adresaClient) + 1, c.adresaClient);

}
Comanda::~Comanda() {
	//cout << "Destructor";
	if (this->numeClient) {
		delete[] this->numeClient;
		this->numeClient = NULL;
	}
	if (this->adresaClient) {
		delete[] this->adresaClient;
		this->adresaClient = NULL;
	}

}
char* Comanda::getNumeClient() {
	return this->numeClient;
}

char* Comanda::getAdresaClient() {
	return this->adresaClient;
}
void Comanda::setNumeClient(const char* numeClient) {
	if (this->numeClient) {
		delete[] this->numeClient;
	}
	this->numeClient = new char[strlen(numeClient) + 1];

	strcpy_s(this->numeClient, strlen(numeClient) + 1, numeClient);
}
void Comanda::setAdresaClient(const char* adresaClient) {

	if (this->adresaClient) {
		delete[] this->adresaClient;
	}
	this->adresaClient = new char[strlen(adresaClient) + 1];

	strcpy_s(this->adresaClient, strlen(adresaClient) + 1, adresaClient);
}
Comanda& Comanda::operator=(const Comanda& c) {
	this->setNumeClient(c.numeClient);
	this->setAdresaClient(c.adresaClient);
	return *this;
}
*/
