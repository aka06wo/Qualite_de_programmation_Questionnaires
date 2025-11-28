#ifndef CODE_QUESTIONNAIRE_EVALUATION_H
#define CODE_QUESTIONNAIRE_EVALUATION_H


#include "Questionnaire.h"
#include "QuestionnaireJSON.h"



class Evaluation
{
public:
    Evaluation(const Questionnaire &questionnaire);
    std::string reponseUtilisateurQuestion() const ;
    virtual void lanceEvaluation() = 0;
    virtual void resultatEvaluation() const = 0;
    virtual ~Evaluation() = default;

    // on mets la possibilité de voir ses erreurs, on stocke l'indice des questions ou il se trompe
    // a la fin on lui affiche question et reponse
protected:
    // pour s'assurer qu'on le modifie pas (le questionnaire)
    const Questionnaire *d_questionnaire;
    int d_nbEssai ;
    int d_score ;
};
/*class Evaluation
{
public:
    Evaluation(const std::string &nomQuestionnaire);
    std::string reponseUtilisateurQuestion() const ;
    virtual void lanceEvaluation() const = 0;
    virtual void resultatEvaluation() const = 0;
    //virtual void certificatReussite() const = 0;
   // virtual void certificatHtml() const = 0;
    virtual ~Evaluation() = default;

protected:
    Questionnaire d_questionnaire;
    QuestionnaireJSON d_monFichier;
    int d_nbEssai ;
};*/


#endif //CODE_QUESTIONNAIRE_EVALUATION_H
