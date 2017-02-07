#ifndef INFOAUTHORS_H
#define INFOAUTHORS_H

#include <QDialog>

namespace Ui {
class InfoAuthors;
}

class InfoAuthors : public QDialog
{
    Q_OBJECT

public:
    explicit InfoAuthors(QWidget *parent = 0);
    ~InfoAuthors();

private:
    Ui::InfoAuthors *ui;
};

#endif // INFOAUTHORS_H
