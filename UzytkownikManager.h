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
	PlikZuzytkownikami plik;

	int pobierzIdNowegoUzytkownika();
	bool czyIstniejeLogin(string login);
	Uzytkownik podajDaneNowegoUzytkownika();


public:
	void rejestracjaUzytkownika();
	int logowanieUzytkownika();
	void zmianaHaslaZalogowanegoUzytkownika(int idZalogowanegoUzytkownika);
	
	void wypiszWszystkichUzytkownikow();
	void wczytajUzytkownikowZPliku();
	UzytkownikManager(string nazwa) : plik(nazwa) {};


};

