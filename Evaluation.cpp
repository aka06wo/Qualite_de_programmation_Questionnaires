#include "Evaluation.h"
#include <iostream>


std::string Evaluation::separateur(const char &c, int k)
{
    return std::string(k,c) + '\n';
}


Evaluation::Evaluation(const Questionnaire &questionnaire) :
        d_questionnaire{&questionnaire}, d_essais{}
{
}

void Evaluation::augmenteEssai()
{
    essai nouveauEssai{} ;
    d_essais.push_back(nouveauEssai);
}

int Evaluation::nombreEssais() const {
    return d_essais.size();
}


essai Evaluation::dernierEssai() const
{
    if (nombreEssais()>0)
    {
        return d_essais[nombreEssais()-1] ;
    }
    else
    {
        return essai{} ;
    }
}

void Evaluation::augmenteScore()
{
    d_essais[nombreEssais()-1].augmenteScore() ;
}

void Evaluation::enregistreErreurs(int indiceErreur)
{
    d_essais[nombreEssais()-1].saisieErreurs(indiceErreur) ;
}

std::string Evaluation::erreursEssaiNumero (int numEssai) const
{
    std::string essai {} ;
    essai += "ESSAI NUMERO : " + std::to_string(numEssai) + '\n';
    for (int i=0; i < d_essais[numEssai].nombreErreurs(); i++)
    {
        essai += separateur(100,'-') ;
        essai += "Erreur N°"+ std::to_string(i+1) +":\n" ;
        essai += d_questionnaire->intituleQuestionNumero(i) + '\n' ;
        essai += "Reponse correcte : " +
                     d_questionnaire->reponseQuestionNumero(i) + '\n';
        essai += separateur(100,'-') ;
    }
    return essai ;
}

std::string Evaluation::erreursCommisesEssais() const
{
    std::string erreursEssais {} ;
    erreursEssais += "Voici vos erreurs commises sur le Questionnaire \n["
              + d_questionnaire->nomQuestionnaire() + "]\n" ;
    for (int i=0;i<d_essais.size();i++)
    {
        erreursEssais += erreursEssaiNumero(i) ;
    }
    return erreursEssais ;
}

void Evaluation::changerQuestionnaire(const Questionnaire &nouveauQuestionnaire)
{
    d_questionnaire = &nouveauQuestionnaire;
    d_essais.clear();
}

int Evaluation::scoreDernierEssai() const
{
    return dernierEssai().score() ;
}

double Evaluation::pourcentageReussite() const
{
    return (1.0*scoreDernierEssai()/d_questionnaire->nombreDeQuestions())*100 ;
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


std::string Evaluation::resultatEvaluation() const
{
    return std::string{messageSelonScore(pourcentageReussite())} ;
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


void Evaluation::affichageQuestionNumero (int i, int nbQuestions) const
{
    std::cout << separateur('=',100) ;
    std::cout <<"Entrez * pour quitter l'evaluation seconde chance\n" ;
    std::cout << separateur('-',100) ;
    std::cout << "Question N°" + std::to_string(i+1) + " sur "
              + std::to_string(nbQuestions) + '\n' ;
    std::cout << d_questionnaire->intituleQuestionNumero(i) << '\n';
    std::cout << d_questionnaire->instructionsQuestionNumero(i) << '\n' ;
    std::cout << "> " ;
}

