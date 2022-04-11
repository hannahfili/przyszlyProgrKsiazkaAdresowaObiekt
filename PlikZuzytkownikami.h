#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Uzytkownik.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZuzytkownikami : public PlikTekstowy
{
	Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
	
public:
	PlikZuzytkownikami(string nazwa) : PlikTekstowy(nazwa) {};
	void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
	void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik>& uzytkownicy);
	string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
	vector <Uzytkownik> wczytajUzytkownikowZPliku();
};

