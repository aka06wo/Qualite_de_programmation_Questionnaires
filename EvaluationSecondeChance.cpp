#include "EvaluationSecondeChance.h"
#include <iostream>

EvaluationSecondeChance::EvaluationSecondeChance(const Questionnaire &questionnaire)
                        : Evaluation{questionnaire}
{
}


void EvaluationSecondeChance::lanceEvaluation()
{
    std::cout << "Lancement de l'evaluation Seconde Chance sur le questionnaire\n" ;
    augmenteEssai() ;
    std::string reponseUtilisateur ;
    int i=0 ;
    int nbQuestions = d_questionnaire->nombreDeQuestions() ;
    bool quitter = false ;

    while (i<nbQuestions && quitter==false)
    {
        std::cout << separateur('=',100) ;
        std::cout <<"Entrez * pour quitter l'evaluation seconde chance\n" ;
        std::cout << separateur('-',100) ;
        std::cout << "Question N°" + std::to_string(i+1) + " sur "
                  + std::to_string(nbQuestions) + '\n' ;
        std::cout << d_questionnaire->intituleQuestionNumero(i) << '\n';
        std::cout << d_questionnaire->instructionsQuestionNumero(i) << '\n' ;
        getline(std::cin,reponseUtilisateur);
        if (reponseUtilisateur == "*")
        {
            std::cout<< "Vous avez quittez l'evaluation Seconde Chance\n" ;
            quitter = true ;
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
                    std::cout << separateur('.',100) ;
                    std::cout << "[x] Toujours incorrect.\n" ;
                    std::cout << "La bonne reponse est : "+ d_questionnaire->reponseQuestionNumero(i) << '\n' ;
                    std::cout << separateur('.',100) ;
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
        }
        std::cout << separateur('=',100) ;
        std::cout << "\n\n" ;

        i++ ;
    }

    std::cout<<resultatEvaluation() ;
}
