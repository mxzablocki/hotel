#include "infoauthors.h"
#include "ui_infoauthors.h"
#include <QPixmap>

InfoAuthors::InfoAuthors(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoAuthors)
{
    ui->setupUi(this);

    // ikona
    QPixmap iconAuthors(":/images/img/icon-authors.png");
    ui->labelIconAuthors->setPixmap(iconAuthors.scaled(120, 120, Qt::KeepAspectRatio));
}

InfoAuthors::~InfoAuthors()
{
    delete ui;
}
