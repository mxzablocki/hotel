#pragma once
#include <iostream>
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
	std::string getTerminKoncowy();
	std::string getStatusRezerwacji();
	bool operator<(Rezerwacje& l);
	friend std::ostream& operator <<(std::ostream& stream, Rezerwacje* baza);
private:
	int rezerwacjaID;
	int pokojID;
	int KlientID;
	std::string terminPoczatkowy;
	std::string terminKoncowy;
	std::string statusRezerwacji;
};

