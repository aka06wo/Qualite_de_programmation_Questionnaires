#ifndef CODE_QUESTIONNAIRE_H
#define CODE_QUESTIONNAIRE_H

#include<string>
#include<iostream>
#include <vector>
#include <memory>
#include "json.hpp"

class Question ;

using nlohmann::json ;
using std::string ;
using std::ostream;
using std::istream;
using std::vector ;

class Questionnaire
{
public :
    friend class QuestionnaireJSON ;

    Questionnaire() ;
    Questionnaire(const string &nom,const string &description = "" ,const vector<std::unique_ptr<Question>> &Questions = {});
    string nomQuestionnaire() const ;
    void changerNomQuestionnaire(const string &nomQuestionnaire);
    string descriptionQuestionnaire() const ;
    void changerDescriptionQuestionnaire(const string &descriptionQuestionnaire);
    int nombreDeQuestions() const ;
    void afficherQuestionNumero(int i) const ;
    void afficherReponseNumero(int i) const ;
    // verifie si la reponse rep est juste pour la question I
    bool verificationReponse(int i,const std::string &reponse) const ;
    json conversionQuestionnaireJson() const ;
    // elle doit juste remettre tout à zero si jamais il y avait quelque chose
    void reinitialiser() const ;

private :
    string d_nom ;
    string d_description ;
    int d_nbQuestions ;
    vector<std::unique_ptr<Question>> d_Questions ;
    // L'utilisateur de doit pas pouvoir ajouter une question
    void ajouterQuestion(std::unique_ptr<Question> q);
};


#endif //CODE_QUESTIONNAIRE_H
