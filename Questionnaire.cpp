#include "Questionnaire.h"
#include "Question.h"

Questionnaire::Questionnaire() : d_nom{"Questionnaire Vide"},d_description{"Ceci est un questionnaire vide"}, d_nbQuestions{0}
{
}

Questionnaire::Questionnaire(const string &nom,const string &description, const vector<std::unique_ptr<Question>>& Questions):
    d_nom{nom},d_description{description}, d_nbQuestions{0}
{
    // On peut faire un move d'un tableau entier ou pas ??
    d_Questions.reserve(Questions.size()) ;
    for (const auto &q : Questions) {
        d_Questions.push_back(q->clone()); // copie polymorphe
        d_nbQuestions++;
    }
}

string Questionnaire::nomQuestionnaire() const
{
    return d_nom ;
}

void Questionnaire::changerNomQuestionnaire(const string &nomQuestionnaire) {
    d_nom = nomQuestionnaire ;
}

string Questionnaire::descriptionQuestionnaire() const {
    return d_description ;
}

void Questionnaire::changerDescriptionQuestionnaire(const string &descriptionQuestionnaire) {
    d_description = descriptionQuestionnaire ;
}

int Questionnaire::nombreDeQuestions() const {
    return d_nbQuestions;
}



void Questionnaire::ajouterQuestion(std::unique_ptr<Question> q)
{
    d_Questions.push_back(std::move(q));
    d_nbQuestions++;
}


void Questionnaire::afficherQuestionNumero(int i) const {
    d_Questions[i]->afficherQuestion() ;
}

void Questionnaire::afficherReponseNumero(int i) const {
    d_Questions[i]->afficherReponse() ;
}

bool Questionnaire::verificationReponse(int i,const std::string &reponse) const {
    return d_Questions[i]->verificationReponse(reponse) ;
}

json Questionnaire::conversionQuestionnaireJson() const {
    json description_questionnaires ;
    json resultat ;

    description_questionnaires["description"]=descriptionQuestionnaire() ;
    description_questionnaires["nombreDeQuestions"] = nombreDeQuestions() ;
    description_questionnaires["questions"]=json::array() ;
    for (const auto &q : d_Questions) {
        description_questionnaires["questions"].push_back(q->conversionJSON()) ;
    }

    resultat["titre"] = nomQuestionnaire() ;

    return resultat ;
}



