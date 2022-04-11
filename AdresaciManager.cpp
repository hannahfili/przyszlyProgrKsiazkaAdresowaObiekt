#include "AdresaciManager.h"
#include "MetodyPomocnicze.h"
#include "Menu.h"
void AdresaciManager::wyswietlWszystkichAdresatow() {
	system("cls");
	if (!adresaci.empty())
	{
		cout << "             >>> ADRESACI <<<" << endl;
		cout << "-----------------------------------------------" << endl;
		for (vector <Adresat> ::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
		{
			(*itr).wyswietlDaneAdresata();
		}
		cout << endl;
	}
	else
	{
		cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
	}
	system("pause");
}
void AdresaciManager::wyszukajAdresatowPoImieniu() {
	string imiePoszukiwanegoAdresata = "";
	int iloscAdresatow = 0;

	system("cls");
	if (!adresaci.empty())
	{
		cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

		cout << "Wyszukaj adresatow o imieniu: ";
		imiePoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
		imiePoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

		for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
		{
			if (itr->pobierzImie() == imiePoszukiwanegoAdresata)
			{
				itr->wyswietlDaneAdresata();
				iloscAdresatow++;
			}
		}
		MetodyPomocnicze::wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
	}
	else
	{
		cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
	}
	cout << endl;
	system("pause");
}
void AdresaciManager::wyszukajAdresatowPoNazwisku() {
	string nazwiskoPoszukiwanegoAdresata;
	int iloscAdresatow = 0;

	system("cls");
	if (!adresaci.empty())
	{
		cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

		cout << "Wyszukaj adresatow o nazwisku: ";
		nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
		nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

		for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
		{
			if (itr->pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata)
			{
				itr->wyswietlDaneAdresata();
				iloscAdresatow++;
			}
		}
		MetodyPomocnicze::wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
	}
	else
	{
		cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
	}
	cout << endl;
	system("pause");
}
void AdresaciManager::dodajAdresata() {
	Adresat adresat;

	system("cls");
	cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
	adresat = podajDaneNowegoAdresata();

	adresaci.push_back(adresat);
	if (plikZAdresatami.dopiszAdresataDoPliku(adresat)) {
		cout << "Nowy adresat zostal dodany" << endl;
	}
	else {
		cout << "Blad. Nie udalo sie dodac nowego adresata do pliku" << endl;
	}
	system("pause");

}
void AdresaciManager::edytujAdresata()
{
	system("cls");
	Adresat adresat;
	int idEdytowanegoAdresata = 0;
	int numerLiniiEdytowanegoAdresata = 0;
	string liniaZDanymiAdresata = "";

	cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
	idEdytowanegoAdresata = MetodyPomocnicze::podajIdWybranegoAdresata();

	char wybor;
	bool czyIstniejeAdresat = false;

	for (int i = 0; i < adresaci.size(); i++)
	{
		if (adresaci[i].pobierzIdAdresata() == idEdytowanegoAdresata)
		{
			czyIstniejeAdresat = true;
			wybor = Menu::wybierzOpcjeZMenuEdycja();

			switch (wybor)
			{
			case '1':
				cout << "Podaj nowe imie: ";
				adresaci[i].ustawImie(MetodyPomocnicze::wczytajLinie());
				adresaci[i].ustawImie (MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].pobierzImie()));
				plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
				break;
			case '2':
				cout << "Podaj nowe nazwisko: ";
				adresaci[i].ustawNazwisko(MetodyPomocnicze::wczytajLinie());
				adresaci[i].ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].pobierzNazwisko()));
				plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
				break;
			case '3':
				cout << "Podaj nowy numer telefonu: ";
				adresaci[i].ustawNrTel(MetodyPomocnicze::wczytajLinie());
				plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
				break;
			case '4':
				cout << "Podaj nowy email: ";
				adresaci[i].ustawEmail(MetodyPomocnicze::wczytajLinie());
				plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
				break;
			case '5':
				cout << "Podaj nowy adres zamieszkania: ";
				adresaci[i].ustawAdres(MetodyPomocnicze::wczytajLinie());
				plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
				break;
			case '6':
				cout << endl << "Powrot do menu uzytkownika" << endl << endl;
				break;
			default:
				cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
				break;
			}
		}
	}
	if (czyIstniejeAdresat == false)
	{
		cout << endl << "Nie ma takiego adresata." << endl << endl;
	}
	system("pause");
}
void AdresaciManager::usunAdresata() {
	int idUsuwanegoAdresata = 0;
	int numerLiniiUsuwanegoAdresata = 0;

	system("cls");
	cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
	wyswietlWszystkichAdresatow();
	idUsuwanegoAdresata = MetodyPomocnicze::podajIdWybranegoAdresata();

	char znak;
	bool czyIstniejeAdresat = false;

	for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
	{
		if (itr->pobierzIdAdresata() == idUsuwanegoAdresata)
		{
			czyIstniejeAdresat = true;
			cout << endl << "Potwierdz naciskajac klawisz 't': ";
			znak = MetodyPomocnicze::wczytajZnak();
			if (znak == 't')
			{
				plikZAdresatami.usunAdresata(idUsuwanegoAdresata);
				adresaci.erase(itr);
				cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
				system("pause");
			}
			else
			{
				cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
				system("pause");
			}
			break;
		}
	}
	if (czyIstniejeAdresat == false)
	{
		cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
		system("pause");
	}	
	/*cout << "wszystko ok " << endl;
	system("pause");*/
	plikZAdresatami.usunAdresata(idUsuwanegoAdresata);
}
int AdresaciManager::pobierzIdOstatniegoAdresata() {
	return plikZAdresatami.pobierzIdOstatniegoAdresataZPliku();
}
Adresat AdresaciManager::podajDaneNowegoAdresata()
{
	Adresat adresat;

	adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresataZeZmiennej() + 1);
	adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

	cout << "Podaj imie: ";
	adresat.ustawImie(MetodyPomocnicze::wczytajLinie());
	adresat.ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie()));

	cout << "Podaj nazwisko: ";
	adresat.ustawNazwisko(MetodyPomocnicze::wczytajLinie());
	adresat.ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko()));

	cout << "Podaj numer telefonu: ";
	adresat.ustawNrTel(MetodyPomocnicze::wczytajLinie());

	cout << "Podaj email: ";
	adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());

	cout << "Podaj adres: ";
	adresat.ustawAdres(MetodyPomocnicze::wczytajLinie());

	return adresat;
}
