#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Uzytkownik.h"
#include "UzytkownikManager.h"

using namespace std;

class KsiazkaAdresowa
{
	UzytkownikManager uzytkownikManager;
public:
	void rejestracjaUzytkownika();
	void wypiszWszystkichUzytkownikow();
	KsiazkaAdresowa(string nazwaPliku) :uzytkownikManager(nazwaPliku) {
		uzytkownikManager.wczytajUzytkownikowZPliku();
};
};

