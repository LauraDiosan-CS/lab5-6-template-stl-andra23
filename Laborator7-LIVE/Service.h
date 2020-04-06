#pragma once
#pragma once
#include "Aplicatie.h"
#include "Repo.h"
#include "ValidareDate.h"
#include<stack>
class Service {
private:
	Repo<AplicatieManagement>r;
	ValidareDate v;
	int  Memorie = 12000;
	
public:
	Service();
	Service(const Repo<AplicatieManagement>&);
	void setRepo(const Repo<AplicatieManagement>&);
	void addAplicatieManagement(AplicatieManagement a);
	void delElem(int);
	void updateElem(int,char*,int,char*);
	int getSize();
	map<int,AplicatieManagement> showAplicatiiManagement();
	bool findOne(int i);
	void initService();
	int VerificareMemorie(AplicatieManagement);
	int AdaugareLaRam(AplicatieManagement);
	int adaugare(AplicatieManagement a);
	int memorie();
	





};
