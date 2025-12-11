#ifndef EVALUATIONADAPTATIVE_H
#define EVALUATIONADAPTATIVE_H

#include "Evaluation.h"

class EvaluationAdaptative : public Evaluation
{
public:
    EvaluationAdaptative(const Questionnaire &questionnaire);
    void lanceEvaluation() override;

private:
    void PoseQuestions(vector<int>& tableau,vector<int>& TableauErreurs );

};

#endif // EVALUATIONADAPTATIVE_H
