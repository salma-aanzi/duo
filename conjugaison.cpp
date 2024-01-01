#include "conjugaison.h"
#include "ui_conjugaison.h"

Conjugaison::Conjugaison(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Conjugaison)
{
    ui->setupUi(this);
    // Set the background image using stylesheet
    QString imagePath = ":/img/img/bggi.PNG"; // Replace this with your image path
    setStyleSheet("QMainWindow { background-image: url(" + imagePath + "); }");
}

Conjugaison::~Conjugaison()
{
    delete ui;
}

void Conjugaison::on_coursco_clicked()
{
    //fct to hide the Mainwindow
    this->hide();
    //fct to acces to others window
    courcong *conj = new courcong();
    conj->show();
}


void Conjugaison::on_back_clicked()
{
    //fct to hide the Mainwindow
    this->hide();
    //fct to acces to others window
    base *bjh = new base();
    bjh->show();

}

