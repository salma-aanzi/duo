#ifndef PROFIEL_H
#define PROFIEL_H

#include <QMainWindow>
#include<QtCore>
#include "level.h"
#include "mainwindow.h"

namespace Ui {
class profiel;
}

class profiel : public QMainWindow
{
    Q_OBJECT

public:
    explicit profiel(QWidget *parent = nullptr);
    ~profiel();



private slots:
    void on_back_clicked();

    void on_logout_clicked();

private:
    Ui::profiel *ui;
};

#endif // PROFIEL_H
