#ifndef CODE_QUESTIONNAIRE_APPRENTISSAGE_H
#define CODE_QUESTIONNAIRE_APPRENTISSAGE_H

#include "Questionnaire.h"

class Apprentissage
{
    public:
    Apprentissage(const Questionnaire& questionnaire);
    void changerQuestionnaire(const Questionnaire& questionnaire);
    virtual ~Apprentissage()=default;
    virtual void lanceApprentissage()=0;

protected:
    const Questionnaire *d_questionnaire;
};


#endif //CODE_QUESTIONNAIRE_APPRENTISSAGE_H