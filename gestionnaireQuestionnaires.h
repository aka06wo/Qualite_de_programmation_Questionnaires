#ifndef CODE_QUESTIONNAIRE_GESTIONNAIREQUESTIONNAIRES_H
#define CODE_QUESTIONNAIRE_GESTIONNAIREQUESTIONNAIRES_H

#include "Questionnaire.h"

class gestionnaireQuestionnaires
{
    public :
    gestionnaireQuestionnaires() ;
    gestionnaireQuestionnaires(const std::string &nomQuestionnaire) ;
    Questionnaire renvoiQuestionnaireCourant() const;
    void changeQuestionnaire(const std::string &nomQ) ;
    std::string nomsDesDifferentsQuestionnaires() const;

    private :
    const std::string d_questionnaireCourant ;

};


#endif //CODE_QUESTIONNAIRE_GESTIONNAIREQUESTIONNAIRES_H