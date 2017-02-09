#include "infoapplication.h"
#include "ui_infoapplication.h"
#include <QPixmap>

InfoApplication::InfoApplication(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoApplication)
{
    ui->setupUi(this);

    // ikona ekran logowania
    QPixmap iconHotel(":/images/img/icon-hotel.png");
    ui->labelIconHotel->setPixmap(iconHotel.scaled(120, 120, Qt::KeepAspectRatio));
}

InfoApplication::~InfoApplication()
{
    delete ui;
}
