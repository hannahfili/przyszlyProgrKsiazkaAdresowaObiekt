#pragma once
#include "Uzytkownik.h"
#include "Adresat.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class MetodyPomocnicze
{
public:
	static string konwerjsaIntNaString(int liczba);
	static char wczytajZnak();
	static string wczytajLinie();
	static int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
	static int konwersjaStringNaInt(string liczba);
	static string pobierzLiczbe(string tekst, int pozycjaZnaku);
	static Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
	static int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
};

