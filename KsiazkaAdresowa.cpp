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
    idZalogowanegoUzytkownika=uzytkownikManager.logowanieUzytkownika();
}
void KsiazkaAdresowa::wczytajAdresatowZalogowanegoUzytkownikaZPliku() {
    adresaciManager.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
}
void KsiazkaAdresowa::dodajAdresata() {
    idOstatniegoAdresata = adresaciManager.dodajAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);
    //cout << "id ostatniego adresata:" << idOstatniegoAdresata << endl;
}
void KsiazkaAdresowa::pobierzIdOstatniegoAdresata() {
    idOstatniegoAdresata=adresaciManager.pobierzIdOstatniegoAdresata();
}
void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikManager.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
}
void KsiazkaAdresowa::wyloguj() {
    idZalogowanegoUzytkownika = 0;
    adresaciManager.wyczyscWektor();
}
void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {
    adresaciManager.wyswietlWszystkichAdresatow();
}
void KsiazkaAdresowa::menuGlowne(){
    char wybor;
    while (true)
    {
        if (idZalogowanegoUzytkownika == 0)
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
            wczytajAdresatowZalogowanegoUzytkownikaZPliku();
            pobierzIdOstatniegoAdresata();
            wybor = Menu::wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                dodajAdresata();
                break;
            /*case '2':
                wyszukajAdresatowPoImieniu(adresaci);
                break;
            case '3':
                wyszukajAdresatowPoNazwisku(adresaci);
                break;*/
            case '4':
                wyswietlWszystkichAdresatow();
                break;
            /*case '5':
                idUsunietegoAdresata = usunAdresata(adresaci);
                idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                break;
            case '6':
                edytujAdresata(adresaci);
                break;*/
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

