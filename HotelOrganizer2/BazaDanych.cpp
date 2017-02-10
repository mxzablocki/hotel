#include "bazaDanych.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "BazaLogow.h"
#include "Klienci.h"
#include "Pokoje.h"
#include "Rezerwacje.h"
#include "Uzytkownicy.h"

using namespace std;

void BazaDanych::zapiszDane()
{
	ofstream klienci;
	ofstream logi;
	ofstream pokoje;
	ofstream rezerwacje;
	ofstream uzytkownicy;
	klienci.open(nazwaTabeliKlientow );
	logi.open(nazwaTabeliLogow );
	pokoje.open(nazwaTabeliPokoi );
	rezerwacje.open(nazwaTabeliRezerwacji );
	uzytkownicy.open(nazwaTabeliUzytkownikow );
	for (int i = 0; i < tabelaKlientow.size(); i++)
	{
		klienci <<tabelaKlientow[i] << endl;
	} 
	for (int i = 0; i < tabelaLogow.size(); i++)
	{
		logi << tabelaLogow[i] << endl;;
	}
	for (int i = 0; i < tabelaPokojow.size(); i++)
	{
		pokoje << tabelaPokojow[i] << endl;
	}
	for (int i = 0; i < tabelaRezerwacji.size(); i++)
	{
		rezerwacje << tabelaRezerwacji[i] << endl;
	}
	for (int i = 0; i < tabelaUzytkownikow.size(); i++)
	{
		uzytkownicy << tabelaUzytkownikow[i] << endl;
	}
	klienci.close();
	rezerwacje.close();
	uzytkownicy.close();
	pokoje.close();
	logi.close();
}

void BazaDanych::pobranieWartoscizTabel(ifstream &klienci, ifstream &pokoje, ifstream &rezerwacje, ifstream &uzytkownicy, ifstream &logi)
{
	Klienci *tmpKlienci;
	Pokoje *tmpPokoje;
	Rezerwacje *tmpRezerwacje;
	Uzytkownicy *tmpUzytkownicy;
	BazaLogow *tmpLogi;
	string* dane;
	int licznikDanych = 0;
	dane = new string[6];
	while (!klienci.eof())
	{
		if (licznikDanych < 6)		//pobieranie klientow
		{
			klienci >> dane[licznikDanych];
			licznikDanych++;
		}
		else if(licznikDanych != 0)
		{
			tmpKlienci = new Klienci(dane);
			tabelaKlientow.push_back(tmpKlienci);
			licznikDanych = 0;
		}
	}
	licznikDanych = 0;
	while (!pokoje.eof())		//pobieranie pokojow
	{
		if (licznikDanych < 3)
		{
			pokoje >> dane[licznikDanych];
			licznikDanych++;
		}
		else
		{
			tmpPokoje = new Pokoje(dane);
			tabelaPokojow.push_back(tmpPokoje);
			licznikDanych = 0;
		}
	}
	licznikDanych = 0;
	while (!uzytkownicy.eof())
	{
		if (licznikDanych < 6)		//pobieranie uzytkownikow
		{
			uzytkownicy >> dane[licznikDanych];
			licznikDanych++;
		}
		else if (licznikDanych != 0)
		{
			tmpUzytkownicy = new Uzytkownicy(dane);
			tabelaUzytkownikow.push_back(tmpUzytkownicy);
			licznikDanych = 0;
		}
	}
	licznikDanych = 0;
	while (!rezerwacje.eof())
	{
		if (licznikDanych < 6)		//pobieranie rezerwacji
		{
			rezerwacje >> dane[licznikDanych];
			licznikDanych++;
		}
		else
		{
			tmpRezerwacje = new Rezerwacje(dane);
			tabelaRezerwacji.push_back(tmpRezerwacje);
			licznikDanych = 0;
		}
	}
	licznikDanych = 0;
	while (!logi.eof())
	{
		if (licznikDanych < 6)		//pobieranie rezerwacji
		{
			logi >> dane[licznikDanych];
			licznikDanych++;
		}
		else
		{
			tmpLogi = new BazaLogow(dane);
			tabelaLogow.push_back(tmpLogi);
			licznikDanych = 0;
		}
	}
	klienci.close();
	rezerwacje.close();
	uzytkownicy.close();
	pokoje.close();
}

void BazaDanych::otwarcieBazy()
{
	ifstream klienci;
	ifstream logi;
	ifstream pokoje;
	ifstream rezerwacje;
	ifstream uzytkownicy;
	klienci.open(nazwaTabeliKlientow);
	logi.open(nazwaTabeliLogow);
	pokoje.open(nazwaTabeliPokoi);
	rezerwacje.open(nazwaTabeliRezerwacji);
	uzytkownicy.open(nazwaTabeliUzytkownikow);
	pobranieWartoscizTabel(klienci, pokoje, rezerwacje, uzytkownicy, logi);
	//jesli ktorys sie nie otworzy to mozna stworzyc baze danych
}

void BazaDanych::otwarcieConfig()
{
	ifstream plik;
	string nazwaTabeli;
	plik.open("config.txt");	//jesli cos bedzie zapisywane to bedzie od konca (by nie nadpisywac)
	if (plik)
	{
		//gdy jest plik
		nazwaTabeliKlientow = "klienci.txt";		//dzieki temu jak cos bedzie brakowac to stworzy automatycznie tabele
		nazwaTabeliLogow = "logi.txt";
		nazwaTabeliPokoi = "pokoje.txt";
		nazwaTabeliRezerwacji = "rezerwacje.txt";
		nazwaTabeliUzytkownikow = "uzytkownicy.txt";
		while (!plik.eof())
		{
			getline(plik, nazwaTabeli);
			if (nazwaTabeli == "baza klientów")
			{
				getline(plik, nazwaTabeli);
				nazwaTabeliKlientow = nazwaTabeli;
			}
			else if (nazwaTabeli == "baza logów")
			{
				getline(plik, nazwaTabeli);
				nazwaTabeliLogow = nazwaTabeli;
			}
			else if (nazwaTabeli == "baza pokoi")
			{
				getline(plik, nazwaTabeli);
				nazwaTabeliPokoi = nazwaTabeli;
			}
			else if (nazwaTabeli == "baza rezerwacji")
			{
				getline(plik, nazwaTabeli);
				nazwaTabeliRezerwacji = nazwaTabeli;
			}
			else if (nazwaTabeli == "baza u¿ytkowników")
			{
				getline(plik, nazwaTabeli);
				nazwaTabeliUzytkownikow = nazwaTabeli;
			}
		}
		plik.close();
	}
	else
	{
		// "b³¹d otworzenia pliku"
		ofstream NowyPlik;
		NowyPlik.open("config.txt");		//twozy plik config
		NowyPlik << "baza klientów" << endl << "klienci.txt" << endl;
		NowyPlik << "baza logów" << endl << "logi.txt" << endl;
		NowyPlik << "baza pokoi" << endl << "pokoje.txt" << endl;
		NowyPlik << "baza rezerwacji" << endl << "rezerwacje.txt" << endl;
		NowyPlik << "baza u¿ytkowników" << endl << "uzytkownicy.txt" << endl;
		nazwaTabeliKlientow = "klienci.txt";	//ustawia startowe wartosci
		nazwaTabeliLogow = "logi.txt";
		nazwaTabeliPokoi = "pokoje.txt";
		nazwaTabeliRezerwacji = "rezerwacje.txt";
		nazwaTabeliUzytkownikow = "uzytkownicy.txt";

		NowyPlik.close();
	}
}

BazaDanych::BazaDanych()
{
	//otwarcie config.txt do sprawdzenia sciezek do bazy danych
	otwarcieConfig();
	otwarcieBazy();
}

BazaDanych::~BazaDanych()
{
	//zwolnienie pamieci z wektorow i zamkniecie plikow
}

int BazaDanych::szukajID(string bazaDanych)
{	//sprawdzanie aktualnego z poprzednim
	int aktualneID, poprzednieID;
	if (bazaDanych == "klienci")
	{
		for (int i = 1; i < tabelaKlientow.size(); i++)
		{
			aktualneID = tabelaKlientow[i]->getKlientID();
			poprzednieID = tabelaKlientow[i-1]->getKlientID();
			if ((aktualneID - poprzednieID) != 1)
			{
				return (poprzednieID + 1);
			}
		}	
		if (tabelaKlientow.size() == 0)
			return 1;
		else if (tabelaKlientow.size() == 1)
			return 2;
		else
			return (aktualneID + 1);

	}
	else if (bazaDanych == "uzytkownicy")
	{
		for (int i = 1; i < tabelaUzytkownikow.size(); i++)
		{
			aktualneID = tabelaUzytkownikow[i]->getUzytkownikID();
			poprzednieID = tabelaUzytkownikow[i-1]->getUzytkownikID();
			if ((aktualneID - poprzednieID) != 1)
			{
				return (poprzednieID + 1);
			}
		}
		if (tabelaUzytkownikow.size() == 0)
			return 1;
		else if (tabelaUzytkownikow.size() == 1)
			return 2;
		else
			return (aktualneID + 1);
	}
	else if (bazaDanych == "logi")
	{
		for (int i = 1; i < tabelaLogow.size(); i++)
		{
			aktualneID = tabelaLogow[i]->getLogID();
			poprzednieID = tabelaLogow[i-1]->getLogID();
			if ((aktualneID - poprzednieID) != 1)
			{
				return (poprzednieID + 1);
			}
		}
		if (tabelaLogow.size() == 0)
			return 1;
		else if (tabelaLogow.size() == 1)
			return 2;
		else
			return aktualneID + 1;
	}
	else if (bazaDanych == "pokoje")
	{
		for (int i = 1; i < tabelaPokojow.size(); i++)
		{
			aktualneID = tabelaPokojow[i]->getPokojID();
			poprzednieID = tabelaPokojow[i-1]->getPokojID();
			if ((aktualneID - poprzednieID) != 1)
			{
				return (poprzednieID + 1);
			}
		}
		if (tabelaPokojow.size() == 0)
			return 1;
		else if (tabelaPokojow.size() == 1)
			return 2;
		else
			return aktualneID + 1;
	}
	else if (bazaDanych == "rezerwacje")
	{
		for (int i = 1; i < tabelaRezerwacji.size(); i++)
		{
			aktualneID = tabelaRezerwacji[i]->getRezerwacjaID();
			poprzednieID = tabelaRezerwacji[i-1]->getRezerwacjaID();
			if ((aktualneID - poprzednieID) != 1)
			{
				return (poprzednieID + 1);
			}
		}
		if (tabelaRezerwacji.size() == 0)
			return 1;
		else if (tabelaRezerwacji.size() == 1)
			return 2;
		else
			return aktualneID + 1;
	}
}

void BazaDanych::insert(string bazaDanych, string* dane)
{
	Klienci *tmpKlienci;
	Pokoje *tmpPokoje;
	Rezerwacje *tmpRezerwacje; 
	Uzytkownicy *tmpUzytkownicy;
	BazaLogow *tmpLogi;
	if (bazaDanych == "klienci")
	{
		dane[0] = to_string(szukajID("klienci"));
		tmpKlienci = new Klienci(dane);
		tabelaKlientow.push_back(tmpKlienci);
		if(tabelaKlientow.size() != 1)
			sort(tabelaKlientow.begin(), tabelaKlientow.end(), [](Klienci* a, Klienci* b) {return (a->getKlientID() < b->getKlientID()); });
	}
	else if (bazaDanych == "uzytkownicy")
	{
		dane[0] = to_string(szukajID("uzytkownicy"));
		tmpUzytkownicy = new Uzytkownicy(dane);
		tabelaUzytkownikow.push_back(tmpUzytkownicy);
		if(tabelaUzytkownikow.size() != 1)
			sort(tabelaUzytkownikow.begin(), tabelaUzytkownikow.end(), [](Uzytkownicy* a, Uzytkownicy* b) {return (a->getUzytkownikID() < b->getUzytkownikID()); });
	}
	else if (bazaDanych == "logi")
	{
		if (select("uzytkownicy", atoi(dane[5].c_str())) != nullptr)	//jesli istnienie takie id w uzytkownikach
		{
			dane[0] = to_string(szukajID("logi"));
			tmpLogi = new BazaLogow(dane);
			tabelaLogow.push_back(tmpLogi);
			if(tabelaLogow.size() != 1)
				sort(tabelaLogow.begin(), tabelaLogow.end(), [](BazaLogow* a, BazaLogow* b) {return (a->getLogID() < b->getLogID()); });
		}
	}
	else if (bazaDanych == "pokoje")
	{
		dane[0] = to_string(szukajID("pokoje"));
		tmpPokoje = new Pokoje(dane);
		tabelaPokojow.push_back(tmpPokoje);
		if(tabelaPokojow.size() != 1)
			sort(tabelaPokojow.begin(), tabelaPokojow.end(), [](Pokoje* a, Pokoje* b) {return (a->getPokojID() < b->getPokojID()); });
	}
	else if (bazaDanych == "rezerwacje")
	{
		
		if ((select("pokoje", atoi(dane[1].c_str())) != nullptr) && (select("klienci", atoi(dane[2].c_str())) != nullptr))		//jesli istnieje takie id w tabeli pokoji i klientow
		{
			dane[0] = to_string(szukajID("rezerwacje"));
			tmpRezerwacje = new Rezerwacje(dane);
			tabelaRezerwacji.push_back(tmpRezerwacje);
			if(tabelaRezerwacji.size() != 1)
				sort(tabelaRezerwacji.begin(), tabelaRezerwacji.end(), [](Rezerwacje* a, Rezerwacje* b) {return (a->getRezerwacjaID() < b->getRezerwacjaID()); });
		}
	}
	zapiszDane();
}

string** BazaDanych::rozszezenieTablicy(string** tab,int wielkoscX, int wielkoscY)
{
	string ** tmp = new string*[wielkoscY + 1];

	for (int i = 0; i < wielkoscY; i++)
	{
		tmp[i] = new string[wielkoscX];
	}
	for (int i = 0; i < wielkoscY; i++)
	{
		for (int j = 0; j < wielkoscX; j++)
		{
			tmp[i][j] = tab[i][j];
		}
	}
	for (int i = 0; i < wielkoscY; i++)
	{
		delete[] tab[i];
	}
	delete[] tab;
	return tmp;
}

int BazaDanych::remove(string bazaDanych, int ID)
{
	if (bazaDanych == "klienci")
	{
		for (int i = 0; i < tabelaKlientow.size(); i++)
		{
			if (tabelaKlientow[i]->getKlientID() == ID)
			{
				tabelaKlientow.erase(tabelaKlientow.begin() + i);
			}
		}
		return 0;
	}
	else if (bazaDanych == "uzytkownicy")
	{
		for (int i = 0; i < tabelaUzytkownikow.size(); i++)
		{
			if (tabelaUzytkownikow[i]->getUzytkownikID() == ID)
			{
				tabelaUzytkownikow.erase(tabelaUzytkownikow.begin() + i);
			}
		}
		return 0;
	}
	else if (bazaDanych == "logi")
	{
		for (int i = 0; i < tabelaLogow.size(); i++)
		{
			if (tabelaLogow[i]->getLogID() == ID)
			{
				tabelaLogow.erase(tabelaLogow.begin() + i);
			}
		}
		return 0;
	}
	else if (bazaDanych == "pokoje")
	{
		for (int i = 0; i < tabelaPokojow.size(); i++)
		{
			if (tabelaPokojow[i]->getPokojID() == ID)
			{
				tabelaPokojow.erase(tabelaPokojow.begin() + i);
			}
		}
		return 0;
	}
	else if (bazaDanych == "rezerwacje")
	{
		for (int i = 0; i < tabelaRezerwacji.size(); i++)
		{
			if (tabelaRezerwacji[i]->getRezerwacjaID() == ID)
			{
				tabelaRezerwacji.erase(tabelaRezerwacji.begin() + i);
			}
		}
		return 0;
	}
	else
	{
		return 1;
	}
}

//pobiera wszystko z odpowiedniej bazy
int BazaDanych::select(string bazaDanych, string** &dane)
{
	string** wynik = nullptr;
	string* kluczObcy;
	int iloscDanych;
	if (bazaDanych == "klienci")
	{
		iloscDanych = tabelaKlientow.size();
		wynik = new string*[iloscDanych];
		for (int i = 0; i < iloscDanych; i++)
		{
			wynik[i] = new string[6];
		}
		for(int i = 0; i < iloscDanych; i++)
		{
			wynik[i][0] = to_string(tabelaKlientow[i]->getKlientID());
			wynik[i][1] = tabelaKlientow[i]->getImie();
			wynik[i][2] = tabelaKlientow[i]->getNazwisko();
			wynik[i][3] = tabelaKlientow[i]->getAdres();
			wynik[i][4] = tabelaKlientow[i]->getTelefon();
			wynik[i][5] = tabelaKlientow[i]->getEmail();
		}
	}
	else if (bazaDanych == "uzytkownicy")
	{
		iloscDanych = tabelaUzytkownikow.size();
		wynik = new string*[iloscDanych];
		for (int i = 0; i < iloscDanych; i++)
		{
			wynik[i] = new string[6];
		}
		for (int i = 0; i < iloscDanych; i++)
		{
			wynik[i][0] = to_string(tabelaUzytkownikow[i]->getUzytkownikID());
			wynik[i][1] = tabelaUzytkownikow[i]->getImie();
			wynik[i][2] = tabelaUzytkownikow[i]->getNazwisko();
			wynik[i][3] = tabelaUzytkownikow[i]->getLogin();
			wynik[i][4] = tabelaUzytkownikow[i]->getHaslo();
			wynik[i][5] = tabelaUzytkownikow[i]->getTyp();
		}
	}
	else if (bazaDanych == "logi")
	{
		iloscDanych = tabelaLogow.size();
		wynik = new string*[iloscDanych];
		for (int i = 0; i < iloscDanych; i++)
		{
			wynik[i] = new string[11];
		}

		for (int i = 0; i < iloscDanych; i++)
		{
			
			wynik[i][0] = to_string(tabelaLogow[i]->getLogID());
			wynik[i][1] = tabelaLogow[i]->getData();
			wynik[i][2] = to_string(tabelaLogow[i]->getGodzina());
			wynik[i][3] = tabelaLogow[i]->getNazwaAkcji();
			wynik[i][4] = tabelaLogow[i]->getParametry();
			kluczObcy = select("uzytkownicy", tabelaLogow[i]->getUzytkownicyID());
			for (int j = 0; j < 6; j++) {wynik[i][j + 5] = kluczObcy[j];}
		}
	}
	else if (bazaDanych == "pokoje")
	{
		iloscDanych = tabelaPokojow.size();
		wynik = new string*[iloscDanych];
		for (int i = 0; i < iloscDanych; i++)
		{
			wynik[i] = new string[3];
		}
		for (int i = 0; i < iloscDanych; i++)
		{
			wynik[i][0] = to_string(tabelaPokojow[i]->getPokojID());
			wynik[i][1] = tabelaPokojow[i]->getIloscMiejsc();
			wynik[i][2] = tabelaPokojow[i]->getIloscMiejsc();
		}
	}
	else if (bazaDanych == "rezerwacje")
	{
		iloscDanych = tabelaRezerwacji.size();
		wynik = new string*[iloscDanych];
		for (int i = 0; i < iloscDanych; i++)
		{
			wynik[i] = new string[13];
		}
		for (int i = 0; i < iloscDanych; i++)
		{
			kluczObcy = select("pokoje", tabelaRezerwacji[i]->getPokojID());
			wynik[i][0] = to_string(tabelaRezerwacji[i]->getRezerwacjaID());
			for (int j = 0; j < 3; j++) { wynik[i][j + 1] = kluczObcy[j]; }
			kluczObcy = select("klienci", tabelaRezerwacji[i]->getKlientID());
			for (int j = 0; j < 6; j++) { wynik[i][j + 5] = kluczObcy[j]; }
			wynik[i][11] = tabelaRezerwacji[i]->getTerminPoczatkowy();
			wynik[i][12] = tabelaRezerwacji[i]->getTerminKoncowy();
			wynik[i][13] = tabelaRezerwacji[i]->getStatusRezerwacji();
		}
	}
	dane = wynik;
	return iloscDanych;
}

//zwraca pojedynczy rekord bazy dla podanego ID (przydatne do kluczy obcych)
string* BazaDanych::select(string bazaDanych, int id)
{
	string * kluczObcy;
	string * wynik = nullptr;
	if (bazaDanych == "klienci")
	{
		wynik = new string[6];
		for (int i = 0; i < tabelaKlientow.size(); i++)
		{
			if (id == tabelaKlientow[i]->getKlientID())
			{
				wynik[0] = to_string(tabelaKlientow[i]->getKlientID());
				wynik[1] = tabelaKlientow[i]->getImie();
				wynik[2] = tabelaKlientow[i]->getNazwisko();
				wynik[3] = tabelaKlientow[i]->getAdres();
				wynik[4] = tabelaKlientow[i]->getTelefon();
				wynik[5] = tabelaKlientow[i]->getEmail();
				return wynik;
			}
		}
	}
	else if (bazaDanych == "uzytkownicy")
	{
		wynik = new string[6];
		for (int i = 0; i < tabelaUzytkownikow.size(); i++)
		{
			if (id == tabelaUzytkownikow[i]->getUzytkownikID())
			{
				wynik[0] = to_string(tabelaUzytkownikow[i]->getUzytkownikID());
				wynik[1] = tabelaUzytkownikow[i]->getImie();
				wynik[2] = tabelaUzytkownikow[i]->getNazwisko();
				wynik[3] = tabelaUzytkownikow[i]->getLogin();
				wynik[4] = tabelaUzytkownikow[i]->getHaslo();
				wynik[5] = tabelaUzytkownikow[i]->getTyp();
				return wynik;
			}
		}
	}
	else if (bazaDanych == "logi")
	{
		wynik = new string[11];
		for (int i = 0; i < tabelaLogow.size(); i++)
		{
			if (id == tabelaLogow[i]->getLogID())
			{
				wynik[0] = to_string(tabelaLogow[i]->getLogID());
				wynik[1] = tabelaLogow[i]->getData();
				wynik[2] = to_string(tabelaLogow[i]->getGodzina());
				wynik[3] = tabelaLogow[i]->getNazwaAkcji();
				wynik[4] = tabelaLogow[i]->getParametry();
				kluczObcy = select("uzytkownicy", tabelaLogow[i]->getUzytkownicyID());
				for (int j = 0; j < 6; j++) { wynik[j + 5] = kluczObcy[j]; }
				//wynik[5] = to_string(tabelaLogow[i]->getUzytkownicyID());
				return wynik;
			}
		}
	}
	else if (bazaDanych == "pokoje")
	{
		wynik = new string[3];
		for (int i = 0; i < tabelaPokojow.size(); i++)
		{
			if (id == tabelaPokojow[i]->getPokojID())
			{
				wynik[0] = to_string(tabelaPokojow[i]->getPokojID());
				wynik[1] = tabelaPokojow[i]->getIloscMiejsc();
				wynik[2] = tabelaPokojow[i]->getIloscMiejsc();
				return wynik;
			}
		}
	}
	else if (bazaDanych == "rezerwacje")
	{
		wynik = new string[13];
		for (int i = 0; i < tabelaRezerwacji.size(); i++)
		{
			if (id == tabelaRezerwacji[i]->getRezerwacjaID())
			{
				wynik[0] = to_string(tabelaRezerwacji[i]->getRezerwacjaID());
				kluczObcy = select("pokoje", tabelaRezerwacji[i]->getPokojID());
				for (int j = 0; j < 3; j++) { wynik[1 + j] = kluczObcy[j]; }
				kluczObcy = select("klienci", tabelaRezerwacji[i]->getKlientID());
				for (int j = 0; j < 6; j++) { wynik[j + 5] = kluczObcy[j]; }
				//wynik[1] = to_string(tabelaRezerwacji[i]->getPokojID());
				//wynik[2] = to_string(tabelaRezerwacji[i]->getKlientID());
				wynik[11] = tabelaRezerwacji[i]->getTerminPoczatkowy();
				wynik[12] = tabelaRezerwacji[i]->getTerminKoncowy();
				wynik[13] = tabelaRezerwacji[i]->getStatusRezerwacji();
				return wynik;
			}
		}
	}
	return nullptr;
}
