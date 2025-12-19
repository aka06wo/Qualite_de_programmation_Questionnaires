#include <iostream>

#include "gestionnaireEvaluations.h"

#include "certificatHTML.h"
#include "certificatText.h"
#include "EvaluationAdaptative.h"
#include "EvaluationSecondeChance.h"
#include "EvaluationTest.h"

gestionnaireEvaluations::gestionnaireEvaluations() : d_questionnaire{}, d_evaluations{}, d_certificats{}
{

}

gestionnaireEvaluations::gestionnaireEvaluations(const Questionnaire &q) :
            d_questionnaire(&q), d_evaluations {}, d_certificats{}
{
    d_evaluations.push_back(std::make_unique<EvaluationTest>(q)) ;
    d_evaluations.push_back(std::make_unique<EvaluationSecondeChance>(q)) ;
    d_evaluations.push_back(std::make_unique<EvaluationAdaptative>(q)) ;

    d_certificats.push_back(std::make_unique<certificatText>()) ;
    d_certificats.push_back(std::make_unique<certificatHTML>()) ;
}

void gestionnaireEvaluations::changeQuestionnaire(const Questionnaire &q)
{
    d_questionnaire = &q ;
    for (int i=0 ; i<d_evaluations.size() ; i++)
    {
        d_evaluations[i]->changerQuestionnaire(q) ;
    }
}

void gestionnaireEvaluations::genereCertificat(int numCertificat,int evaluation)
{
    d_certificats[numCertificat]->genereCertificat( d_questionnaire->nomQuestionnaire(),
        d_questionnaire->descriptionQuestionnaire(), d_evaluations[evaluation]->scoreDernierEssai(),
        d_questionnaire->nombreDeQuestions()) ;
}

void gestionnaireEvaluations::commenceEvaluation(int evaluation)
{
    std::cout << '[' + d_questionnaire->nomQuestionnaire() << "] pour un total de " ;
    std::cout << d_questionnaire->nombreDeQuestions() << " questions\n" ;
    d_evaluations[evaluation]->lanceEvaluation();
}


