#include "EvaluationAdaptative.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

EvaluationAdaptative::EvaluationAdaptative(const Questionnaire &questionnaire)
    : Evaluation{questionnaire}, d_indicesErreursPremierPassage{} {}

bool EvaluationAdaptative::traiterReponse(int indice, const std::string& reponse)
{
    std::string reponsePropre = lireReponseValide(indice, reponse);

    if (d_questionnaire->verificationReponse(indice, reponsePropre))
    {
        std::cout << "[v] Bonne reponse !" << '\n';
        augmenteScore();
        return true ;
    }
    else
    {
        std::cout << "[x] Mauvaise reponse..." << '\n';
        return false;
    }
}

void EvaluationAdaptative::PremierPassage(std::vector<int>& tableau, bool &aQuitter)
{
    int taille = tableau.size();
    d_indicesErreursPremierPassage.clear();
    std::srand(std::time(nullptr));

    while (!tableau.empty())
    {
        int indiceAlea = std::rand() % tableau.size();
        int indQuestion = tableau[indiceAlea];

        std::cout << separateur('=', 100);
        std::cout <<"Entrez * pour quitter l'evaluation seconde chance\n" ;
        std::cout << separateur('-',100) ;
        std::cout << "Question N°" + std::to_string(indQuestion+1) + " sur "
                  + std::to_string(taille) + '\n' ;
        std::cout << d_questionnaire->intituleQuestionNumero(indQuestion)<<std::endl ;
        std::cout << d_questionnaire->instructionsQuestionNumero(indQuestion)<<std::endl ;

        std::string saisie;
        std::cout<<"> " ;
        std::getline(std::cin, saisie);

        if (saisie == "*")
        {
            std::cout << "Vous avez quittez l'evaluation Seconde Chance\n" ;
            aQuitter = true;
            return;
        }

        if (!traiterReponse(indQuestion, saisie))
        {
            d_indicesErreursPremierPassage.push_back(indQuestion);
        }
        tableau.erase(tableau.begin() + indiceAlea);
    }
}

void EvaluationAdaptative::SecondPassage()
{
    if (d_indicesErreursPremierPassage.empty()) return;

    std::cout << "\n--- PHASE DE RATTRAPAGE ---\n";

    for (int indQuestion : d_indicesErreursPremierPassage)
    {
        std::cout << separateur('=', 100);
        std::cout <<"Entrez * pour quitter l'evaluation seconde chance\n" ;
        std::cout << separateur('-',100) ;
        std::cout << "Question N°" + std::to_string(indQuestion+1) + " sur "
                  + std::to_string(d_indicesErreursPremierPassage.size()) + '\n' ;
        std::cout << d_questionnaire->intituleQuestionNumero(indQuestion)<<std::endl;
        std::cout << d_questionnaire->instructionsQuestionNumero(indQuestion)<<std::endl;

        std::string saisie;
        std::cout<<"> " ;
        std::getline(std::cin, saisie);

        if (saisie == "*")
        {
            std::cout << "Vous avez quittez l'evaluation Seconde Chance\n" ;
            for (int j = indQuestion; j < d_indicesErreursPremierPassage.size(); j++)
            {
                enregistreErreurs(j) ;
            }
            return;
        }

        if (!traiterReponse(indQuestion, saisie))
        {
            enregistreErreurs(indQuestion);
        }
    }
}

void EvaluationAdaptative::lanceEvaluation()
{
    std::cout << "Lancement de l'evaluation Adaptative sur le questionnaire\n" ;
    augmenteEssai();
    bool aQuitter = false ;

    std::vector<int> questionsDisponibles;
    questionsDisponibles.reserve(d_questionnaire->nombreDeQuestions()) ;
    for (int i = 0; i < d_questionnaire->nombreDeQuestions(); ++i)
    {
        questionsDisponibles.push_back(i);
    }

    PremierPassage(questionsDisponibles,aQuitter);

    if (!d_indicesErreursPremierPassage.empty() && !aQuitter)
    {
        SecondPassage();
    }

    std::cout << "\n" << resultatEvaluation() << '\n';
}
