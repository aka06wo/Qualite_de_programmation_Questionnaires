#ifndef CODE_QUESTIONNAIRE_EVALUATION_H
#define CODE_QUESTIONNAIRE_EVALUATION_H

#include "Questionnaire.h"
#include <string>
#include <vector>
#include <memory>

class Evaluation
{
    public:
    Evaluation(const Questionnaire &questionnaire);
    virtual ~Evaluation() = default;
    void revueErreursCommises() const ;
    void changerQuestionnaire(const Questionnaire &nouveauQuestionnaire);
    virtual void lanceEvaluation() = 0 ;

    protected:
    const Questionnaire *d_questionnaire;
    std::string lireReponseValide(int indiceQuestion, const std::string &reponse) const ;
    void resultatEvaluation() const ;
    void enregistreErreurs(int indiceErreur) ;
    void augmenteScore() ;
    void augmenteEssai() ;

    private:
    int d_nbEssai ;
    int d_score ;
    std::vector<int> d_tabIndiceErreur ;
};


#endif //CODE_QUESTIONNAIRE_EVALUATION_H
