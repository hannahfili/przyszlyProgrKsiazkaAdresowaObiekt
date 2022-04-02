// ksiazkaAdresowaObiektowo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "KsiazkaAdresowa.h"
#include <windows.h>

using namespace std;


int main()
{
    string nazwaUzytkownicy = "Uzytkownicy.txt";
    string nazwaAdresy = "Adresaci.txt";
    KsiazkaAdresowa ksiazkaAdresowa(nazwaUzytkownicy, nazwaAdresy);
    ksiazkaAdresowa.menuGlowne();
}

 