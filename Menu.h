#ifndef CODE_QUESTIONNAIRE_MENU_H
#define CODE_QUESTIONNAIRE_MENU_H

#include "gestionnaireQuestionnaires.h"
#include "GestionnaireActivites.h"

class Menu
{
    public :
    Menu() ;
    void execute() ;

    private :
    Questionnaire d_questionnaire ;
    gestionnaireQuestionnaires  d_gestionnaireQuestionnaires ;
    GestionnaireActivites d_gestionnaireActivites ;
    void menuChoixQuestionnaire(const std::vector<std::string> &questionnaires) ;
    void menuQuestionnaire(const Questionnaire& questionnaire) ;
};


#endif //CODE_QUESTIONNAIRE_MENU_H