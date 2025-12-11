#include "Evaluation.h"
#include "Afficheur.h"
#include "AfficheurConcole.h"

Evaluation::Evaluation(const Questionnaire &questionnaire,std::unique_ptr<Afficheur> afficheur) :
        d_questionnaire(&questionnaire),d_afficheur{std::move(afficheur)},
        d_nbEssai{0}, d_score{0}, d_tabIndiceErreur{}, d_certificatText{}
{

}


std::string Evaluation::lireReponseValide(int indiceQuestion, const std::string &reponse) const
{
    std::string rep {reponse} ;
    while (!d_questionnaire->validiteEntreeUtilisateur(indiceQuestion, rep))
    {
        d_afficheur->affiche("> ") ;
        getline(std::cin, rep);
    }
    return reponse;
}

int Evaluation::score() const {
    return d_score;
}

int Evaluation::nombreEssais() const {
    return d_nbEssai;
}

int Evaluation::nombreErreurs() const {
    return d_tabIndiceErreur.size();
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
    d_afficheur->affiche("Voici vos erreurs commises sur le Questionnaire \n["
                                    + d_questionnaire->nomQuestionnaire() + "]\n") ;
    for (int i=0;i<d_tabIndiceErreur.size();i++)
    {
        d_afficheur->separateur(100,'-') ;
        d_afficheur->affiche("Erreur N°"+ std::to_string(i+1) +":\n") ;
        std::cout<<d_questionnaire->intituleQuestionNumero(i) ;
        d_afficheur->affiche("Reponse correcte : " +
                                        d_questionnaire->reponseQuestionNumero(i)) ;
        d_afficheur->separateur(100,'-') ;
    }
}

void Evaluation::resultatEvaluation() const
{
    d_afficheur->affiche("Vous avez trouvé "+ std::to_string(score()) + "%\n"
                    +" sur "+std::to_string(d_questionnaire->nombreDeQuestions()) +
                    " questions\n") ;
    double pourcentage {100.0*(score()/d_questionnaire->nombreDeQuestions())} ;
    d_afficheur->messageSelonScore(pourcentage) ;
    if (pourcentage >= 75)
    {

        // on lui donne les mots clé en parametre et il genere le certificat
        d_certificatText.genereCertificat() ;
    }
}

void Evaluation::afficheQuestionsInstructions(int indice) const
{
    d_afficheur->affiche(d_questionnaire->intituleQuestionNumero(indice)) ;
    d_afficheur->affiche(d_questionnaire->instructionsQuestionNumero(indice)) ;
    d_afficheur->affiche("Tapez * pour quitter l'evaluation Seconde chance\n") ;
    d_afficheur->affiche("> ") ;
}

