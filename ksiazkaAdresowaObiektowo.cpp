// ksiazkaAdresowaObiektowo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "KsiazkaAdresowa.h"
#include <windows.h>

using namespace std;


int main()
{
    string nazwaUzytkownicy = "Uzytkownicy6.txt";
    string nazwaAdresy = "Uzytkownicy6.txt";
    KsiazkaAdresowa ksiazkaAdresowa(nazwaUzytkownicy, nazwaAdresy);
    ksiazkaAdresowa.menuGlowne();
}

 