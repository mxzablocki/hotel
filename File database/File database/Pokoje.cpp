#include "stdafx.h"
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
	nrPokoju = tab[2];
}
int Pokoje::getPokojID()
{
	return pokojID;
}
int Pokoje::getIloscMiejsc()
{
	return iloscMiejsc;
}
std::string Pokoje::getNrPokoju()
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
