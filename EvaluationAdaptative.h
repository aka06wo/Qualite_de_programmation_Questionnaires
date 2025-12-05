#ifndef EVALUATIONADAPTATIVE_H
#define EVALUATIONADAPTATIVE_H

#include<memory>
#include <iostream>
#include "Evaluation.h"
#include <vector>
#include <cstdlib>
#include <ctime>

class EvaluationAdaptative : public Evaluation
{
public:
    EvaluationAdaptative(const Questionnaire &questionnaire);
    void lanceEvaluation() override;

private:

};

#endif // EVALUATIONADAPTATIVE_H
