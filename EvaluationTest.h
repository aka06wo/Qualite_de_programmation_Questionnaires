#ifndef EVALUATIONTEST_H
#define EVALUATIONTEST_H

#include "Evaluation.h"
class EvaluationTest : public Evaluation {
public:
    EvaluationTest(const Questionnaire &quest);
    std::string reponseUtilisateurQuestion() const override;
    void lanceEvaluation() const override;
    void resultatEvaluation() const override;
    void certificatReussite() const override;
    void certificatHtml() const override;

private:
};

#endif // EVALUATIONTEST_H
