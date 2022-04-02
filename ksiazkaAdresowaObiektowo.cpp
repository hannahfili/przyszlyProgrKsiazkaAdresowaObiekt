// ksiazkaAdresowaObiektowo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "KsiazkaAdresowa.h"
#include <windows.h>

using namespace std;


int main()
{
    string nazwa = "Uzytkownicy6.txt";
    KsiazkaAdresowa ksiazkaAdresowa(nazwa);
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.rejestracjaUzytkownika();

    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
}

 