#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include "roomwindow.h"
#include <string>
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
	
    void on_pushButtonManageRooms_clicked();  // przycisk zarzadzania pokojami
	void on_pushButtonClientAdd_clicked();    // przycisk dodawanie klienta
	void on_pushButtonClientSearch_clicked(); // przycisk szukanie klienta
	void on_pushButtonClientEdit_clicked();   // przycisk edycja klienta
	void on_pushButtonClientDelete_clicked(); // przycisk usuwanie klienta

private:
	void konwertujStringNaDate(std::string StrData, struct tm *timeinfo);
	int szukajDanychWPolu(std::string dana, std::string** tabela, int iloscDanych,int nrPola);	//zwraca id z tabeli a przyjmuje tablice z bazy i nr pola z ktorym ma porownywac
    Ui::AdminWindow *ui;
    RoomWindow *roomWindow; // przechowuje okno zarzadzania pokojami
};

#endif // ADMINWINDOW_H
