#pragma once
#include "Aplicatie.h"
#include "Repo.h"
#include "RepoFile.h"
#include "ValidareDate.h"

class Service {
private:
	Repo<AplicatieManagement> &r;
	ValidareDate v;
public:
	Service(Repo<AplicatieManagement>& repo) :r(repo) {r = repo;};
	void addAplicatieManagement(AplicatieManagement a);
	void delElem(int);
	void updateElem(int,AplicatieManagement);
	int getSize();
	map<int,AplicatieManagement> showAplicatiiManagement();
	int addInMemory(AplicatieManagement);
	int returnMemory1();
	void fromSwapInRam(int);
};
