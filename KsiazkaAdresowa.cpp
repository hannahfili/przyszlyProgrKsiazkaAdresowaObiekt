#include "KsiazkaAdresowa.h"
#include "Menu.h"
#include "AdresaciManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

void KsiazkaAdresowa::rejestracjaUzytkownika() {
	uzytkownikManager.rejestracjaUzytkownika();
}
void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
	uzytkownikManager.wypiszWszystkichUzytkownikow();
}
void KsiazkaAdresowa::logowanieUzytkownika() {
    uzytkownikManager.logowanieUzytkownika();
    if (uzytkownikManager.czyUzytkownikJestZalogowany()) {
        adresaciManager = new AdresaciManager(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikManager.pobierzIdZalogowanegoUzytkowika());
    }
}
void KsiazkaAdresowa::dodajAdresata() {
    if(uzytkownikManager.czyUzytkownikJestZalogowany()) adresaciManager->dodajAdresata();
    else {
        cout << "Aby dodac adresata, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}
void KsiazkaAdresowa::pobierzIdOstatniegoAdresata() {
    idOstatniegoAdresata=adresaciManager->pobierzIdOstatniegoAdresata();
}
void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikManager.zmianaHaslaZalogowanegoUzytkownika();
}
bool KsiazkaAdresowa::czyUzytkownikJestZalogowany() {
    return uzytkownikManager.czyUzytkownikJestZalogowany();
}
void KsiazkaAdresowa::wyszukajAdresatowPoImieniu() {
    adresaciManager->wyszukajAdresatowPoImieniu();
}
void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku() {
    adresaciManager->wyszukajAdresatowPoNazwisku();
}
void KsiazkaAdresowa::wyloguj() {
    uzytkownikManager.wyloguj();
    delete adresaciManager;
    adresaciManager = NULL;
}
void KsiazkaAdresowa::usunAdresata() {
    adresaciManager->usunAdresata();
}
void KsiazkaAdresowa::edytujAdresata() {
    adresaciManager->edytujAdresata();
}
void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {
    adresaciManager->wyswietlWszystkichAdresatow();
}
void KsiazkaAdresowa::menuGlowne(){
    char wybor;
    while (true)
    {
        if (!czyUzytkownikJestZalogowany())
        {
            wybor = Menu::wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                rejestracjaUzytkownika();
                break;
            case '2':
                logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            wybor = Menu::wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                dodajAdresata();
                break;
            case '2':
                wyszukajAdresatowPoImieniu();
                break;
            case '3':
                wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                wyswietlWszystkichAdresatow();
                break;
            case '5':
                usunAdresata();
                break;
            case '6':
                edytujAdresata();
                break;
            case '7':
                zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                wyloguj();
                break;
            }
        }
    }
}

