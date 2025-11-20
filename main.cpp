#include <iostream>
#include "QuestionnaireJSON.h"

void test() {
    QuestionnaireJSON fichier {"Questionnaire sur la programmation"} ;
    Questionnaire monQuestionnaire {} ;
    fichier.chargerDansQuestionnaire(monQuestionnaire) ;
    monQuestionnaire.apprentissage() ;
}

int main()
{
    test() ;
    return 0;
}
