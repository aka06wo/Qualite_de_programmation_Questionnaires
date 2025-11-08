//
// Created by Ibrahima Diallo on 30/10/2025.
//

#ifndef CODE_QUESTIONNAIRE_H
#define CODE_QUESTIONNAIRE_H
#include<string>
#include<iostream>
#include <vector>
#include <memory>
using std::string ;
using std::ostream;
using std::istream;
using std::vector ;
using namespace std ;
#include "Question.h"

class Questionnaire {
public :
    Questionnaire(const string &titre , const vector<unique_ptr<Question>> Questions);
    Questionnaire() ;
    string titre() const ;
    void ajouterQuestion(unique_ptr<Question> q);
   // void afficherQuestions() const ;
    void sauvegarder(ostream& os) const ;
    void charger(istream& ist) ; // à faire une fois que toutes les classes derivés de la classe seront fonctionnelle
private :
    string d_titre ;
    vector<unique_ptr<Question>> d_Questions;
};


#endif //CODE_QUESTIONNAIRE_H
