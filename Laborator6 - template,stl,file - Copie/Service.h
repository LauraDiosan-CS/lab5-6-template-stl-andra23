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
	





};
