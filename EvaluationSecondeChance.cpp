#include "EvaluationSecondeChance.h"
#include "certificat.h"

EvaluationSecondeChance::EvaluationSecondeChance(const Questionnaire &questionnaire) : Evaluation{questionnaire}
{
}

void EvaluationSecondeChance::lanceEvaluation()
{
    d_nbEssai++ ;
    std::string reponseUtilisateur ;

    // faire une boucle while pour arreter le questionnaire si l'utilisateur le souhaite
    // qu'il appuie sur * pour arreter le questionnaire par exemple, il faut qu'on recupere la saisie
    // utilisateur avant de la tester (verifier)


    for (int i=0 ; i<d_questionnaire->nombreDeQuestions();i++)
    {
        separateur(100,'=') ;

        std::cout<<d_questionnaire->intituleQuestionNumero(i) ;
        std::cout<<d_questionnaire->instructionsQuestionNumero(i) ;
        reponseUtilisateur = lireReponseValide(i) ;

        if (!d_questionnaire->verificationReponse(i,reponseUtilisateur))
        {
            d_tabIndiceErreur.push_back(i) ;
            std::cout<<"[x] Incorrect, mais tu as droit à une seconde chance. \n" ;
            reponseUtilisateur = lireReponseValide(i) ;
            if (!d_questionnaire->verificationReponse(i,reponseUtilisateur))
            {
                separateur(100,'.') ;
                std::cout<<"[x] Toujours incorrect.\n" ;
                std::cout<<"La bonne reponse est : "+ d_questionnaire->reponseQuestionNumero(i) ;
                separateur(100,'.') ;
            }
            else {
                std::cout<<"[v] Bonne reponse !\n" ;
                d_score++ ;
            }
        }
        else
        {
            std::cout<<"[v] Bonne reponse !\n" ;
            d_score++ ;
        }

        separateur(100,'=') ;
        std::cout<<"\n\n" ;
    }

    // il faut juste qu'on stocke
    resultatEvaluation() ;
}


