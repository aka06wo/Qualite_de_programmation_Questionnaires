#ifndef CODE_QUESTIONNAIRE_APPRENTISSAGE_H
#define CODE_QUESTIONNAIRE_APPRENTISSAGE_H

#include "Questionnaire.h"

class Apprentissage
{
    public:
    /**
     Constructeur de la classe Apprentissage
     @param questionnaire Le questionnaire qui sera utilise pour l'apprentissage
     */
    Apprentissage(const Questionnaire& questionnaire);

    /**
     Permet de modifier le questionnaire associe à l'apprentissage courant
     @param questionnaire Le nouveau questionnaire
     */
    void changerQuestionnaire(const Questionnaire& questionnaire);

    /**
     Destructeur virtuel par defaut
     */
    virtual ~Apprentissage()=default;

    /**
     Methode virtuelle pure qui definit le point d'entree de l'activite d'apprentissage
     */
    virtual void lanceApprentissage()=0;

protected:
    const Questionnaire *d_questionnaire;
};


#endif //CODE_QUESTIONNAIRE_APPRENTISSAGE_H