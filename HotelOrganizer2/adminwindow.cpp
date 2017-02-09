#include "adminwindow.h"
#include "ui_adminwindow.h"
#include <QMessageBox>

AdminWindow::AdminWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::AdminWindow)
{
	ui->setupUi(this);
}

AdminWindow::~AdminWindow()
{
	delete ui;
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
}
