#pragma once
#include <string>

using namespace std;

class Adresat
{
    int id = 0;
    int idUzytkownika = 0;
    string imie = "";
    string nazwisko = "";
    string numerTelefonu = "";
    string email = "";
    string adres = "";
public:
    /*int pobierzIdAdresata() { return id; }
    string pobierzImie() { return imie; }
    string pobierzNazwisko() { return nazwisko; }*/
    void ustawId(int noweId) { if (noweId > 0) id = noweId; }
    void ustawIdUzytkownika(int noweId) { if (noweId > 0) idUzytkownika = noweId; }
    void ustawImie(string noweImie) { imie = noweImie; }
    void ustawNazwisko(string noweNazwisko) { nazwisko = noweNazwisko; }
    void ustawNrTel(string nowyNr) { numerTelefonu = nowyNr; }
    void ustawEmail(string nowyEmail) { email = nowyEmail; }
    void ustawAdres(string nowyAdres) { adres = nowyAdres; }


};

