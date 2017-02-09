#include "roomwindow.h"
#include "ui_roomwindow.h"
#include <QMessageBox>

RoomWindow::RoomWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RoomWindow)
{
    ui->setupUi(this);
}

RoomWindow::~RoomWindow()
{
    delete ui;
}

void RoomWindow::on_pushButtonManageRooms_clicked()
{
    // ukrycie aktualnego okna oraz utworzenie nowego okna (zarzadzanie klientami)
    hide();
    adminWindow = new AdminWindow();
    adminWindow->show();
}

void RoomWindow::on_pushButtonRoomAdd_clicked()
{
	QMessageBox::information(this, "Info", "klikn¹³eœ Dodaj");
}

void RoomWindow::on_pushButtonRoomSearch_clicked()
{
	QMessageBox::information(this, "Info", "klikn¹³eœ Szukaj");
}

void RoomWindow::on_pushButtonRoomEdit_clicked()
{
	QMessageBox::information(this, "Info", "klikn¹³eœ Edytuj");
}

void RoomWindow::on_pushButtonRoomDelete_clicked()
{
	QMessageBox::information(this, "Info", "klikn¹³eœ Usuñ");
}
