#pragma once
#include <iostream>
class Klienci
{
public:
	Klienci();
	Klienci(std::string *tab);
	~Klienci();
	int getKlientID();
	std::string getImie();
	std::string getNazwisko();
	std::string getAdres();
	std::string getTelefon();
	std::string getEmail();
	bool operator<(Klienci& l);
	friend std::ostream& operator <<(std::ostream& stream, Klienci* baza);
private:
	int klientID;
	std::string imie;
	std::string nazwisko;
	std::string adres;
	std::string telefon;
	std::string email;
};

