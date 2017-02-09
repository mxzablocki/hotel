#include "Klienci.h"
#include <cstdlib>
#include <iostream>
#include <string>

Klienci::Klienci()
{
}

std::ostream& operator <<(std::ostream& stream, Klienci* baza)
{
	stream << baza->getKlientID() << " " << baza->getImie() << " " << baza->getNazwisko() << " " << baza->getAdres() << " " << baza->getTelefon() << " " << baza->getEmail();
	return stream;
}

Klienci::Klienci(std::string *tab)
{
	klientID = std::atoi(tab[0].c_str());
	imie = tab[1];
	nazwisko = tab[2];
	adres = tab[3];
	telefon = tab[4];
	email = tab[5];
}

// Gettery
int Klienci::getKlientID()
{
	return klientID;
}

std::string Klienci::getImie()
{
	return imie;
}

std::string Klienci::getNazwisko()
{
	return nazwisko;
}

std::string Klienci::getAdres()
{
	return adres;
}

std::string Klienci::getTelefon()
{
	return telefon;
}

std::string Klienci::getEmail()
{
	return email;
}

bool Klienci::operator<(Klienci& l)
{
	return(klientID < l.getKlientID());
}

Klienci::~Klienci()
{
}
