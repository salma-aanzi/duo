#include "profiel.h"
#include "ui_profiel.h"

profiel::profiel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::profiel)
{
    ui->setupUi(this);
    // Set the background image using stylesheet
    QString imagePath = ":/img/img/bggi.PNG"; // Replace this with your image path
    setStyleSheet("QMainWindow { background-image: url(" + imagePath + "); }");
}

profiel::~profiel()
{
    delete ui;
}



void profiel::on_back_clicked()
{
    //fct to hide the Mainwindow
    this->hide();
    //fct to acces to others window
    level *lev = new level();
    lev->show();
}


void profiel::on_logout_clicked()
{
    //fct to hide the Mainwindow
    this->hide();
    //fct to acces to others window
    MainWindow *loge = new MainWindow();
    loge->show();
}

