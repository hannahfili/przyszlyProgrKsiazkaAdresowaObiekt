#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"
vector <Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika) {
    Adresat adresat;
    vector<Adresat> adresaci;
    int idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if (idZalogowanegoUzytkownika == MetodyPomocnicze::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = MetodyPomocnicze::pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    plikTekstowy.close();
    return adresaci;
}
void PlikZAdresatami::zaktualizujDaneWybranegoAdresata(Adresat adresat) {
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    string nazwaTymczasowegoPlikuZAdresatami = "Adresaci-tymczas.txt";
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneEdytowanegoAdresata = MetodyPomocnicze::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
    int nrOdczytanejLinii = 0;
    Adresat adresatZPliku;

    odczytywanyPlikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true && adresat.pobierzIdAdresata() != 0)
    {
        while (getline(odczytywanyPlikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            nrOdczytanejLinii++;
            adresatZPliku = MetodyPomocnicze::pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
            if (adresat.pobierzIdAdresata() != adresatZPliku.pobierzIdAdresata()) {
                if (nrOdczytanejLinii != 1) tymczasowyPlikTekstowy << endl;
                tymczasowyPlikTekstowy << daneJednegoAdresataOddzielonePionowymiKreskami;
            }
            else {
                if (nrOdczytanejLinii != 1) tymczasowyPlikTekstowy << endl;
                tymczasowyPlikTekstowy << daneEdytowanegoAdresata;
            }
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(pobierzNazwePliku());
        zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, pobierzNazwePliku());
    }
}
bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::out | ios::app);
    bool rezultat = false;

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = MetodyPomocnicze::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (czyPlikJestPusty() == true)
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiAdresata;
        }
        rezultat = true;
        idOstatniegoAdresata += 1;
    }
    else
    {
        rezultat = false;
    }
    plikTekstowy.close();
    return rezultat;
}
void PlikZAdresatami::usunAdresata(int idUsuwanegoAdresata) {
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    string nazwaTymczasowegoPlikuZAdresatami = "Adresaci-tymczas.txt";
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    int nrOdczytanejLinii = 0;
    Adresat adresat;

    odczytywanyPlikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);



    if (odczytywanyPlikTekstowy.good() == true && idUsuwanegoAdresata != 0)
    {
        while (getline(odczytywanyPlikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            nrOdczytanejLinii++;
            adresat = MetodyPomocnicze::pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
            if (idUsuwanegoAdresata != adresat.pobierzIdAdresata()) {
                if (nrOdczytanejLinii != 1) tymczasowyPlikTekstowy << endl;
                tymczasowyPlikTekstowy << daneJednegoAdresataOddzielonePionowymiKreskami;
            }
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(pobierzNazwePliku());
        zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, pobierzNazwePliku());
    }
}
void PlikZAdresatami::usunPlik(string nazwaPlikuZRozszerzeniem)
{
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}
void PlikZAdresatami::zmienNazwePliku(string staraNazwa, string nowaNazwa) {
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}
int PlikZAdresatami::pobierzIdOstatniegoAdresataZPliku() {
    ifstream ifs;
    char c;
    int id;
    string idStr = "";

    ifs.open(pobierzNazwePliku());
    if (!ifs) return 0;
    if (ifs.peek() == ifstream::traits_type::eof()) return 0;

    ifs.seekg(-1, ios::end);

    int pos = ifs.tellg();

    while (true) {
        ifs.seekg(pos);
        ifs.get(c);
        if (pos == 0) {
            while (true) {
                ifs.seekg(pos);
                ifs.get(c);
                if (c == '|') {
                    id = stoi(idStr); break;
                }
                idStr.push_back(c);
                pos++;
            }
            break;
        }
        if (char(c) == '\n') {
            ifs >> id;
            break;
        }
        pos--;
    }
    ifs.close();
    idOstatniegoAdresata = id;
    return id;
}