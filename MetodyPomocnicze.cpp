#include "MetodyPomocnicze.h"
#include "Adresat.h"

string MetodyPomocnicze::konwersjaIntNaString(int liczba)
{
	ostringstream ss;
	ss << liczba;
	string str = ss.str();
	return str;
}
void MetodyPomocnicze::wyswietlIloscWyszukanychAdresatow(int iloscAdresatow)
{
	if (iloscAdresatow == 0)
		cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
	else
		cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}
string MetodyPomocnicze::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat)
{
	string liniaZDanymiAdresata = "";

	liniaZDanymiAdresata += konwersjaIntNaString(adresat.pobierzIdAdresata()) + '|';
	liniaZDanymiAdresata += konwersjaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
	liniaZDanymiAdresata += adresat.pobierzImie() + '|';
	liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
	liniaZDanymiAdresata += adresat.pobierzNrTel() + '|';
	liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
	liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

	return liniaZDanymiAdresata;
}
string MetodyPomocnicze::wczytajLinie() {
	string wejscie = "";
	getline(cin, wejscie);
	return wejscie;
}
char MetodyPomocnicze::wczytajZnak()
{
	string wejscie = "";
	char znak = { 0 };

	while (true)
	{
		getline(cin, wejscie);

		if (wejscie.length() == 1)
		{
			znak = wejscie[0];
			break;
		}
		cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
	}
	return znak;
}
int MetodyPomocnicze::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
	int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
	int idUzytkownika = -1;

	string kawalek = "";

	for (int i = pozycjaRozpoczeciaIdUzytkownika; i < daneJednegoAdresataOddzielonePionowymiKreskami.size(); i++) {
		if (daneJednegoAdresataOddzielonePionowymiKreskami[i] != '|') {
			kawalek += daneJednegoAdresataOddzielonePionowymiKreskami[i];
		}
		else {
			idUzytkownika = atoi(kawalek.c_str());
			break;
		}
	}

	return idUzytkownika;
}
int MetodyPomocnicze::podajIdWybranegoAdresata() {
	int idWybranegoAdresata = 0;
	cout << "Podaj numer ID Adresata: ";
	idWybranegoAdresata = wczytajLiczbeCalkowita();
	return idWybranegoAdresata;
}
int MetodyPomocnicze::wczytajLiczbeCalkowita()
{
	string wejscie = "";
	int liczba = 0;

	while (true)
	{
		getline(cin, wejscie);

		stringstream myStream(wejscie);
		if (myStream >> liczba)
			break;
		cout << "To nie jest liczba. Wpisz ponownie. " << endl;
	}
	return liczba;
}


int MetodyPomocnicze::konwersjaStringNaInt(string liczba)
{
	int liczbaInt;
	istringstream iss(liczba);
	iss >> liczbaInt;

	return liczbaInt;
}
string MetodyPomocnicze::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
	string liczba = "";

	for (int i = 0; i < tekst.length(); i++) {
		if (isdigit(tekst[i]) == 1) {
			liczba += tekst[i];
		}
		else break;
	}
	return liczba;
}
Adresat MetodyPomocnicze::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
	Adresat adresat;
	string pojedynczaDanaAdresata = "";
	int numerPojedynczejDanejAdresata = 1;

	for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
	{
		if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
		{
			pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
		}
		else
		{
			switch (numerPojedynczejDanejAdresata)
			{
			case 1:
				adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
				break;
			case 2:
				adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
				break;
			case 3:
				adresat.ustawImie(pojedynczaDanaAdresata);
				break;
			case 4:
				adresat.ustawNazwisko(pojedynczaDanaAdresata);
				break;
			case 5:
				adresat.ustawNrTel(pojedynczaDanaAdresata);
				break;
			case 6:
				adresat.ustawEmail(pojedynczaDanaAdresata);
				break;
			case 7:
				adresat.ustawAdres(pojedynczaDanaAdresata);
				break;
			}
			pojedynczaDanaAdresata = "";
			numerPojedynczejDanejAdresata++;
		}
	}
	return adresat;
}
string MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
	if (!tekst.empty())
	{
		transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
		tekst[0] = toupper(tekst[0]);
	}
	return tekst;
}