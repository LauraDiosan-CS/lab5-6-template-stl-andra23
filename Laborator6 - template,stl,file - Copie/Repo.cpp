#include"Repo.h"
#include<iostream>
#include<fstream>
#include <cstddef>
#include<string>

Repo<AplicatieManagement>::Repo() {
}
Repo<AplicatieManagement>::~Repo() {
}

Repo<AplicatieManagement>::Repo(const char* fileName){

	fis = fileName;
	ifstream f(fileName);
	string linie;
	char* nume = new char[10];
	int consumMemorieKb;
	char* status = new char[10];
	while (!f.eof()) {
		f >> nume >> consumMemorieKb>>status;
	
		if (nume !="") {
			AplicatieManagement a(nume, consumMemorieKb,status);
			
			elem.insert({ key++,a });		
		}	
	}
	
	delete[] nume;
	delete[] status;
	f.close();
}


void Repo<AplicatieManagement>::loadFromFile(const char* fileName){

	
	elem.clear();
	fis = fileName;
	ifstream f(fileName);
	char* nume = new char[100];
	int consumMemorieKb;
	char* status = new char[100];
	while (!f.eof()) {
		f >> nume >> consumMemorieKb >> status;
		if (strcmp(nume, "") != 0) {
			AplicatieManagement a(nume, consumMemorieKb, status);
			elem.insert(pair<int, AplicatieManagement>(key++, a));	
		}		
		}
	delete[] nume;
	delete[] status;
	f.close();
	
}
void Repo<AplicatieManagement>::addAplicatieManagement(AplicatieManagement a) {

	//elem.insert({ key++,a });
	elem.insert(pair<int, AplicatieManagement>(key++, a));
	saveToFile();
}

int Repo<AplicatieManagement>::findElem(int i) {

	map<int,AplicatieManagement>::iterator it;
	it = elem.find(i);
	if (it != elem.end()) {
		return distance(elem.begin(), it);
	}
	return -1;
}

int Repo<AplicatieManagement>::delElem(int i){

	map<int, AplicatieManagement> ::iterator itr = elem.find(i);
	if (itr != elem.end()) {
		elem.erase(itr);
		saveToFile();
		
		return 0;
	}
	
	return -1;
	
	//elem.erase(i);
	//saveToFile();
	//return 0;
	
}
void Repo<AplicatieManagement>::updateElem(int it, char* nume, int consumMemorieKb,char* status) {

	for (int i = 0; i <elem.size(); i++)
		if (i == it)
		{
			elem[i].setName(nume);
			elem[i].setConsumMemorieKb(consumMemorieKb);
			elem[i].setStatus(status);
			saveToFile();
			return;
		}
}

AplicatieManagement Repo<AplicatieManagement>::elemAtPos(int i){

	if (i < 0 || i >= elem.size())
		return AplicatieManagement("", -1,"");
	return elem[i];
}

template<class AplicatieManagement> void Repo<AplicatieManagement>::saveToFile()
{
	ofstream f(fis);
	for (auto i = elem.begin(); i != elem.end(); i++)
		f << i->second<<"\n";
	f.close();
}
int Repo<AplicatieManagement>::getSize() {

	return elem.size();
}
map<int,AplicatieManagement> Repo<AplicatieManagement>::getAll() {
	
	return elem;
}
void Repo<AplicatieManagement>:: clearFile(){

	std::ifstream File;
	std::string filepath = "Teste.txt";
	File.open(filepath.c_str(), std::ifstream::out | std::ifstream::trunc);
	if (!File.is_open() || File.fail())
	{
		File.close();
		printf("\nError : failed to erase file content !");
	}
	File.close();
}













