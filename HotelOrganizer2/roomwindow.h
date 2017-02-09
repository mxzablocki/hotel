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
    void on_pushButtonManageRooms_clicked();

private:
    Ui::RoomWindow *ui;
    AdminWindow *adminWindow; // przechowuje okno zarzadzania klientami
};

#endif // ROOMWINDOW_H
