#include "level.h"
#include "ui_level.h"
#include <QLabel>

level::level(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::level)
{
    ui->setupUi(this);

    // Set the background image using stylesheet
    QString imagePath = ":/img/img/bggl.PNG"; // Replace this with your image path
    setStyleSheet("QMainWindow { background-image: url(" + imagePath + "); }");
    //

}




level::~level()
{
    delete ui;
}

void level::on_base_clicked()
{
    //fct to hide the Mainwindow
    this->hide();
    //fct to acces to others window
    base *basee = new base();
    basee->show();


}


void level::on_sauter_clicked()
{
    //fct to show success
        QMessageBox::information(this,"Super", "Ce test rapide est un moyen simple et précis de s'assurer que tu commences au bon endroit dans le cours.");
        //fct to hide the Mainwindow
        this->hide();
    //fct to acces to others window
    Test *test = new Test();
    test->show();


}

