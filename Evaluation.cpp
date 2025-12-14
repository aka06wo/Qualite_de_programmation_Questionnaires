#include "Evaluation.h"
#include <iostream>

Evaluation::Evaluation(const Questionnaire &questionnaire) :
        d_questionnaire{&questionnaire},d_nbEssai{0}, d_score{0}, d_tabIndiceErreur{}
{
}

std::string Evaluation::messageSelonScore(double pourcentage)
{
    std::string message {"Score obtenu : " + std::to_string(pourcentage) + '\n'} ;
    if (pourcentage >= 90)
    {
        message += "Félicitations ! Tu es un génie, presque invincible !\n";
    }
    else if (pourcentage >= 75)
    {
        message += "Bravo ! Très bon travail \n";
    }
    else if (pourcentage >= 50)
    {
        message += "Pas mal ! Mais tu peux faire encore mieux, on croit en toi !\n";
    }
    else if (pourcentage >= 25)
    {
        message += "Hum... ça commence à se compliquer. Allez, courage !\n";
    }
    else
    {
        message += "Oups... peut-être que tu devrais revoir tes notes\n";
    }

    return message;
}


std::string Evaluation::lireReponseValide(int indiceQuestion, const std::string &reponse) const
{
    std::string reponseValide = reponse;
    while (!d_questionnaire->validiteEntreeUtilisateur(indiceQuestion, reponseValide))
    {
        std::cout<<"> " ;
        getline(std::cin,reponseValide);
    }
    return reponseValide;
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
    std::cout << "Voici vos erreurs commises sur le Questionnaire \n["
              << d_questionnaire->nomQuestionnaire() << "]\n" ;
    for (int i=0;i<d_tabIndiceErreur.size();i++)
    {
        std::cout << std::string(100,'-') << std::endl ;
        std::cout << "Erreur N°"+ std::to_string(i+1) +":\n" ;
        std::cout<<d_questionnaire->intituleQuestionNumero(i) ;
        std::cout << "Reponse correcte : " +
                     d_questionnaire->reponseQuestionNumero(i) ;
        std::cout << std::string(100,'-') << std::endl ;
    }
}

void Evaluation::changerQuestionnaire(const Questionnaire &nouveauQuestionnaire)
{
    d_questionnaire = &nouveauQuestionnaire;
    d_nbEssai=0 ;
    d_score = 0 ;
    d_tabIndiceErreur.clear();
}

int Evaluation::score() const {
    return d_score;
}

double Evaluation::pourcentageReussite() const {
    return (1.0*score()/d_questionnaire->nombreDeQuestions())*100 ;
}

void Evaluation::resultatEvaluation() const
{
    std::cout << "Vous avez une score de "+ std::to_string(score())
              +" sur "+std::to_string(d_questionnaire->nombreDeQuestions()) + '\n' ;
    messageSelonScore(1.0*score()/d_questionnaire->nombreDeQuestions()) ;

    // Certificat console ?
}

