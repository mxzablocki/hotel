#ifndef BAZADANYCH_H
#define BAZADANYCH_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "BazaLogow.h"
#include "Klienci.h"
#include "Pokoje.h"
#include "Rezerwacje.h"
#include "Uzytkownicy.h"

using namespace std; // cos z ta przestrzenia nazwa trzeba zrobic, bo nie powinny byc w naglowkach

class BazaDanych
{
public:
	void zapiszDane();
	void pobranieWartoscizTabel(std::ifstream &klienci, std::ifstream &pokoje, std::ifstream &rezerwacje, std::ifstream &uzytkownicy, std::ifstream &logi);
	void otwarcieBazy();
	void otwarcieConfig();
	BazaDanych();
	~BazaDanych();
	std::string** rozszezenieTablicy(std::string** tab,int wielkoscX, int wielkoscY);
	//zwraca ilosc danych i zapisuje dane w zmiennej dane
	int select(std::string bazaDanych, std::string** &dane);
	std::string* select(std::string BazaDanych, int id);
	int szukajID(std::string bazaDanych);
	void modyfy(std::string bazaDanych, int ID, std::string dane[]);
	int remove(std::string bazaDanych, int ID);
	//przyjmuje tablice danych o rozmiaze wyszyskich pol tablicy(lacznie z id) ID nie musi byc podawane
	void insert(std::string bazaDanych, std::string* dane);
	//void sortTable(std::string bazaDanych);
private:
	//sciezki do polaczenia z plikami
	std::string nazwaTabeliLogow;
	std::string nazwaTabeliKlientow;
	std::string nazwaTabeliPokoi;
	std::string nazwaTabeliRezerwacji;
	std::string nazwaTabeliUzytkownikow;

	std::vector<BazaLogow*> tabelaLogow;
	std::vector<Klienci*> tabelaKlientow;
	std::vector<Pokoje*> tabelaPokojow;
	std::vector<Rezerwacje*> tabelaRezerwacji;
	std::vector<Uzytkownicy*> tabelaUzytkownikow;
};

#endif // BAZADANYCH_H
