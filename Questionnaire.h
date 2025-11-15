#ifndef CODE_QUESTIONNAIRE_H
#define CODE_QUESTIONNAIRE_H

#include<string>
#include<iostream>
#include <vector>
#include <memory>

class Question ;

using std::string ;
using std::ostream;
using std::istream;
using std::vector ;


class Questionnaire
{
public :
    Questionnaire() ;
    Questionnaire(const string &titre , const vector<std::unique_ptr<Question>>& Questions);
    string titre() const ;
    int nombreDeQuestions() const ;

    // On le mets ici, ou on fait une classe à part ?? (je ne sais pas encore)
    void apprentissage() const ;

    void sauvegarder(ostream& os) const ;
    void charger(istream& ist) ; // à faire une fois que toutes les classes derivés de la classe seront fonctionnelle
private :
    string d_titre ;
    int d_nbQuestions ;
    vector<std::unique_ptr<Question>> d_Questions ;
    // L'utilisateur de doit pas pouvoir ajouter une question
    void ajouterQuestion(std::unique_ptr<Question> q);
};


#endif //CODE_QUESTIONNAIRE_H
