#include"Repofile.h"
#include<iostream>
#include<fstream>
#include <cstddef>
#include<string>
template<class T>
RepoFile<T>::RepoFile() :Repo() {

};
template<class T>
RepoFile<T>::~RepoFile() {

};
template <class T>
RepoFile<T>::RepoFile(const char* fis) {

	loadFromFile(fis);
}
template<class T>
void RepoFile<T>::addElem(T a) {

	Repo<T>::addElem(a);
	saveToFile();
}
template <class T>
void RepoFile<T>::delElem(int i) {

	Repo<T>::delElem(i);
	saveToFile();
}
template<class T>
void RepoFile<T>::updateElem(int i,T a) {

	Repo<T>::updateElem(i, a);
	saveToFile();
}
template<class T>
void RepoFile<T>::loadFromFile(const char* fileName) {

	elem.clear();
	fis = fileName;
	ifstream f(fileName);
	char* nume = new char[100];
	int consumMemorieKb;
	char* status = new char[100];
	while (!f.eof()) {
		f >> nume >> consumMemorieKb >> status;
		if (strcmp(nume, "") != 0) {
			T a(nume, consumMemorieKb, status);
			elem.insert(pair<int, T>(key++, a));


		}
	}
	delete[] nume;
	delete[] status;
	f.close();

}
template<class T>
void RepoFile<T>::saveToFile()
{
	ofstream f(fis);
	for (auto i = elem.begin(); i != elem.end(); i++)
		f << i->second << "\n";
	f.close();
}
template<class T>
void RepoFile<T>::clearFile() {

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
