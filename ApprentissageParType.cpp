#include "ApprentissageParType.h"
#include "styleAffichage.h"

#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

ApprentissageParType::ApprentissageParType(const Questionnaire& questionnaire):Apprentissage{questionnaire}
{

}

void ApprentissageParType::lanceApprentissage()
{
    cin.ignore();

    styleAffichage::affichageEnteteActivites("APPRENTISSAGE PAR TYPE");

    cout << "  Questionnaire : " << d_questionnaire->nomQuestionnaire() << endl;

    int nbQuestions = d_questionnaire->nombreDeQuestions();

    if(nbQuestions == 0)
    {
        styleAffichage::ecritEnRouge("\n  [!] Le questionnaire est vide. Fin de l'apprentissage.") ;
        std::cout << std::string(70,'=') << std::endl;
        return;
    }

    std::set<string> types_uniques {d_questionnaire->nomsDifferentsTypesQuestions()};

    for(const string& type_courant : types_uniques)
    {
        styleAffichage::ecritEnVert("\n  >>> CATEGORIE : " + type_courant + '\n') ;

        for(int i = 0; i < nbQuestions; ++i)
        {
            if(d_questionnaire->typeQuestionNumero(i) == type_courant)
            {
                styleAffichage::affichageEnteteQuestion("APPRENTISSAGE PAR TYPE",i,nbQuestions) ;

                cout << "   [QUESTION] :" << endl;
                cout << "     " << d_questionnaire->intituleQuestionNumero(i) << endl;

                styleAffichage::ecritEnBleu("\n   (Appuyez sur ENTREE pour voir la REPONSE)\n") ;
                cin.get();

                cout << "   [REPONSE] :" << endl;
                cout << "     -> " << d_questionnaire->reponseQuestionNumero(i) << endl;

                styleAffichage::affichagePiedDePageQuestion() ;

                std::cout << string(70,'.') << std::endl;
                styleAffichage::ecritEnBleu("> Appuyez sur ENTRER pour passer a la question suivante\n") ;
                std::cout << string(70,'.') << std::endl;
                cin.get();
            }
        }
    }

    styleAffichage::affichagePiedDePageActivites("APPRENTISSAGE PAR TYPE");
}