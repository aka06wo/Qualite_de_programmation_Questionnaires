#include "EvaluationSecondeChance.h"
#include "Question.h"
#include "certificat.h"

EvaluationSecondeChance::EvaluationSecondeChance(const Questionnaire &questionnaire) : Evaluation{questionnaire}
{
}

std::string EvaluationSecondeChance::lireReponseValide(int indiceQuestion) const {
    std::string reponse;
    reponse = reponseUtilisateurQuestion();
    while (!d_questionnaire->validiteEntreeUtilisateur(indiceQuestion, reponse)) {
        reponse = reponseUtilisateurQuestion();
    }

    return reponse;
}

void EvaluationSecondeChance::lanceEvaluation()
{
    d_nbEssai++ ;
    std::string reponseUtilisateur ;

    // faire une boucle while pour arreter le questionnaire si l'utilisateur le souhaite
    for (int i=0 ; i<d_questionnaire->nombreDeQuestions();i++)
    {
        std::cout << std::string(100, '=') << "\n";

        d_questionnaire->afficherQuestionNumero(i) ;
        reponseUtilisateur = lireReponseValide(i) ;
        if (!d_questionnaire->verificationReponse(i,reponseUtilisateur))
        {
            // possibilité de le faire dans la classe de base, pour que toutes les evas l'utilise
            // mais pas de la meme maniere, obligatoire pour adaptative
            // mais ici pour qu'il ait la possibilité de voir ses erreurs
            d_tabIndiceErreur.push_back(i) ;

            std::cout<<"[x] Mauvaise reponse, Seconde chance : \n" ;
            reponseUtilisateur = lireReponseValide(i) ;
            if (!d_questionnaire->verificationReponse(i,reponseUtilisateur))
            {
                std::cout << std::string(100, '-') << "\n";
                d_questionnaire->afficherReponseNumero(i);
                std::cout << std::string(100, '-') << "\n";
            }
            else {
                std::cout<<"[v] Bonne reponse !\n" ;
                d_score++ ;
            }
        }
        else
        {
            std::cout<<"[v] Bonne reponse !\n" ;
            d_score++ ;
        }
        std::cout << std::string(100, '=') << "\n\n";
    }

    resultatEvaluation() ;
}

void EvaluationSecondeChance::resultatEvaluation() const {
    std::cout << "Vous avez une score de "+ std::to_string(d_score)
                    +" sur "+std::to_string(d_questionnaire->nombreDeQuestions()) ;
}
