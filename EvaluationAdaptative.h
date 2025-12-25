#ifndef EVALUATIONADAPTATIVE_H
#define EVALUATIONADAPTATIVE_H

#include "Evaluation.h"
#include <vector>

class EvaluationAdaptative : public Evaluation
{
public:
    /**
     Constructeur de la classe EvaluationAdaptative
     @param questionnaire Le questionnaire servant de base à l'evaluation
     */
    EvaluationAdaptative(const Questionnaire &questionnaire);

    /**
     Effectue le premier tour de questions de l'evaluation
     Les questions sont traitees de maniere aleatoire jusqu'à epuisement du tableau
     @param tableau Le vecteur contenant les indices des questions à poser
     @param aQuitter Booleen passe par reference, mis à vrai si l'utilisateur abandonne avec '*'
     */
    void PremierPassage(std::vector<int>& tableau, bool &aQuitter);

    /**
     Effectue la phase de rattrapage sur les questions echouees lors du premier passage
     Cette methode n'est appelee que si des erreurs ont ete detectees precedemment
     */
    void SecondPassage();

    /**
     Gere le traitement complet d'une reponse : validation de la saisie et verification de la justesse
     Affiche un message de feedback immediat à l'utilisateur
     @param indice L'indice de la question concernee
     @param reponse La chaine de caracteres saisie par l'utilisateur
     @return Vrai si la reponse est correcte, Faux sinon
     */
    bool traiterReponse(int indice, const std::string& reponse);

    /**
     Lance l'evaluation adaptative (Premier passage puis Second passage)
     Met à jour le nombre d'essais et affiche le score final
     */
    void lanceEvaluation() override;

private:
    std::vector <int> d_indicesErreursPremierPassage ;

};

#endif // EVALUATIONADAPTATIVE_H
