#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox> // wyswietlanie komunikatow podczas logownia
#include <QPixmap>     // do ikon
#include <string>
#include "BazaDanych.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // ikona ekran logowania
    QPixmap iconLogin(":/images/img/icon-login.png");
    ui->labelIconLogin->setPixmap(iconLogin.scaled(120, 120, Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// przycisk logowania
void MainWindow::on_pushButtonLogin_clicked()
{
    BazaDanych *baza;
    baza = new BazaDanych();
    bool poprawneHaslo = false;
    int nrWiersza = -1;  //nr wiersza gdzie znaleziono uzytkownika
    string** uzytkownicy = nullptr;
    int iloscDanych = baza->select("uzytkownicy",uzytkownicy);
    // pobranie nazwy uzytkownika oraz hasla z inputow
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();

    // mechanika logowania
    for (int i = 0; i<iloscDanych;i++)
    {
        if ((username.toStdString() == uzytkownicy[i][3]) && (password.toStdString() == uzytkownicy[i][4]))
        {
            poprawneHaslo = true;
            nrWiersza = i;
            i= iloscDanych;
        }
    }
    if (poprawneHaslo == true)
    {
        if (uzytkownicy[nrWiersza][5]=="admin")   // jesli typ zalogowanego uzytkownika to admin
        {
            QMessageBox::information(this, "Logowanie", "Zostałeś/łaś zalogowany/na jako administrator.");
            // ukrycie aktualnego okna oraz utworzenie nowego okna (zarzadzanie klientami)
            hide();
            adminWindow = new AdminWindow();
            adminWindow->show();
        }
        else if (uzytkownicy[nrWiersza][5]=="recepcjonista")
        {
            QMessageBox::information(this, "Logowanie", "Zostałeś/łaś zalogowany/na jako recepcjonista.");
            hide();
            receptionistWindow = new ReceptionistWindow();
            receptionistWindow->show();
        }
    }
    else
    {
        QMessageBox::warning(this, "Logowanie", "Podano nieprawidłową nazwe użytkownika lub hasło.");
    }
    delete baza;
    for (int i = 0; i< iloscDanych; ++i)
    {
        delete [] uzytkownicy[i];
    }
    delete [] uzytkownicy;
}

// otwarcie okna informacje o aplikacji z menu programu
void MainWindow::on_actionApplication_triggered()
{
    InfoApplication infoApplicationWindow;
    infoApplicationWindow.setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint); // wylaczenie rozszerzania okna
    infoApplicationWindow.setModal(true);
    infoApplicationWindow.exec();
}

// otwarcie okna informacje o autorach
void MainWindow::on_actionAuthors_triggered()
{
    InfoAuthors infoAuthorsWindow;
    infoAuthorsWindow.setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint); // wylaczenie rozszerzania okna
    infoAuthorsWindow.setModal(true);
    infoAuthorsWindow.exec();
}
