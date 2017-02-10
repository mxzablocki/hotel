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
int AdminWindow::szukajDanychWPolu(string dana, string** tabela, int iloscDanych, int nrPola)
	for (int i = 0; i < iloscDanych; i++)
	{
		if (klienci[i][nrPola] == dana)
		{
			return atoi(dana[i][0]);	//jak znajdzie to zwraca id
		}
	}
	return -1;
}
void AdminWindow::konwertujStringNaDate(string StrData, struct tm *timeinfo)	//format daty yyyy-mm-dd
{	//nie testowalem tego nie wiem czy dziala
	time_t rawtime;
	//struct tm * timeinfo;
	int year, month, day;
	year = atoi(StrData.substr(0, 4));//rok
	month = atoi(StrData.substr(5, 2));//miesiac
	month = atoi(StrData.substr(8, 2))//miesiac 
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	timeinfo->tm_year = year - 1900;
	timeinfo->tm_mon = month - 1;
	timeinfo->tm_mday = day;
	mktime(timeinfo);
}
void AdminWindow::on_pushButtonClientAdd_clicked()
{
	string **klienci = nullptr;
	string **pokoje = nullptr;
	BazaDanych * baza;
	string* rezerwacja, klient;
	int iloscDanych;
	int idKlienta = -1;
	int idPokoju = -1;
	bool czyIstnieje = false;
	rezerwacja = new string[6];
	baza = new BazaDanych();
	iloscDanych = baza->select("klienci", klienci);
	QMessageBox::information(this, "Info", "kliknąłeś Dodaj");
	// TODO: obsluzyc dodawanie

	// pobranie danych z inputow
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
		klient = new string[5];
		klient[1] = clientName.toStdString();
		klient[2] = clientSurname.toStdString();
		klient[3] = clientPesel.toStdString();
		klient[4] = "0";		//telefon;
		klient[5] = "0";		//email;
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
			rezerwacja[1] = idPokoju;
			rezerwacja[2] = idKlienta;
			rezerwacja[3] = clientDate.toStdString();
			rezerwacja[4] = clientDays.toStdString();
			rezerwacja[5] = clientPeople.toStdString();		//tabela rezerwacji mila miec inne pola
			baza->insert("rezerwacje", rezerwacja);
			ui->listWidgetClients->addItem(
				clientName + " " + clientSurname + " " + clientPesel + " " +
				clientDate + " " + clientDays + " " + clientRoomNumber + " " + clientPeople
			);
		}
		else
		{
			//nie ma pokoju
		}
	}
	else
	{
		//error nie udalo sie stowrzyc klienta
	}
}

void AdminWindow::on_pushButtonClientSearch_clicked()
{
	QMessageBox::information(this, "Info", "kliknąłeś Szukaj");
	// TODO: obsluzyc szukanie
}

void AdminWindow::on_pushButtonClientEdit_clicked()
{
	QMessageBox::information(this, "Info", "kliknąłeś Edytuj");
	// TODO: obsluzyc edycje
}

void AdminWindow::on_pushButtonClientDelete_clicked()
{
	QMessageBox::information(this, "Info", "kliknąłeś Usuń");
	// TODO: obsluzyc usuwanie

    // usuwanie zaznaczonego elementu
	delete ui->listWidgetClients->currentItem();
}
