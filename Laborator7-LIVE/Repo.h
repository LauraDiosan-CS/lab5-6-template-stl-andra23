#pragma once
#include "Aplicatie.h"
#include<map>
template<class AplicatieManagement>
class Repo {
private:
	const char* fis;
	map<int, AplicatieManagement> elem = {};
	int key=0;
public:
	Repo(const char* fileName);
	void loadFromFile(const char* fileName);
	Repo();
	~Repo();
	void addAplicatieManagement(AplicatieManagement);
	int findElem(int);
	int delElem(int );
	void updateElem(int , char*, int, char*);
	AplicatieManagement elemAtPos(int i);
	void saveToFile();
	int getSize();
	map<int,AplicatieManagement> getAll(); 
	void clearFile();
};
