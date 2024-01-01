#ifndef COURGRAMMAIRE_H
#define COURGRAMMAIRE_H

#include <QMainWindow>
#include <QString>
#include"grammaire.h"

namespace Ui {
class courgrammaire;
}

class courgrammaire : public QMainWindow
{
    Q_OBJECT

public:
    explicit courgrammaire(QWidget *parent = nullptr);
    ~courgrammaire();

private slots:
    void loadQuestion();
    void checkAnswer();
    void nextQuestion();
    void showQuiz();
    void on_nextButton_clicked();

private:
    Ui::courgrammaire *ui;
    QStringList questions;
    QStringList answers;
    int currentQuestionIndex;
};

#endif // COURGRAMMAIRE_H
