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
    /*

    if (questionnaires.empty())
    {
        cout << "Aucun questionnaire disponible.\n";
        return ;
    }
        cout << " Liste des questionnaires .\n";
        for (int i = 0; i < questionnaires.size(); ++i)
        {
            cout << i + 1 << ". " << questionnaires[i] << '\n';
        }
        cout << endl ;

    // cou t faire votre choix
    int choix;
    cin >> choix;

    // tant que le choix n'est pas valide, cin
    if (choix < 1 || choix > questionnaires.size())

    d_gestionnaireQuestionnaires.selectionneQuestionnaire(questionnaires[choix]) ;
    Questionnaire monq ;
    monq = d_gestionnaireQuestionnaires.questionnaireCourant() ;


    // on prend le questionnaire depuis gestionnaireQuestionnaires c'est tout
    // en ensuite on lance menuQuestionnaire
    // on ne renvoie pas le choix
    // menuQuestionnaire()
     // pour gerer les indices ;

     */
}


 void Menu::menuQuestionnaire(const Questionnaire& questionnaire)
 {
    /*
     *cout
     vous fait un affichage, vous recuperer le nom du questionnaire, et le nombre de questions


    int choix;
    do
    {
        cout << " Menu Questionnaire =\n";
        cout << "(1) Apprentissage Simple\n";
        cout << "(2) Apprentissage par type de Questions (QCM, Numerique, Texte)\n";
        cout << "(3) Évaluation Simple\n";
        cout << "(4) Evaluation Seconde chance\n";
        cout << "(5) Evaluation Adaptative\n";
        cout << "(6) Certificat Simple\n";
        cout << "(7) Certificat HTML\n";
        cout << "(8) Changer de questionnaire\n";
        cout << "(0) Quitter\n";
        cout << "Votre choix : ";
        cin >> choix;
        while (choix< 0 || choix > 8)
        {
            // affichage pour lui dire que c'est incorrect
            cin>>choix;
        }

        switch (choix)
        case 3 : d_gestionnaireEvaluation.commenceEvaluation(EVALUATION_TEST) ;
        case 5 : d_gestionnaireEvaluation.commenceEvaluation(EVALUATION_ADAPTATIVE)
        case 1 : d_gestionnaireApprentissage.commenceApprentissage(APPRENTISSAGE_SIMPLE)
        // changer questionnaire on rappelle menu choix questionnaire

        // quand on lance une evaluation on doit direct generer le certificat text

    } while (choix != QUITTER);

    // affichage pour dire qu'il a quitté le questionnaire
    */

}
