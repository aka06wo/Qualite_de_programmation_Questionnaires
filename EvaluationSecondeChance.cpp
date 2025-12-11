#include "EvaluationSecondeChance.h"
#include "certificat.h"
#include "Afficheur.h"

EvaluationSecondeChance::EvaluationSecondeChance(const Questionnaire &questionnaire) : Evaluation{questionnaire}
{
}

void EvaluationSecondeChance::lanceEvaluation()
{
    augmenteEssai() ;
    std::string reponseUtilisateur ;

    // faire une boucle while pour arreter le questionnaire si l'utilisateur le souhaite
    // qu'il appuie sur * pour arreter le questionnaire par exemple, il faut qu'on recupere la saisie
    // utilisateur avant de la tester (verifier)


    for (int i=0 ; i<d_questionnaire->nombreDeQuestions();i++)
    {
        Afficheur::separateur(100,'=') ;

        Afficheur::affichageConsole(d_questionnaire->intituleQuestionNumero(i)) ;
        Afficheur::affichageConsole(d_questionnaire->instructionsQuestionNumero(i)) ;

        reponseUtilisateur = lireReponseValide(i) ;

        if (!d_questionnaire->verificationReponse(i,reponseUtilisateur))
        {
            Afficheur::affichageConsole("[x] Incorrect, mais tu as droit à une seconde chance. \n") ;
            reponseUtilisateur = lireReponseValide(i) ;
            if (!d_questionnaire->verificationReponse(i,reponseUtilisateur))
            {
                enregistreErreurs(i) ;
                Afficheur::separateur(100,'.') ;
                Afficheur::affichageConsole("[x] Toujours incorrect.\n") ;
                Afficheur::affichageConsole("La bonne reponse est : "+ d_questionnaire->reponseQuestionNumero(i)) ;
                Afficheur::separateur(100,'.') ;
            }
            else {
                Afficheur::affichageConsole("[v] Bonne reponse !\n") ;
                augmenteScore() ;
            }
        }
        else
        {
            Afficheur::affichageConsole("[v] Bonne reponse !\n") ;
            augmenteScore() ;
        }

        Afficheur::separateur(100,'=') ;
        Afficheur::affichageConsole("\n\n") ;
    }

    // il faut juste qu'on stocke
    resultatEvaluation() ;


    // dans la classe evaluation (je teste)
    revueErreursCommises() ;
}
