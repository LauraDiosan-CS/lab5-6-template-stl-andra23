#pragma once
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
#include<sstream>
class Comanda {
protected:
	char* numeClient;
	char* adresaClient;
	float pretTotal;
private:
	Comanda();
	Comanda(const char* numeClient, const char* adresaClient, float pretTotal);
	Comanda(const Comanda& c);
    virtual ~Comanda();
	virtual char* getNumeClient();
	virtual char* getAdresaClient();
	virtual float getPretTotal();
	virtual void setNumeClient(const char* numeClient);
	virtual void setAdresaClient(const char* adresaClient);
	virtual void setPretTotal(float pretTotal);
	Comanda& operator=(const Comanda& c);
};
Comanda::Comanda() {
	//cout << "const implicit";
	this->numeClient = NULL;
	this->adresaClient = NULL;
	this->pretTotal = 0;

}
Comanda::Comanda(const char* numeClient, const  char* adresaClient, float pretTotal) {
	//cout << "constructor with param" << endl;
	this->numeClient = new char[strlen(numeClient) + 1];
	strcpy_s(this->numeClient, strlen(numeClient) + 1, numeClient);

	this->adresaClient = new char[strlen(adresaClient) + 1];
	strcpy_s(this->adresaClient, strlen(adresaClient) + 1, adresaClient);

	this->pretTotal = pretTotal;
}
Comanda::Comanda(const Comanda& c) {
	//cout << "copy constructor" << endl;
	this->numeClient = new char[strlen(c.numeClient) + 1];
	strcpy_s(this->numeClient, strlen(c.numeClient) + 1, c.numeClient);
	this->adresaClient = new char[strlen(c.adresaClient) + 1];
	strcpy_s(this->adresaClient, strlen(c.adresaClient) + 1, c.adresaClient);
	this->pretTotal = c.pretTotal;

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
	this->pretTotal = 0;

}
char* Comanda::getNumeClient() {
	return this->numeClient;
}

char* Comanda::getAdresaClient() {
	return this->adresaClient;
}
float Comanda::getPretTotal() {
	return this->pretTotal;
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
void Comanda::setPretTotal(float pretTotal) {
	this->pretTotal = pretTotal;
}

Comanda& Comanda::operator=(const Comanda& c) {
	this->setNumeClient(c.numeClient);
	this->setAdresaClient(c.adresaClient);
	this->setPretTotal(c.pretTotal);
	return *this;
}

