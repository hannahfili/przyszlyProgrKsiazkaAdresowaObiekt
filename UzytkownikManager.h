#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Uzytkownik.h"
#include "PlikZuzytkownikami.h"

using namespace std;

class UzytkownikManager
{
	vector<Uzytkownik> uzytkownicy;
	PlikZuzytkownikami plikZUzytkownikami;
	int idZalogowanegoUzytkownika;

	int pobierzIdNowegoUzytkownika();
	bool czyIstniejeLogin(string login);
	Uzytkownik podajDaneNowegoUzytkownika();
	


public:
	void rejestracjaUzytkownika();
	void logowanieUzytkownika();
	void wyloguj();
	void zmianaHaslaZalogowanegoUzytkownika();
	int pobierzIdZalogowanegoUzytkowika() { return idZalogowanegoUzytkownika; }
	bool czyUzytkownikJestZalogowany() { 
		if (idZalogowanegoUzytkownika > 0) return true; return false; }
	
	void wypiszWszystkichUzytkownikow();
	UzytkownikManager(string nazwa) : plikZUzytkownikami(nazwa) {
		uzytkownicy=plikZUzytkownikami.wczytajUzytkownikowZPliku();
		idZalogowanegoUzytkownika = 0;
	};


};

