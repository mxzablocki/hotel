#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "adminwindow.h"
#include "infoapplication.h"
#include "infoauthors.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonLogin_clicked();			// przycisk logowania
    void on_actionApplication_triggered();		// opcja "o aplikacji" z menu informacje
    void on_actionAuthors_triggered();			// opcja "o autorach" z menu informacje

private:
    Ui::MainWindow *ui;
    AdminWindow *adminWindow;                   // okno zarzadzania klientami
    InfoApplication *infoApplicationWindow;     // okno informacje o aplikacji
    InfoAuthors *infoAuthorsWindow;             // okno informacje o autorach
};

#endif // MAINWINDOW_H
