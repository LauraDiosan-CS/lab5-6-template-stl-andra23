#pragma once
#include<ostream>
using namespace std;

class AplicatieManagement {
private:
	char* name;
	int consumMemorieKb;
	char* status;
public:
	AplicatieManagement();
	AplicatieManagement(string); //constructor de conversie
	AplicatieManagement(const char* name, int consumMemorieKb, const char* status);
	AplicatieManagement(const AplicatieManagement& a);
	~AplicatieManagement();
	char* getName();
	int getConsumMemorieKb();
	char* getStatus();
	
	void setName(const char* name);
	void setConsumMemorieKb(int consumMemorieKb);
	void setStatus(const char* status);
	AplicatieManagement& operator=(const AplicatieManagement& a);
	bool operator==(const AplicatieManagement& a);
	friend ostream& operator<<(ostream& os, const AplicatieManagement& a);
	
	friend istream& operator>>(istream&, AplicatieManagement&);


}; 
