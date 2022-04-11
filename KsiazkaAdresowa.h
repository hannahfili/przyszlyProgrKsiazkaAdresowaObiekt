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
	AdresaciManager* adresaciManager;
	const string NAZWA_PLIKU_Z_ADRESATAMI;
	int idOstatniegoAdresata;
	bool czyUzytkownikJestZalogowany();
public:
	void rejestracjaUzytkownika();
	void logowanieUzytkownika();
	void dodajAdresata();
	void edytujAdresata();
	void wypiszWszystkichUzytkownikow();
	void menuGlowne();
	void wyloguj();
	void pobierzIdOstatniegoAdresata();
	void zmianaHaslaZalogowanegoUzytkownika();
	void wyswietlWszystkichAdresatow();
	void usunAdresata();
	void wyszukajAdresatowPoImieniu();
	void wyszukajAdresatowPoNazwisku();
	
	KsiazkaAdresowa(string nazwaPlikuUzytkownicy, string nazwaPlikuAdresaci) :
		uzytkownikManager(nazwaPlikuUzytkownicy),
		NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuAdresaci)
	{
		adresaciManager = NULL;
	};
	~KsiazkaAdresowa() {
		delete adresaciManager;
		adresaciManager = NULL;
	}
};

