#include "test.h"
#include "ui_test.h"
#include <QMessageBox>
#include <QCheckBox>
#include "string" //


QString question[] = {
    "Quel est le nom du groupe de mots qui remplace un nom ou un groupe nominal ?",
    "Quelle est la forme du verbe 'aller' à la 3e personne du pluriel au futur simple ?",
    "Quel mot est le synonyme de 'éphémère' ?",
    "Quel est le pluriel de 'cheval' ?",
    "Comment s'écrit le mot signifiant 'grand' au féminin ?",
    "Quel est l'adverbe de temps dans la phrase : 'Hier, nous sommes allés au cinéma' ?",
    "Quelle est la nature grammaticale du mot 'souvent' ?",
    "Quel est le participe passé du verbe 'finir' ?",
    "Quelle est la fonction du mot 'avec' dans la phrase : 'Il mange avec appétit' ?",
    "Comment s'appelle la figure de style utilisant des termes opposés ?"
};

QString optiona[] = {
    "Pronom", "iront", "Courant", "chevals", "grande", "Hier", "Adverbe", "Finiré", "Verbe", "Antithèse"
};

QString optionb[] = {
    "Déterminant", "ironts", "Durable", "cheveux", "grand", "Nous", "Conjonction", "Finissant", "Adjectif", "Métaphore"
};

QString optionc[] = {
    "Verbe", "alleront", "Permanent", "chevaux", "grande", "Allés", "Adjectif", "Finie", "Préposition", "Hyperbole"
};

QString optiond[] = {
    "Adverbe", "ira", "Fugace", "chevals", "grands", "Mange", "Article", "Finis", "Conjonction", "Litote"
};

Test::Test(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Test)

{
    ui->setupUi(this);

    // Set the background image using stylesheet
    QString imagePath = ":/img/img/bggi.PNG"; // Replace this with your image path
    setStyleSheet("QMainWindow { background-image: url(" + imagePath + "); }");

    ui->plainTextEdit->setPlainText(question[0]);
    ui->checkBox->setText(optiona[0]);
    ui->checkBox_2->setText(optionb[0]);
    ui->checkBox_3->setText(optionc[0]);
    ui->checkBox_4->setText(optiond[0]);
    ui->next->hide();
}
//

Test::~Test()
{
    delete ui;
}
static int count=1;
static int score=0;
void Test::on_submitButton_clicked()
{
    /*QString userAnswer = ui->lineEditAnswer->text();

    if (currentQuestionIndex < quizQuestions.size()) {
        QString expectedAnswer = quizQuestions[currentQuestionIndex].second;

        if (userAnswer == expectedAnswer) {
            displayCorrectAnswerMessage();
        } else {
            displayIncorrectAnswerMessage();
        }

        currentQuestionIndex++;
        displayNextQuestion(); // Affiche la question suivante
    }*/
    if(count<9){
        if(ui->checkBox->isChecked()){
            score++;}
        ui->plainTextEdit->setPlainText(question[count]);
        ui->checkBox->setChecked(false);
        ui->checkBox_2->setChecked(false);
        ui->checkBox_3->setChecked(false);
        ui->checkBox_4->setChecked(false);

        ui->checkBox->setText(optiona[count]);
        ui->checkBox_2->setText(optionb[count]);
        ui->checkBox_3->setText(optionc[count]);
        ui->checkBox_4->setText(optiond[count]);
        count++;
    }
    else{
        ui->plainTextEdit->setPlainText("      Your score is : "+QString::number(score));
        ui->checkBox->hide();
        ui->checkBox_2->hide();
        ui->checkBox_3->hide();
        ui->checkBox_4->hide();
        ui->submitButton->hide();
        ui->label->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->hide();
        ui->next->show();
    }

}


/*void Test::displayNextQuestion() {
    if (currentQuestionIndex < quizQuestions.size()) {
        QString currentQuestion = quizQuestions[currentQuestionIndex].first;
        ui->labelQuestion->setText(currentQuestion); // Affiche la question dans votre interface
        /*ui->lineEditAnswer->clear(); // Efface la zone de réponse
        ui->labelResult->clear(); // Efface le message de résultat précédent
    } else {
        ui->labelQuestion->setText("Quiz terminé"); // Indique que le quiz est terminé
    }
}

void Test::displayCorrectAnswerMessage() {
    ui->labelResult->setText("Bonne réponse !");
}

void Test::displayIncorrectAnswerMessage() {
    ui->labelResult->setText("Mauvaise réponse !");
}
bool Test::checkAnswer() {
    QString expectedAnswer = quizQuestions[currentQuestionIndex].second;
    QList<QCheckBox *> checkBoxes = ui->groupBox->findChildren<QCheckBox *>();

    QString userAnswer;
    for (QCheckBox *checkBox : checkBoxes) {
        if (checkBox->isChecked()) {
            userAnswer += checkBox->text() + " ";
        }
    }

    // Compare la réponse de l'utilisateur avec la réponse attendue
    return (userAnswer.trimmed() == expectedAnswer);
} */

void Test::on_next_clicked()
{
    if (score > 5) {
        QMessageBox::information(this, "Félicitations", "Vous êtes compétent !");
        // Redirection vers la page de base pour commencer les cours (à adapter en fonction de votre application)
        base *bas = new base();
        bas->show();
        this->hide(); // Cachez la fenêtre actuelle si nécessaire
    } else {
        QMessageBox::information(this, "Score insuffisant", "Vous n'avez pas atteint le score requis.");
        // Redirection vers la page d'Alphabet (à adapter en fonction de votre application)
        alphabet *alpha = new alphabet();
        alpha->show();
        this->hide(); // Cachez la fenêtre actuelle si nécessaire

    }
}

