#include "Question.h"

Question::Question(const std::string& intitule): d_intitule{intitule}
{}

std::string Question::intitule() const
{
    return d_intitule ;
}
