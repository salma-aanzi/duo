#ifndef COURLEXI_H
#define COURLEXI_H

#include <QMainWindow>
#include"quizmanager.h"
#include"lexique.h"
namespace Ui {
class courlexi;
}

class courlexi : public QMainWindow
{
    Q_OBJECT

public:
    explicit courlexi(QWidget *parent = nullptr);
    ~courlexi();
    void showQuiz() ;
    // Implémentation d'autres méthodes pour le cours de grammaire
    void loadQuestion() ;
    void checkAnswer() ;
    void nextQuestion() ;
private slots:


    void on_nextButton_clicked();

private:
    Ui::courlexi *ui;
    QStringList questions;
    QStringList answers;
    int currentQuestionIndex;
};

#endif // COURLEXI_H




