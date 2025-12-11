#ifndef CODE_QUESTIONNAIRE_EVALUATIONSECONDECHANCE_H
#define CODE_QUESTIONNAIRE_EVALUATIONSECONDECHANCE_H

#include "Evaluation.h"

class EvaluationSecondeChance : public Evaluation
{
    public:
    EvaluationSecondeChance(const Questionnaire &questionnaire,
                                std::unique_ptr<Afficheur> afficheur);
    void lanceEvaluation() override;

    private:
};


#endif //CODE_QUESTIONNAIRE_EVALUATIONSECONDECHANCE_H