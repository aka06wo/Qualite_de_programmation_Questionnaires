#ifndef EVALUATIONADAPTATIVE_H
#define EVALUATIONADAPTATIVE_H

#include "Evaluation.h"

#include<iostream>
#include <vector>

class EvaluationAdaptative : public Evaluation
{
public:
    EvaluationAdaptative(const Questionnaire &questionnaire);
    void lanceEvaluation() override;

private:
    void PoseQuestionsDe(std::vector<int>& tableau);
    void ReposerQuestionsFausses();

};

#endif // EVALUATIONADAPTATIVE_H
