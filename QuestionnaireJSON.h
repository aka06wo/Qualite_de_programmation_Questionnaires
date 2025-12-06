#ifndef CODE_PROJET_QUESTIONNAIREJSON_H
#define CODE_PROJET_QUESTIONNAIREJSON_H

#include "json.hpp"
#include "Questionnaire.h"
#include "Question.h"

using nlohmann::json ;

class QuestionnaireJSON {
public:
    QuestionnaireJSON() ;
    QuestionnaireJSON (const std::string &nomQuestionnaire) ;
    void changerQuestionnaire(const std::string &nomQuestionnaire) ;
    std::string nomQuestionnaire() const ;
    bool ouvertureFichier(const std::ifstream &monFichier) const;
    bool conversionJSON(json &monJSON, std::ifstream &monFichier) ;
    bool lireFichierJSON(json &d_monFichier, const std::string &nomFichier) ;
    bool extraireQuestionnaire(const json &d_monFichier, const std::string &nomQuestionnaire, json &monQuestionnaire) ;
    void extraireDescription(const json &monFichier,Questionnaire &questionnaire) ;
    json extraireQuestions(const json &monQuestionnaire) ;
    void ajouterQuestionDepuisJSON(Questionnaire &questionnaire, const json &q) ;
    void chargerDansQuestionnaire(Questionnaire &questionnaire) ;


    void sauvegarderQuestionnaire(const Questionnaire &questionnaire) const ;

private:
    std::string d_nomQuestionnaire ;
    json d_monFichier ;
    static std::string NomFichierQuestionnaire() ;
    static std::string NomFichierQuestionnairesSauvegarde() ;
};


#endif //CODE_PROJET_QUESTIONNAIREJSON_H
