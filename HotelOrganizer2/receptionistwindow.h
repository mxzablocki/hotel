#ifndef RECEPTIONISTWINDOW_H
#define RECEPTIONISTWINDOW_H

#include <QMainWindow>
#include <string>
#include "BazaDanych.h"

namespace Ui {
class ReceptionistWindow;
}

class ReceptionistWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ReceptionistWindow(QWidget *parent = 0);
    ~ReceptionistWindow();
	std::string* dzieleniePoSpacji(QString dane, BazaDanych *baza);

private slots:
	void on_pushButtonClientAdd_clicked();    // przycisk dodawanie klienta
	void on_pushButtonClientEdit_clicked();   // przycisk edycja klienta
	void on_pushButtonClientDelete_clicked(); // przycisk usuwanie klienta

private:
	void konwertujStringNaDate(std::string StrData, struct tm *timeinfo);
	int szukajDanychWPolu(std::string dana, std::string** tabela, int iloscDanych,int nrPola);	//zwraca id z tabeli a przyjmuje tablice z bazy i nr pola z ktorym ma porownywac
    Ui::ReceptionistWindow *ui;
};

#endif // RECEPTIONISTWINDOW_H
