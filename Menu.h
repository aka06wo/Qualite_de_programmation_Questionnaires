#ifndef CODE_QUESTIONNAIRE_MENU_H
#define CODE_QUESTIONNAIRE_MENU_H


class Menu
{
public :
    void execute() ;
private :
    std::unique_ptr<gestionnaireQuestionnaires> d_gestionnaireQuestion ;
    int MenuPrincipale() ;
    void menuQuestionnaire() ;
    void menuApprentissage() ;
    void menuevaluation()

};


#endif //CODE_QUESTIONNAIRE_MENU_H
