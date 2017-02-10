/********************************************************************************
** Form generated from reading UI file 'roomwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMWINDOW_H
#define UI_ROOMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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

class Ui_RoomWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBoxDatabase;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelRoomList;
    QListWidget *listWidgetRooms;
    QGroupBox *groupBoxManage;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBoxRoom;
    QFormLayout *formLayout;
    QLabel *labelRoomName;
    QLabel *labelRoomSurname;
    QLabel *labelRoomInstitution;
    QLineEdit *lineEditRoomInstitution;
    QSpinBox *spinBoxRoomNumber;
    QSpinBox *spinBoxRoomPeople;
    QGroupBox *groupBoxBasicOperations;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonRoomAdd;
    QPushButton *pushButtonRoomSearch;
    QPushButton *pushButtonRoomEdit;
    QPushButton *pushButtonRoomDelete;
    QGroupBox *groupBoxOtherOperations;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonManageClients;
    QPushButton *pushButtonResetForm;
    QGroupBox *groupBoxInfo;
    QFormLayout *formLayout_2;
    QLabel *labelInfoRooms;
    QLabel *labelInfoRoomsNumber;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RoomWindow)
    {
        if (RoomWindow->objectName().isEmpty())
            RoomWindow->setObjectName(QStringLiteral("RoomWindow"));
        RoomWindow->resize(1024, 650);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/img/icon-dashboard.png"), QSize(), QIcon::Normal, QIcon::Off);
        RoomWindow->setWindowIcon(icon);
        centralwidget = new QWidget(RoomWindow);
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
        labelRoomList = new QLabel(groupBoxDatabase);
        labelRoomList->setObjectName(QStringLiteral("labelRoomList"));

        verticalLayout_2->addWidget(labelRoomList);

        listWidgetRooms = new QListWidget(groupBoxDatabase);
        listWidgetRooms->setObjectName(QStringLiteral("listWidgetRooms"));

        verticalLayout_2->addWidget(listWidgetRooms);


        horizontalLayout_3->addWidget(groupBoxDatabase);

        groupBoxManage = new QGroupBox(centralwidget);
        groupBoxManage->setObjectName(QStringLiteral("groupBoxManage"));
        verticalLayout_5 = new QVBoxLayout(groupBoxManage);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        groupBoxRoom = new QGroupBox(groupBoxManage);
        groupBoxRoom->setObjectName(QStringLiteral("groupBoxRoom"));
        formLayout = new QFormLayout(groupBoxRoom);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        labelRoomName = new QLabel(groupBoxRoom);
        labelRoomName->setObjectName(QStringLiteral("labelRoomName"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelRoomName);

        labelRoomSurname = new QLabel(groupBoxRoom);
        labelRoomSurname->setObjectName(QStringLiteral("labelRoomSurname"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelRoomSurname);

        labelRoomInstitution = new QLabel(groupBoxRoom);
        labelRoomInstitution->setObjectName(QStringLiteral("labelRoomInstitution"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelRoomInstitution);

        lineEditRoomInstitution = new QLineEdit(groupBoxRoom);
        lineEditRoomInstitution->setObjectName(QStringLiteral("lineEditRoomInstitution"));
        lineEditRoomInstitution->setMaxLength(500);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditRoomInstitution);

        spinBoxRoomNumber = new QSpinBox(groupBoxRoom);
        spinBoxRoomNumber->setObjectName(QStringLiteral("spinBoxRoomNumber"));
        spinBoxRoomNumber->setMaximum(1000);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBoxRoomNumber);

        spinBoxRoomPeople = new QSpinBox(groupBoxRoom);
        spinBoxRoomPeople->setObjectName(QStringLiteral("spinBoxRoomPeople"));
        spinBoxRoomPeople->setMaximum(10);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBoxRoomPeople);


        verticalLayout_5->addWidget(groupBoxRoom);

        groupBoxBasicOperations = new QGroupBox(groupBoxManage);
        groupBoxBasicOperations->setObjectName(QStringLiteral("groupBoxBasicOperations"));
        horizontalLayout = new QHBoxLayout(groupBoxBasicOperations);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonRoomAdd = new QPushButton(groupBoxBasicOperations);
        pushButtonRoomAdd->setObjectName(QStringLiteral("pushButtonRoomAdd"));

        horizontalLayout->addWidget(pushButtonRoomAdd);

        pushButtonRoomSearch = new QPushButton(groupBoxBasicOperations);
        pushButtonRoomSearch->setObjectName(QStringLiteral("pushButtonRoomSearch"));

        horizontalLayout->addWidget(pushButtonRoomSearch);

        pushButtonRoomEdit = new QPushButton(groupBoxBasicOperations);
        pushButtonRoomEdit->setObjectName(QStringLiteral("pushButtonRoomEdit"));

        horizontalLayout->addWidget(pushButtonRoomEdit);

        pushButtonRoomDelete = new QPushButton(groupBoxBasicOperations);
        pushButtonRoomDelete->setObjectName(QStringLiteral("pushButtonRoomDelete"));

        horizontalLayout->addWidget(pushButtonRoomDelete);


        verticalLayout_5->addWidget(groupBoxBasicOperations);

        groupBoxOtherOperations = new QGroupBox(groupBoxManage);
        groupBoxOtherOperations->setObjectName(QStringLiteral("groupBoxOtherOperations"));
        horizontalLayout_2 = new QHBoxLayout(groupBoxOtherOperations);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButtonManageClients = new QPushButton(groupBoxOtherOperations);
        pushButtonManageClients->setObjectName(QStringLiteral("pushButtonManageClients"));

        horizontalLayout_2->addWidget(pushButtonManageClients);

        pushButtonResetForm = new QPushButton(groupBoxOtherOperations);
        pushButtonResetForm->setObjectName(QStringLiteral("pushButtonResetForm"));

        horizontalLayout_2->addWidget(pushButtonResetForm);


        verticalLayout_5->addWidget(groupBoxOtherOperations);

        groupBoxInfo = new QGroupBox(groupBoxManage);
        groupBoxInfo->setObjectName(QStringLiteral("groupBoxInfo"));
        formLayout_2 = new QFormLayout(groupBoxInfo);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        labelInfoRooms = new QLabel(groupBoxInfo);
        labelInfoRooms->setObjectName(QStringLiteral("labelInfoRooms"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelInfoRooms);

        labelInfoRoomsNumber = new QLabel(groupBoxInfo);
        labelInfoRoomsNumber->setObjectName(QStringLiteral("labelInfoRoomsNumber"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelInfoRoomsNumber->sizePolicy().hasHeightForWidth());
        labelInfoRoomsNumber->setSizePolicy(sizePolicy1);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, labelInfoRoomsNumber);


        verticalLayout_5->addWidget(groupBoxInfo);


        horizontalLayout_3->addWidget(groupBoxManage);

        RoomWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RoomWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1024, 25));
        RoomWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(RoomWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        RoomWindow->setStatusBar(statusbar);

        retranslateUi(RoomWindow);
        QObject::connect(pushButtonResetForm, SIGNAL(clicked()), lineEditRoomInstitution, SLOT(clear()));
        QObject::connect(pushButtonResetForm, SIGNAL(clicked()), spinBoxRoomNumber, SLOT(clear()));
        QObject::connect(pushButtonResetForm, SIGNAL(clicked()), spinBoxRoomPeople, SLOT(clear()));

        QMetaObject::connectSlotsByName(RoomWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RoomWindow)
    {
        RoomWindow->setWindowTitle(QApplication::translate("RoomWindow", "Hotel Organizer | Panel Administracyjny", Q_NULLPTR));
        groupBoxDatabase->setTitle(QApplication::translate("RoomWindow", "Baza Hotel", Q_NULLPTR));
        labelRoomList->setText(QApplication::translate("RoomWindow", "Lista pokoi", Q_NULLPTR));
        groupBoxManage->setTitle(QApplication::translate("RoomWindow", "Zarz\304\205dzanie Hotel", Q_NULLPTR));
        groupBoxRoom->setTitle(QApplication::translate("RoomWindow", "Pok\303\263j", Q_NULLPTR));
        labelRoomName->setText(QApplication::translate("RoomWindow", "Nr pokoju", Q_NULLPTR));
        labelRoomSurname->setText(QApplication::translate("RoomWindow", "Ilo\305\233\304\207 miejsc", Q_NULLPTR));
        labelRoomInstitution->setText(QApplication::translate("RoomWindow", "Plac\303\263wka", Q_NULLPTR));
        groupBoxBasicOperations->setTitle(QApplication::translate("RoomWindow", "Podstawowe operacje", Q_NULLPTR));
        pushButtonRoomAdd->setText(QApplication::translate("RoomWindow", "Dodaj", Q_NULLPTR));
        pushButtonRoomSearch->setText(QApplication::translate("RoomWindow", "Szukaj", Q_NULLPTR));
        pushButtonRoomEdit->setText(QApplication::translate("RoomWindow", "Edytuj", Q_NULLPTR));
        pushButtonRoomDelete->setText(QApplication::translate("RoomWindow", "Usu\305\204", Q_NULLPTR));
        groupBoxOtherOperations->setTitle(QApplication::translate("RoomWindow", "Dodatkowe operacje", Q_NULLPTR));
        pushButtonManageClients->setText(QApplication::translate("RoomWindow", "Zarz\304\205dzaj klientami", Q_NULLPTR));
        pushButtonResetForm->setText(QApplication::translate("RoomWindow", "Resetuj formularz", Q_NULLPTR));
        groupBoxInfo->setTitle(QApplication::translate("RoomWindow", "Informacje o hotelu", Q_NULLPTR));
        labelInfoRooms->setText(QApplication::translate("RoomWindow", "Liczba pokoi", Q_NULLPTR));
        labelInfoRoomsNumber->setText(QApplication::translate("RoomWindow", "0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RoomWindow: public Ui_RoomWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMWINDOW_H
