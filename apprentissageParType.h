#ifndef APPRENTISSAGEPARTYPE_H
#define APPRENTISSAGEPARTYPE_H

#include "apprentissage.h"


class apprentissageParType : public apprentissage
{
    public:
        apprentissageParType(Questionnaire& questionnaire);
        void executer() override;
    private:
};

#endif // APPRENTISSAGEPARTYPE_H
