#include "QuestionnaireJSON.h"
#include "Evaluation.h"
#include "EvaluationSecondeChance.h"
#include "EvaluationAdaptative.h"
#include "QuestionChoixMultiple.h"
#include "QuestionNumerique.h"
#include "QuestionTexte.h"

void test() {
    /*QuestionnaireJSON fichier {"Questionnaire sur la programmation"} ;
    Questionnaire monQuestionnaire {} ;
    fichier.chargerDansQuestionnaire(monQuestionnaire) ;
    EvaluationSecondeChance monEva {monQuestionnaire} ;

    monEva.lanceEvaluation() ;*/

    QuestionnaireJSON fichier {"Questionnaire sur la programmation"} ;
    Questionnaire monQuestionnaire {} ;
    fichier.chargerDansQuestionnaire(monQuestionnaire) ;
    EvaluationAdaptative eval {monQuestionnaire} ;
    eval.lanceEvaluation();
}
void testEvalAdaptative ()
{
     std::vector<std::unique_ptr<Question>> questions;

    // Question 1 : Choix Multiple
    std::vector<std::string> choix = {"Python", "Java", "C++"};
    questions.push_back(std::make_unique<QuestionChoixMultiple>(
        "Quel langage est le plus utilisé ?", choix, 1));

    // Question 2 : Numérique
    questions.push_back(std::make_unique<QuestionNumerique>(
        "Combien de continents y a-t-il sur Terre ?", 7, 10, 1));

    // Question 3 : Texte
    questions.push_back(std::make_unique<QuestionTexte>(
        "Qui a inventé le langage C++ ?", "Bjarne Stroustrup"));

    // Crée le questionnaire
    Questionnaire q("Questionnaire de test","les langages de programmation", std::move(questions));
    EvaluationAdaptative eval {q} ;
    eval.lanceEvaluation();
}

int main()
{
    //test() ;
    testEvalAdaptative();
    return 0;
}
