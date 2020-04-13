#pragma once
#include "Comanda.h"
#include<vector>
class Mancare : public Comanda {
private:
	vector<char> listaPreparate;
public:
	Mancare();
	~Mancare();
   
};
