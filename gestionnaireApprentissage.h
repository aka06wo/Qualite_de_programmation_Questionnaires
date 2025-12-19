#ifndef CODE_QUESTIONNAIRE_GESTIONNAIREAPPRENTISSAGE_H
#define CODE_QUESTIONNAIRE_GESTIONNAIREAPPRENTISSAGE_H

#include "Questionnaire.h"
#include "Apprentissage.h"

class gestionnaireApprentissage
{
    public :
    gestionnaireApprentissage() ;
    gestionnaireApprentissage(const Questionnaire &q) ;
    void selectionneQuestionnaire(const Questionnaire &q) ;
    void commenceApprentissage(int evaluation) ;

    private :
    const Questionnaire *d_questionnaire ;
    std::vector<std::unique_ptr<Apprentissage>> d_apprentissage ;
};


#endif //CODE_QUESTIONNAIRE_GESTIONNAIREAPPRENTISSAGE_H