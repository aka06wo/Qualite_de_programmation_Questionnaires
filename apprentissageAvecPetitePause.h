#ifndef APPRENTISSAGEAVECPETITEPAUSE_H
#define APPRENTISSAGEAVECPETITEPAUSE_H
#include "apprentissage.h"


class apprentissageAvecPetitePause : public apprentissage
{
    public:
        apprentissageAvecPetitePause(const Questionnaire& questionnaire);
        void executer() override;

    private:
};

#endif // APPRENTISSAGEAVECPETITEPAUSE_H
