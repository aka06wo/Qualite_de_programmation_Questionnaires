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
        std::cout << "Entrée invalide, veuillez saisir une entrée valide.\n";
        reponse = reponseUtilisateurQuestion();
        //std::cout<<"Entrée invalide ! Veuillez saisir un nombre : " ;
        // si je veux faire cela, dire ce qu'il faut rentrer
        // il faut que les autres tests soit bien fait avec des if else
        // sur validite entreeutilisatuer
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
        // voir fonction precedente, s'assure qu'on a une bonne valeur
        reponseUtilisateur = lireReponseValide(i) ;

        if (!d_questionnaire->verificationReponse(i,reponseUtilisateur))
        {
            // ses erreurs
            d_tabIndiceErreur.push_back(i) ;

            std::cout<<"[x] Mauvaise reponse, Seconde chance : \n" ;
            reponseUtilisateur = lireReponseValide(i) ;
            if (!d_questionnaire->verificationReponse(i,reponseUtilisateur))
            {
                d_questionnaire->afficherReponseNumero(i);
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

    //resultatEvaluation() ;
    std::cout << "Vous avez une score de "+ std::to_string(d_score)
                    +" sur "+std::to_string(d_questionnaire->nombreDeQuestions()) ;
}

void EvaluationSecondeChance::resultatEvaluation() const {
    // si il a reussi le test, 70% de bonne reponses, on appelle certificatReussite
    // sinon on affiche les basiques, reponses sur nbquestions, .....


    //monCertificat.certficatHtml() ;
    //monCertificat.certficatText() ;

    // on affiche la possibili
}
