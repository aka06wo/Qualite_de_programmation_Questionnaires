#ifndef CODE_QUESTIONNAIRE_GESTIONNAIREQUESTIONNAIRES_H
#define CODE_QUESTIONNAIRE_GESTIONNAIREQUESTIONNAIRES_H

#include "Questionnaire.h"
#include "QuestionnaireJSON.h"

class gestionnaireQuestionnaires
{
    public :
    /**
     Constructeur par defaut de la classe gestionnaireQuestionnaires
     */
    gestionnaireQuestionnaires() ;

    /**
     Constructeur avec selection immediate d'un questionnaire
     @param nomQuestionnaire Le nom du questionnaire selectionné
     */
    gestionnaireQuestionnaires(const std::string &nomQuestionnaire) ;

    /**
     Modifie le questionnaire actif en le recherchant dans le fichier JSON
     @param nom Le nom du nouveau questionnaire à charger
     */
    void selectionneQuestionnaire(const std::string& nom);

    /**
     Recupere l'objet Questionnaire correspondant à la selection actuelle
     @return Un objet Questionnaire complet (contenant nom, description et questions)
     */
    Questionnaire questionnaireCourant() ;

    /**
     Renvoie la liste de tous les noms de questionnaires disponibles dans le fichier source
     @return Un tableau de chaines de caracteres contenant les différents noms des questionnaires disponibles
     */
    std::vector<std::string> nomsDesDifferentsQuestionnaires() const;

    private :
    std::string d_nomQuestionnaire ;
    QuestionnaireJSON d_gestionnaireJSON;
};



#endif //CODE_QUESTIONNAIRE_GESTIONNAIREQUESTIONNAIRES_H