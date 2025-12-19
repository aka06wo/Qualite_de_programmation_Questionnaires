#ifndef CODE_QUESTIONNAIRE_APPRENTISSAGEPARTYPE_H
#define CODE_QUESTIONNAIRE_APPRENTISSAGEPARTYPE_H

#include "Apprentissage.h"

class ApprentissageParType : public Apprentissage
{
    public:
    ApprentissageParType(const Questionnaire& questionnaire);
    void executer() override;
    private:
};


#endif //CODE_QUESTIONNAIRE_APPRENTISSAGEPARTYPE_H