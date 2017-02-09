#ifndef UZYTKOWNICY_H
#define UZYTKOWNICY_H

#include <iostream>
#include <string>

class Uzytkownicy
{
public:
	Uzytkownicy();
	Uzytkownicy(std::string * tab);
	int getUzytkownikID();
	std::string getImie();
	std::string getNazwisko();
	std::string getLogin();
	std::string getHaslo();
	std::string getTyp();
	~Uzytkownicy();
	bool operator<(Uzytkownicy& l);
	friend std::ostream& operator <<(std::ostream& stream,  Uzytkownicy* baza);
private:
	int uzytkownikID;
	std::string imie;
	std::string nazwisko;
	std::string login;
	std::string haslo;
	std::string typ;
};

#endif // UZYTKOWNICY_H
