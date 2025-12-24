#include "Menu.h"
#include "Questionnaire.h"
#include "Evaluation.h"
#include <iostream>

using std::cout;
using std::cin;
using std::string;
using std::endl ;

Menu::Menu() : d_gestionnaireQuestionnaires{}, d_gestionnaireEvaluation{},d_gestionnaireApprentissage{}
{
}


void Menu::execute()
{
    menuChoixQuestionnaire(d_gestionnaireQuestionnaires.nomsDesDifferentsQuestionnaires()) ;
}


void Menu::menuChoixQuestionnaire(const std::vector<string> &questionnaires)
{



    if (questionnaires.empty())
    {
        cout << "Aucun questionnaire disponible.\n";
        return;
    }

    cout << "Liste des questionnaires disponibles :\n";
    for (size_t i = 0; i < questionnaires.size(); ++i)
    {
        cout << i + 1 << ". " << questionnaires[i] << '\n';
    }

    int choix = -1;
    do
    {
        cout << "Votre choix : ";
        cin >> choix;
    }
    while (choix < 1 || choix > questionnaires.size());

    const std::string &nomChoisi = questionnaires[choix - 1];
    d_gestionnaireQuestionnaires.selectionneQuestionnaire(nomChoisi);

    Questionnaire questionnaire = d_gestionnaireQuestionnaires.questionnaireCourant();

    cout << "\nQuestionnaire sélectionné : "
         << questionnaire.nomQuestionnaire() << '\n';
    cout << "Nombre de questions : "
         << questionnaire.nombreDeQuestions() << '\n';

}


 void Menu::menuQuestionnaire(const Questionnaire& questionnaire)
 {

    // (ibra) On informe les gestionnaires du questionnaire courant  car les gestionnaires
    //ne savent pas automatiquement quel questionnaire l’utilisateur a choisi.
    d_gestionnaireEvaluation.changeQuestionnaire(questionnaire);
    d_gestionnaireApprentissage.selectionneQuestionnaire(questionnaire);

    int choix = -1;

    do {
        cout << "\n====================================\n";
        cout << "Questionnaire : " << questionnaire.nomQuestionnaire() << '\n';
        cout << "Nombre de questions : " << questionnaire.nombreDeQuestions() << '\n';
        cout << "====================================\n";

        cout << "(1) Apprentissage simple\n";
        cout << "(2) Apprentissage par type\n";
        cout << "(3) Evaluation test\n";
        cout << "(4) Evaluation seconde chance\n";
        cout << "(5) Evaluation adaptative\n";
        cout << "(6) Certificat texte\n";
        cout << "(7) Certificat HTML\n";
        cout << "(8) Changer de questionnaire\n";
        cout << "(0) Quitter\n";
        cout << "Votre choix : ";
        cin >> choix;

        while (choix < 0 || choix > 8) {
            cout << "Choix invalide, recommencez : ";
            cin >> choix;
        }

        switch (choix) {

            case 1:
                d_gestionnaireApprentissage.commenceApprentissage(APPRENTISSAGE_SIMPLE);
                break;

            case 2:
                d_gestionnaireApprentissage.commenceApprentissage(APPRENTISSAGE_TYPE);
                break;

            case 3:
                d_gestionnaireEvaluation.commenceEvaluation(EVALUATION_TEST);
                d_gestionnaireEvaluation.genereCertificat(0, EVALUATION_TEST);
                break;

            case 4:
                d_gestionnaireEvaluation.commenceEvaluation(EVALUATION_SECONDE_CHANCE);
                d_gestionnaireEvaluation.genereCertificat(0, EVALUATION_SECONDE_CHANCE);
                break;

            case 5:
                d_gestionnaireEvaluation.commenceEvaluation(EVALUATION_ADAPTATIVE);
                d_gestionnaireEvaluation.genereCertificat(0, EVALUATION_ADAPTATIVE);
                break;

            case 6:
                d_gestionnaireEvaluation.genereCertificat(0, EVALUATION_TEST);
                break;

            case 7:
                d_gestionnaireEvaluation.genereCertificat(1, EVALUATION_TEST);
                break;

            case 8:
                cout << "Retour au menu principal...\n";
                return;

            case 0:
                cout << "Fin du programme.\n";
                 break;
        }

    } while (choix != 8);
}

