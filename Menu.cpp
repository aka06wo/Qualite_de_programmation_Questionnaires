#include "Menu.h"
#include "Question.h"
#include "Questionnaire.h"
#include "apprentissage.h"
#include "Evaluation.h"
#include "EvaluationTest.h"
#include "EvaluationAdaptative.h"
#include "EvaluationSecondeChance.h"
#include "gestionnaireEvaluations.h"
#include "gestionnaireQuestionnaires.h"
#include <vector>
#include <iostream>
#include <memory>
#include "QuestionnaireJSON.h"
using std::cout;
using std::cin;
using std::string;
using std::endl ;
// finalement pas besoin de creer des questions(ils sont deja stock"=é dans json) donc s'occuper uniquement de la parti questionnaire , evaluation et apprentissage
void Menu::execute()
{
}

int Menu::MenuPrincipale()
{
    int choix {-1};
    do
    {
        cout<<"Veuillez choisir un type de question :\n";
        cout<<"(1) Questionnaire texte\n";
        cout<<"(2) Questionnaire numerique\n";
        cout<<"(3) Questionnaire à choix multiple\n";
        cout<<"(0) Quitter le programme\n";
        cout<<"Votre choix  est : ";
        cin>>choix;
    }
    while (choix<0 || choix > 3);
    return choix;
}
int Menu::menuChoixQuestionnaire(const std::vector<Questionnaire>& questionnaires)
{
    if (questionnaires.empty())
    {
        cout << "Aucun questionnaire disponible.\n";
        return -1  ;
    }
        cout << " Liste des questionnaires .\n";
        for (int i = 0; i < questionnaires.size(); ++i)
        {
            cout << i + 1 << ". " << questionnaires[i].nomQuestionnaire() << '\n';
        }
        cout << endl ;
    int choix;
    cin >> choix;

    if (choix < 1 || choix > questionnaires.size())
        return -1;

    return choix - 1; // pour gerer les indices ;
}
 int Menu::menuQuestionnaire()
 {
    int choix;
    do {
        cout << " Menu Questionnaire =\n";
        cout << "(1) Apprentissage\n";
        cout << "(2) Évaluation\n";
        cout << "(3) Statistiques\n";
        cout << "(4) Certificat\n";
        cout << "(5) Changer de questionnaire\n";
        cout << "(0) Quitter\n";
        cout << "Votre choix : ";
        cin >> choix;
    } while (choix < 0 || choix > 5);
    return choix;
}
int Menu::menuApprentissage()
{
    int choix;
    do {
        cout << "Apprentissage \n";
        cout << "(1) Apprentissage simple\n";
        cout << "(2) Apprentissage par type\n";
        cout << "(0) Retour\n";
        cout << "Votre choix : ";
        cin >> choix;
    } while (choix < 0 || choix > 2);
    return choix;
}
int Menu::menuEvaluation() {
    int choix;
    do {
        cout << " Évaluation \n";
        cout << "(1) Évaluation test\n";
        cout << "(2) Évaluation seconde chance\n";
        cout << "(3) Évaluation adaptative\n";
        cout << "(0) Retour\n";
        cout << "Votre choix : ";
        cin >> choix;
    } while (choix < 0 || choix > 3);
    return choix;
}




