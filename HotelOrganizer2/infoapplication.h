#ifndef INFOAPPLICATION_H
#define INFOAPPLICATION_H

#include <QDialog>

namespace Ui {
class InfoApplication;
}

class InfoApplication : public QDialog
{
    Q_OBJECT

public:
    explicit InfoApplication(QWidget *parent = 0);
    ~InfoApplication();

private:
    Ui::InfoApplication *ui;
};

#endif // INFOAPPLICATION_H
