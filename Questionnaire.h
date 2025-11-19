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
    string descriptionQuestionnaire() const ;
    vector<std::unique_ptr<Question>> mesQuestions() const ;
    int nombreDeQuestions() const ;

    json conversionQuestionnaireJson() const ;

    // On le mets ici, ou on fait une classe � part ?? (je ne sais pas encore)
    void apprentissage() const ;

private :
    string d_nom ;
    string d_description ;
    int d_nbQuestions ;
    vector<std::unique_ptr<Question>> d_Questions ;
    // L'utilisateur de doit pas pouvoir ajouter une question
    void ajouterQuestion(std::unique_ptr<Question> q);
};


#endif //CODE_QUESTIONNAIRE_H
