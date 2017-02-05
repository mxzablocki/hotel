#pragma once
#include <iostream>
class BazaLogow
{
public:
	BazaLogow();
	BazaLogow(std::string * dane);
	~BazaLogow();
	int getLogID();
	std::string getData();
	int getGodzina();
	std::string getNazwaAkcji();
	std::string getParametry();
	int getUzytkownicyID();
	bool operator<(BazaLogow& l);
	friend std::ostream& operator <<(std::ostream& stream,  BazaLogow* baza);
private:
	int logID;
	std::string Data;
	int godzina;
	std::string nazwaAkcji;
	std::string parametry;
	int uzytkownicyID;
};

