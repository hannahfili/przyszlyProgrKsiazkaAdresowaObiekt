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
	string nazwaPlikuzUzytkownikami;
	fstream plikTekstowy;
	bool czyPlikJestPusty();
	
public:
	PlikZuzytkownikami();
	void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
	string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
};

