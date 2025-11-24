#ifndef CODE_QUESTIONNAIRE_EVALUATIONSECONDECHANCE_H
#define CODE_QUESTIONNAIRE_EVALUATIONSECONDECHANCE_H

#include "Evaluation.h"

class EvaluationSecondeChance : public Evaluation
{
    public:
    EvaluationSecondeChance(const Questionnaire &questionnaire);
    void lanceEvaluation() override;
    void resultatEvaluation() const override;
    private:
};


#endif //CODE_QUESTIONNAIRE_EVALUATIONSECONDECHANCE_H