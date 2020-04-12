#include"Repo.h"
#include<iostream>
#include<fstream>
#include <cstddef>
#include<string>
/*
template<class T>
Repo<T>::Repo() {
}
template<class T>
Repo<T>::~Repo() {
}
template< class T> Repo<T>::Repo(const char* fileName){

	fis = fileName;
	ifstream f(fileName);
	string linie;
	char* nume = new char[10];
	int consumMemorieKb;
	char* status = new char[10];
	while (!f.eof()) {
		f >> nume >> consumMemorieKb >> status;
		if (nume !="") {
			AplicatieManagement a(nume, consumMemorieKb,status);
			elem.insert({ key++,a });		
		}	
	}
	
	delete[] nume;
	delete[] status;
	f.close();
}


template<class T>
void Repo<T>::addElem(T e) {

	//elem.insert({ key++,e});
	elem.insert(pair<int,T> (key++, e));
}

template<class T>
int Repo<T>::findElem(int i) {
	
	T e;
	//map<int,T>::iterator it=elem.find(i);
	e = (elem.find(i))->second;
	int index = 0;
	for (T crt : elem) {
		index++;
		if (crt == e) return index;
	}
	return -1;
}

template<class T>
int Repo<T>::delElem(int i){
	map<int,T>::iterator itr = elem.find(i);
	if (itr != elem.end()) {
		elem.erase(itr);
		return 0;
	}
	
	return -1;	
}
template< class T>
void Repo<T>::updateElem(int it,  T nou) {
	T vechi;
	for (int i = 0; i < elem.size(); i++)
		if (i == it) {
			vechi = elem[i];
			break;
		}
	for (T e : elem) {
		if (e == vechi) {
				e = nou;
				
				return 0;
				}
			}
			return -1;
}

template<class T>
T Repo<T>::elemAtPos(int i){

	if (i < 0 || i >= elem.size())
		return T("", -1,"");
	return elem[i];
}

template<class T>
int Repo<T>::getSize() {

	return elem.size();
}
template<class T>
map<int,T> Repo<T>::getAll() {
	
	return elem;
}
*/













