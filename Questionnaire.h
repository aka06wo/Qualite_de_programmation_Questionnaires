#ifndef CODE_QUESTIONNAIRE_H
#define CODE_QUESTIONNAIRE_H

#include<string>
#include<iostream>
#include <vector>
#include <memory>

#include "Question.h"

using std::string ;
using std::ostream;
using std::istream;
using std::vector ;


class Questionnaire
{
public :
    Questionnaire(const string &titre , const vector<std::unique_ptr<Question>>& Questions);
    Questionnaire() ;
    string titre() const ;
    void ajouterQuestion(std::unique_ptr<Question> q);
    void sauvegarder(ostream& os) const ;
    void charger(istream& ist) ; // à faire une fois que toutes les classes derivés de la classe seront fonctionnelle
private :
    string d_titre ;
    vector<std::unique_ptr<Question>> d_Questions ;
};


#endif //CODE_QUESTIONNAIRE_H
