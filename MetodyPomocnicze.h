#pragma once
#include "Uzytkownik.h"
#include "Adresat.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

class MetodyPomocnicze
{
public:
	static string konwersjaIntNaString(int liczba);
	static char wczytajZnak();
	static string wczytajLinie();
	static int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
	static int konwersjaStringNaInt(string liczba);
	static string pobierzLiczbe(string tekst, int pozycjaZnaku);
	static Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
	static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
	static string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
	static int podajIdWybranegoAdresata();
	static int wczytajLiczbeCalkowita();
	static void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
};

