#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Uzytkownik.h"
#include "Adresat.h"

using namespace std;
class PlikZAdresatami
{
	const string nazwaPlikuZAdresatami;
public:
	PlikZAdresatami(string nazwa) : nazwaPlikuZAdresatami(nazwa) {};
	int wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika, vector<Adresat> &adresaci);
	void dopiszAdresataDoPliku(Adresat adresat);
};

