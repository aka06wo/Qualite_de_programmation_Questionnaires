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
    //virtual ~EvaluationAdaptative();
    std::string reponseUtilisateurQuestion() const override;
    void lanceEvaluation() const override;
    void resultatEvaluation() const override;
    void certificatReussite() const override;
    void certificatHtml() const  override;

private:
    int d_nbEssai;
    std::vector<std::unique_ptr<Question>> d_questionsNonposees;
    std::vector<std::unique_ptr<Question>> d_questionsFaussees;
};

#endif // EVALUATIONADAPTATIVE_H
