#include "Evaluation.h"
#include <iostream>

#include "styleAffichage.h"


std::string Evaluation::separateur(const char &c, int k)
{
    return std::string(k,c) + '\n';
}


Evaluation::Evaluation(const Questionnaire &questionnaire) :
        d_questionnaire{&questionnaire}, d_essais{}
{
}

int Evaluation::nombreDeQuestions() const
{
    return d_questionnaire->nombreDeQuestions() ;
}
bool Evaluation::reponseJuste (int i, const std::string &rep) const
{
    return d_questionnaire->verificationReponse(i,rep) ;
}

std::string Evaluation::reponseNumero (int i) const
{
    return d_questionnaire->reponseQuestionNumero(i) ;
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

int Evaluation::scoreDernierEssai() const
{
    return dernierEssai().score() ;
}

void Evaluation::augmenteScore()
{
    d_essais[nombreEssais()-1].augmenteScore() ;
}

void Evaluation::enregistreErreurs(int indiceErreur)
{
    d_essais[nombreEssais()-1].saisieErreurs(indiceErreur) ;
}

void Evaluation::afficherErreursEssaiNum(int numEssai) const
{
    int nbErreurs = d_essais[numEssai].nombreErreurs();
    if (nbErreurs == 0) return;

    styleAffichage::ecritEnGras("\n--- ESSAI N°" + std::to_string(numEssai + 1) + " ---\n");

    for (int i = 0; i < nbErreurs; i++)
    {
        int idx = d_essais[numEssai].erreurNumero(i);

        styleAffichage::ecritEnBleuCiel("  " + std::to_string(i + 1) + ". ");
        std::cout << d_questionnaire->intituleQuestionNumero(idx) << "\n";

        styleAffichage::ecritEnVert("     -> Correction : ");
        std::cout << "         "<<d_questionnaire->reponseQuestionNumero(idx) << "\n\n";
    }
}

void Evaluation::erreursCommisesEssais() const
{
    std::cout<<"\n============================================================\n";
    styleAffichage::ecritEnBleuCielGras("              RECAPITULATIF GLOBAL DES ERREURS             \n");
    std::cout<<"============================================================\n";

    if (d_essais.empty())
    {
        styleAffichage::ecritEnRouge("  [!] Aucun essai n'a ete enregistre pour le moment.\n");
    }
    else
    {
        for (int i = 0; i < (int)d_essais.size(); ++i)
        {
            afficherErreursEssaiNum(i);
        }
    }

    std::cout<<"\n____________________________________________________________\n\n";
}

void Evaluation::changerQuestionnaire(const Questionnaire &nouveauQuestionnaire)
{
    d_questionnaire = &nouveauQuestionnaire;
    d_essais.clear();
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
        std::cout<<"  > " ;
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


void Evaluation::affichageQuestionNumero(int i, int nbQuestions) const
{
    std::cout << "\n [QUESTION] :" << std::endl;
    std::cout << "   " << d_questionnaire->intituleQuestionNumero(i) << std::endl;
    styleAffichage::ecritEnBleu("   " + d_questionnaire->instructionsQuestionNumero(i) + '\n') ;

    std::cout << "\n [VOTRE RÉPONSE] :\n" ;
    std::cout << "   > ";
}

