#include "adminwindow.h"
#include "ui_adminwindow.h"

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
