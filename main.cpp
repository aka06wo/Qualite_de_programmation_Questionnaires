#include <iostream>
#include "QuestionnaireJSON.h"
#include "Evaluation.h"
//#include "EvaluationSecondeChance.h"

void test() {
    QuestionnaireJSON fichier {"Questionnaire sur la programmation"} ;
    Questionnaire monQuestionnaire {} ;
    fichier.chargerDansQuestionnaire(monQuestionnaire) ;
    //EvaluationSecondeChance monEva {monQuestionnaire} ;

    monEva.lanceEvaluation() ;
}

int main()
{
    test() ;
    return 0;
}
