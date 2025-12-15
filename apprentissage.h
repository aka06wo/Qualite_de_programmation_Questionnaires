#ifndef APPRENTISSAGE_H
#define APPRENTISSAGE_H
#include "Questionnaire.h"
#include <memory>

class apprentissage
{
    public:
        apprentissage(const Questionnaire& questionnaire);
        virtual ~apprentissage()=default;
        virtual void executer()=0;

    protected:
        Questionnaire d_questionnaire;

};

#endif // APPRENTISSAGE_H
