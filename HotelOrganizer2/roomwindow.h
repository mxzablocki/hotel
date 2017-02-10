#ifndef ROOMWINDOW_H
#define ROOMWINDOW_H

#include <QMainWindow>
#include "adminwindow.h"

class AdminWindow;

namespace Ui {
class RoomWindow;
}

class RoomWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RoomWindow(QWidget *parent = 0);
    ~RoomWindow();

private slots:
    void on_pushButtonManageClients_clicked(); // przycisk zarzadzania klientami
	void on_pushButtonRoomAdd_clicked();	   // przycisk dodawanie pokoju
	void on_pushButtonRoomSearch_clicked();	   // przycisk szukanie pokoju
	void on_pushButtonRoomEdit_clicked();      // przycisk edycja pokoju
	void on_pushButtonRoomDelete_clicked();    // przycisk usuwanie pokoju

private:
    Ui::RoomWindow *ui;
    AdminWindow *adminWindow; // przechowuje okno zarzadzania klientami
};

#endif // ROOMWINDOW_H
