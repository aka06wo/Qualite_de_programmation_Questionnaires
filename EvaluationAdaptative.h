#ifndef EVALUATIONADAPTATIVE_H
#define EVALUATIONADAPTATIVE_H

#include<memory>
#include <iostream>
#include "Question.h"
#include "Evaluation.h"

class EvaluationAdaptative : public Evaluation
{
public:
    EvaluationAdaptative(const std::string &nomQuestionnaire);
    void lanceEvaluation() override;
    void resultatEvaluation() const override;

private:
    std::vector<std::unique_ptr<Question>> d_questionsNonposees;
    std::vector<std::unique_ptr<Question>> d_questionsFaussees;
};

#endif // EVALUATIONADAPTATIVE_H
