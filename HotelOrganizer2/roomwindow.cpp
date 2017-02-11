#include "roomwindow.h"
#include "ui_roomwindow.h"
#include <QMessageBox>
#include "BazaDanych.h"
RoomWindow::RoomWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RoomWindow)
{
    ui->setupUi(this);
	adminWindow = nullptr;
	BazaDanych *baza;
	int iloscDanych = 0;
	string** pokoje;
	QString IDpokoju, nrPokoju, maxIloscMiejsc;
	baza = new BazaDanych();
	iloscDanych = baza->select("pokoje", pokoje);
	for (int i = 0; i < iloscDanych; i++)
	{
		IDpokoju = QString::fromStdString(pokoje[i][0]);
		nrPokoju = QString::fromStdString(pokoje[i][1]);
		maxIloscMiejsc = QString::fromStdString(pokoje[i][2]);
		ui->listWidgetRooms->addItem(IDpokoju + " " + nrPokoju + " " + maxIloscMiejsc);
	}
	ui->labelInfoRoomsNumber->setText(QString::number(iloscDanych));
	delete baza;
	for (int i = 0; i < iloscDanych; i++)
	{
		delete[] pokoje[i];
	}
	delete[] pokoje;

}

RoomWindow::~RoomWindow()
{
    delete ui;
	// zwalnianie okna zarzadzania klientami
	// musi byc zwolnione, poniewaz tworzone jest bez uzycia parametru (okno nie ma "rodzica")
	delete adminWindow;
}

void RoomWindow::on_pushButtonManageClients_clicked()
{
    // ukrycie aktualnego okna oraz utworzenie nowego okna (zarzadzanie klientami)
    hide();
    adminWindow = new AdminWindow();
    adminWindow->show();
}
int RoomWindow::szukajDanychWPolu(std::string dana, std::string** tabela, int iloscDanych, int nrPola)
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
string* RoomWindow::dzieleniePoSpacji(QString dane, BazaDanych *baza)
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
			dana[licznikDanych] = +linia[i];
		}
		else
		{
			licznikDanych++;
			tmp = new string[licznikDanych + 1];
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
void RoomWindow::on_pushButtonRoomAdd_clicked()
{
	BazaDanych *baza;
	string** pokoje = nullptr;
	string* pokoj= nullptr;
	int iloscDanych = 0;
	int idPokoju = -1;
	pokoj = new string[3];
	QMessageBox::information(this, "Info", "kliknąłeś Dodaj");
	// TODO: obsluzyc dodawanie
	QString IDpokoju;
	QString nrPokoju = ui->spinBoxRoomNumber->text();
	QString maxIloscOsob = ui->spinBoxRoomPeople->text();
	baza = new BazaDanych();
	iloscDanych = baza->select("pokoje", pokoje);
	idPokoju = szukajDanychWPolu(nrPokoju.toStdString(), pokoje, iloscDanych, 1);
	if (idPokoju == -1)	//jesli taki pokoj nie istnieje
	{
		pokoj[1] = nrPokoju.toStdString();
		pokoj[2] = maxIloscOsob.toStdString();
		idPokoju = baza->insert("pokoje", pokoj);
		IDpokoju = QString::number(idPokoju);
		ui->listWidgetRooms->addItem(IDpokoju + " " + nrPokoju + " " + maxIloscOsob);
		baza->zapiszDane();
		ui->labelInfoRoomsNumber->setText(QString::number(iloscDanych));
	}
	else
	{
		QMessageBox::information(this, "Info", "Taki pokój już istnieje");
	}
	delete baza;
	for (int i = 0; i < iloscDanych; i++)
	{
		delete[] pokoje[i];
	}
	delete[] pokoje;
}

void RoomWindow::on_pushButtonRoomSearch_clicked()
{
	BazaDanych *baza;
	QMessageBox::information(this, "Info", "kliknąłeś Szukaj");
	// TODO: obsluzyc szukanie
	QString IDpokoju;
	QString nrPokoju = ui->spinBoxRoomNumber->text();
	QString maxIloscOsob = ui->spinBoxRoomPeople->text();
	string* daneSzukania;
	string** pokoje;
	baza = new BazaDanych();
	int iloscDanych = baza->select("pokoje", pokoje);
	daneSzukania = new string[3];
	daneSzukania[1] = nrPokoju.toStdString();
	daneSzukania[2] = maxIloscOsob.toStdString();

	if (daneSzukania[1] != "0")
	{
		for (int i = 0; i < iloscDanych; i++)
		{
			if (pokoje[i][1] != daneSzukania[1])
			{
				pokoje[i][0] = "";	//jesli rozne to zerujemy ID
			}
		}
	}
	else if (daneSzukania[2] != "0")
	{
		for (int i = 0; i < iloscDanych; i++)
		{
			if (pokoje[i][2] != daneSzukania[2])
			{
				pokoje[i][0] = "";	//jesli rozne to zerujemy ID
			}
		}
	}
	else if ((daneSzukania[1] != "0") && (daneSzukania[2] != "0"))
	{
		for (int i = 0; i < iloscDanych; i++)
		{
			if ((pokoje[i][1] != daneSzukania[1]) && (pokoje[i][2] != daneSzukania[2]))
			{
				pokoje[i][0] = "";	//jesli rozne to zerujemy ID
			}
		}
	}
	

	while (ui->listWidgetRooms->count() > 0)
	{
		ui->listWidgetRooms->takeItem(0);
	}
	for (int i = 0; i < iloscDanych; i++)
	{
		if (pokoje[i][0] != "")
		{
			IDpokoju = QString::fromStdString(pokoje[i][0]);
			nrPokoju = QString::fromStdString(pokoje[i][1]);
			maxIloscOsob = QString::fromStdString(pokoje[i][2]);
			ui->listWidgetRooms->addItem(IDpokoju + " " + nrPokoju + " " + maxIloscOsob);
		}
	}
}

void RoomWindow::on_pushButtonRoomEdit_clicked()
{
	QMessageBox::information(this, "Info", "kliknąłeś Edytuj");
	BazaDanych *baza;
	string** pokoje;
	string* pokoj;
	string* dane;
	int iloscDanych = 0;
	int idPokoju = -1;
	QString wiersz;
	if ((ui->listWidgetRooms->currentItem()->text()) != nullptr)	//jesli jest zaznaczone
	{
		baza = new BazaDanych();
		pokoj = new string[3];
		wiersz = ui->listWidgetRooms->currentItem()->text();
		dane = dzieleniePoSpacji(wiersz, baza);
		//TODO ustawienie danych do rezerwacji

		baza->remove("pokoje", atoi(dane[0].c_str()));	//usuwa rezerwacje z bazy
		delete ui->listWidgetRooms->currentItem();
		baza->zapiszDane();
		//baza->zapiszDane();
		QString IDpokoju;
		QString nrPokoju = ui->spinBoxRoomNumber->text();
		QString maxIloscOsob = ui->spinBoxRoomPeople->text();
		baza = new BazaDanych();
		iloscDanych = baza->select("pokoje", pokoje);
		idPokoju = szukajDanychWPolu(nrPokoju.toStdString(), pokoje, iloscDanych, 1);
		if (idPokoju == -1)	//jesli taki pokoj nie istnieje
		{
			pokoj[1] = nrPokoju.toStdString();
			pokoj[2] = maxIloscOsob.toStdString();
			idPokoju = baza->insert("pokoje", pokoj);
			IDpokoju = QString::number(idPokoju);
			ui->listWidgetRooms->addItem(IDpokoju + " " + nrPokoju + " " + maxIloscOsob);
			baza->zapiszDane();

		}
		else
		{
			QMessageBox::information(this, "Info", "Taki pokój już istnieje");
		}

	}
	// TODO: obsluzyc edycje
}

void RoomWindow::on_pushButtonRoomDelete_clicked()
{
	BazaDanych *baza;
	string** pokoje;
	string* pokoj;
	string* dane;
	QString wiersz;
	QMessageBox::information(this, "Info", "kliknąłeś Usuń");
	if ((ui->listWidgetRooms->currentItem()->text()) != nullptr)	//jesli jest zaznaczone
	{
		baza = new BazaDanych();
		pokoj = new string[3];
		string** pokoje;
		int iloscDanych;
		wiersz = ui->listWidgetRooms->currentItem()->text();
		dane = dzieleniePoSpacji(wiersz, baza);
		//TODO ustawienie danych do rezerwacji
		baza->remove("pokoje", atoi(dane[0].c_str()));	//usuwa rezerwacje z bazy
		delete ui->listWidgetRooms->currentItem();
		baza->zapiszDane();
		iloscDanych = baza->select("pokoje", pokoje);
		ui->labelInfoRoomsNumber->setText(QString::number(iloscDanych));
	}
	// TODO: obsluzyc usuwanie
}
