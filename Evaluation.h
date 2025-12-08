#ifndef CODE_QUESTIONNAIRE_EVALUATION_H
#define CODE_QUESTIONNAIRE_EVALUATION_H


#include "Questionnaire.h"
#include <string>
#include <vector>



/*

On doit ecrire un gestionnaire d'evaluation qui gère les evalutaions

*/

class Evaluation
{
public:
    Evaluation(const Questionnaire &questionnaire);
    virtual ~Evaluation() = default;
    std::string lireReponseValide(int indiceQuestion) const  ;
    void revueErreursCommises() const ;
    void resultatEvaluation() const ;
    virtual void lanceEvaluation() = 0;


protected:
    int d_nbEssai ;
    int d_score ;
    const Questionnaire *d_questionnaire;
    std::vector<int> d_tabIndiceErreur ;
    static void separateur(int largeur, char symbole) ;
    static std::string reponseUtilisateurQuestion() ;
};


#endif //CODE_QUESTIONNAIRE_EVALUATION_H
