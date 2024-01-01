#ifndef ALPHABET_H
#define ALPHABET_H
#include"grammaire.h"
#include"base.h"

#include <QMainWindow>

namespace Ui {
class alphabet;
}

class alphabet : public QMainWindow
{
    Q_OBJECT

public:
    explicit alphabet(QWidget *parent = nullptr);
    ~alphabet();

private slots:
    void on_nextButton_clicked();

    void on_back_2_clicked();

private:
    Ui::alphabet *ui;

};

#endif // ALPHABET_H
