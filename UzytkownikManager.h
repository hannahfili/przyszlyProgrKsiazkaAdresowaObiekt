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
	int idZalogowanegoUzytkownika;
	vector<Uzytkownik> uzytkownicy;
	PlikZuzytkownikami plik;

	int pobierzIdNowegoUzytkownika();bool czyIstniejeLogin(string login);
	bool czyIstniejeLogin();
	Uzytkownik podajDaneNowegoUzytkownika();


public:
	void rejestracjaUzytkownika();
	int logowanieUzytkownika();
	
	void wypiszWszystkichUzytkownikow();
	void wczytajUzytkownikowZPliku();

};

