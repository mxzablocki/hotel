#include "roomwindow.h"
#include "ui_roomwindow.h"

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

void RoomWindow::on_pushButtonManageRooms_clicked()
{
    // ukrycie aktualnego okna oraz utworzenie nowego okna (zarzadzanie klientami)
    hide();
    adminWindow = new AdminWindow();
    adminWindow->show();
}
