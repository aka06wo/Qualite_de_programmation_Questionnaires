#ifndef CODE_QUESTIONNAIRE_EVALUATION_H
#define CODE_QUESTIONNAIRE_EVALUATION_H


#include "Questionnaire.h"
#include "QuestionnaireJSON.h"

class Evaluation
{
public:
    Evaluation(const std::string &nomQuestionnaire);
    virtual std::string reponseUtilisateurQuestion() const = 0 ;
    virtual void lanceEvaluation() const = 0;
    virtual void resultatEvaluation() const = 0;
    virtual void certificatReussite() const = 0;
    virtual void certificatHtml() const = 0;
    virtual ~Evaluation() = default;

    protected:
    // pour s'assurer qu'on le modifie pas (le questionnaire)
    const Questionnaire *d_questionnaire;
    int d_nbEssai ;
    int d_score ;
};


#endif //CODE_QUESTIONNAIRE_EVALUATION_H
