#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //
    // Set the background image using stylesheet
    QString imagePath = ":/img/img/bg.PNG"; // Replace this with your image path
    setStyleSheet("QMainWindow { background-image: url(" + imagePath + "); }");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_login_clicked()
{
    QString username =ui->username->text();
    QString password = ui->password->text();
    QString email = ui->email->text();
    if (username == "salma" && password == "123456" && email == "salma@gmail.com")
    {
        //fct to show success
        QMessageBox::information(this,"Succes", "Login Success.");
        //fct to hide the Mainwindow
        this->hide();
        //fct to acces to others window
        level *leve = new level();
        leve->show();

    }
    else
    {
        QMessageBox::warning(this,"Error", "Please Enter valid Username Or Password");
    }
}

