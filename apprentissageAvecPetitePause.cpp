#include "apprentissageAvecPetitePause.h"
#include <string>
using std::cout;
using std::cin;
using std::endl;

apprentissageAvecPetitePause::apprentissageAvecPetitePause(const Questionnaire& questionnaire):apprentissage{questionnaire}
{
}
void apprentissageAvecPetitePause::executer()
{
    cout<<"---DEBUT DU MODE ENPRRENTISSAGE AVEC PAUSE AVANT DE VOIR LA REPONSE---"<<endl;
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
            cout<<"---REFLECHISSEZ,puis appuyer sur ENTRER pour voir la réponse--"<<endl;
            cin.get();
            d_questionnaire.afficherReponseNumero(i);
            cout<<endl;
            if(i<nbQuestions-1)
            {
                cout<<"Appuyer sur ENTRER pour passer à la question suivante..."<<endl;
                cin.get();
            }
        }
        cout<<"---FIN DU MODE APPRENTISSAGE AVEC TEMPS DE PAUSE---"<<endl;
    }

}


