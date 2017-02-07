#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include "roomwindow.h"

class RoomWindow;

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = 0);
    ~AdminWindow();

private slots:
    void on_pushButtonManageRooms_clicked();

private:
    Ui::AdminWindow *ui;
    RoomWindow *roomWindow; // przechowuje okno zarzadzania pokojami
};

#endif // ADMINWINDOW_H
