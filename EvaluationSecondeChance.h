#ifndef CODE_QUESTIONNAIRE_EVALUATIONSECONDECHANCE_H
#define CODE_QUESTIONNAIRE_EVALUATIONSECONDECHANCE_H

#include "Evaluation.h"

class EvaluationSecondeChance : public Evaluation
{
    public:
    EvaluationSecondeChance(const std::string &nomQuestionnaire);
    std::string reponseUtilisateurQuestion() const override ;
    void lanceEvaluation() const override;
    void resultatEvaluation() const override;
    void certificatReussite() const override;
    void certificatHtml() const override;

    private:
    
};


#endif //CODE_QUESTIONNAIRE_EVALUATIONSECONDECHANCE_H