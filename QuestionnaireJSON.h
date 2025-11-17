#ifndef CODE_PROJET_QUESTIONNAIREJSON_H
#define CODE_PROJET_QUESTIONNAIREJSON_H

#include "json.hpp"
#include "Questionnaire.h"
#include "Question.h"



using nlohmann::json ;

class QuestionnaireJSON {
    public:
    QuestionnaireJSON (const std::string &nomQuestionnaire) ;
    std::string nomQuestionnaire() const ;
    void chargerQuestionnaire(Questionnaire &questionnaire) ;

    json conversionJSON(const Questionnaire &q) const ;
    // Pour respecter le questionnaire, son format
    // on doit ajouter la methode type question ?? pour savoir le type de la question
    void sauvegarderQuestionnaire(const Questionnaire &questionnaire) const ;

    private:
    std::string d_nomQuestionnaire ;
    json d_monFichier ;
};


#endif //CODE_PROJET_QUESTIONNAIREJSON_H
