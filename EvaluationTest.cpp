#include "EvaluationTest.h"
#include <iostream>

EvaluationTest::EvaluationTest(const Questionnaire &questionnaire)
    : Evaluation{questionnaire}
{}

void EvaluationTest::lanceEvaluation()
{
    augmenteEssai() ;
    int nbQuestions = d_questionnaire->nombreDeQuestions();
    std::string reponseDeUtilisateur ;

    for (int i = 0; i < nbQuestions; ++i)
    {
        std::cout << separateur(100,'=') ;
        std::cout <<"Entrez * pour quitter l'evaluation test\n" ;
        std::cout<<d_questionnaire->intituleQuestionNumero(i) ; ;
        std::cout<<d_questionnaire->instructionsQuestionNumero(i) ;
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
            augmenteScore() ;
        }
        std::cout<<separateur(100,'=') ;
        std::cout<<"\n\n" ;
    }
    std::cout<<resultatEvaluation();
}
