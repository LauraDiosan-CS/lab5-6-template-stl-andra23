#pragma once
#include "Repo.h"

// DERIVED CLASS
template <class T>
class RepoFile : public Repo<T> {
public:
	RepoFile();
	~RepoFile();
	RepoFile(const char*);
	void addElem( T);
	void delElem(int);
	void updateElem(int i, T);
	void loadFromFile(const char* fileName);
	void saveToFile();
	void clearFile();
};
