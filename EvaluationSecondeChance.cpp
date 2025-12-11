#include "EvaluationSecondeChance.h"
#include "certificat.h"
#include "Afficheur.h"

EvaluationSecondeChance::EvaluationSecondeChance(const Questionnaire &questionnaire,
                        std::unique_ptr<Afficheur> afficheur) : Evaluation{questionnaire,std::move(afficheur)}
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
        d_afficheur->separateur(100,'=') ;
        d_afficheur->affiche("Question N°" + std::to_string(i+1) + " sur "
                                        + std::to_string(nbQuestions) + '\n') ;
        getline(std::cin,reponseUtilisateur);
        afficheQuestionsInstructions(i) ;
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
                d_afficheur->affiche("[x] Incorrect, mais tu as droit à une seconde chance. \n") ;
                d_afficheur->affiche("> ") ;
                getline(std::cin,reponseUtilisateur);
                reponseUtilisateur = lireReponseValide(i,reponseUtilisateur) ;
                if ( ! d_questionnaire->verificationReponse(i,reponseUtilisateur))
                {
                    enregistreErreurs(i) ;
                    d_afficheur->separateur(100,'.') ;
                    d_afficheur->affiche("[x] Toujours incorrect.\n") ;
                    d_afficheur->affiche("La bonne reponse est : "+ d_questionnaire->reponseQuestionNumero(i)) ;
                    d_afficheur->separateur(100,'.') ;
                }
                else
                {
                    d_afficheur->affiche("[v] Bonne reponse !\n") ;
                    augmenteScore() ;
                }
            }
            else
            {
                d_afficheur->affiche("[v] Bonne reponse !\n") ;
                augmenteScore() ;
            }

            d_afficheur->separateur(100,'=') ;
            d_afficheur->affiche("\n\n") ;
        }

        resultatEvaluation() ;
    }
}


