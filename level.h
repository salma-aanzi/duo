#ifndef LEVEL_H
#define LEVEL_H

#include <QMainWindow>
#include <QMessageBox>
#include "test.h"
#include "profiel.h"

namespace Ui {
class level;
}

class level : public QMainWindow
{
    Q_OBJECT

public:
    explicit level(QWidget *parent = nullptr);
    ~level();

private slots:
    void on_base_clicked();
    void on_sauter_clicked();

    void on_profe_clicked();

private:
    Ui::level *ui;
};

#endif // LEVEL_H
