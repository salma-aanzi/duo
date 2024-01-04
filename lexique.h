#ifndef LEXIQUE_H
#define LEXIQUE_H

#include <QMainWindow>
#include"base.h"
#include"courlexi.h"

namespace Ui {
class Lexique;
}

class Lexique : public QMainWindow
{
    Q_OBJECT

public:
    explicit Lexique(QWidget *parent = nullptr);
    ~Lexique();

private slots:
    void on_back_clicked();

    void on_cours1_clicked();

private:
    Ui::Lexique *ui;
};

#endif // LEXIQUE_H
