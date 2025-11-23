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

string Questionnaire::descriptionQuestionnaire() const {
    return d_description ;
}

int Questionnaire::nombreDeQuestions() const {
    return d_nbQuestions;
}


void Questionnaire::ajouterQuestion(std::unique_ptr<Question> q)
{
    d_Questions.push_back(std::move(q));
    d_nbQuestions++;
}


json Questionnaire::conversionQuestionnaireJson() const {
    json description_questionnaires ;
    json resultat ;

    //aisse: j'ai enleve le q. devant les methodes carpas la peine
    description_questionnaires["description"]=descriptionQuestionnaire() ;
    description_questionnaires["nombreDeQuestions"] = nombreDeQuestions() ;
    description_questionnaires["questions"]=json::array() ;
    for (const auto &q : d_Questions) {
        description_questionnaires["questions"].push_back(q->conversionJSON()) ;
    }

    resultat["titre"] = nomQuestionnaire() ;

    return resultat ;
}


void Questionnaire::apprentissage() const
{
    std::cout << " Apprentissage : " << d_nom << " \n";
        for (const auto &q : d_Questions)
        {
            q->afficherQuestion() ;
            std::cout<<'\n' ;
            q->afficherReponse() ;
        }
}

