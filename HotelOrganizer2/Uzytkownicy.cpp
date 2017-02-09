#include "Uzytkownicy.h"
#include <string>

Uzytkownicy::Uzytkownicy()
{
}

std::ostream& operator <<(std::ostream& stream, Uzytkownicy* baza)
{
	stream << baza->getUzytkownikID() << " " << baza->getImie() << " " << baza->getNazwisko() << " " << baza->getLogin() << " " << baza->getHaslo() << " " << baza->getTyp();
	return stream;
}

Uzytkownicy::Uzytkownicy(std::string * tab)
{
	uzytkownikID = atoi(tab[0].c_str());
	imie = tab[1];
	nazwisko = tab[2];
	login = tab[3];
	haslo = tab[4];
	typ = tab[5];
}

// Gettery
int Uzytkownicy::getUzytkownikID()
{
	return uzytkownikID;
}

std::string Uzytkownicy::getImie()
{
	return imie;
}

std::string Uzytkownicy::getNazwisko()
{
	return nazwisko;
}

std::string Uzytkownicy::getLogin()
{
	return login;
}

std::string Uzytkownicy::getHaslo()
{
	return haslo;
}

std::string Uzytkownicy::getTyp()
{
	return typ;
}

bool Uzytkownicy::operator<(Uzytkownicy& l)
{
	return(uzytkownikID < l.getUzytkownikID());
}

Uzytkownicy::~Uzytkownicy()
{
}
