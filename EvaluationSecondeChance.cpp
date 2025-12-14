#include "EvaluationSecondeChance.h"
#include "certificat.h"
#include <iostream>

EvaluationSecondeChance::EvaluationSecondeChance(const Questionnaire &questionnaire)
                        : Evaluation{questionnaire}
{
}


void EvaluationSecondeChance::lanceEvaluation() {
    augmenteEssai() ;
    std::string reponseUtilisateur ;
    int i=0 ;
    int nbQuestions = d_questionnaire->nombreDeQuestions() ;
    bool quitter = false ;

    while (i<nbQuestions && quitter==false)
    {
        std::cout << std::string(100,'=') << std::endl ;
        std::cout << "Question N°" + std::to_string(i+1) + " sur "
                  + std::to_string(nbQuestions) + '\n' ;
        std::cout << d_questionnaire->intituleQuestionNumero(i) ;
        std::cout << d_questionnaire->instructionsQuestionNumero(i) ;
        getline(std::cin,reponseUtilisateur);
        if (reponseUtilisateur == "*")
        {
            quitter = true ;
            resultatEvaluation() ;
        }
        else
        {
            reponseUtilisateur = lireReponseValide(i,reponseUtilisateur) ;
            if ( ! d_questionnaire->verificationReponse(i,reponseUtilisateur))
            {
                std::cout << "[x] Incorrect, mais tu as droit à une seconde chance. \n" ;
                std::cout << "> " ;
                getline(std::cin,reponseUtilisateur);
                reponseUtilisateur = lireReponseValide(i,reponseUtilisateur) ;
                if ( ! d_questionnaire->verificationReponse(i,reponseUtilisateur))
                {
                    enregistreErreurs(i) ;
                    std::cout << std::string(100,'.') << std::endl ;
                    std::cout << "[x] Toujours incorrect.\n" ;
                    std::cout << "La bonne reponse est : "+ d_questionnaire->reponseQuestionNumero(i) ;
                    std::cout << std::string(100,'.') << std::endl ;
                }
                else
                {
                    std::cout << "[v] Bonne reponse !\n" ;
                    augmenteScore() ;
                }
            }
            else
            {
                std::cout << "[v] Bonne reponse !\n" ;
                augmenteScore() ;
            }

            std::cout << std::string(100,'=') << std::endl ;
            std::cout << "\n\n" ;
        }

        resultatEvaluation() ;
    }
}
