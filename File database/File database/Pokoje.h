#pragma once
#include <iostream>
class Pokoje
{
public:

	Pokoje();
	Pokoje(std::string * tab);
	~Pokoje();
	int getPokojID();
	int getIloscMiejsc();
	std::string getNrPokoju();
	bool operator<(Pokoje& l);
	friend std::ostream& operator <<(std::ostream& stream,Pokoje* baza);
private:
	int pokojID;
	int iloscMiejsc;
	std::string nrPokoju;
};

