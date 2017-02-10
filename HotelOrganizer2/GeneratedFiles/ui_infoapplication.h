/********************************************************************************
** Form generated from reading UI file 'infoapplication.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOAPPLICATION_H
#define UI_INFOAPPLICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_InfoApplication
{
public:
    QLabel *labelInfoTitle;
    QLabel *labelInfoText;
    QLabel *labelIconHotel;
    QFrame *line;

    void setupUi(QDialog *InfoApplication)
    {
        if (InfoApplication->objectName().isEmpty())
            InfoApplication->setObjectName(QStringLiteral("InfoApplication"));
        InfoApplication->resize(600, 590);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/img/icon-hotel.png"), QSize(), QIcon::Normal, QIcon::Off);
        InfoApplication->setWindowIcon(icon);
        InfoApplication->setStyleSheet(QStringLiteral(""));
        labelInfoTitle = new QLabel(InfoApplication);
        labelInfoTitle->setObjectName(QStringLiteral("labelInfoTitle"));
        labelInfoTitle->setGeometry(QRect(0, 120, 601, 71));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelInfoTitle->sizePolicy().hasHeightForWidth());
        labelInfoTitle->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        labelInfoTitle->setFont(font);
        labelInfoTitle->setStyleSheet(QStringLiteral(""));
        labelInfoTitle->setAlignment(Qt::AlignCenter);
        labelInfoText = new QLabel(InfoApplication);
        labelInfoText->setObjectName(QStringLiteral("labelInfoText"));
        labelInfoText->setGeometry(QRect(0, 180, 601, 411));
        labelInfoText->setStyleSheet(QStringLiteral(""));
        labelInfoText->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        labelInfoText->setWordWrap(true);
        labelIconHotel = new QLabel(InfoApplication);
        labelIconHotel->setObjectName(QStringLiteral("labelIconHotel"));
        labelIconHotel->setGeometry(QRect(240, 10, 120, 120));
        labelIconHotel->setScaledContents(false);
        labelIconHotel->setAlignment(Qt::AlignCenter);
        line = new QFrame(InfoApplication);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(199, 180, 201, 20));
        line->setStyleSheet(QStringLiteral(""));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        retranslateUi(InfoApplication);

        QMetaObject::connectSlotsByName(InfoApplication);
    } // setupUi

    void retranslateUi(QDialog *InfoApplication)
    {
        InfoApplication->setWindowTitle(QApplication::translate("InfoApplication", "Hotel Organizer | Aplikacja", Q_NULLPTR));
        labelInfoTitle->setText(QApplication::translate("InfoApplication", "Hotel Organizer", Q_NULLPTR));
        labelInfoText->setText(QApplication::translate("InfoApplication", "<head></head>\n"
"<body>\n"
"<p>Hotel Organizer jest aplikacj\304\205 okienkow\304\205 (GUI) s\305\202u\305\274\304\205c\304\205 do zarz\304\205dzania rezerwacjami w hotelu. Program mo\305\274e by\304\207 instalowany na komputerze pod kontrol\304\205 systemu Microsoft Windows w recepcji oraz mo\305\274e gromadzi\304\207 dane w plikach na lokalnym komputerze. Z programu mo\305\274e korzysta\304\207 naraz tylko jeden u\305\274ytkownik po uprzednim zalogowaniu si\304\231.</p>\n"
"\n"
"<p>Oprogramowanie posiada nast\304\231puj\304\205ce funkcjonalno\305\233ci:</p>\n"
"<ul>\n"
"  <li>Przegl\304\205danie bazy klient\303\263w,</li>\n"
"  <li>Przegl\304\205danie bazy pokoi,</li>\n"
"  <li>Zarz\304\205dzanie baz\304\205 klient\303\263w (podstawowe operacje tj. dodawanie, wyszukiwanie, edycja, usuwanie),</li>\n"
"  <li>Zarz\304\205dzanie baz\304\205 pokoi (podstawowe operacje tj. dodawanie, wyszukiwanie, edycja, usuwanie),</li>\n"
"  <li>Generowanie log\303\263w,</li>\n"
"  <li>I wiele wi\304\231cej...</li>\n"
"</ul>\n"
""
                        "\n"
"<p>Informacje techniczne:</p>\n"
"<ul>\n"
"  <li>Wersja aplikacji: <strong>1.0</strong>,</li>\n"
"  <li>Wykorzystane biblioteki: Qt (GUI).</li>\n"
"</ul>\n"
"</body>", Q_NULLPTR));
        labelIconHotel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class InfoApplication: public Ui_InfoApplication {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOAPPLICATION_H
