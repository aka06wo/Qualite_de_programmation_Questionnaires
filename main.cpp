#include "QuestionnaireJSON.h"
#include "Evaluation.h"
#include "EvaluationSecondeChance.h"
#include "EvaluationAdaptative.h"
#include "certificat.h"
#include "certificatHTML.h"
#include "EvaluationTest.h"

#include <fstream>


void testSauvegardeFichier()
{
    QuestionnaireJSON fichier {"Questionnaire sur la programmation"} ;
    Questionnaire monQuestionnaire {} ;
    fichier.chargerDansQuestionnaire(monQuestionnaire) ;

    fichier.sauvegarderQuestionnaire(monQuestionnaire) ;
}

void evalSecondeChance() {
    QuestionnaireJSON fichier {"Questionnaire sur la programmation"} ;
    Questionnaire monQuestionnaire {} ;
    fichier.chargerDansQuestionnaire(monQuestionnaire) ;

    EvaluationSecondeChance monEva {monQuestionnaire} ;
    monEva.lanceEvaluation() ;
}

void evalAdaptative() {
    QuestionnaireJSON fichier {"Questionnaire sur la programmation"} ;
    Questionnaire monQuestionnaire {} ;
    fichier.chargerDansQuestionnaire(monQuestionnaire) ;
    EvaluationAdaptative eval {monQuestionnaire} ;
    eval.lanceEvaluation();
}

void evalTest() {
    QuestionnaireJSON fichier {"Questionnaire sur la programmation"} ;
    Questionnaire monQuestionnaire {} ;
    fichier.chargerDansQuestionnaire(monQuestionnaire) ;
    EvaluationTest eval {monQuestionnaire} ;
    eval.lanceEvaluation();
}


void testCertificatHTML ()
{
    certificatHTML monCertificat{};

    std::ofstream fichier("certificat.html");
    if (fichier.is_open())
    {
        monCertificat.genereCertificat("Algorithmique","Evaluation EC2",19,20) ;
        fichier.close();
        std::cout << "\nFichier certificat.html créé avec succès !\n";
    } else {
        std::cout << "Erreur lors de la création du fichier.\n";
    }
}

int main()
{
    evalSecondeChance() ;
    //evalAdaptative();
    //evalTest() ;
    //testCertificatHTML();

    return 0;
}
