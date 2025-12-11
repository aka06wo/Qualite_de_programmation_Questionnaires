#include "EvaluationTest.h"
#include <iostream>

//using std::cout;
//using std::cin;
//using std::string;
EvaluationTest::EvaluationTest(const Questionnaire &questionnaire)
    : Evaluation(questionnaire)
}
    void EvaluationTest::lanceEvaluation()
{

    int nbQuestions = d_questionnaire->nombreDeQuestions();
    std::string reponseDeUtilisateur ;
    Evaluation::separateur(50, '=');
    std::cout << "Début de l'Évaluation Test : " << d_questionnaire->nomQuestionnaire()
              << " (" << d_questionnaire->descriptionQuestionnaire() << ")\n";
    Evaluation::separateur(50, '=');


    for (i = 0; i < nbQuestions; ++i)
    {

        Evaluation::separateur(50, '=');
        std::cout<<d_questionnaire->intituleQuestionNumero(i) << "\n"; ;
        std::cout<<d_questionnaire->instructionsQuestionNumero(i) << "\n"; ;
        reponseDeUtilisateur  = lireReponseValide(i) ;
        d_nbEssai++ ;
        bool estJuste = d_questionnaire->verificationReponse(i, reponseDeUtilisateur) ;
        if (estJuste)
            {
                d_score++ ;
            }

        Evaluation::separateur(50, '=');
        std::cout<<"\n\n" ;

    }
        resultatEvaluation();


}


// ... (Le reste du code de EvaluationTest.cpp : evaluerQuestionCourante, afficherFeedback) ...
