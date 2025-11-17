#ifndef CODE_QUESTIONNUMERIQUE_H
#define CODE_QUESTIONNUMERIQUE_H

#include "Question.h"
#include <iostream>


class QuestionNumerique : public Question
{
    public:
    QuestionNumerique(const string& intitule,int reponse);
    string reponse() const override ;
    void afficherReponse() const override ;
    bool estunentier(const string& reponse) const;
    bool verificationReponse(string reponse) const override ;


    private:
    int d_reponse;
    int d_limitemax,d_limitemin;

};


#endif //CODE_QUESTIONNUMERIQUE_H
