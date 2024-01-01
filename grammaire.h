#ifndef GRAMMAIRE_H
#define GRAMMAIRE_H

#include <QMainWindow>
#include"courgrammaire.h"
#include"base.h"

namespace Ui {
class Grammaire;
}

class Grammaire : public QMainWindow
{
    Q_OBJECT

public:
    explicit Grammaire(QWidget *parent = nullptr);
    ~Grammaire();

private slots:
    void on_cours1_clicked();

    void on_back_clicked();

private:
    Ui::Grammaire *ui;
};

#endif // GRAMMAIRE_H
