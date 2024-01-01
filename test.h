#ifndef TEST_H
#define TEST_H

#include <QMainWindow>
#include "base.h"
 ///
#include <QWidget>
#include <vector>
#include <utility>
#include "question.h"
#include"base.h"
#include"alphabet.h"

namespace Ui {
class Test;
}

class Test : public QMainWindow
{
    Q_OBJECT

public:
    explicit Test(QWidget *parent = nullptr);
    ~Test();

private slots:


    void on_submitButton_clicked();    
    void on_next_clicked();

private:
    Ui::Test *ui;
    ////
   /* std::vector<std::pair<QString, QString>> quizQuestions;
    int currentQuestionIndex;

    void displayNextQuestion();
    void displayCorrectAnswerMessage();
    void displayIncorrectAnswerMessage();*/

};

#endif // TEST_H
