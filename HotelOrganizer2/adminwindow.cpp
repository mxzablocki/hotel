#include "adminwindow.h"
#include "ui_adminwindow.h"
#include <QMessageBox>
#include <QString>
#include "BazaDanych.h"

AdminWindow::AdminWindow(QWidget *parent) :
	QMainWindow(parent), 
	ui(new Ui::AdminWindow)
{
	ui->setupUi(this);
	roomWindow = nullptr;
	BazaDanych * baza;
	QString clientID, clientName, clientSurname, clientPesel, clientDate, clientDays, clientRoomNumber, clientPeople;
	string** rezerwacje = nullptr;
	string** klienci;
	baza = new BazaDanych();
	int iloscKlientow;
	int iloscDanych = baza->select("rezerwacje", rezerwacje);
	for (int i = 0; i < iloscDanych; i++)
	{
		clientID = QString::fromStdString(rezerwacje[i][0]);
		clientRoomNumber = QString::fromStdString(rezerwacje[i][3]);
		clientPeople = QString::fromStdString(rezerwacje[i][12]);
		clientName = QString::fromStdString(rezerwacje[i][6]);
		clientSurname = QString::fromStdString(rezerwacje[i][7]);
		clientPesel = QString::fromStdString(rezerwacje[i][8]);
		clientDate = QString::fromStdString(rezerwacje[i][10]);
		clientDays = QString::fromStdString(rezerwacje[i][11]);
		ui->listWidgetClients->addItem(
			clientID + " " + clientName + " " + clientSurname + " " + clientPesel + " " +
			clientDate + " " + clientDays + " " + clientRoomNumber + " " + clientPeople
		);
	}
	iloscKlientow = baza->select("klienci", klienci);
	ui->labelInfoClientsNumber->setText(QString::number(iloscKlientow));
	delete baza;
	for (int i = 0; i < iloscDanych; i++)
		delete[] rezerwacje[i];
	delete[] rezerwacje;
}

AdminWindow::~AdminWindow()
{
	delete ui;
	// zwalnianie okna zarzadzania klientami
	// musi byc zwolnione, poniewaz tworzone jest bez uzycia parametru (okno nie ma "rodzica")
	delete roomWindow;
}

void AdminWindow::on_pushButtonManageRooms_clicked()
{
	// ukrycie aktualnego okna oraz utworzenie nowego okna (zarzadzanie pokojami)
	hide();
	roomWindow = new RoomWindow();
	roomWindow->show();
}
int AdminWindow::szukajDanychWPolu(std::string dana, std::string** tabela, int iloscDanych, int nrPola)
{
	for (int i = 0; i < iloscDanych; i++)
	{
		if (tabela[i][nrPola] == dana)
		{
			return atoi(tabela[i][0].c_str());	//jak znajdzie to zwraca id
		}
	}
	return -1;
}
void AdminWindow::konwertujStringNaDate(string StrData, struct tm *timeinfo)	//format daty yyyy-mm-dd
{	//nie testowalem tego nie wiem czy dziala
	//time_t rawtime;
	////struct tm * timeinfo;
	//int year, month, day;
	//year = atoi(StrData.substr(0, 4).c_str());//rok
	//month = atoi(StrData.substr(5, 2).c_str());//miesiac
	//month = atoi(StrData.substr(8, 2).c_str());//miesiac 
	//time(&rawtime);
	//timeinfo = localtime(&rawtime);
	//timeinfo->tm_year = year - 1900;
	//timeinfo->tm_mon = month - 1;
	//timeinfo->tm_mday = day;
	//mktime(timeinfo);
}
void AdminWindow::on_pushButtonClientAdd_clicked()
{
	string **klienci = nullptr;
	string **pokoje = nullptr;
	BazaDanych * baza;
	string* rezerwacja;
	string* klient;
	int iloscDanych;
	int idKlienta = -1;
	int idPokoju = -1;
	int idRezerwacji = -1;
	bool czyIstnieje = false;
	rezerwacja = new string[6];
	baza = new BazaDanych();
	iloscDanych = baza->select("klienci", klienci);
	QMessageBox::information(this, "Info", "kliknąłeś Dodaj");

	// TODO: obsluzyc dodawanie

	// pobranie danych z inputow
	QString clientID = "";
	QString clientName = ui->lineEditClientName->text();
	QString clientSurname = ui->lineEditClientSurname->text();
	QString clientPesel = ui->lineEditClientPesel->text();
	QString clientDate = ui->dateEditClientDate->text();
	QString clientDays = ui->spinBoxClientDays->text();
	QString clientRoomNumber = ui->spinBoxClientRoomNumber->text();
	QString clientPeople = ui->spinBoxClientPeople->text();

	idKlienta = szukajDanychWPolu(clientPesel.toStdString(), klienci, iloscDanych, 3);
	if(idKlienta != -1)
	{
		rezerwacja[2] = idKlienta;
	}
	else	//jesli nie ma takiego klienta to go dodaje
	{
		klient = new string[6];
		klient[1] = clientName.toStdString();
		klient[2] = clientSurname.toStdString();
		klient[3] = clientPesel.toStdString();
		klient[4] = "ala";		//telefon;
		klient[5] = "ala";		//email;
		baza->insert("klienci", klient);
	}
	iloscDanych = baza->select("klienci", klienci);
	idKlienta = szukajDanychWPolu(clientPesel.toStdString(), klienci, iloscDanych,3);
	if (idKlienta != -1)		//jesli udalo sie stworzyc
	{
		iloscDanych = baza->select("pokoje", pokoje);
		idPokoju = szukajDanychWPolu(clientRoomNumber.toStdString(), pokoje, iloscDanych, 2);
		if(idPokoju != -1)
		{
			rezerwacja[1] = to_string(idPokoju);
			rezerwacja[2] = to_string(idKlienta);
			rezerwacja[3] = clientDate.toStdString();
			rezerwacja[4] = clientDays.toStdString();
			rezerwacja[5] = clientPeople.toStdString();		//tabela rezerwacji mila miec inne pola
			idRezerwacji = baza->insert("rezerwacje", rezerwacja);
			clientID = QString::number(idRezerwacji);
			
			ui->listWidgetClients->addItem(
				clientID + " " + clientName + " " + clientSurname + " " + clientPesel + " " +
				clientDate + " " + clientDays + " " + clientRoomNumber + " " + clientPeople
			);
			baza->zapiszDane();
			iloscDanych = baza->select("klienci", klienci);
			ui->labelInfoClientsNumber->setText(QString::number(iloscDanych));
		}
		else
		{
			QMessageBox::information(this, "Info", "Nie można takiego pokoju");
		}
	}
	else
	{
		QMessageBox::information(this, "Info", "nie można stwożyć klienta");
	}
	//zwalnianie pamieci
}

string* AdminWindow::dzieleniePoSpacji(QString dane, BazaDanych *baza)
{
	string *dana;
	int licznikDanych = 0;
	dana = new string[1];
	dana[0] = "";
	string *tmp;
	string linia = dane.toStdString();
	for (int i = 0; i < linia.length(); i++)
	{
		if (linia[i] != ' ')
		{
			dana[licznikDanych] =+ linia[i];
		}
		else
		{
			licznikDanych++;
			tmp = new string[licznikDanych+1];
			for (int j = 0; j < licznikDanych; j++)
			{
				tmp[j] = dana[j];
			}
			delete[] dana;
			dana = tmp;

			//baza->rozszezenieTablicy(dana, licznikDanych, 1);
			dana[licznikDanych] = "";
		}
	}	
	return dana;
}
void AdminWindow::on_pushButtonClientEdit_clicked()
{
	
	BazaDanych * baza;
	string** klienci = nullptr;
	string** pokoje = nullptr;
	string** rezerwacje = nullptr;
	string* klient = nullptr;
	string *rezerwacja = nullptr;
	string *pokoj = nullptr;
	string *dane = nullptr;
	int iloscDanych;
	int idKlienta = -1;
	int idPokoju = -1;
	int idRezerwacji = -1;
	QMessageBox::information(this, "Info", "kliknąłeś Edytuj");
	QString wiersz;
	if ((ui->listWidgetClients->currentItem()->text()) != nullptr)	//jesli jest zaznaczone
	{
		baza = new BazaDanych();
		rezerwacja = new string[6];
		wiersz = ui->listWidgetClients->currentItem()->text();
		dane = dzieleniePoSpacji(wiersz, baza);
		//TODO ustawienie danych do rezerwacji

		
		baza->remove("rezerwacje", atoi(dane[0].c_str()));	//usuwa rezerwacje z bazy
		//pobranie danych z pól
		QString clientID = dane[0].c_str();
		QString clientName = ui->lineEditClientName->text();
		QString clientSurname = ui->lineEditClientSurname->text();
		QString clientPesel = ui->lineEditClientPesel->text();
		QString clientDate = ui->dateEditClientDate->text();
		QString clientDays = ui->spinBoxClientDays->text();
		QString clientRoomNumber = ui->spinBoxClientRoomNumber->text();
		QString clientPeople = ui->spinBoxClientPeople->text();
		iloscDanych = baza->select("klienci", klienci);
		idKlienta = szukajDanychWPolu(clientPesel.toStdString(), klienci, iloscDanych, 3);
		if (idKlienta != -1)
		{
			rezerwacja[2] = idKlienta;
		}
		else	//jesli nie ma takiego klienta to go dodaje
		{
			klient = new string[6];
			klient[1] = clientName.toStdString();
			klient[2] = clientSurname.toStdString();
			klient[3] = clientPesel.toStdString();
			klient[4] = "ala";		//telefon;
			klient[5] = "ala";		//email;
			baza->insert("klienci", klient);
		}
		iloscDanych = baza->select("klienci", klienci);
		idKlienta = szukajDanychWPolu(clientPesel.toStdString(), klienci, iloscDanych, 3);
		if (idKlienta != -1)		//jesli udalo sie stworzyc
		{
			iloscDanych = baza->select("pokoje", pokoje);
			idPokoju = szukajDanychWPolu(clientRoomNumber.toStdString(), pokoje, iloscDanych, 2);
			if (idPokoju != -1)
			{
				rezerwacja[1] = to_string(idPokoju);
				rezerwacja[2] = to_string(idKlienta);
				rezerwacja[3] = clientDate.toStdString();
				rezerwacja[4] = clientDays.toStdString();
				rezerwacja[5] = clientPeople.toStdString();		//tabela rezerwacji mila miec inne pola
				idRezerwacji = baza->insert("rezerwacje", rezerwacja);
				clientID = QString::number(idRezerwacji);
				ui->listWidgetClients->addItem(
					clientID + " " + clientName + " " + clientSurname + " " + clientPesel + " " +
					clientDate + " " + clientDays + " " + clientRoomNumber + " " + clientPeople
				);
				delete ui->listWidgetClients->currentItem();
			}
			else
			{
				QMessageBox::information(this, "Info", "Nie można takiego pokoju");
			}
		}
		else
		{
			QMessageBox::information(this, "Info", "nie można stwożyć klienta");
		}
		//wlasciwie to to samo co jest w dodawaniu
	}

	// TODO: obsluzyc edycje
}

void AdminWindow::on_pushButtonClientDelete_clicked()
{
	BazaDanych * baza;
	baza = new BazaDanych();
	int iloscDanych;
	string** klienci;
	string* rezerwacja;
	string* dane;
	QMessageBox::information(this, "Info", "kliknąłeś Usuń");
	QString wiersz;
	if ((ui->listWidgetClients->currentItem()->text()) != nullptr)	//jesli jest zaznaczone
	{
		baza = new BazaDanych();
		rezerwacja = new string[6];
		wiersz = ui->listWidgetClients->currentItem()->text();
		dane = dzieleniePoSpacji(wiersz, baza);
		//TODO ustawienie danych do rezerwacji

		baza->remove("rezerwacje", atoi(dane[0].c_str()));	//usuwa rezerwacje z bazy
		delete ui->listWidgetClients->currentItem();
		baza->zapiszDane();
		iloscDanych = baza->select("klienci", klienci);
		ui->labelInfoClientsNumber->setText(QString::number(iloscDanych));
	}
	// TODO: obsluzyc usuwanie
	//wlasciwie to 1 czesc edycji :)
    // usuwanie zaznaczonego elementu
	
}
