#include "Evaluation.h"

Evaluation::Evaluation(const Questionnaire &questionnaire) : d_questionnaire(&questionnaire),
                        d_nbEssai{0}, d_score{0}, d_tabIndiceErreur{}
{
}

void Evaluation::separateur(int largeur, char symbole)
{
    std::cout << std::string(largeur, symbole) << std::endl;
}

std::string Evaluation::reponseUtilisateurQuestion() const {
    std::string reponse ;
    std::cout<<'>' ;
    std::cin>>reponse;
    return reponse;
}

std::string Evaluation::lireReponseValide(int indiceQuestion) const
{
    std::string reponse ;
    reponse = reponseUtilisateurQuestion();
    while (!d_questionnaire->validiteEntreeUtilisateur(indiceQuestion, reponse)) {
        reponse = reponseUtilisateurQuestion();
    }
    return reponse;
}


void Evaluation::revueErreursCommises() const {

}

void Evaluation::resultatEvaluation() const {
    std::cout << "Vous avez une score de "+ std::to_string(d_score)
                    +" sur "+std::to_string(d_questionnaire->nombreDeQuestions()) ;
}

