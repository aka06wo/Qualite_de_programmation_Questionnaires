#include "QuestionnaireJSON.h"
#include "Evaluation.h"
#include "EvaluationSecondeChance.h"
#include "EvaluationAdaptative.h"
#include "certificat.h"




/*
 Et on doit cacher certaines methodes a l'utilisateur, privée, et utilser l'amitié
 */








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

void testCertificat () {
    certificat monCertificat("Mamadou", "Programmation C++", 85);

    // ----- Test console -----
    monCertificat.certificatText(std::cout);

    // ----- Test HTML dans un fichier -----
    std::ofstream fichier("certificat.html");
    if (fichier.is_open())
    {
        monCertificat.certificatHtml(fichier);
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
    //testCertificat();

    return 0;
}
