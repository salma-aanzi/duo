#include "courcong.h"
#include "ui_courcong.h"
#include<QMessageBox>

courcong::courcong(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::courcong), currentQuestionIndex1(0)
{
    ui->setupUi(this);
    // Set the background image using stylesheet
    QString imagePath = ":/img/img/bggi.PNG"; // Replace this with your image path
    setStyleSheet("QMainWindow { background-image: url(" + imagePath + "); }");
    //
    connect(ui->submitButton, &QPushButton::clicked, this, &courcong::checkAnswer);
    connect(ui->nextButton, &QPushButton::clicked, this, &courcong::nextQuestion);

    // Ajouter les questions et réponses directement ici
    questions << "Conjugue le verbe 'chanter' à la troisième personne du singulier."
              << "Conjugue le verbe 'aimer' à la première personne du pluriel."
              << "Conjugue le verbe 'finir' à la deuxième personne du singulier."
              << "Conjugue le verbe 'aller' à la troisième personne du pluriel."
              << "Conjugue le verbe 'prendre' à la première personne du singulier."
              << "Conjugue le verbe 'voir' à la deuxième personne du pluriel."
              << "Conjugue le verbe 'vivre' à la première personne du pluriel."
              << "Conjugue le verbe 'manger' à la deuxième personne du singulier."
              << "Conjugue le verbe 'comprendre' à la troisième personne du pluriel."
              << "Conjugue le verbe 'boire' à la première personne du singulier.";

    answers << "il chante" << "nous aimons" << "tu finis" << "ils vont" << "je prends"
            << "vous voyez" << "nous vivons" << "tu manges" << "ils comprennent" << "je bois";


    // loadQuestion(); // Charge la première question au démarrage
    // Masquer les éléments du quiz initialement
    ui->questionLabel->hide();
    ui->answerLineEdit->hide();
    ui->submitButton->hide();
    ui->nextButton->hide();
    ui->label->hide();

    // Afficher le cours au démarrage
    // Afficher tous les QLabel dans le QHBoxLayout
    for (int i = 0; i < ui->horizontalLayout->count(); ++i) {
        QWidget *widget = ui->horizontalLayout->itemAt(i)->widget();
        if (widget) {
            widget->show();
        }
    }

    // Connexion pour démarrer le quiz après avoir lu le cours
    connect(ui->startQuizButton, &QPushButton::clicked, this, &courcong::showQuiz);
}

courcong::~courcong()
{
    delete ui;
}
 void courcong::showQuiz() {
    // Afficher le quiz et masquer le cours
     // Masquer tous les QLabel dans le QHBoxLayout
     for (int i = 0; i < ui->horizontalLayout->count(); ++i) {
         QWidget *widget = ui->horizontalLayout->itemAt(i)->widget();
         if (widget) {
             widget->hide();
         }
     }
    ui->startQuizButton->hide();
    ui->questionLabel->show();
    ui->answerLineEdit->show();
    ui->submitButton->show();
    ui->nextButton->show();
    ui->label->show();

    loadQuestion(); // Commence le quiz
}
void courcong::loadQuestion() {
    if (currentQuestionIndex1 < questions.size()) {
        ui->questionLabel->setText(questions[currentQuestionIndex1]);
        ui->answerLineEdit->clear(); // Si vous utilisez un QLineEdit pour la réponse
    } else {
        QMessageBox::information(this, "Fin du quiz", "Vous avez terminé le quiz !");
    }
}

void courcong::checkAnswer() {
    QString userAnswer = ui->answerLineEdit->text(); // Récupère la réponse de l'utilisateur

    if (currentQuestionIndex1 < answers.size() && userAnswer.toLower() == answers[currentQuestionIndex1].toLower()) {
        QMessageBox::information(this, "Réponse", "Bonne réponse !");
    } else {
        QMessageBox::information(this, "Réponse", "Mauvaise réponse !");
    }
     nextQuestion(); // Appelle la prochaine question après avoir vérifié la répons
}

void courcong::nextQuestion() {
    currentQuestionIndex1++;
    loadQuestion(); // Charge la prochaine question
}

void courcong::on_nextButton_clicked()
{
    //fct to hide the Mainwindow
    this->hide();
    //fct to acces to others window
    Conjugaison *cnj = new Conjugaison();
    cnj->show();
}

