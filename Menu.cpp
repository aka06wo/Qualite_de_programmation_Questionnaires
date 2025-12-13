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
#include <limits>
using std::cout;
using std::cin;
using std::string;
void Menu::execute()
{
    auto choix = MenuPrincipale();
    while (choix != 0)
    {
        std::unique_ptr<Question> question = nullptr;

        switch (choix)
        {
        case 1 :
            cout << "-> Lancement de la creation d'une question Texte...\n";
            string intitule, reponse;
            cout << "Intitulé : ";
            std::getline(cin >> std::ws, intitule); // ws ignore tous les espaces, tabulations et retours à la ligne en attente

            cout << "Réponse : ";
            std::getline(cin, reponse);

            question = std::make_unique<QuestionTexte>(intitule, reponse);
            break;
        case 2 :
            cout << "-> Lancement de la creation d'une question Numerique...\n";
            string intitule;
            int reponse, mini, maxi;

            cout << "Intitulé : ";
            std::getline(cin >> std::ws, intitule);

            cout << "Réponse correcte : ";
            cin >> reponse;

            cout << "Valeur min : ";
            cin >> mini;

            cout << "Valeur max : ";
            cin >> maxi;

            question = std::make_unique<QuestionNumerique>(intitule, reponse, maxi, mini);
        break;
    case 3 :
        cout << "-> Lancement de la creation d'une question a Choix Multiple.\n";

        string intitule;
        int bonneReponse;

        cout << "Intitulé : ";
        std::getline(cin >> std::ws, intitule);

        std::vector<string> choixPossibles;
        for (int i = 0; i < 3; ++i)
        {
            string choix;
            cout << "Choix " << i + 1 << " : ";
            std::getline(cin, choix);
            choixPossibles.push_back(choix);
        }

        cout << "Numéro de la bonne réponse (1-3) : ";
        cin >> bonneReponse;

        question = std::make_unique<QuestionChoixMultiple>(
                       intitule, choixPossibles, bonneReponse - 1);
        break;
    default:
        cout << "Erreur : Choix non reconnu.\n";
        break;
    }
    choix =MenuPrincipale();
 }
}

int Menu::MenuPrincipale()
{
    int choix {-1};
    do
    {
        cout<<"Veuillez choisir un type de question :\n";
        cout<<"(1) Question texte\n";
        cout<<"(2) Question numerique\n";
        cout<<"(3) Question à choix multiple\n";
        cout<<"(0) Quitter le programme\n";
        cout<<"Votre choix  est : ";
        cin>>choix;
    }
    while (choix<0 || choix > 3);
    return choix;
}


