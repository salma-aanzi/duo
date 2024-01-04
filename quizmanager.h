#ifndef QUIZMANAGER_H
#define QUIZMANAGER_H
#include <QObject>

class QuizManager : public QObject {
    Q_OBJECT
public:
    QuizManager();

    explicit QuizManager(QObject *parent = nullptr);
    virtual ~QuizManager();

    virtual void showQuiz() = 0;
    // Autres méthodes virtuelles pures pour le quiz
    virtual void loadQuestion() = 0;
    virtual void checkAnswer() = 0;
    virtual void nextQuestion() = 0;
};

#endif // QUIZMANAGER_H
