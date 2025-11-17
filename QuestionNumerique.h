#ifndef CODE_QUESTIONNUMERIQUE_H
#define CODE_QUESTIONNUMERIQUE_H

#include "Question.h"
#include <iostream>


class QuestionNumerique : public Question
{
    public:
    // l'utilisateur nous donne d_limiteMax et min, on rajoute dans les paramètres du constructeur
    QuestionNumerique(const string& intitule,int reponse);
    string reponse() const override ;
    void afficherReponse() const override ;
    bool estUnEntier(const string& reponse) const;
    bool verificationReponse(const string &reponse) const override ;


    private:
    int d_reponse;
    int d_limiteMax,d_limiteMin;
};


#endif //CODE_QUESTIONNUMERIQUE_H
