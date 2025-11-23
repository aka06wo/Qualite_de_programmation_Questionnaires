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
    Questionnaire d_questionnaire;
    QuestionnaireJSON d_monFichier;
    int d_nbEssai ;
};


#endif //CODE_QUESTIONNAIRE_EVALUATION_H
