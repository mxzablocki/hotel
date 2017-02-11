#include "Pokoje.h"
#include <iostream>
#include <string>

Pokoje::Pokoje()
{
}

Pokoje::Pokoje(std::string* tab)
{
	pokojID = atoi(tab[0].c_str());
	iloscMiejsc = atoi(tab[1].c_str());
	nrPokoju = atoi(tab[2].c_str());
}

// Gettery
int Pokoje::getPokojID()
{
	return pokojID;
}

int Pokoje::getIloscMiejsc()
{
	return iloscMiejsc;
}

int Pokoje::getNrPokoju()
{
	return nrPokoju;
}

bool Pokoje::operator<(Pokoje& l)
{
	return(pokojID < l.getPokojID());
}

std::ostream& operator <<(std::ostream& stream, Pokoje* baza)
{
	stream << baza->getPokojID() << " " << baza->getIloscMiejsc() << " " << baza->getNrPokoju();
	return stream;
}

Pokoje::~Pokoje()
{
}
