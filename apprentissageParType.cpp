#include "apprentissageParType.h"
#include <string>
#include <iostream>
#include <algorithm>/// pour la méthode find
#include <vector>
#include <set>///Pour stocker les types de questions uniques
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::set;
using std::string;

apprentissageParType::apprentissageParType(Questionnaire& questionnaire):apprentissage{questionnaire}
{

}
void apprentissageParType::executer()
{
    cout<<"---DEBUT DU MODE ENPRRENTISSAGE PAR TYPE DU QUESTIONNAIRE("<<d_questionnaire.nomQuestionnaire()<<")---"<<endl;
    cout<<"Questionnaire portant sur: "<<d_questionnaire.nomQuestionnaire()<<endl;
    int nbQuestions=d_questionnaire.nombreDeQuestions();
    if(nbQuestions==0)
    {
        cout<<"Le questionnaire est vide, fin de l'apprentissage!!!"<<endl;
        return;
    }
    else
    {
        set<string>types_uniques;
        for(int i=0;i<nbQuestions;++i)
        {
            types_uniques.insert(d_questionnaire.typeQuestion(i));
        }
        int numeroType=0;
        for(const string& type_courant:types_uniques)
        {
            ++numeroType;
            //cout<<string(100,"=")<<endl;
            cout<<"--- TYPE D'APPRENTISSAGE "<<numeroType<<": "<<type_courant<<"---"<<endl;
           // cout<<string(100,"=")<<endl;
            int numQuestion=0;
            for(int i=0;i<nbQuestions;++i)
            {
                if(d_questionnaire.typeQuestion(i)==type_courant)
                {
                    ++numQuestion;
                    cout<<"Question "<<numQuestion<<" (Type: "<<type_courant<<")]"<<endl;
                     d_questionnaire.afficherQuestionNumero(i);
                     cout<<endl;
                     d_questionnaire.afficherReponseNumero(i);
                     cout<<endl;
                     cout<<"Appuyer sur ENTRER pour passer à la question suivante..."<<endl;
                      cin.get();
                }
            }
        }
        cout<<"---FIN DU MODE APPRENTISSAGE PAR TYPE---"<<endl;
    }
}
