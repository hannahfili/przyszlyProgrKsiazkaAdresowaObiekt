// ksiazkaAdresowaObiektowo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "KsiazkaAdresowa.h"
#include <windows.h>

using namespace std;


int main()
{
    KsiazkaAdresowa ksiazkaAdresowa;
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
}

 