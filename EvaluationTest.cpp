#include "EvaluationTest.h"
#include "styleAffichage.h"
#include <iostream>

EvaluationTest::EvaluationTest(const Questionnaire &questionnaire)
    : Evaluation{questionnaire}
{}


void EvaluationTest::lanceEvaluation()
{
    styleAffichage::affichageEnteteActivites("EVALUATION TEST") ;

    augmenteEssai() ;
    int nbQuestions = nombreDeQuestions();
    std::string reponseDeUtilisateur ;
    std::cin.ignore();

    for (int i = 0; i < nbQuestions; ++i)
    {
        styleAffichage::affichageEnteteQuestion("EVALUATION TEST", i, nbQuestions) ;
        styleAffichage::ecritEnBleu("  (Tapez '*' pour quitter l'evaluation seconde chance)") ;
        affichageQuestionNumero(i, nbQuestions) ;

        getline(std::cin,reponseDeUtilisateur);

        if (reponseDeUtilisateur == "*")
        {
            std::cout << "\n [!] Vous avez quitté l'évaluation Test." << std::endl;
            break;
        }

        reponseDeUtilisateur = lireReponseValide(i, reponseDeUtilisateur) ;
        bool estJuste = reponseJuste(i, reponseDeUtilisateur) ;

        if (estJuste)
        {
            styleAffichage::ecritEnVert("\n [V] BONNE RÉPONSE !\n") ;
            augmenteScore() ;
        }
        else {
            styleAffichage::ecritEnRouge("\n [X] MAUVAISE RÉPONSE...\n") ;
            enregistreErreurs(i) ;
        }

        styleAffichage::affichagePiedDePageQuestion() ;
    }

    styleAffichage::affichagePiedDePageActivites("EVALUATION TEST") ;

    std::cout << resultatEvaluation();
}