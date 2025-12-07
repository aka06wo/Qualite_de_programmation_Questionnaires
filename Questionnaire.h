#ifndef CODE_QUESTIONNAIRE_H
#define CODE_QUESTIONNAIRE_H

#include<string>
#include<iostream>
#include <vector>
#include <memory>
#include "json.hpp"

class Question ;

class Questionnaire
{
public :
    friend class QuestionnaireJSON ;

    Questionnaire() ;
    Questionnaire(const std::string &nom,const std::string &description = "" ,const std::vector<std::unique_ptr<Question>> &Questions = {});
    ~Questionnaire();
    std::string nomQuestionnaire() const ;

    // Changer le nom et la description du questionnaire doit etre privée
    void changerNomQuestionnaire(const std::string &nomQuestionnaire);
    std::string descriptionQuestionnaire() const ;
    void changerDescriptionQuestionnaire(const std::string &descriptionQuestionnaire);
    int nombreDeQuestions() const ;


    /*
    Tes classes Question et Questionnaire font des std::cout.
    C'est un mélange de responsabilités. Si demain tu veux faire une interface graphique (Qt)
    ou Web, tu devras tout réécrire.
    donc c'est mieux que je renvoie l'intitulé de la question i au lieu de l'afficher dans le questionnaire
     */
    void afficherQuestionNumero(int i) const ;
    void afficherReponseNumero(int i) const ;


    // on convertit reponse dans validite entree utilisateur et aussi dans verification reponse
    // il faut qu'on le fasse une seule fois
    bool validiteEntreeUtilisateur(int i,const std::string &reponse) const ;
    // verifie si la reponse rep est juste pour la question I
    bool verificationReponse(int i,const std::string &reponse) const ;
    nlohmann::json conversionQuestionnaireJson() const ;

private :
    std::string d_nom ;
    std::string d_description ;
    std::vector<std::unique_ptr<Question>> d_Questions ;
    void ajouterQuestion(std::unique_ptr<Question> q);
};


#endif //CODE_QUESTIONNAIRE_H
