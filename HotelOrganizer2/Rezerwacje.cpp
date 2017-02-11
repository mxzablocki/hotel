#include "Rezerwacje.h"
#include <string>

Rezerwacje::Rezerwacje()
{
}

std::ostream& operator <<(std::ostream& stream, Rezerwacje* baza)
{
	stream << baza->getRezerwacjaID() << " " << baza->getPokojID() << " " << baza->getKlientID() << " " << baza->getTerminPoczatkowy() << " " << baza->getTerminKoncowy() << " " << baza->getStatusRezerwacji();
	return stream;
}

Rezerwacje::Rezerwacje(std::string * tab)
{
	rezerwacjaID = atoi(tab[0].c_str());
	pokojID = atoi(tab[1].c_str());
	KlientID = atoi(tab[2].c_str());
	terminPoczatkowy = tab[3];
	terminKoncowy = atoi(tab[4].c_str());
	statusRezerwacji = atoi(tab[5].c_str());
}

// Gettery
int Rezerwacje::getRezerwacjaID()
{
	return rezerwacjaID;
}

int Rezerwacje::getPokojID()
{
	return pokojID;
}

int Rezerwacje::getKlientID()
{
	return KlientID;
}

std::string Rezerwacje::getTerminPoczatkowy()
{
	return terminPoczatkowy;
}

int Rezerwacje::getTerminKoncowy()
{
	return terminKoncowy;
}

int Rezerwacje::getStatusRezerwacji()
{
	return statusRezerwacji;
}

bool Rezerwacje::operator<(Rezerwacje& l)
{
	return(rezerwacjaID < l.getRezerwacjaID());
}

Rezerwacje::~Rezerwacje()
{
}
