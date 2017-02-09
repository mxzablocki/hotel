#include "adminwindow.h"
#include "ui_adminwindow.h"

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
