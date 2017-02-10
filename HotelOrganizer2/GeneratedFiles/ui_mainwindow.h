/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAuthors;
    QAction *actionApplication;
    QWidget *centralWidget;
    QLabel *labelIconLogin;
    QGroupBox *groupBoxLogin;
    QFormLayout *formLayout;
    QLabel *labelUsername;
    QLineEdit *lineEditUsername;
    QLabel *labelPassword;
    QLineEdit *lineEditPassword;
    QPushButton *pushButtonLogin;
    QMenuBar *menuBar;
    QMenu *menuInformacje;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(600, 250);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(600, 250));
        MainWindow->setMaximumSize(QSize(600, 250));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/img/icon-login.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QStringLiteral(""));
        actionAuthors = new QAction(MainWindow);
        actionAuthors->setObjectName(QStringLiteral("actionAuthors"));
        actionApplication = new QAction(MainWindow);
        actionApplication->setObjectName(QStringLiteral("actionApplication"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        labelIconLogin = new QLabel(centralWidget);
        labelIconLogin->setObjectName(QStringLiteral("labelIconLogin"));
        labelIconLogin->setGeometry(QRect(60, 20, 200, 150));
        labelIconLogin->setScaledContents(false);
        groupBoxLogin = new QGroupBox(centralWidget);
        groupBoxLogin->setObjectName(QStringLiteral("groupBoxLogin"));
        groupBoxLogin->setGeometry(QRect(260, 20, 310, 150));
        groupBoxLogin->setStyleSheet(QStringLiteral(""));
        formLayout = new QFormLayout(groupBoxLogin);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        labelUsername = new QLabel(groupBoxLogin);
        labelUsername->setObjectName(QStringLiteral("labelUsername"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelUsername);

        lineEditUsername = new QLineEdit(groupBoxLogin);
        lineEditUsername->setObjectName(QStringLiteral("lineEditUsername"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditUsername);

        labelPassword = new QLabel(groupBoxLogin);
        labelPassword->setObjectName(QStringLiteral("labelPassword"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelPassword);

        lineEditPassword = new QLineEdit(groupBoxLogin);
        lineEditPassword->setObjectName(QStringLiteral("lineEditPassword"));
        lineEditPassword->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditPassword);

        pushButtonLogin = new QPushButton(groupBoxLogin);
        pushButtonLogin->setObjectName(QStringLiteral("pushButtonLogin"));
        pushButtonLogin->setStyleSheet(QStringLiteral(""));

        formLayout->setWidget(2, QFormLayout::FieldRole, pushButtonLogin);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 25));
        menuInformacje = new QMenu(menuBar);
        menuInformacje->setObjectName(QStringLiteral("menuInformacje"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuInformacje->menuAction());
        menuInformacje->addAction(actionApplication);
        menuInformacje->addAction(actionAuthors);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Hotel Organizer | Logowanie", Q_NULLPTR));
        actionAuthors->setText(QApplication::translate("MainWindow", "Autorzy", Q_NULLPTR));
        actionApplication->setText(QApplication::translate("MainWindow", "Aplikacja", Q_NULLPTR));
        labelIconLogin->setText(QString());
        groupBoxLogin->setTitle(QApplication::translate("MainWindow", "Logowanie", Q_NULLPTR));
        labelUsername->setText(QApplication::translate("MainWindow", "Nazwa u\305\274ytkownika", Q_NULLPTR));
        labelPassword->setText(QApplication::translate("MainWindow", "Has\305\202o", Q_NULLPTR));
        pushButtonLogin->setText(QApplication::translate("MainWindow", "Zaloguj", Q_NULLPTR));
        menuInformacje->setTitle(QApplication::translate("MainWindow", "Informacje", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
