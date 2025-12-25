#ifndef CODE_QUESTIONNAIRE_MENU_H
#define CODE_QUESTIONNAIRE_MENU_H

#include "gestionnaireQuestionnaires.h"
#include "GestionnaireActivites.h"

class Menu {
public:
    Menu();
    /** Lance la boucle principale de l'application */
    void execute();

private:
    gestionnaireQuestionnaires d_gestionnaireQuestionnaires;
    GestionnaireActivites d_gestionnaireActivite;

    /** Menu de selection du fichier JSON */
    void menuChoixQuestionnaire(const std::vector<std::string> &questionnaires);
    /** Menu des activites pour un questionnaire precis */
    void menuQuestionnaire(const Questionnaire& q);
};


#endif //CODE_QUESTIONNAIRE_MENU_H