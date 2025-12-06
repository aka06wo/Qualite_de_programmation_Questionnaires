#ifndef CODE_QUESTIONNUMERIQUE_H
#define CODE_QUESTIONNUMERIQUE_H

#include "Question.h"


class QuestionNumerique : public Question
{
    public:
    QuestionNumerique(const std::string& intitule,int reponse,int limitemax,int limitemin);
    std::string reponse() const override ;
    int limiteMinimum() const ;
    int limiteMaximum() const ;
    void afficherQuestion() const override ;
    void afficherReponse() const override ;
    bool validiteEntreeUtilisateur(const std::string &reponse) const override ;
    bool verificationReponse(const std::string &reponse) const override ;
    std::unique_ptr<Question> clone() const override ;
    nlohmann::json conversionJSON () const override ;


    private:
    int d_reponse;
    int d_limiteMax,d_limiteMin;
};


#endif //CODE_QUESTIONNUMERIQUE_H
