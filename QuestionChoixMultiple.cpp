#include "QuestionChoixMultiple.h"
#include "styleAffichage.h"
#include <iostream>


QuestionChoixMultiple::QuestionChoixMultiple(const std::string &question,
                    const std::vector<std::string> &reponsesPossibles, int numReponse) :
    Question{question}, d_reponsesPossibles{reponsesPossibles}, d_indiceReponse{numReponse-1}
{
}

int QuestionChoixMultiple::indiceReponse() const
{
    return d_indiceReponse;
}

int QuestionChoixMultiple::nombreDeChoix() const
{
    return d_reponsesPossibles.size() ;
}

std::string QuestionChoixMultiple::choixNumero(int i) const
{
    return d_reponsesPossibles[i] ;
}

std::string QuestionChoixMultiple::intitule() const
{
    std::string question {d_intitule} ;
    for (int i = 0; i < nombreDeChoix(); i++)
    {
        question += "\n       " + std::to_string(i+1) + "- " + choixNumero(i) ;
    }
    return question ;
}

std::string QuestionChoixMultiple::instructionsQuestion() const
{
    return std::string {"Saisissez le numéro de la bonne reponse"} ;
}

std::string QuestionChoixMultiple::reponse() const
{
    return std::string(std::to_string(d_indiceReponse+1) + "- " + choixNumero(d_indiceReponse) ) ;
}

bool QuestionChoixMultiple::validiteEntreeUtilisateur(const std::string &reponse) const
{
    if (reponse.empty())
    {
        styleAffichage::ecritEnRouge("Veuillez entrer le numero de la bonne reponse\n") ;
        return false;
    }
    try
    {
        int valeur = std::stoi(reponse);
        if (valeur <= 0 || valeur > d_reponsesPossibles.size())
        {
            styleAffichage::ecritEnRouge("Numero de réponse hors plage, veuillez entrez un numéro valide\n") ;
            return false;
        }
        else
            return true;
    }
    catch (const std::invalid_argument&)
    {
        styleAffichage::ecritEnRouge("Veuillez saisir un numero valide\n") ;
        return false;
    }
    catch (const std::out_of_range&)
    {
        styleAffichage::ecritEnRouge("Nombre trop grand, veuillez saisir un numéro valide\n") ;
        return false;
    }
}

bool QuestionChoixMultiple::verificationReponse(const std::string &reponse) const
{
    return std::stoi(reponse) == d_indiceReponse + 1 ;
}

std::unique_ptr<Question> QuestionChoixMultiple::clone() const
{
    return std::make_unique<QuestionChoixMultiple>(*this) ;
}

std::string QuestionChoixMultiple::typeQuestion() const
{
    return std::string {"choixMultiples"} ;
}

nlohmann::json QuestionChoixMultiple::conversionJSON() const
{
    return nlohmann::json {
        {"type", "choixMultiples"},
        {"question", intitule()},
        {"reponsesPossibles", d_reponsesPossibles},
        {"numReponseCorrecte", d_indiceReponse}
    } ;
}
