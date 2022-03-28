#pragma once
#include <iostream>
#include <vector>
#include "Uzytkownik.h"

using namespace std;

class KsiazkaAdresowa
{
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;

    vector<Uzytkownik> Uzytkownicy;

public: 
    void rejestracjaUzytkownika();
};

