#include "EvaluationSecondeChance.h"
#include "styleAffichage.h"
#include <iostream>

EvaluationSecondeChance::EvaluationSecondeChance(const Questionnaire &questionnaire)
                        : Evaluation{questionnaire}
{
}


void EvaluationSecondeChance::lanceEvaluation()
{
    styleAffichage::affichageEnteteActivites("EVALUATION SECONDE CHANCE") ;

    augmenteEssai();
    std::string reponseUtilisateur;
    int i = 0;
    int nbQuestions = nombreDeQuestions();
    bool quitter = false;

    std::cin.ignore();

    while (i < nbQuestions && !quitter)
    {
        styleAffichage::affichageEnteteQuestion("EVALUATION SECONDE CHANCE", i, nbQuestions);
        styleAffichage::ecritEnBleu("  (Tapez '*' pour quitter l'evaluation seconde chance)") ;

        affichageQuestionNumero(i, nbQuestions);
        std::getline(std::cin, reponseUtilisateur);

        if (reponseUtilisateur == "*")
        {
            std::cout << "\n [!] Vous avez quitté l'évaluation." << std::endl;
            quitter = true;
        }
        else {
            reponseUtilisateur = lireReponseValide(i, reponseUtilisateur);

            if (!reponseJuste(i, reponseUtilisateur))
            {
                styleAffichage::ecritEnRouge("\n[X] INCORRECT... Mais vous avez droit à une seconde chance !\n") ;
                std::cout << "   > ";

                std::getline(std::cin, reponseUtilisateur);
                reponseUtilisateur = lireReponseValide(i, reponseUtilisateur);

                if (!reponseJuste(i, reponseUtilisateur)) {
                    enregistreErreurs(i);
                    styleAffichage::ecritEnRouge("\n [X] TOUJOURS INCORRECT.\n") ;
                    std::cout << "     La bonne réponse est : " << reponseNumero(i) << std::endl;
                } else
                    {
                        styleAffichage::ecritEnVert("\n [V] BONNE RÉPONSE !\n") ;
                        augmenteScore();
                    }
            }
            else {
                styleAffichage::ecritEnVert("\n [V] BONNE RÉPONSE !\n") ;
                augmenteScore();
            }
        }
        styleAffichage::affichagePiedDePageQuestion() ;
        i++;
    }

    styleAffichage::affichagePiedDePageActivites("EVALUATION SECONDE CHANCE") ;

    if (!quitter) std::cout << resultatEvaluation();
}