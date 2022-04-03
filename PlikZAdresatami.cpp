#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"
vector <Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika) {
    Adresat adresat;
    vector<Adresat> adresaci;
    int idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(nazwaPlikuZAdresatami.c_str(), ios::in);

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
    //cout << "dane ostatniego adresata: " << daneOstaniegoAdresataWPliku << "&& &&&&&&" << endl;
    /*if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = MetodyPomocnicze::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
        return idOstatniegoAdresata;
    }
    else
        return 0;*/
}
void PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(nazwaPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = MetodyPomocnicze::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (MetodyPomocnicze::czyPlikJestPusty(plikTekstowy) == true)
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiAdresata;
        }
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    plikTekstowy.close();
    system("pause");
}
int PlikZAdresatami::pobierzIdOstatniegoAdresata() {
    ifstream ifs;
    char c;
    int id;
    string idStr = "";

    ifs.open(nazwaPlikuZAdresatami);
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
    return id;
}