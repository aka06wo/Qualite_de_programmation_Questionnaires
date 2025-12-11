#include "Evaluation.h"

#include "Afficheur.h"

Evaluation::Evaluation(const Questionnaire &questionnaire) : d_questionnaire(&questionnaire),
                                                             d_nbEssai{0}, d_score{0}, d_tabIndiceErreur{}
{
}

std::string Evaluation::reponseUtilisateurQuestion()
{
    std::string reponse ;
    std::cout<<"> " ;
    getline(std::cin, reponse);
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

void Evaluation::augmenteEssai()
{
    d_nbEssai++ ;
}


void Evaluation::augmenteScore()
{
    d_score++ ;
}

void Evaluation::enregistreErreurs(int indiceErreur)
{
    d_tabIndiceErreur.push_back(indiceErreur) ;
}



void Evaluation::revueErreursCommises() const
{
    std::cout<<"Voici vos erreurs commises sur le Questionnaire \n["<<d_questionnaire->nomQuestionnaire()<<"]\n" ;
    for (int i=0;i<d_tabIndiceErreur.size();i++)
    {
        Afficheur::separateur(100,'-') ;
        std::cout<<"Erreur N°"+ std::to_string(i+1) +":\n";
        std::cout<<d_questionnaire->intituleQuestionNumero(i) ;
        std::cout<<"Reponse correcte : "<<d_questionnaire->reponseQuestionNumero(i) ;
        Afficheur::separateur(100,'-') ;
    }
}

void Evaluation::resultatEvaluation() const
{
    // Utiliser les certificats ici ?
    // les mettres comme classe abstraite ??


    std::cout << "Vous avez une score de "+ std::to_string(d_score)
                    +" sur "+std::to_string(d_questionnaire->nombreDeQuestions()) + '\n' ;
}

