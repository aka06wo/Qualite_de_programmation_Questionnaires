//
// Created by Ibrahima Diallo on 30/10/2025.
//
#include<string>
#include<iostream>
#include <vector>
#include <memory>
using std::string ;
using std::ostream;
using std::istream;
using std::cout ;
#include "Questionnaire.h"
#include "Question.h"
Questionnaire::Questionnaire(const string &titre, const vector<std::unique_ptr<Question>>&& Questions):
    d_titre{titre}
{
    d_Questions.reserve(Questions.size()) ; // juste pour optimiser

    d_Questions.reserve(Questions.size());
    for (const auto &q : Questions)
       d_Questions.push_back(q->clone()); // copie polymorphe

}


string Questionnaire::titre() const
{
    return d_titre ;
}
void Questionnaire::ajouterQuestion(std::unique_ptr<Question> q)
{
    d_Questions.push_back(std::move(q));
}
/**void Questionnaire::sauvegarder(ostream& os) const
{
    os << d_titre << "\n";
    os << d_Questions.size() << "\n";
    for(const auto& q : d_Questions)
    {
        q->sauvegarder(os);
    }

}
**/
void Questionnaire::apprentissage() const
{
    std::cout << " Apprentissage : " << d_titre << " \n";
        for (const auto &q : d_Questions)
        {
            q->afficherQuestion() ;
            cout<<'\n' ;
            q->afficherReponse() ;
        }

}
/**void Questionnaire::charger(istream& ist)
{
    // � definir apres
}
**/
/**void Questionnaire::afficherQuestions() const
{
    for (const auto& q : d_Questions)
    {
            q->afficherQuestion();
    }
}**/
