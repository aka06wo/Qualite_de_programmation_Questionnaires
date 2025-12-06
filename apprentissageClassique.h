#ifndef APPRENTISSAGECLASSIQUE_H
#define APPRENTISSAGECLASSIQUE_H


#include "apprentissage.h"


class apprentissageClassique : public apprentissage
{
    ///Les questions sont posées dans l'ordre
    ///avec un affichage immédiat
    public:
        apprentissageClassique(const Questionnaire& questionnaire);
        void executer() override;

    private:
};

#endif // APPRENTISSAGECLASSIQUE_H
