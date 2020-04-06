#include "UI.h"
#include<iostream>
using namespace std;

void UI::display() {
	std::cout << "\n";
	std::cout << "********** Main Menu **********" << std::endl;
	std::cout << "Alegeti o optiune: " << std::endl;
	std::cout << "(1): Adaugare aplicatie." << std::endl;
	std::cout << "(2): Afisare aplicatie." << std::endl;
	std::cout << "(3):Stergere aplicatie. " << std::endl;
	std::cout << "(4):Modificare aplicatie. " << std::endl;
	std::cout << "(5): " << std::endl;
	std::cout << "(6): " << std::endl;
	std::cout << "(7): " << std::endl;
	std::cout << "(8): " << std::endl;
	std::cout << "(9): Exit." << std::endl;
}
void UI::PrintMenu()
{
	s.initService();
	char name[10];
	int consumMemorieKb = {};
	char status[10];
	int opt;

	do {
		display();
		while (true) {

			cin >> opt;
			if (opt == 1) {
				try {
					cout << "\n Introduceti numele: ";
					cin >> name;
					cout << " Introduceti consum memorie (kb): ";
					cin >> consumMemorieKb;
					cout << " Introduceti status( ram, swap):  ";
					cin >> status;
					cout << endl;
					AplicatieManagement a(name, consumMemorieKb, status);
					cout << s.memorie();
					if(s.VerificareMemorie(a)==0)
						throw std::exception("Consumul de Memorie depasteste memoria ram.");
					else
						if (s.AdaugareLaRam(a) == 0) {
							a.setStatus("ram");
							s.addAplicatieManagement(a);
						}
						else {
							if (s.adaugare(a) == 0) {
								s.addAplicatieManagement(a);
							}
							else cout << "Nu s a putut adauga.";
						}
					  
					break;
				}
				catch (exception e) { cout << "An exception occurred." << "->"; cout << e.what();  }
				cout << "\n";
			}
			if (opt == 2) {
				map<int, AplicatieManagement> element;
				element = s.showAplicatiiManagement();
		
				for (auto i=element.begin(); i != element.end(); i++)
				{  
					cout << "Aplicatia" <<" "<<(i->first)<<"\n";
					cout <<" \n";
					cout <<"Nume: " <<( i->second).getName() << endl;
					cout <<"ConsumMemorieKb: " << (i->second).getConsumMemorieKb() << endl;
					cout <<"Status: " << (i->second).getStatus() << endl;
					cout << "-------------------------------" << endl;
	
				}
				
				break;
			}
			if (opt == 3)
			{
				int key;
				cout << "Dati cheia elementului pe care doriti sa il stergeti: ";
				cin >> key;
				s.delElem(key);
				break;
			}

			if (opt == 4)
			{
				int key;
				cout << "Dati cheia elementului pe care doriti sa il modificati: ";
				cin >> key;
				cout << "Update aplicatie: \n";
				cout << "\n Nume: ";
				cin >> name;
				cout << " ConsumMemorieKb: ";
				cin >> consumMemorieKb;
				cout << " Status: ";
				cin >> status;
				cout << endl;
				s.updateElem(key,name,consumMemorieKb,status);
				break;
			}
			if (opt == 5) {
				
			
				break;
			}
			if (opt == 6)
			{
				
				break;
			}
			if (opt == 7) {

				break;
				
			}
			if (opt == 8) {

				break;

			}
			if (opt == 9) {
				cout << "Exit.";
				exit(0);
			}

			if (opt != 1 && opt != 2 && opt != 3 && opt != 4 && opt != 5 && opt != 6 && opt != 7 && opt != 8 && opt != 9) {
				cout << "ERROR!You have selected an invalid choice.";
				break;

			}


		}

	} while (opt != 9);
}



