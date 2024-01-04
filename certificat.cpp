#include "certificat.h"
#include "ui_certificat.h"


certificat::certificat(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::certificat)
{
    ui->setupUi(this);
}

certificat::~certificat()
{
    delete ui;
}

void certificat::on_back_clicked()
{
    //fct to hide the Mainwindow
    this->hide();
    //fct to acces to others window
    base *bu = new base();
    bu->show();
}

