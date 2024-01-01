#ifndef QUESTION_H
#define QUESTION_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include<vector>

class QuestionData;

class Question : public QObject
{
    Q_OBJECT

public:
    Question();
    Question(const Question &);
    Question &operator=(const Question &);
    ~Question();
    //


private:
    QSharedDataPointer<QuestionData> data;
    //

};

#endif // QUESTION_H
