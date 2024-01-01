#ifndef COURCONG_H
#define COURCONG_H

#include <QMainWindow>
#include <QHBoxLayout>
#include"conjugaison.h"
namespace Ui {
class courcong;
}

class courcong : public QMainWindow
{
    Q_OBJECT

public:
    explicit courcong(QWidget *parent = nullptr);
    ~courcong();
private slots:
    void loadQuestion();
    void checkAnswer();
    void nextQuestion();
    void showQuiz();
    void on_nextButton_clicked();

private:
    Ui::courcong *ui;
    QStringList questions;
    QStringList answers;
    int currentQuestionIndex1;
};

#endif // COURCONG_H
