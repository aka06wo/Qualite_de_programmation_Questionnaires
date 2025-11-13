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
#include "Question.h"

class Questionnaire {
public :
    Questionnaire(const string &titre , const vector<std::unique_ptr<Question>>&& Questions);
    Questionnaire() ;
    string titre() const ;
    void ajouterQuestion(std::unique_ptr<Question> q);
   // void afficherQuestions() const ;
   void apprentissage() const ; // pour l'apprentissage
    void sauvegarder(ostream& os) const ;
    void charger(istream& ist) ; // à faire une fois que toutes les classes derivés de la classe seront fonctionnelle
private :
    string d_titre ;
    vector<std::unique_ptr<Question>> d_Questions ;
};


#endif //CODE_QUESTIONNAIRE_H
