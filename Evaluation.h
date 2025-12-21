#ifndef CODE_QUESTIONNAIRE_EVALUATION_H
#define CODE_QUESTIONNAIRE_EVALUATION_H

#include "Questionnaire.h"
#include "essai.h"

#include <string>
#include <vector>

class Evaluation
{
    public:
    Evaluation(const Questionnaire &questionnaire);
    virtual ~Evaluation() = default;
    int nombreEssais() const ;
    essai dernierEssai() const ;
    void augmenteScore() ;
    void augmenteEssai() ;
    void enregistreErreurs(int indiceErreur) ;
    int scoreDernierEssai() const ;
    std::string erreursEssaiNumero (int numEssai) const;
    std::string erreursCommisesEssais() const ;
    void changerQuestionnaire(const Questionnaire &nouveauQuestionnaire);
    double pourcentageReussite() const;
    std::string resultatEvaluation() const ;
    void affichageQuestionNumero (int i, int nbQuestions) const ;
    virtual void lanceEvaluation() = 0 ;

    protected:
    const Questionnaire *d_questionnaire;
    std::string lireReponseValide(int indiceQuestion, const std::string &reponse) const ;
    static std::string separateur(const char &c, int k) ;


    private:
    std::vector<essai> d_essais;
    static std::string messageSelonScore(double pourcentage) ;
};


#endif //CODE_QUESTIONNAIRE_EVALUATION_H
