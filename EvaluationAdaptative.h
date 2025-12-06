#ifndef EVALUATIONADAPTATIVE_H
#define EVALUATIONADAPTATIVE_H

#include "Evaluation.h"

class EvaluationAdaptative : public Evaluation
{
public:
    EvaluationAdaptative(const Questionnaire &questionnaire);
    void lanceEvaluation() override;

private:

};

#endif // EVALUATIONADAPTATIVE_H
