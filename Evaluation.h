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
    std::string  lireReponseValide(int indiceQuestion ) const;
    virtual void lanceEvaluation() = 0;
    void resultatEvaluation() const ;//tous les types d'évaluation ont la meme présentation du résultat
    virtual ~Evaluation() = default;
    void genererCertificatHtml() const;
    void genererCertificatText() const;

    // on mets la possibilité de voir ses erreurs, on stocke l'indice des questions ou il se trompe
    // a la fin on lui affiche question et reponse

    // Fonction helper pour obtenir une réponse validée selon le type de question
    std::string obtenirReponseValidee(int indexQuestion) const;

protected:
    int d_nbEssai ;
    int d_score ;
    const Questionnaire *d_questionnaire;
    std::vector<int> d_tabIndiceErreur ;

    // Méthodes helper privées pour la validation
    bool estEntierValide(const std::string& str) const;
    bool estChoixValide(const std::string& str, int nbChoix) const;
    void nettoyerBuffer() const;

};


#endif //CODE_QUESTIONNAIRE_EVALUATION_H
