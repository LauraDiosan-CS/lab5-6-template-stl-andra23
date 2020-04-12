#include"Repofile.h"
#include<iostream>
#include<fstream>
#include <cstddef>
#include<string>

RepoFile::RepoFile():Repo() {

};
RepoFile::~RepoFile() {

};
RepoFile::RepoFile(const char* fis) {

	loadFromFile(fis);
}

void RepoFile::addElem( AplicatieManagement a) {

	Repo::addElem(a);
	saveToFile();
}
void RepoFile::delElem(int i) {
	
	Repo::delElem(i);
	saveToFile();
}
void RepoFile::updateElem(int i, AplicatieManagement a) {

	Repo::updateElem(i, a);
	saveToFile();
}

void RepoFile::loadFromFile(const char* fileName) {
	
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
void RepoFile::saveToFile()
{
	ofstream f(fis);
	for (auto i = elem.begin(); i != elem.end(); i++)
		f << i->second << "\n";
	f.close();
}
void RepoFile::clearFile() {

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
