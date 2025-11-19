#include<string>
#include<iostream>

using std::string ;
using std::ostream;
using std::istream;
using std::cout ;

#include "Question.h"
Question::Question(const string& intitule): d_intitule{intitule}
{}

string Question::intitule() const
{
    return d_intitule ;
}
