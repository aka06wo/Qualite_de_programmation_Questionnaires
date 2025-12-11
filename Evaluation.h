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




    void augmenteScore() ;
    void augmenteEssai() ;
    void enregistreErreurs(int indiceErreur) ;




    void revueErreursCommises() const ;
    void resultatEvaluation() const ;
    virtual void lanceEvaluation() = 0;


protected:
    const Questionnaire *d_questionnaire;
    static std::string reponseUtilisateurQuestion() ;

private:
    int d_nbEssai ;
    int d_score ;
    std::vector<int> d_tabIndiceErreur ;
};


#endif //CODE_QUESTIONNAIRE_EVALUATION_H
