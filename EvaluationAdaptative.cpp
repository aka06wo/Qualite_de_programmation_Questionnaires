#include "EvaluationAdaptative.h"

EvaluationAdaptative::EvaluationAdaptative(const std::string &nomQuestionnaire):Evaluation{nomQuestionnaire},d_questionsNonposees{},d_questionsFaussees{}
{

}

void EvaluationAdaptative::lanceEvaluation() {
    vector<bool> TabDeMarque(d_questionsNonposees.size(),false);
}

void EvaluationAdaptative::resultatEvaluation() const
{

}


