#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Uzytkownik.h"
#include "UzytkownikManager.h"
#include "AdresaciManager.h"

using namespace std;

class KsiazkaAdresowa
{
	UzytkownikManager uzytkownikManager;
	AdresaciManager adresaciManager;
	int idZalogowanegoUzytkownika;
	int idOstatniegoAdresata;
public:
	void rejestracjaUzytkownika();
	void logowanieUzytkownika();
	void dodajAdresata();
	void wypiszWszystkichUzytkownikow();
	void menuGlowne();
	void wyloguj();
	void pobierzIdOstatniegoAdresata();
	void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
	void zmianaHaslaZalogowanegoUzytkownika();
	KsiazkaAdresowa(string nazwaPlikuUzytkownicy, string nazwaPlikuAdresaci) :
		uzytkownikManager(nazwaPlikuUzytkownicy),
		adresaciManager(nazwaPlikuAdresaci),
		idZalogowanegoUzytkownika(0) {
		uzytkownikManager.wczytajUzytkownikowZPliku();
};
};

