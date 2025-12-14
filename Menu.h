#ifndef CODE_QUESTIONNAIRE_MENU_H
#define CODE_QUESTIONNAIRE_MENU_H

#include <iostream>
#include <memory>
#include "gestionnaireQuestionnaires.h"
#include "gestionnaireEvaluations.h"

class Menu
{
public :
    void execute() ;
private :
    gestionnaireQuestionnaires  d_gestionnaireQuestion ;
    gestionnaireEvaluations    d_gestionnairevaluation ;
    int MenuPrincipale() ;
    int menuChoixQuestionnaire(const std::vector<Questionnaire>& questionnaires) ;
    int menuQuestionnaire() ;
    int menuApprentissage() ;
    int menuevaluation();

};


#endif //CODE_QUESTIONNAIRE_MENU_H
