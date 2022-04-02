#include "KsiazkaAdresowa.h"
#include <fstream>
#include <sstream>
#include <iostream>

KsiazkaAdresowa::KsiazkaAdresowa() {
	uzytkownikManager.wczytajUzytkownikowZPliku();
}
void KsiazkaAdresowa::rejestracjaUzytkownika() {
	uzytkownikManager.rejestracjaUzytkownika();
}
void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
	uzytkownikManager.wypiszWszystkichUzytkownikow();
}

