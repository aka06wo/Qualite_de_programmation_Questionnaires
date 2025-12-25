#include "ApprentissageSimple.h"
#include "styleAffichage.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

ApprentissageSimple::ApprentissageSimple(const Questionnaire& questionnaire):
        Apprentissage{questionnaire}
{
}

void ApprentissageSimple::lanceApprentissage()
{
    styleAffichage::affichageEnteteActivites("APPRENTISSAGE SIMPLE") ;

    std::cout << "\n  Questionnaire : " << d_questionnaire->nomQuestionnaire() << std::endl;

    int nbQuestions = d_questionnaire->nombreDeQuestions();

    cin.ignore();

    if(nbQuestions == 0)
    {
        styleAffichage::ecritEnRouge("\n  [!] Le questionnaire est vide. Fin de l'apprentissage.") ;
        std::cout << std::string(70,'=') << std::endl;
    }
    else
    {
        for(int i = 0; i < nbQuestions - 1; ++i)
        {
            styleAffichage::affichageEnteteQuestion("APPRENTISSAGE SIMPLE",i,nbQuestions) ;

            std::cout << "\n [QUESTION] :" << std::endl;
            std::cout << "   " << d_questionnaire->intituleQuestionNumero(i) << std::endl;

            std::cout << "\n [REPONSE] :" << std::endl;
            std::cout << "   -> " << d_questionnaire->reponseQuestionNumero(i) << std::endl;

            styleAffichage::affichagePiedDePageQuestion() ;

            std::cout << std::string(70,'.') << std::endl;
            styleAffichage::ecritEnBleu("> Appuyez sur ENTRER pour passer a la question suivante\n") ;
            std::cout << std::string(70,'.') << std::endl;

            cin.get();
        }


        int dernierElement = nbQuestions - 1;

        styleAffichage::affichageEnteteQuestion("APPRENTISSAGE SIMPLE",dernierElement,nbQuestions) ;

        std::cout << "\n [QUESTION] :" << std::endl;
        std::cout << "   " << d_questionnaire->intituleQuestionNumero(dernierElement) << std::endl;

        std::cout << "\n [RÉPONSE] :" << std::endl;
        std::cout << "   -> " << d_questionnaire->reponseQuestionNumero(dernierElement) << std::endl;

        styleAffichage::affichagePiedDePageQuestion() ;


        styleAffichage::affichagePiedDePageActivites("APPRENTISSAGE SIMPLE") ;
    }
}