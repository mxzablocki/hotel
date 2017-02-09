#include "mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // wczytanie stylow aplikacji
    QFile styleFile(":/styles/qss/style.qss");
    styleFile.open(QFile::ReadOnly);

    // ustawienie stylow
    QString style(styleFile.readAll());
    a.setStyleSheet(style);

    // utworzenie i wyswietlanie glownego okna
    MainWindow w;
    w.show();
    return a.exec();
}
