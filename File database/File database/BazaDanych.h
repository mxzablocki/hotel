#pragma once
#include <iostream>
#include "BazaLogow.h"
#include "Klienci.h"
#include "Pokoje.h"
#include "Rezerwacje.h"
#include "Uzytkownicy.h"
#include <vector>
#include <algorithm>
using namespace std;
class BazaDanych
{
public:
	void zapiszDane();
	void pobranieWartoscizTabel(ifstream &klienci, ifstream &pokoje, ifstream &rezerwacje, ifstream &uzytkownicy, ifstream &logi);
	void otwarcieBazy();
	void otwarcieConfig();
	BazaDanych();
	~BazaDanych();
	string** rozszezenieTablicy(string** tab,int wielkoscX, int wielkoscY);
	//zwraca ilosc danych i zapisuje dane w zmiennej dane
	int select(string bazaDanych, string** &dane);
	string* select(string BazaDanych, int id);
	int szukajID(string bazaDanych);
	void modyfy(string bazaDanych, int ID, string dane[]);
	int remove(string bazaDanych, int ID);
	//przyjmuje tablice danych o rozmiaze wyszyskich pol tablicy(lacznie z id) ID nie musi byc podawane
	void insert(string bazaDanych, string dane[]);
	//void sortTable(string bazaDanych);

private:			//sciezka do po³¹czenia z plikami
	string nazwaTabeliLogow;
	string nazwaTabeliKlientow;
	string nazwaTabeliPokoi;
	string nazwaTabeliRezerwacji;
	string nazwaTabeliUzytkownikow;

	vector <BazaLogow*> tabelaLogow;
	vector <Klienci*> tabelaKlientow;
	vector <Pokoje*> tabelaPokojow;
	vector <Rezerwacje*> tabelaRezerwacji;
	vector <Uzytkownicy*> tabelaUzytkownikow;
};

