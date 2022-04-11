#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Adresat.h"
#include "PlikZAdresatami.h"
class AdresaciManager
{
	const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
	vector <Adresat> adresaci;
	PlikZAdresatami plikZAdresatami;
	Adresat podajDaneNowegoAdresata();
public:
	void wyswietlWszystkichAdresatow();
	int pobierzIdOstatniegoAdresata();
	
	void dodajAdresata();
	void edytujAdresata();
	void usunAdresata();
	void wyszukajAdresatowPoImieniu();
	void wyszukajAdresatowPoNazwisku();
	void wyczyscWektor(){ adresaci.clear(); }

	AdresaciManager(string nazwaPliku, int idZalogowanegoUzytkownika) :
		plikZAdresatami(nazwaPliku), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika) {
		adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
	};

};

