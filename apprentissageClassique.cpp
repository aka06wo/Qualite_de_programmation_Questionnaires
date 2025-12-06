#include "apprentissageClassique.h"
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
apprentissageClassique::apprentissageClassique(const Questionnaire& questionnaire):apprentissage{questionnaire}
{
}
void apprentissageClassique::executer()
{
    cout<<"---DEBUT DU MODE ENPRRENTISSAGE CLASSIQUE---"<<endl;
    cout<<"Questionnaire portant sur: "<<d_questionnaire.nomQuestionnaire()<<endl;
    int nbQuestions=d_questionnaire.nombreDeQuestions();
    if(nbQuestions==0)
    {
        cout<<"Le questionnaire est vide, fin de l'apprentissage!!!"<<endl;
        return;
    }
    else
    {
        for(int i=0;i<nbQuestions;++i)
        {
            cout<<"[Question "<<i+1<<"/"<<nbQuestions<<"]"<<endl;
            d_questionnaire.afficherQuestionNumero(i);
            cout<<endl;
            d_questionnaire.afficherReponseNumero(i);
            cout<<endl;
            if(i<nbQuestions-1)
            {
                cout<<"Appuyer sur ENTRER pour passer à la question suivante..."<<endl;
                cin.get();
            }
        }
        cout<<"---FIN DU MODE APPRENTISSAGE CLASSIQUE---"<<endl;
    }

}
