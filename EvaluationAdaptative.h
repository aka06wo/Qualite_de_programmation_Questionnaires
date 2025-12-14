#ifndef EVALUATIONADAPTATIVE_H
#define EVALUATIONADAPTATIVE_H

#include "Evaluation.h"
#include <vector>

class EvaluationAdaptative : public Evaluation
{
public:
    EvaluationAdaptative(const Questionnaire &questionnaire,std::unique_ptr<Afficheur> afficheur);
    void lanceEvaluation() override;

private:
    void PoseQuestionsDe(std::vector<int>& tableau);
    void ReposerQuestionsFausses();

};

#endif // EVALUATIONADAPTATIVE_H
