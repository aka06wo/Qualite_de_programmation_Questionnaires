#include "ApprentissageSimple.h"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

ApprentissageSimple::ApprentissageSimple(const Questionnaire& questionnaire):
        Apprentissage{questionnaire}
{
}

void ApprentissageSimple::executer()
{
    cout<<"Apprentissage Simple"<<endl;
    cout<<"Questionnaire portant sur: "<<d_questionnaire->nomQuestionnaire()<<endl;
    int nbQuestions=d_questionnaire->nombreDeQuestions();
    if(nbQuestions==0)
    {
        cout<<"Le questionnaire est vide."<<endl;
        return;
    }
    else
    {
        for(int i=0;i<nbQuestions - 1;++i)
        {
            cout<<"[Question "<<i+1<<"/"<<nbQuestions<<"]"<<endl;
            std::cout<<d_questionnaire->intituleQuestionNumero(i) ;
            std::cout<<d_questionnaire->reponseQuestionNumero(i) ;
            cout<<"Appuyer sur ENTRER pour passer a la question suivante..."<<endl;
            cin.get();
        }
        int dernierElement = nbQuestions - 1;
        cout<<"[Question "<<dernierElement+1<<"/"<<nbQuestions<<"]"<<endl;
        std::cout<<d_questionnaire->intituleQuestionNumero(dernierElement) ;
        std::cout<<d_questionnaire->reponseQuestionNumero(dernierElement) ;

        cout<<"FIN de l'apprentissage"<<endl;
    }

}
