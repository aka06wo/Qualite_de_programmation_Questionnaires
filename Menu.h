#ifndef CODE_QUESTIONNAIRE_MENU_H
#define CODE_QUESTIONNAIRE_MENU_H

#include "gestionnaireQuestionnaires.h"
#include "gestionnaireEvaluations.h"
#include "gestionnaireApprentissage.h"

class Menu
{
    public :
    Menu() ;
    void execute() ;

    private :
    gestionnaireApprentissage d_gestionnaireApprentissage ;
    gestionnaireQuestionnaires  d_gestionnaireQuestionnaires ;
    gestionnaireEvaluations    d_gestionnaireEvaluation ;
    void menuChoixQuestionnaire(const std::vector<std::string> &questionnaires) ;
    void menuQuestionnaire(const Questionnaire& questionnaire) ;
    // MENU Questionnaire
    static constexpr int APPRENTISSAGE_SIMPLE = 0 ;
    static constexpr int APPRENTISSAGE_TYPE = 1 ;
    static constexpr int EVALUATION_TEST = 0 ;
    static constexpr int EVALUATION_SECONDE_CHANCE = 1 ;
    static constexpr int EVALUATION_ADAPTATIVE = 2 ;
    static constexpr int CERTIFICATE_TEXT = 1 ;
    static constexpr int CERTIFICATE_HTML = 2 ;
};


#endif //CODE_QUESTIONNAIRE_MENU_H