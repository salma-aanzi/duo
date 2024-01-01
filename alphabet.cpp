#include "alphabet.h"
#include "ui_alphabet.h"
#include <QPushButton>
#include <QVBoxLayout>

alphabet::alphabet(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::alphabet)

{
    ui->setupUi(this);
    // Set the background image using stylesheet
    QString imagePath = ":/img/img/bggi.PNG"; // Replace this with your image path
    setStyleSheet("QMainWindow { background-image: url(" + imagePath + "); }");
    //

}

alphabet::~alphabet()
{
    delete ui;
}

void alphabet::on_nextButton_clicked()
{
    //fct to hide the Mainwindow
    this->hide();
    //fct to acces to others window
    Grammaire *gre = new Grammaire();
    gre->show();
}

/*{
    if (currentAlphabetIndex < 25) // Pour les 26 lettres de l'alphabet
    {
        if (currentAlphabetIndex > 0) {
            QString previousAlphabet = QString('A' + currentAlphabetIndex - 1);
            ui->centralwidget->findChild<QLabel*>(previousAlphabet)->hide();
        }

        QString currentAlphabet = QString('A' + currentAlphabetIndex);
        QLabel *label = ui->centralwidget->findChild<QLabel*>(currentAlphabet);
        if (!label) {
            label = new QLabel(currentAlphabet, ui->centralwidget);
            label->setObjectName(currentAlphabet);
        }
        label->show();
        currentAlphabetIndex++;
    }
    else
    {
        // Vous avez atteint la fin de l'alphabet
        // Vous pouvez ajouter un message ou une action supplémentaire ici
    }
}
*/



void alphabet::on_back_2_clicked()
{
    //fct to hide the Mainwindow
    this->hide();
    //fct to acces to others window
    base *bb = new base();
    bb->show();
}

