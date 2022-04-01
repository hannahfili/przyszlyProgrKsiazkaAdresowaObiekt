#include "KsiazkaAdresowa.h"
#include <fstream>
#include <sstream>
#include <iostream>

KsiazkaAdresowa::KsiazkaAdresowa() {
    nazwaPlikuZUzytkownikami = "Uzytkownicy.txt";
}
void KsiazkaAdresowa::rejestracjaUzytkownika() {
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    Uzytkownicy.push_back(uzytkownik);
    dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}
Uzytkownik KsiazkaAdresowa::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    string login;
    string haslo;

    do
    {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}
int KsiazkaAdresowa::pobierzIdNowegoUzytkownika()
{
    if (Uzytkownicy.empty() == true)
        return 1;
    else
        return Uzytkownicy.back().pobierzId() + 1;
}
bool KsiazkaAdresowa::czyIstniejeLogin(string login)
{
    for (int i = 0; i < Uzytkownicy.size(); i++) {
        if (Uzytkownicy[i].pobierzLogin() == login) {
            cout << "Istnieje uzytkownik o takim loginie";
            return true;
        }
    }   
    return false;
}
void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    for (int i = 0; i < Uzytkownicy.size(); i++) {
        cout << Uzytkownicy[i].pobierzId() << endl;
        cout << Uzytkownicy[i].pobierzLogin() << endl;
        cout << Uzytkownicy[i].pobierzHaslo() << endl;
        
    }
}
void KsiazkaAdresowa::dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik) {
    fstream plikTekstowy;
    string liniaZDanymiUzytkownika = "";
    plikTekstowy.open(nazwaPlikuZUzytkownikami.c_str(), ios::app);
    cout << nazwaPlikuZUzytkownikami << "!!!!!!!!!!!" << endl;
    if (plikTekstowy.good() == true)
    {
        liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownik);

        if (czyPlikJestPusty(plikTekstowy) == true)
        {
            plikTekstowy << liniaZDanymiUzytkownika;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiUzytkownika;
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << nazwaPlikuZUzytkownikami << " i zapisac w nim danych." << endl;
    plikTekstowy.close();
}
string KsiazkaAdresowa::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik)
{
    string liniaZDanymiUzytkownika = "";

    liniaZDanymiUzytkownika += konwerjsaIntNaString(uzytkownik.pobierzId()) + '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzLogin() + '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzHaslo()+ '|';

    return liniaZDanymiUzytkownika;
}
string KsiazkaAdresowa::konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}
bool KsiazkaAdresowa::czyPlikJestPusty(fstream& plikTekstowy) {
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}
