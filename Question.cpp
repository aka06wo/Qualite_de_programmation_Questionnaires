//
//
// Created by Ibrahima Diallo on 30/10/2025.
//
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
void Question::afficherQuestion() const
{
    cout << "Question : " << d_intitule << "\n";
}
