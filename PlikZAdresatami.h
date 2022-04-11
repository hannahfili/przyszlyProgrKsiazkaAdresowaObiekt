#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Uzytkownik.h"
#include "Adresat.h"
#include "PlikTekstowy.h"
using namespace std;
class PlikZAdresatami : public PlikTekstowy
{
	int idOstatniegoAdresata;
public:
	PlikZAdresatami(string nazwa) : PlikTekstowy(nazwa) {
		idOstatniegoAdresata = pobierzIdOstatniegoAdresataZPliku();
	};
	vector<Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
	int pobierzIdOstatniegoAdresataZPliku();
	bool dopiszAdresataDoPliku(Adresat adresat);
	void zaktualizujDaneWybranegoAdresata(Adresat adresat);
	int pobierzIdOstatniegoAdresataZeZmiennej() { return idOstatniegoAdresata; };
	void usunAdresata(int idUsuwanegoAdresata);
	void usunPlik(string nazwaPliku);
	void zmienNazwePliku(string staraNazwa, string nowaNazwa);
};

