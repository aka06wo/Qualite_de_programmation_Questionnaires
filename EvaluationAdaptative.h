#ifndef EVALUATIONADAPTATIVE_H
#define EVALUATIONADAPTATIVE_H

#include "Evaluation.h"

class EvaluationAdaptative : public Evaluation
{
public:
    EvaluationAdaptative(const Questionnaire &questionnaire);

    // et si on renommait premierPassage et secondPassage (pose et repose questions ?)
    void PoseQuestionsDe(std::vector<int>& tableau) ;
    void ReposerQuestionsFausses() ;
    void lanceEvaluation() override;

private:

};

#endif // EVALUATIONADAPTATIVE_H
