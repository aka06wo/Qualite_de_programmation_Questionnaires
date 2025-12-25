#include "EvaluationAdaptative.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "styleAffichage.h"

EvaluationAdaptative::EvaluationAdaptative(const Questionnaire &questionnaire)
    : Evaluation{questionnaire}, d_indicesErreursPremierPassage{}
{

}


bool EvaluationAdaptative::traiterReponse(int indice, const std::string& reponse)
{
    std::string reponsePropre = lireReponseValide(indice, reponse);

    if (reponseJuste(indice, reponsePropre))
    {
        styleAffichage::ecritEnVert("[v] Bonne reponse !\n") ;
        augmenteScore();
        return true ;
    }
    else
    {
        styleAffichage::ecritEnRouge("[x] Mauvaise reponse...\n") ;
        return false;
    }
}

void EvaluationAdaptative::PremierPassage(std::vector<int>& tableau, bool &aQuitter)
{
    int taille = tableau.size();
    d_indicesErreursPremierPassage.clear();
    std::srand(std::time(nullptr));

    int i = -1 ;

    while (!tableau.empty())
    {
        int indiceAlea = std::rand() % tableau.size();
        int indQuestion = tableau[indiceAlea];

        styleAffichage::affichageEnteteQuestion("EVALUATION ADAPTATIVE", ++i, taille);
        styleAffichage::ecritEnBleu("  (Tapez '*' pour quitter l'Evaluation Adaptativr)") ;
        affichageQuestionNumero(indQuestion, taille) ;

        std::string saisie;
        std::getline(std::cin, saisie);

        if (saisie == "*")
        {
            std::cout << "Vous avez quittez l'evaluation Seconde Chance\n" ;
            for (int j = indQuestion; j < d_indicesErreursPremierPassage.size(); j++)
            {
                enregistreErreurs(j) ;
            }
            aQuitter = true;
            return;
        }

        if (!traiterReponse(indQuestion, saisie))
        {
            d_indicesErreursPremierPassage.push_back(indQuestion);
        }
        tableau.erase(tableau.begin() + indiceAlea);

        styleAffichage::affichagePiedDePageQuestion() ;
    }
}

void EvaluationAdaptative::SecondPassage()
{
    if (d_indicesErreursPremierPassage.empty()) return;
    int taille = d_indicesErreursPremierPassage.size() ;

    styleAffichage::ecritEnGras("\n--- PHASE DE RATTRAPAGE ---\n") ;

    int i = -1 ;

    for (int indQuestion : d_indicesErreursPremierPassage)
    {
        styleAffichage::affichageEnteteQuestion("EVALUATION ADAPTATIVE", ++i, taille);
        styleAffichage::ecritEnBleu("  (Tapez '*' pour quitter l'Evaluation Adaptative)") ;
        affichageQuestionNumero(indQuestion, taille) ;

        std::string saisie;
        std::getline(std::cin, saisie);

        if (saisie == "*")
        {
            std::cout << "Vous avez quittez l'evaluation Seconde Chance\n" ;
            for (int j = indQuestion; j < taille; j++)
            {
                enregistreErreurs(j) ;
            }
            return;
        }

        if (!traiterReponse(indQuestion, saisie))
        {
            enregistreErreurs(indQuestion);
        }

        styleAffichage::affichagePiedDePageQuestion() ;
    }
}

void EvaluationAdaptative::lanceEvaluation()
{
    std::cin.ignore() ;

    styleAffichage::affichageEnteteActivites("EVALUATION ADAPTATIVE") ;

    augmenteEssai();
    bool aQuitter = false ;

    std::vector<int> questionsDisponibles;
    questionsDisponibles.reserve(nombreDeQuestions()) ;
    for (int i = 0; i < nombreDeQuestions(); ++i)
    {
        questionsDisponibles.push_back(i);
    }

    PremierPassage(questionsDisponibles,aQuitter);

    if (!d_indicesErreursPremierPassage.empty() && !aQuitter)
    {
        SecondPassage();
    }

    styleAffichage::affichageEnteteActivites("EVALUATION ADAPTATIVE") ;

    std::cout << "\n" << resultatEvaluation() << '\n';
}
