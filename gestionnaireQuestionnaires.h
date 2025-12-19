#ifndef CODE_QUESTIONNAIRE_GESTIONNAIREQUESTIONNAIRES_H
#define CODE_QUESTIONNAIRE_GESTIONNAIREQUESTIONNAIRES_H

#include "Questionnaire.h"
#include "QuestionnaireJSON.h"

class gestionnaireQuestionnaires
{
    public :
    gestionnaireQuestionnaires() ;
    gestionnaireQuestionnaires(const std::string &nomQuestionnaire) ;
    void selectionneQuestionnaire(const std::string& nom);
    Questionnaire questionnaireCourant() ;
    void changeQuestionnaire(const std::string &nomQ) ;
    std::vector<std::string> nomsDesDifferentsQuestionnaires() const;

    private :
    std::string d_nomQuestionnaire ;
    QuestionnaireJSON d_gestionnaireJSON;
};



#endif //CODE_QUESTIONNAIRE_GESTIONNAIREQUESTIONNAIRES_H