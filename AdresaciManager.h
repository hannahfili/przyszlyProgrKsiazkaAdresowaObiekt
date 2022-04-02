#pragma once
#include <vector>
#include "Adresat.h"
#include "PlikZAdresatami.h"
class AdresaciManager
{
	vector <Adresat> adresaci;
	PlikZAdresatami plikZAdresatami;
public:
	int wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
	AdresaciManager(string nazwaPliku) : plikZAdresatami(nazwaPliku) {};
};

