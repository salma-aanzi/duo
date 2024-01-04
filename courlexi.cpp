#include "courlexi.h"
#include "ui_courlexi.h"
#include <QMessageBox>

courlexi::courlexi(QWidget *parent)
    : QMainWindow(parent)

    , ui(new Ui::courlexi), currentQuestionIndex(0)
{
    ui->setupUi(this);
    // Set the background image using stylesheet
    QString imagePath = ":/img/img/bggi.PNG"; // Replace this with your image path
    setStyleSheet("QMainWindow { background-image: url(" + imagePath + "); }");
    //
    connect(ui->submButton, &QPushButton::clicked, this, &courlexi::checkAnswer);
    connect(ui->nextButton, &QPushButton::clicked, this, &courlexi::nextQuestion);
    // Ajouter les questions et réponses directement ici
    questions << "Qu'est-ce qu'un nom ?"
              << "Quel est le rôle des verbes dans une phrase ?"
              << "Comment les adjectifs modifient-ils les noms ?"
              << "Quel est le but des adverbes dans une phrase ?"
              << "Quelle est la fonction des pronoms en grammaire ?"
              << "Quelle est l'utilité des conjonctions dans une phrase ?"
              << "Quels sont les rôles des déterminants en grammaire ?"
              << "Quelle est la fonction des prépositions dans une phrase ?";


    answers << "Personnes, lieux, choses"
            << "Actions, états"
            << "Caractéristiques des noms"
            << "Comment, où, quand"
            << "Remplacent des noms"
            << "Relient des éléments"
            << "Précisent un nom"
            << "Établissent des liens";


    // loadQuestion(); // Charge la première question au démarrage

    // Masquer les éléments du quiz initialement
    ui->questionLabel->hide();
    ui->answerLineEdit->hide();
    ui->submButton->hide();
    ui->nextButton->hide();


    // Afficher le cours au démarrage
    ui->lessonLabel->show();

    // Connexion pour démarrer le quiz après avoir lu le cours
    connect(ui->startQuizButton, &QPushButton::clicked, this, &courlexi::showQuiz);
    loadQuestion(); // Appeler ici pour afficher la première question
}

courlexi::~courlexi()
{
    delete ui;
}

void courlexi::showQuiz() {
    // Implémentation de showQuiz spécifique au cours de grammaire
    // Cacher certains éléments et afficher d'autres pour le quiz de conjugaison
    ui->lessonLabel->hide();
    ui->startQuizButton->hide();
    ui->questionLabel->show();
    ui->answerLineEdit->show();
    ui->submButton->show();
    ui->nextButton->show();


    currentQuestionIndex = 0;
    loadQuestion(); // Commencer le quiz
}
void courlexi::loadQuestion() {
    if (currentQuestionIndex < questions.size()) {
        ui->questionLabel->setText(questions[currentQuestionIndex]);
        ui->answerLineEdit->clear(); // Si vous utilisez un QLineEdit pour la réponse


        currentQuestionIndex++; // Supposons que c'est votre index pour les questions
    } else {
        QMessageBox::information(this, "Fin du quiz", "Vous avez terminé le quiz !");
    }
}

void courlexi::checkAnswer() {
    QString userAnswer = ui->answerLineEdit->text(); // Récupère la réponse de l'utilisateur

    //if (currentQuestionIndex < answers.size() && userAnswer.toLower() == answers[currentQuestionIndex].toLower()) {
    if (currentQuestionIndex > 0 && userAnswer.toLower() == answers[currentQuestionIndex - 1].toLower()){
        QMessageBox::information(this, "Réponse", "Bonne réponse !");
    } else {
        QMessageBox::information(this, "Réponse", "Mauvaise réponse !");
    }
     nextQuestion(); // Appelle la prochaine question après avoir vérifié la répons
}

void courlexi::nextQuestion() {
    currentQuestionIndex++;
    loadQuestion(); // Charge la prochaine question
}




void courlexi::on_nextButton_clicked()
{

    //fct to hide the Mainwindow
    this->hide();
    //fct to acces to others window
    Lexique *lxq = new Lexique();
    lxq->show();
}

