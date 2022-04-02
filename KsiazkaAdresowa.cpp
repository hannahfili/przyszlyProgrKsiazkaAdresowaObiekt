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
    idOstatniegoAdresata = adresaciManager.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
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
            /*

            wybor = wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                idOstatniegoAdresata = dodajAdresata(adresaci, idZalogowanegoUzytkownika, idOstatniegoAdresata);
                break;
            case '2':
                wyszukajAdresatowPoImieniu(adresaci);
                break;
            case '3':
                wyszukajAdresatowPoNazwisku(adresaci);
                break;
            case '4':
                wyswietlWszystkichAdresatow(adresaci);
                break;
            case '5':
                idUsunietegoAdresata = usunAdresata(adresaci);
                idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                break;
            case '6':
                edytujAdresata(adresaci);
                break;
            case '7':
                zmianaHaslaZalogowanegoUzytkownika(uzytkownicy, idZalogowanegoUzytkownika);
                break;
            case '8':
                idZalogowanegoUzytkownika = 0;
                adresaci.clear();
                break;
            }*/
        }
    }
}

