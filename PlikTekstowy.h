#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;
class PlikTekstowy
{
	const string NAZWA_PLIKU;

public:
	
	PlikTekstowy(string nazwa) : NAZWA_PLIKU(nazwa) { };

    string pobierzNazwePliku();
	bool czyPlikJestPusty();    

};

