#include "grammaire.h"
#include "ui_grammaire.h"

Grammaire::Grammaire(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Grammaire)
{
    ui->setupUi(this);
    // Set the background image using stylesheet
    QString imagePath = ":/img/img/bggi.PNG"; // Replace this with your image path
    setStyleSheet("QMainWindow { background-image: url(" + imagePath + "); }");
}

Grammaire::~Grammaire()
{
    delete ui;
}

void Grammaire::on_cours1_clicked()
{
    //fct to hide the Mainwindow
    this->hide();
    //fct to acces to others window
    courgrammaire *cour = new courgrammaire();
    cour->show();
}


void Grammaire::on_back_clicked()
{
        //fct to hide the Mainwindow
     this->hide();
    //fct to acces to others window
    base *bc = new base();
    bc->show();
}

