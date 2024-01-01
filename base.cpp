#include "base.h"
#include "ui_base.h"

base::base(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::base)
{
    ui->setupUi(this);
    //
    // Set the background image using stylesheet
    QString imagePath = ":/img/img/bggi.PNG"; // Replace this with your image path
    setStyleSheet("QMainWindow { background-image: url(" + imagePath + "); }");

}

base::~base()
{
    delete ui;
}

void base::on_alphaet_clicked()
{
    //fct to hide the Mainwindow
    this->hide();
    //fct to acces to others window
    alphabet *alpha = new alphabet();
    alpha->show();
}


void base::on_grammaire_clicked()
{
    //fct to hide the Mainwindow
    this->hide();
    //fct to acces to others window
    Grammaire *grammaire = new Grammaire();
    grammaire->show();
}


void base::on_gonjugaison_clicked()
{
    //fct to hide the Mainwindow
    this->hide();
    //fct to acces to others window
    Conjugaison *con = new Conjugaison();
    con->show();
}

