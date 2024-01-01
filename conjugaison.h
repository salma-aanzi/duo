#ifndef CONJUGAISON_H
#define CONJUGAISON_H

#include <QMainWindow>
#include "courcong.h"
#include "base.h"

namespace Ui {
class Conjugaison;
}

class Conjugaison : public QMainWindow
{
    Q_OBJECT

public:
    explicit Conjugaison(QWidget *parent = nullptr);
    ~Conjugaison();

private slots:
    void on_coursco_clicked();

    void on_back_clicked();

private:
    Ui::Conjugaison *ui;
};

#endif // CONJUGAISON_H
