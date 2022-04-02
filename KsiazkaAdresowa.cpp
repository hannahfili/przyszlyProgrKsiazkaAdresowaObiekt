#include "KsiazkaAdresowa.h"
#include <fstream>
#include <sstream>
#include <iostream>

void KsiazkaAdresowa::rejestracjaUzytkownika() {
	uzytkownikManager.rejestracjaUzytkownika();
}
void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
	uzytkownikManager.wypiszWszystkichUzytkownikow();
}

