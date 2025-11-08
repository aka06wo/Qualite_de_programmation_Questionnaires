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
#include "Questionnaire.h"
#include "Question.h"
Questionnaire::Questionnaire(const string &titre, const vector<unique_ptr<Question>> Questions):
    d_titre{titre},d_Questions{std::move(Questions)}
{}
string Questionnaire::titre() const
{
    return d_titre ;
}
void Questionnaire::ajouterQuestion(unique_ptr<Question> q)
{
    d_Questions.push_back(std::move(q));
}
void Questionnaire::sauvegarder(ostream& os) const
{
    os << d_titre << "\n";
    os << d_Questions.size() << "\n";
    for(const auto& q : d_Questions)
    {
        q->sauvegarder(os);
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
