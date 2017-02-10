#include "adminwindow.h"
#include "ui_adminwindow.h"
#include <QMessageBox>
#include <QString>

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

void AdminWindow::on_pushButtonClientAdd_clicked()
{
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

	ui->listWidgetClients->addItem(
		clientName + " " + clientSurname + " " + clientPesel + " " + 
		clientDate + " " + clientDays + " " + clientRoomNumber + " " + clientPeople
	);
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
