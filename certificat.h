#ifndef CERTIFICAT_H
#define CERTIFICAT_H

#include <QMainWindow>
#include"base.h"
namespace Ui {
class certificat;
}

class certificat : public QMainWindow
{
    Q_OBJECT

public:
    explicit certificat(QWidget *parent = nullptr);
    ~certificat();

private slots:
    void on_back_clicked();

private:
    Ui::certificat *ui;
};

#endif // CERTIFICAT_H
