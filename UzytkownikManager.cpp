#include "UzytkownikManager.h"
void UzytkownikManager::rejestracjaUzytkownika() {
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    Uzytkownicy.push_back(uzytkownik);
    plik.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}
Uzytkownik UzytkownikManager::podajDaneNowegoUzytkownika()
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
int UzytkownikManager::pobierzIdNowegoUzytkownika()
{
    if (Uzytkownicy.empty() == true)
        return 1;
    else
        return Uzytkownicy.back().pobierzId() + 1;
}
bool UzytkownikManager::czyIstniejeLogin(string login)
{
    for (int i = 0; i < Uzytkownicy.size(); i++) {
        if (Uzytkownicy[i].pobierzLogin() == login) {
            cout << "Istnieje uzytkownik o takim loginie";
            return true;
        }
    }
    return false;
}
void UzytkownikManager::wypiszWszystkichUzytkownikow() {
    for (int i = 0; i < Uzytkownicy.size(); i++) {
        cout << Uzytkownicy[i].pobierzId() << endl;
        cout << Uzytkownicy[i].pobierzLogin() << endl;
        cout << Uzytkownicy[i].pobierzHaslo() << endl;

    }
}
