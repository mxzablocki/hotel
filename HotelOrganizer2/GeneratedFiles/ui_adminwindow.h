/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBoxDatabase;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelClientList;
    QListWidget *listWidgetClients;
    QGroupBox *groupBoxManage;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBoxClient;
    QFormLayout *formLayout;
    QLabel *labelClientName;
    QLineEdit *lineEditClientName;
    QLabel *labelClientSurname;
    QLineEdit *lineEditClientSurname;
    QLabel *labelClientPesel;
    QLineEdit *lineEditClientPesel;
    QLabel *labelClientDate;
    QLabel *labelClientDays;
    QSpinBox *spinBoxClientRoomNumber;
    QLabel *labelClientRoom;
    QLabel *labelClientPeople;
    QSpinBox *spinBoxClientPeople;
    QDateEdit *dateEditClientDate;
    QSpinBox *spinBoxClientDays;
    QGroupBox *groupBoxBasicOperations;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonClientAdd;
    QPushButton *pushButtonClientSearch;
    QPushButton *pushButtonClientEdit;
    QPushButton *pushButtonClientDelete;
    QGroupBox *groupBoxOtherOperations;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonManageRooms;
    QPushButton *pushButtonResetForm;
    QGroupBox *groupBoxInfo;
    QFormLayout *formLayout_2;
    QLabel *labelInfoClients;
    QLabel *labelInfoClientsNumber;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName(QStringLiteral("AdminWindow"));
        AdminWindow->resize(1024, 650);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/img/icon-dashboard.png"), QSize(), QIcon::Normal, QIcon::Off);
        AdminWindow->setWindowIcon(icon);
        centralwidget = new QWidget(AdminWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBoxDatabase = new QGroupBox(centralwidget);
        groupBoxDatabase->setObjectName(QStringLiteral("groupBoxDatabase"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBoxDatabase->sizePolicy().hasHeightForWidth());
        groupBoxDatabase->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(8);
        groupBoxDatabase->setFont(font);
        verticalLayout_2 = new QVBoxLayout(groupBoxDatabase);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        labelClientList = new QLabel(groupBoxDatabase);
        labelClientList->setObjectName(QStringLiteral("labelClientList"));

        verticalLayout_2->addWidget(labelClientList);

        listWidgetClients = new QListWidget(groupBoxDatabase);
        listWidgetClients->setObjectName(QStringLiteral("listWidgetClients"));

        verticalLayout_2->addWidget(listWidgetClients);


        horizontalLayout_3->addWidget(groupBoxDatabase);

        groupBoxManage = new QGroupBox(centralwidget);
        groupBoxManage->setObjectName(QStringLiteral("groupBoxManage"));
        verticalLayout_5 = new QVBoxLayout(groupBoxManage);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        groupBoxClient = new QGroupBox(groupBoxManage);
        groupBoxClient->setObjectName(QStringLiteral("groupBoxClient"));
        formLayout = new QFormLayout(groupBoxClient);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        labelClientName = new QLabel(groupBoxClient);
        labelClientName->setObjectName(QStringLiteral("labelClientName"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelClientName);

        lineEditClientName = new QLineEdit(groupBoxClient);
        lineEditClientName->setObjectName(QStringLiteral("lineEditClientName"));
        lineEditClientName->setMaxLength(100);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditClientName);

        labelClientSurname = new QLabel(groupBoxClient);
        labelClientSurname->setObjectName(QStringLiteral("labelClientSurname"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelClientSurname);

        lineEditClientSurname = new QLineEdit(groupBoxClient);
        lineEditClientSurname->setObjectName(QStringLiteral("lineEditClientSurname"));
        lineEditClientSurname->setMaxLength(100);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditClientSurname);

        labelClientPesel = new QLabel(groupBoxClient);
        labelClientPesel->setObjectName(QStringLiteral("labelClientPesel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelClientPesel);

        lineEditClientPesel = new QLineEdit(groupBoxClient);
        lineEditClientPesel->setObjectName(QStringLiteral("lineEditClientPesel"));
        lineEditClientPesel->setMaxLength(11);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditClientPesel);

        labelClientDate = new QLabel(groupBoxClient);
        labelClientDate->setObjectName(QStringLiteral("labelClientDate"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelClientDate);

        labelClientDays = new QLabel(groupBoxClient);
        labelClientDays->setObjectName(QStringLiteral("labelClientDays"));

        formLayout->setWidget(4, QFormLayout::LabelRole, labelClientDays);

        spinBoxClientRoomNumber = new QSpinBox(groupBoxClient);
        spinBoxClientRoomNumber->setObjectName(QStringLiteral("spinBoxClientRoomNumber"));
        spinBoxClientRoomNumber->setMaximum(1000);

        formLayout->setWidget(5, QFormLayout::FieldRole, spinBoxClientRoomNumber);

        labelClientRoom = new QLabel(groupBoxClient);
        labelClientRoom->setObjectName(QStringLiteral("labelClientRoom"));

        formLayout->setWidget(5, QFormLayout::LabelRole, labelClientRoom);

        labelClientPeople = new QLabel(groupBoxClient);
        labelClientPeople->setObjectName(QStringLiteral("labelClientPeople"));

        formLayout->setWidget(6, QFormLayout::LabelRole, labelClientPeople);

        spinBoxClientPeople = new QSpinBox(groupBoxClient);
        spinBoxClientPeople->setObjectName(QStringLiteral("spinBoxClientPeople"));
        spinBoxClientPeople->setMaximum(10);

        formLayout->setWidget(6, QFormLayout::FieldRole, spinBoxClientPeople);

        dateEditClientDate = new QDateEdit(groupBoxClient);
        dateEditClientDate->setObjectName(QStringLiteral("dateEditClientDate"));
        dateEditClientDate->setDateTime(QDateTime(QDate(2017, 2, 11), QTime(0, 0, 0)));
        dateEditClientDate->setMinimumDateTime(QDateTime(QDate(2017, 2, 11), QTime(0, 0, 0)));
        dateEditClientDate->setCalendarPopup(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, dateEditClientDate);

        spinBoxClientDays = new QSpinBox(groupBoxClient);
        spinBoxClientDays->setObjectName(QStringLiteral("spinBoxClientDays"));
        spinBoxClientDays->setMaximum(365);

        formLayout->setWidget(4, QFormLayout::FieldRole, spinBoxClientDays);


        verticalLayout_5->addWidget(groupBoxClient);

        groupBoxBasicOperations = new QGroupBox(groupBoxManage);
        groupBoxBasicOperations->setObjectName(QStringLiteral("groupBoxBasicOperations"));
        horizontalLayout = new QHBoxLayout(groupBoxBasicOperations);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonClientAdd = new QPushButton(groupBoxBasicOperations);
        pushButtonClientAdd->setObjectName(QStringLiteral("pushButtonClientAdd"));

        horizontalLayout->addWidget(pushButtonClientAdd);

        pushButtonClientSearch = new QPushButton(groupBoxBasicOperations);
        pushButtonClientSearch->setObjectName(QStringLiteral("pushButtonClientSearch"));

        horizontalLayout->addWidget(pushButtonClientSearch);

        pushButtonClientEdit = new QPushButton(groupBoxBasicOperations);
        pushButtonClientEdit->setObjectName(QStringLiteral("pushButtonClientEdit"));

        horizontalLayout->addWidget(pushButtonClientEdit);

        pushButtonClientDelete = new QPushButton(groupBoxBasicOperations);
        pushButtonClientDelete->setObjectName(QStringLiteral("pushButtonClientDelete"));

        horizontalLayout->addWidget(pushButtonClientDelete);


        verticalLayout_5->addWidget(groupBoxBasicOperations);

        groupBoxOtherOperations = new QGroupBox(groupBoxManage);
        groupBoxOtherOperations->setObjectName(QStringLiteral("groupBoxOtherOperations"));
        horizontalLayout_2 = new QHBoxLayout(groupBoxOtherOperations);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButtonManageRooms = new QPushButton(groupBoxOtherOperations);
        pushButtonManageRooms->setObjectName(QStringLiteral("pushButtonManageRooms"));

        horizontalLayout_2->addWidget(pushButtonManageRooms);

        pushButtonResetForm = new QPushButton(groupBoxOtherOperations);
        pushButtonResetForm->setObjectName(QStringLiteral("pushButtonResetForm"));

        horizontalLayout_2->addWidget(pushButtonResetForm);


        verticalLayout_5->addWidget(groupBoxOtherOperations);

        groupBoxInfo = new QGroupBox(groupBoxManage);
        groupBoxInfo->setObjectName(QStringLiteral("groupBoxInfo"));
        formLayout_2 = new QFormLayout(groupBoxInfo);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        labelInfoClients = new QLabel(groupBoxInfo);
        labelInfoClients->setObjectName(QStringLiteral("labelInfoClients"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelInfoClients);

        labelInfoClientsNumber = new QLabel(groupBoxInfo);
        labelInfoClientsNumber->setObjectName(QStringLiteral("labelInfoClientsNumber"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelInfoClientsNumber->sizePolicy().hasHeightForWidth());
        labelInfoClientsNumber->setSizePolicy(sizePolicy1);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, labelInfoClientsNumber);


        verticalLayout_5->addWidget(groupBoxInfo);


        horizontalLayout_3->addWidget(groupBoxManage);

        AdminWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1024, 25));
        AdminWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        AdminWindow->setStatusBar(statusbar);

        retranslateUi(AdminWindow);
        QObject::connect(pushButtonResetForm, SIGNAL(clicked()), lineEditClientName, SLOT(clear()));
        QObject::connect(pushButtonResetForm, SIGNAL(clicked()), lineEditClientSurname, SLOT(clear()));
        QObject::connect(pushButtonResetForm, SIGNAL(clicked()), lineEditClientPesel, SLOT(clear()));
        QObject::connect(pushButtonResetForm, SIGNAL(clicked()), spinBoxClientPeople, SLOT(clear()));
        QObject::connect(pushButtonResetForm, SIGNAL(clicked()), spinBoxClientRoomNumber, SLOT(clear()));
        QObject::connect(pushButtonResetForm, SIGNAL(clicked()), dateEditClientDate, SLOT(clear()));
        QObject::connect(pushButtonResetForm, SIGNAL(clicked()), spinBoxClientDays, SLOT(clear()));

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminWindow)
    {
        AdminWindow->setWindowTitle(QApplication::translate("AdminWindow", "Hotel Organizer | Panel Administracyjny", Q_NULLPTR));
        groupBoxDatabase->setTitle(QApplication::translate("AdminWindow", "Baza Hotel", Q_NULLPTR));
        labelClientList->setText(QApplication::translate("AdminWindow", "Lista klient\303\263w", Q_NULLPTR));
        groupBoxManage->setTitle(QApplication::translate("AdminWindow", "Zarz\304\205dzanie Hotel", Q_NULLPTR));
        groupBoxClient->setTitle(QApplication::translate("AdminWindow", "Klient", Q_NULLPTR));
        labelClientName->setText(QApplication::translate("AdminWindow", "Imi\304\231", Q_NULLPTR));
        labelClientSurname->setText(QApplication::translate("AdminWindow", "Nazwisko", Q_NULLPTR));
        labelClientPesel->setText(QApplication::translate("AdminWindow", "Pesel", Q_NULLPTR));
        lineEditClientPesel->setInputMask(QString());
        labelClientDate->setText(QApplication::translate("AdminWindow", "Data rezerwacji", Q_NULLPTR));
        labelClientDays->setText(QApplication::translate("AdminWindow", "Czas rezerwacji (ilo\305\233\304\207 dni)", Q_NULLPTR));
        labelClientRoom->setText(QApplication::translate("AdminWindow", "Nr pokoju", Q_NULLPTR));
        labelClientPeople->setText(QApplication::translate("AdminWindow", "Liczba os\303\263b", Q_NULLPTR));
        dateEditClientDate->setDisplayFormat(QApplication::translate("AdminWindow", "dd-MM-yyyy", Q_NULLPTR));
        groupBoxBasicOperations->setTitle(QApplication::translate("AdminWindow", "Podstawowe operacje", Q_NULLPTR));
        pushButtonClientAdd->setText(QApplication::translate("AdminWindow", "Dodaj", Q_NULLPTR));
        pushButtonClientSearch->setText(QApplication::translate("AdminWindow", "Szukaj", Q_NULLPTR));
        pushButtonClientEdit->setText(QApplication::translate("AdminWindow", "Edytuj", Q_NULLPTR));
        pushButtonClientDelete->setText(QApplication::translate("AdminWindow", "Usu\305\204", Q_NULLPTR));
        groupBoxOtherOperations->setTitle(QApplication::translate("AdminWindow", "Dodatkowe operacje", Q_NULLPTR));
        pushButtonManageRooms->setText(QApplication::translate("AdminWindow", "Zarz\304\205dzaj pokojami", Q_NULLPTR));
        pushButtonResetForm->setText(QApplication::translate("AdminWindow", "Resetuj formularz", Q_NULLPTR));
        groupBoxInfo->setTitle(QApplication::translate("AdminWindow", "Informacje o hotelu", Q_NULLPTR));
        labelInfoClients->setText(QApplication::translate("AdminWindow", "Liczba klient\303\263w", Q_NULLPTR));
        labelInfoClientsNumber->setText(QApplication::translate("AdminWindow", "0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
