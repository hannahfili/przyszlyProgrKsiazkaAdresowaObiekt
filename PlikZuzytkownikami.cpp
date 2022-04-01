#include "PlikZuzytkownikami.h"
#include "MetodyPomocnicze.h"
PlikZuzytkownikami::PlikZuzytkownikami() {
    nazwaPlikuzUzytkownikami = "Uzytkownicy.txt";
}
void PlikZuzytkownikami::dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik) {
    string liniaZDanymiUzytkownika = "";
    plikTekstowy.open(nazwaPlikuzUzytkownikami.c_str(), ios::app);
    cout << nazwaPlikuzUzytkownikami << "!!!!!!!!!!!" << endl;
    if (plikTekstowy.good() == true)
    {
        liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownik);

        if (czyPlikJestPusty() == true)
        {
            plikTekstowy << liniaZDanymiUzytkownika;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiUzytkownika;
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << nazwaPlikuzUzytkownikami << " i zapisac w nim danych." << endl;
    plikTekstowy.close();
}
bool PlikZuzytkownikami::czyPlikJestPusty() {
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}
string PlikZuzytkownikami::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik)
{
    string liniaZDanymiUzytkownika = "";
    liniaZDanymiUzytkownika += MetodyPomocnicze::konwerjsaIntNaString(uzytkownik.pobierzId()) + '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzLogin() + '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzHaslo() + '|';

    return liniaZDanymiUzytkownika;
}
