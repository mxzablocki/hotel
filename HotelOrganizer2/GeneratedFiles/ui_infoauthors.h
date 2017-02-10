/********************************************************************************
** Form generated from reading UI file 'infoauthors.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOAUTHORS_H
#define UI_INFOAUTHORS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_InfoAuthors
{
public:
    QLabel *labelInfoTitle;
    QLabel *labelInfoText;
    QLabel *labelIconAuthors;
    QFrame *line;

    void setupUi(QDialog *InfoAuthors)
    {
        if (InfoAuthors->objectName().isEmpty())
            InfoAuthors->setObjectName(QStringLiteral("InfoAuthors"));
        InfoAuthors->resize(600, 590);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/img/icon-authors.png"), QSize(), QIcon::Normal, QIcon::Off);
        InfoAuthors->setWindowIcon(icon);
        InfoAuthors->setStyleSheet(QStringLiteral(""));
        labelInfoTitle = new QLabel(InfoAuthors);
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
        labelInfoText = new QLabel(InfoAuthors);
        labelInfoText->setObjectName(QStringLiteral("labelInfoText"));
        labelInfoText->setGeometry(QRect(0, 190, 601, 251));
        labelInfoText->setStyleSheet(QStringLiteral(""));
        labelInfoText->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        labelInfoText->setWordWrap(true);
        labelIconAuthors = new QLabel(InfoAuthors);
        labelIconAuthors->setObjectName(QStringLiteral("labelIconAuthors"));
        labelIconAuthors->setGeometry(QRect(240, 10, 120, 120));
        labelIconAuthors->setScaledContents(false);
        labelIconAuthors->setAlignment(Qt::AlignCenter);
        line = new QFrame(InfoAuthors);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(199, 180, 201, 20));
        line->setStyleSheet(QStringLiteral(""));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        retranslateUi(InfoAuthors);

        QMetaObject::connectSlotsByName(InfoAuthors);
    } // setupUi

    void retranslateUi(QDialog *InfoAuthors)
    {
        InfoAuthors->setWindowTitle(QApplication::translate("InfoAuthors", "Hotel Organizer | Autorzy", Q_NULLPTR));
        labelInfoTitle->setText(QApplication::translate("InfoAuthors", "Autorzy", Q_NULLPTR));
        labelInfoText->setText(QApplication::translate("InfoAuthors", "<head></head>\n"
"<body>\n"
"<p>Przy planowaniu, tworzeniu oraz testowaniu aplikacji Hotel Organizer wzi\304\231\305\202y udzia\305\202 nast\304\231puj\304\205ce osoby:</p>\n"
"<ul>\n"
"  <li>J\303\263zef Mazur</li>\n"
"  <li>Pawe\305\202 Kudzia</li>\n"
"  <li>Maciej Zab\305\202ocki</li>\n"
"  <li>Robert Steiman</li>\n"
"  <li>Izabela Sad\305\202owska</li>\n"
"</ul>\n"
"<p>Je\305\233li masz sugestie dotycz\304\205ce dzia\305\202ania i budowy programu np. chcia\305\202by\305\233 aby dodano nowe, interesuj\304\205ce funkcjonalno\305\233ci lub znalaz\305\202e\305\233 b\305\202\304\205d, skontaktuj si\304\231 z nami na Facebooku lub napisz na email: hotel@organizer.com :)</p>\n"
"</body>", Q_NULLPTR));
        labelIconAuthors->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class InfoAuthors: public Ui_InfoAuthors {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOAUTHORS_H
