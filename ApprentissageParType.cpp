#include "ApprentissageParType.h"

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
    cout<<"---DEBUT DU MODE ENPRRENTISSAGE PAR TYPE DU QUESTIONNAIRE---("<<d_questionnaire->nomQuestionnaire()<<")---"<<endl;
    cout<<"Questionnaire portant sur: "<<d_questionnaire->nomQuestionnaire()<<endl;
    int nbQuestions=d_questionnaire->nombreDeQuestions();
    if(nbQuestions==0)
    {
        cout<<"Le questionnaire est vide, fin de l'apprentissage!!!"<<endl;
        return;
    }

    std::vector<std::string>types_uniques{"choixMultiples","numerique","texte"};
    for(const string& type_courant:types_uniques)
    {
        cout<<"Questions : "<<type_courant<<endl;
        for(int i=0;i<nbQuestions;++i)
        {
            if(d_questionnaire->typeQuestionNumero(i)==type_courant)
            {
                std::cout<<std::string(100,'-') ;
                cout<<"Question: "<<d_questionnaire->intituleQuestionNumero(i)<<endl;
                cout<<"Appuyer sur ENTREE pour voir la REPONSE"<<endl;
                cin.get();
                cout<<"Reponse: "<<d_questionnaire->reponseQuestionNumero(i)<<endl;
                cout<<endl;
                std::cout<<std::string(100,'-') ;
                cout<<"Appuyer sur ENTRER pour passer a la question suivante..."<<endl;
                cin.get();
            }
        }
    }
    cout<<"---FIN DU MODE APPRENTISSAGE PAR TYPE---"<<endl;
}
