#ifndef CODE_QUESTIONNAIRE_GESTIONNAIREEVALUATIONS_H
#define CODE_QUESTIONNAIRE_GESTIONNAIREEVALUATIONS_H

#include "Questionnaire.h"
#include "Evaluation.h"

class gestionnaireEvaluations
{
    public :
    gestionnaireEvaluations(const Questionnaire &q) ;
    bool lanceEvaluation (int evaluation) ;

    private :
    const Questionnaire *d_questionnaire ;
    std::vector<std::unique_ptr<Evaluation>> d_evaluations ;
    static constexpr int EVALUATION_TEST = 0 ;
    static constexpr int EVALUATION_SECONDE_CHANCE = 1 ;
    static constexpr int EVALUATION_ADAPTATIVE = 2 ;
    void commenceEvaluation(int evaluation) ;

};


#endif //CODE_QUESTIONNAIRE_GESTIONNAIREEVALUATIONS_H