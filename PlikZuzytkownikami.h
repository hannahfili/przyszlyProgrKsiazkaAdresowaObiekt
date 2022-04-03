#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Uzytkownik.h"

using namespace std;

class PlikZuzytkownikami
{
	const string nazwaPlikuZUzytkownikami;

	Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
	
public:
	PlikZuzytkownikami(string nazwa) : nazwaPlikuZUzytkownikami(nazwa) {}
	void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
	void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik>& uzytkownicy);
	string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
	vector <Uzytkownik> wczytajUzytkownikowZPliku();
};

