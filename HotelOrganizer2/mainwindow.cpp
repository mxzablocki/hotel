#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox> // wyswietlanie komunikator podczas logownia
#include <QPixmap>     // do ikon

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
    // pobranie nazwy uzytkownika oraz hasla z inputow
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();

    // mechanika logowania
    if (username == "admin" && password == "admin")
    {
        QMessageBox::information(this, "Logowanie", "Zostałeś zalogowany jako administrator.");

        // ukrycie aktualnego okna oraz utworzenie nowego okna (zarzadzanie klientami)
        hide();
        adminWindow = new AdminWindow();
        adminWindow->show();
    }
    else
    {
        QMessageBox::warning(this, "Logowanie", "Podano nieprawidłową nazwe użytkownika lub hasło.");
    }
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
