#pragma once
#include <string>
#include <iostream>
using namespace std;

class Adresat
{
    int id;
    int idUzytkownika;
    string imie;
    string nazwisko;
    string numerTelefonu;
    string email;
    string adres;
public:
    int pobierzIdAdresata() { return id; }
    int pobierzIdUzytkownika() { return idUzytkownika; }
    string pobierzImie() { return imie; }
    string pobierzNazwisko() { return nazwisko; }
    string pobierzNrTel() { return numerTelefonu; }
    string pobierzEmail() { return email; }
    string pobierzAdres() { return adres; }



    void ustawId(int noweId) { if (noweId > 0) id = noweId; }
    void ustawIdUzytkownika(int noweId) { if (noweId > 0) idUzytkownika = noweId; }
    void ustawImie(string noweImie) { imie = noweImie; }
    void ustawNazwisko(string noweNazwisko) { nazwisko = noweNazwisko; }
    void ustawNrTel(string nowyNr) { numerTelefonu = nowyNr; }
    void ustawEmail(string nowyEmail) { email = nowyEmail; }
    void ustawAdres(string nowyAdres) { adres = nowyAdres; }

    void wyswietlDaneAdresata();

    Adresat(int id = 0, int idUzytkownika = 0, string imie = "", string nazwisko = "", string numerTelefonu = "",
        string email = "", string adres = "") {
        this->id = id;
        this->idUzytkownika = idUzytkownika;
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->numerTelefonu = numerTelefonu;
        this->email = email;
        this->adres = adres;
    }

};

