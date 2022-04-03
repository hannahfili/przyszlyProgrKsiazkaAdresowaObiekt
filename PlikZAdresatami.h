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
	vector<Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
	int pobierzIdOstatniegoAdresata();
	void dopiszAdresataDoPliku(Adresat adresat);
};

