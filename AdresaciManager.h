#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Adresat.h"
#include "PlikZAdresatami.h"
class AdresaciManager
{
	vector <Adresat> adresaci;
	PlikZAdresatami plikZAdresatami;
	Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
public:
	void wyswietlWszystkichAdresatow();
	int pobierzIdOstatniegoAdresata();
	void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
	AdresaciManager(string nazwaPliku) : plikZAdresatami(nazwaPliku) {};
	int dodajAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
	void wyczyscWektor(){ adresaci.clear(); }

};

