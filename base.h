#ifndef BASE_H
#define BASE_H

#include <QMainWindow>
#include "alphabet.h"
#include"grammaire.h"
#include"conjugaison.h"

namespace Ui {
class base;
}

class base : public QMainWindow
{
    Q_OBJECT

public:
    explicit base(QWidget *parent = nullptr);
    ~base();

private slots:
    void on_alphaet_clicked();

    void on_grammaire_clicked();

    void on_gonjugaison_clicked();

private:
    Ui::base *ui;
};

#endif // BASE_H
