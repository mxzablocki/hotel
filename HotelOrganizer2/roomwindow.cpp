#include "roomwindow.h"
#include "ui_roomwindow.h"
#include <QMessageBox>

RoomWindow::RoomWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RoomWindow)
{
    ui->setupUi(this);
	adminWindow = nullptr;
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

void RoomWindow::on_pushButtonRoomAdd_clicked()
{
	QMessageBox::information(this, "Info", "klikn¹³eœ Dodaj");
	// TODO: obsluzyc dodawanie
}

void RoomWindow::on_pushButtonRoomSearch_clicked()
{
	QMessageBox::information(this, "Info", "klikn¹³eœ Szukaj");
	// TODO: obsluzyc szukanie
}

void RoomWindow::on_pushButtonRoomEdit_clicked()
{
	QMessageBox::information(this, "Info", "klikn¹³eœ Edytuj");
	// TODO: obsluzyc edycje
}

void RoomWindow::on_pushButtonRoomDelete_clicked()
{
	QMessageBox::information(this, "Info", "klikn¹³eœ Usuñ");
	// TODO: obsluzyc usuwanie
}
