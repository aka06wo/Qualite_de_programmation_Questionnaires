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


    /*
    Tes classes Question et Questionnaire font des std::cout.
    C'est un mélange de responsabilités. Si demain tu veux faire une interface graphique (Qt)
    ou Web, tu devras tout réécrire.
    donc c'est mieux que je renvoie l'intitulé de la question i au lieu de l'afficher dans le questionnaire
     */
    void afficherQuestionNumero(int i) const ;
    void afficherReponseNumero(int i) const ;
    // verifie les entrees utilisateurs
    bool validiteEntreeUtilisateur(int i,const string &reponse) const ;
    // verifie si la reponse rep est juste pour la question I
    bool verificationReponse(int i,const std::string &reponse) const ;
    json conversionQuestionnaireJson() const ;

private :
    string d_nom ;
    string d_description ;
    vector<std::unique_ptr<Question>> d_Questions ;
    // L'utilisateur de doit pas pouvoir ajouter une question
    void ajouterQuestion(std::unique_ptr<Question> q);
};


#endif //CODE_QUESTIONNAIRE_H
