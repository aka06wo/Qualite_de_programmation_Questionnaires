#ifndef CODE_QUESTIONNAIRE_EVALUATION_H
#define CODE_QUESTIONNAIRE_EVALUATION_H


#include "Questionnaire.h"
#include <string>
#include <vector>

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

    // Fonction helper pour obtenir une réponse validée selon le type de question
    std::string obtenirReponseValidee(int indexQuestion) const;

protected:
    int d_nbEssai ;
    int d_score ;
    const Questionnaire *d_questionnaire;
    std::vector<int> d_tabIndiceErreur ;
};


#endif //CODE_QUESTIONNAIRE_EVALUATION_H
