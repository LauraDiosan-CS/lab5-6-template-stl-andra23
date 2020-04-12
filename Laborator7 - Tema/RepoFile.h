#pragma once
#include "Repo.h"

// DERIVED CLASS
class RepoFile : public Repo<AplicatieManagement> {
public:
	RepoFile();
	~RepoFile();
	RepoFile( const char*);
	void addElem(AplicatieManagement);
	void delElem(int);
	void updateElem(int i, const AplicatieManagement);
	void loadFromFile(const char* fileName);
	void saveToFile();
	void clearFile();
};

