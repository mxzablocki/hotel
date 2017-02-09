#ifndef BAZALOGOW_H
#define BAZALOGOW_H

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
	int uzytkownicyID;
	int godzina;
	std::string Data;
	std::string nazwaAkcji;
	std::string parametry;
};

#endif // BAZALOGOW_H
