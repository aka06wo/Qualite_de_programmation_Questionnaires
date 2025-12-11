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
    Questionnaire(const std::string &nom,const std::string &description = "" ,
                        const std::vector<std::unique_ptr<Question>> &Questions = {});
    ~Questionnaire();
    std::string nomQuestionnaire() const ;
    std::string descriptionQuestionnaire() const ;
    int nombreDeQuestions() const ;
    std::string intituleQuestionNumero(int i) const ;
    std::string instructionsQuestionNumero(int i) const ;
    std::string reponseQuestionNumero(int i) const ;
    bool validiteEntreeUtilisateur(int i,const std::string &reponse) const ;
    bool verificationReponse(int i,const std::string &reponse) const ;

    private :
    std::string d_nom ;
    std::string d_description ;
    std::vector<std::unique_ptr<Question>> d_Questions ;
    void changerNomQuestionnaire(const std::string &nomQuestionnaire);
    void changerDescriptionQuestionnaire(const std::string &descriptionQuestionnaire);
    void ajouterQuestion(std::unique_ptr<Question> q);
    nlohmann::json conversionQuestionnaireJson() const ;
};


#endif //CODE_QUESTIONNAIRE_H
