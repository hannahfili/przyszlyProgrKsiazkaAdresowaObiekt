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
	string nazwaPlikuZUzytkownikami;
	bool czyPlikJestPusty();

	Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
	
public:
	PlikZuzytkownikami();
	void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
	string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
	vector <Uzytkownik> wczytajUzytkownikowZPliku();
};

