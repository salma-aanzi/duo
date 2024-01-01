#include "courgrammaire.h"
#include "ui_courgrammaire.h"
#include <QMessageBox>

courgrammaire::courgrammaire(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::courgrammaire) , currentQuestionIndex(0)
{
    ui->setupUi(this);
    // Set the background image using stylesheet
    QString imagePath = ":/img/img/bggi.PNG"; // Replace this with your image path
    setStyleSheet("QMainWindow { background-image: url(" + imagePath + "); }");
    //
    connect(ui->submButton, &QPushButton::clicked, this, &courgrammaire::checkAnswer);
    connect(ui->nextButton, &QPushButton::clicked, this, &courgrammaire::nextQuestion);
    // Ajouter les questions et réponses directement ici
    questions << "Quel est l'article défini masculin singulier ?"
              << "Quel est l'article défini féminin singulier ?"
              << "Quel est l'article défini pluriel ?"
              << "Quel est l'article indéfini masculin singulier ?"
              << "Quel est l'article indéfini féminin singulier ?"
              << "Quel est l'article partitif masculin singulier ?"
              << "Quel est l'article partitif féminin singulier ?"
              << "Quel est l'article partitif pluriel ?"
              << "Quel est l'article contracté pour 'à le' ?"
              << "Quel est l'article contracté pour 'de le' ?";

        answers << "le" << "la" << "les" << "un" << "une" << "du" << "de la" << "des" << "au" << "du";

   // loadQuestion(); // Charge la première question au démarrage

        // Masquer les éléments du quiz initialement
        ui->questionLabel->hide();
        ui->answerLineEdit->hide();
        ui->submButton->hide();
        ui->nextButton->hide();
        ui->progressBar_->hide();

        // Afficher le cours au démarrage
            ui->lessonLabel->show();

        // Connexion pour démarrer le quiz après avoir lu le cours
        connect(ui->startQuizButton, &QPushButton::clicked, this, &courgrammaire::showQuiz);
            loadQuestion(); // Appeler ici pour afficher la première question

}

courgrammaire::~courgrammaire()
{
    delete ui;
}
 void courgrammaire::showQuiz() {

    // Afficher le quiz et masquer le cours
    ui->lessonLabel->hide();
    ui->startQuizButton->hide();
    ui->questionLabel->show();
    ui->answerLineEdit->show();
    ui->submButton->show();
    ui->nextButton->show();
    ui->progressBar_->show();
     currentQuestionIndex = 0;
    loadQuestion(); // Commence le quiz
}
void courgrammaire::loadQuestion() {
    if (currentQuestionIndex < questions.size()) {
        ui->questionLabel->setText(questions[currentQuestionIndex]);
        ui->answerLineEdit->clear(); // Si vous utilisez un QLineEdit pour la réponse

        // Mise à jour de la barre de progression
        int progress = ((currentQuestionIndex + 1) * 100) / questions.size(); // Calcul du pourcentage d'avancement
        ui->progressBar_->setValue(progress); // Définition de la valeur de la barre de progression
        currentQuestionIndex++; // Supposons que c'est votre index pour les questions
    } else {
        QMessageBox::information(this, "Fin du quiz", "Vous avez terminé le quiz !");
    }
}


void courgrammaire::checkAnswer() {
    QString userAnswer = ui->answerLineEdit->text(); // Récupère la réponse de l'utilisateur

    //if (currentQuestionIndex < answers.size() && userAnswer.toLower() == answers[currentQuestionIndex].toLower()) {
    if (currentQuestionIndex > 0 && userAnswer.toLower() == answers[currentQuestionIndex - 1].toLower()){
        QMessageBox::information(this, "Réponse", "Bonne réponse !");
    } else {
        QMessageBox::information(this, "Réponse", "Mauvaise réponse !");
    }
     nextQuestion(); // Appelle la prochaine question après avoir vérifié la répons
}


void courgrammaire::nextQuestion() {
    currentQuestionIndex++;
    loadQuestion(); // Charge la prochaine question
}

void courgrammaire::on_nextButton_clicked()
{
    //fct to hide the Mainwindow
    this->hide();
    //fct to acces to others window
    Grammaire *grm = new Grammaire();
    grm->show();
}

