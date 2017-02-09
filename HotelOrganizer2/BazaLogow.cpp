#include "BazaLogow.h"
#include <cstdlib>
#include <iostream>
#include <string>

BazaLogow::BazaLogow()
{
}

std::ostream& operator <<(std::ostream& stream, BazaLogow* baza)
{
	stream << baza->getLogID() <<" "<<baza->getData() << " " << baza->getGodzina() << " " << baza->getNazwaAkcji() << " " << baza->getParametry() << " " << baza->getUzytkownicyID();
	return stream;
}

BazaLogow::BazaLogow(std::string *dane)
{
	logID = atoi(dane[0].c_str());
	Data = dane[1];
	godzina = atoi(dane[2].c_str());
	nazwaAkcji = dane[3];
	parametry = dane[4];
	uzytkownicyID = atoi(dane[5].c_str());
}

// Gettery
int BazaLogow::getLogID()
{
	return logID;
}

std::string BazaLogow::getData()
{
	return Data;
}

int BazaLogow::getGodzina()
{
	return godzina;
}

std::string BazaLogow::getNazwaAkcji()
{
	return nazwaAkcji;
}

std::string BazaLogow::getParametry()
{
	return parametry;
}

int BazaLogow::getUzytkownicyID()
{
	return uzytkownicyID;
}

bool BazaLogow::operator<(BazaLogow& l)
{
	return(logID < l.getLogID());
}

BazaLogow::~BazaLogow()
{
}
