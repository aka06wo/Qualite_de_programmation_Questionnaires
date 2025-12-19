#include "EvaluationTest.h"
#include <iostream>

EvaluationTest::EvaluationTest(const Questionnaire &questionnaire)
    : Evaluation{questionnaire}
{}

void EvaluationTest::lanceEvaluation()
{
    std::cout << "Lancement de l'evaluation Test sur le questionnaire\n" ;
    augmenteEssai() ;
    int nbQuestions = d_questionnaire->nombreDeQuestions();
    std::string reponseDeUtilisateur ;

    for (int i = 0; i < nbQuestions; ++i)
    {
        std::cout << separateur('=',100) ;
        std::cout <<"Entrez * pour quitter l'evaluation test\n" ;
        std::cout << separateur('-',100) ;
        std::cout << "Question N°" + std::to_string(i+1) + " sur "
                  + std::to_string(nbQuestions) + '\n' ;
        std::cout<<d_questionnaire->intituleQuestionNumero(i) <<'\n';
        std::cout<<d_questionnaire->instructionsQuestionNumero(i) << '\n';
        std::cout<<"> " ;
        getline(std::cin,reponseDeUtilisateur);
        if (reponseDeUtilisateur == "*")
        {
            std::cout<< "Vous avez quittez l'evaluation Test\n" ;
            break;
        }
        reponseDeUtilisateur  = lireReponseValide(i,reponseDeUtilisateur) ;
        bool estJuste = d_questionnaire->verificationReponse(i, reponseDeUtilisateur) ;
        if (estJuste)
        {
            std::cout << "[v] Bonne reponse !\n" ;
            augmenteScore() ;
        }
        else {
            std::cout << "[x] Mauvaise reponse..." << '\n';
            enregistreErreurs(i) ;
        }
        std::cout << separateur('=',100) ;
        std::cout<<"\n\n" ;
    }
    std::cout<<resultatEvaluation();
}
