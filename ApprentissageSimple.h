#ifndef CODE_QUESTIONNAIRE_APPRENTISSAGESIMPLE_H
#define CODE_QUESTIONNAIRE_APPRENTISSAGESIMPLE_H


#include "Apprentissage.h"

class ApprentissageSimple : public Apprentissage
{
    public :
    ApprentissageSimple(const Questionnaire& questionnaire) ;
    void lanceApprentissage() override ;
};


#endif //CODE_QUESTIONNAIRE_APPRENTISSAGESIMPLE_H