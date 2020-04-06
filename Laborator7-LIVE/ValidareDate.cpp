#include"Aplicatie.h";
#include"ValidareDate.h"
#include "Repo.h"
#include<iostream>
using namespace std;


void ValidareDate::validareDate(AplicatieManagement a) {

	if (a.getConsumMemorieKb() < 0)
	{
		throw std::exception("Consumul de Memorie trebuie sa fie strict pozitiv.");	
	}

	if (strcmp(a.getStatus(), "ram") != 0 && strcmp(a.getStatus(),"swap") != 0)
	{
		throw std::exception(" Statusul trebuie sa fie unul dintre [ ram, swap].");
	}
	
	

}

