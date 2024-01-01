#include "question.h"

class QuestionData : public QSharedData
{
public:
};

Question::Question()
    : data(new QuestionData)
{}

Question::Question(const Question &rhs)
    : data{rhs.data}
{}

Question &Question::operator=(const Question &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}
//

//
Question::~Question() {}
