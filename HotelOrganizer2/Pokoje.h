#ifndef POKOJE_H
#define POKOJE_H

#include <iostream>
#include <string>

class Pokoje
{
public:
	Pokoje();
	Pokoje(std::string * tab);
	~Pokoje();
	int getPokojID();
	int getIloscMiejsc();
	int getNrPokoju();
	bool operator<(Pokoje& l);
	friend std::ostream& operator <<(std::ostream& stream,Pokoje* baza);
private:
	int pokojID;
	int iloscMiejsc;
	int nrPokoju;
};

#endif // POKOJE_H
