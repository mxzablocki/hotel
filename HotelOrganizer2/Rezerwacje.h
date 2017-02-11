#ifndef REZERWACJE_H
#define REZERWACJE_H

#include <iostream>
#include <string>

class Rezerwacje
{
public:
	Rezerwacje();
	Rezerwacje(std::string * tab);
	~Rezerwacje();
	int getRezerwacjaID();
	int getPokojID();
	int getKlientID();
	std::string getTerminPoczatkowy();
	int getTerminKoncowy();
	int getStatusRezerwacji();
	bool operator<(Rezerwacje& l);
	friend std::ostream& operator <<(std::ostream& stream, Rezerwacje* baza);
private:
	int rezerwacjaID;
	int pokojID;
	int KlientID;
	std::string terminPoczatkowy;
	int terminKoncowy;
	int statusRezerwacji;
};

#endif // REZERWACJE_H
