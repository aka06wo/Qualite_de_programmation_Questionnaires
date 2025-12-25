#include "Menu.h"
#include <iostream>

#include "styleAffichage.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

Menu::Menu() : d_gestionnaireQuestionnaires{}, d_gestionnaireActivite{}
{}

void Menu::execute()
{
    menuChoixQuestionnaire(d_gestionnaireQuestionnaires.nomsDesDifferentsQuestionnaires());
}

void Menu::menuChoixQuestionnaire(const std::vector<string> &questionnaires)
{
    if (questionnaires.empty())
    {
        cout << "\n[!] Aucun questionnaire disponible dans la base de donnees.\n";
        return;
    }

    int choix = -1;
    do {
        cout <<'\n' ;
        cout << string(100,'=') << "\n";
        styleAffichage::ecritEnBleuCielGras("                           PLATEFORME DE QUESTIONNAIRES\n") ;
        cout << string(100,'=') << "\n";

        cout << "\n  LISTE DES QUESTIONNAIRES DISPONIBLES :\n\n" ;

        for (int i = 0; i < (int)questionnaires.size(); ++i)
        {
            cout << "    [" << i + 1 << "] " << questionnaires[i] << "\n";
        }

        cout << "\n    [0] Quitter le programme \n\n" ;

        styleAffichage::ecritEnBleu(" > Votre choix : ") ;

        cin >> choix;

    } while (choix < 0 || choix > questionnaires.size());

    if (choix == 0) return;

    const std::string &nomQuestionnaire = questionnaires[choix - 1];
    d_gestionnaireQuestionnaires.selectionneQuestionnaire(nomQuestionnaire);

    Questionnaire questionnaire = d_gestionnaireQuestionnaires.questionnaireCourant();
    d_gestionnaireActivite.selectionneQuestionnaire(questionnaire);

    cout << "\n[OK] Chargement de : " << questionnaire.nomQuestionnaire() << "...\n" ;

    menuQuestionnaire(questionnaire);
}

void Menu::menuQuestionnaire(const Questionnaire& questionnaire)
{
    int choix = -1;

    do {
        cout << "\n\n" ;
        cout << "══════════════════════════════════════════════════════════════════════════\n" ;
        cout << "     ACTIF : " ;
        styleAffichage::ecritEnBleuCiel(questionnaire.nomQuestionnaire());
        cout << '\n';

        cout << "     CONTENANT : " << questionnaire.nombreDeQuestions() << " questions \n" ;
        cout << "══════════════════════════════════════════════════════════════════════════\n" ;

        styleAffichage::ecritEnGras("  --- MODES APPRENTISSAGE ---\n") ;
        cout << "  (1) Apprentissage Simple \n" ;
        cout << "  (2) Apprentissage Par type (QCM, Numerique, Texte) \n";

        styleAffichage::ecritEnGras("\n  --- MODES ÉVALUATION ---\n") ;
        cout << "  (3) Evaluation Simple \n" ;
        cout << "  (4) Evaluation Seconde Chance \n" ;
        cout << "  (5) Evaluation Adaptative \n" ;

        styleAffichage::ecritEnGras("\n  --- OPTIONS --- \n") ;
        cout << "  (6) Changer de questionnaire \n" ;
        cout << "  (0) Quitter \n\n";

        styleAffichage::ecritEnBleu(" > Votre choix : ") ;
        cin >> choix;

        switch (choix)
        {
            case 1: d_gestionnaireActivite.lanceApprentissage(Apprentissage_TYPE::APPRENTISSAGE_SIMPLE); break;
            case 2: d_gestionnaireActivite.lanceApprentissage(Apprentissage_TYPE::APPRENTISSAGE_TYPE); break;
            case 3: d_gestionnaireActivite.lanceEvaluation(Evaluation_TYPE::EVALUATION_TEST); break;
            case 4: d_gestionnaireActivite.lanceEvaluation(Evaluation_TYPE::EVALUATION_SECONDE_CHANCE); break;
            case 5: d_gestionnaireActivite.lanceEvaluation(Evaluation_TYPE::EVALUATION_ADAPTATIVE); break;
            case 6: menuChoixQuestionnaire(d_gestionnaireQuestionnaires.nomsDesDifferentsQuestionnaires()) ; break ;
            case 0: return ;
        }

    } while (choix != 0);
}