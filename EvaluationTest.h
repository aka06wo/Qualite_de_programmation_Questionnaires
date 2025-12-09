#ifndef CODE_QUESTIONNAIRE_EVALUATIONTEST_H
#define CODE_QUESTIONNAIRE_EVALUATIONTEST_H

#include "Evaluation.h"
#include <iostream>
#include <string>

class EvaluationTest : public Evaluation
{
public:

    EvaluationTest(const Questionnaire &questionnaire);
    void lanceEvaluation() override;

private:

#endif // CODE_QUESTIONNAIRE_EVALUATIONTEST_H
