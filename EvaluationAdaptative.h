#ifndef EVALUATIONADAPTATIVE_H
#define EVALUATIONADAPTATIVE_H

#include "Evaluation.h"
#include <vector>

class EvaluationAdaptative : public Evaluation
{
public:
    EvaluationAdaptative(const Questionnaire &questionnaire);
    void lanceEvaluation() override;

private:
    void PoseQuestions(std::vector<int>& tableau,std::vector<int>& TableauErreurs );

};

#endif // EVALUATIONADAPTATIVE_H
