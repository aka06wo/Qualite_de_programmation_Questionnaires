#ifndef CODE_QUESTIONNAIRE_EVALUATION_H
#define CODE_QUESTIONNAIRE_EVALUATION_H


#include "Questionnaire.h"

class Evaluation
{
public:
    Evaluation(const Questionnaire &questionnaire);
    std::string reponseUtilisateurQuestion() const ;
    virtual void lanceEvaluation() = 0;
    virtual void resultatEvaluation() const = 0;
    virtual ~Evaluation() = default;

    // on mets la possibilité de voir ses erreurs, on stocke l'indice des questions ou il se trompe
    // a la fin on lui affiche question et reponse
protected:
    // pour s'assurer qu'on le modifie pas (le questionnaire)
    const Questionnaire *d_questionnaire;
    int d_nbEssai ;
    int d_score ;
};


#endif //CODE_QUESTIONNAIRE_EVALUATION_H