#ifndef CODE_QUESTIONNAIRE_EVALUATIONTEST_H
#define CODE_QUESTIONNAIRE_EVALUATIONTEST_H

#include "Evaluation.h"
#include "Questionnaire.h"

class EvaluationTest : public Evaluation
{
    public:
    EvaluationTest(const Questionnaire &questionnaire);
    void lanceEvaluation() override;
};


#endif //CODE_QUESTIONNAIRE_EVALUATIONTEST_H