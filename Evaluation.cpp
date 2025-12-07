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
    // Utiliser getline pour recuperer la reponse ou pas ?
    // sinon si je tape LOUIS IX (avec un espace, il n'y a que louis qui sera dans reponse
    std::cin>>reponse;
    return reponse;
}

std::string Evaluation::lireReponseValide(int indiceQuestion) const
{
    std::string reponse {reponseUtilisateurQuestion()} ;
    while (!d_questionnaire->validiteEntreeUtilisateur(indiceQuestion, reponse))
    {
        reponse = reponseUtilisateurQuestion();
    }
    return reponse;
}


void Evaluation::revueErreursCommises() const
{
    std::cout<<"Voici vos erreurs commises sur le Questionnaire ["<<d_questionnaire->nomQuestionnaire()<<"]\n" ;
    /*
     Une boucle for qui recupere les questions et reponses, (changer la structure de questionnaire.h pourqu'elle
     renvoie les questions au lieu de les afficher
     */
}

void Evaluation::resultatEvaluation() const
{
    // Utiliser les certificats ici ?


    std::cout << "Vous avez une score de "+ std::to_string(d_score)
                    +" sur "+std::to_string(d_questionnaire->nombreDeQuestions()) ;
}

