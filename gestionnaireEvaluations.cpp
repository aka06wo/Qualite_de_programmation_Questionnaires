#include <iostream>

#include "gestionnaireEvaluations.h"
#include "EvaluationAdaptative.h"
#include "EvaluationSecondeChance.h"
#include "EvaluationTest.h"

gestionnaireEvaluations::gestionnaireEvaluations(const Questionnaire &q) :
            d_questionnaire(&q), d_evaluations {}
{
    d_evaluations.push_back(std::make_unique<EvaluationTest>(q)) ;
    d_evaluations.push_back(std::make_unique<EvaluationSecondeChance>(q)) ;
    d_evaluations.push_back(std::make_unique<EvaluationAdaptative>(q)) ;
}

void gestionnaireEvaluations::commenceEvaluation(int evaluation)
{
    std::cout << '[' + d_questionnaire->nomQuestionnaire() << "] pour un total de " ;
    std::cout << d_questionnaire->nombreDeQuestions() << " questions\n" ;
    d_evaluations[evaluation]->lanceEvaluation();
}

bool gestionnaireEvaluations::lanceEvaluation(int evaluation)
{
    if (evaluation == EVALUATION_SECONDE_CHANCE) {
        std::cout << "Lancement de l'evaluation Seconde Chance sur le questionnaire\n" ;
        commenceEvaluation(evaluation) ;
        return true ;
    }
    else if (evaluation == EVALUATION_ADAPTATIVE) {
        std::cout << "Lancement de l'evaluation Adaptative sur le questionnaire\n" ;
        commenceEvaluation(evaluation) ;
        return true ;
    }
    else if (evaluation == EVALUATION_TEST) {
        std::cout << "Lancement de l'evaluation Test sur le questionnaire\n" ;
        commenceEvaluation(evaluation) ;
        return true;
    }
    else {
        // on doit afficher ce message dans le menu plutot
        //std::cout<<"Numéro de l'evaluation invalide, veuillez saisir un numéro valide\n" ;
        return false ;
    }

}


