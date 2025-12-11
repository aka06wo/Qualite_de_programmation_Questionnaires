#ifndef CODE_QUESTIONNAIRE_EVALUATION_H
#define CODE_QUESTIONNAIRE_EVALUATION_H

#include "Questionnaire.h"
#include <string>
#include <vector>
#include <memory>

#include "Afficheur.h"
#include "certificat.h"
#include "certificatText.h"

class AfficheurConcole ;

class Evaluation
{
    public:
    Evaluation(const Questionnaire &questionnaire,
                    std::unique_ptr<Afficheur> afficheur);
    virtual ~Evaluation() = default;
    int score() const ;
    int nombreEssais() const ;
    int nombreErreurs() const ;

    void revueErreursCommises() const ;
    void resultatEvaluation() const ;
    virtual void lanceEvaluation() = 0 ;

    protected:
    const Questionnaire *d_questionnaire;
    std::unique_ptr<Afficheur> d_afficheur;
    void augmenteScore() ;
    void augmenteEssai() ;
    void afficheQuestionsInstructions(int indice) const ;
    void enregistreErreurs(int indiceErreur) ;
    std::string lireReponseValide(int indiceQuestion, const std::string &reponse) const ;


    private:
    int d_nbEssai ;
    int d_score ;
    std::vector<int> d_tabIndiceErreur ;
    certificatText d_certificatText;
};



#endif //CODE_QUESTIONNAIRE_EVALUATION_H
