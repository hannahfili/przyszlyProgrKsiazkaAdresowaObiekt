// ksiazkaAdresowaObiektowo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "KsiazkaAdresowa.h"
#include "AdresaciManager.h"
#include "PlikZAdresatami.h"
#include <windows.h>

using namespace std;


int main()
{
    string nazwaUzytkownicy = "Uzytkownicy.txt";
    string nazwaAdresy = "Adresaci.txt";
    KsiazkaAdresowa ksiazkaAdresowa(nazwaUzytkownicy, nazwaAdresy);
    ksiazkaAdresowa.menuGlowne();
    /*Adresat a(12, 18, "Alicja");
    PlikZAdresatami plik("Adresaci.txt");
    plik.zaktualizujDaneWybranegoAdresata(a);
    cout << "done";*/

}

 