#include "lexique.h"
#include "ui_lexique.h"

Lexique::Lexique(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lexique)
{
    ui->setupUi(this);
    // Set the background image using stylesheet
    QString imagePath = ":/img/img/bggi.PNG"; // Replace this with your image path
    setStyleSheet("QMainWindow { background-image: url(" + imagePath + "); }");
}

Lexique::~Lexique()
{
    delete ui;
}

void Lexique::on_back_clicked()
{
    //fct to hide the Mainwindow
    this->hide();
    //fct to acces to others window
    base *bi = new base();
    bi->show();
}


void Lexique::on_cours1_clicked()
{
    //fct to hide the Mainwindow
    this->hide();
    //fct to acces to others window
    courlexi *bo = new courlexi();
    bo->show();
}

