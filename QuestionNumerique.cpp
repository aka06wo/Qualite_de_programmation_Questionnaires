#include "QuestionNumerique.h"
#include <iostream>

using std::cout;
using std::string ;
using std::endl ;



/*
 Actuellement si une question a comme reponse 5 et limite min 2 et limite max 9
    et que l'utilisateur donne 3, on dit bonne reponse mais affiche pas 5 (qui est la reponse juste sans limite)
    il faut qu'on y pense

 */

QuestionNumerique::QuestionNumerique(const string& intitule,int reponse,int limitemax,int limitemin):
    Question{intitule},d_reponse{reponse}, d_limiteMax{limitemax},d_limiteMin{limitemin}
{
}

int QuestionNumerique::limiteMinimum() const
{
    return d_limiteMin;
}

int QuestionNumerique::limiteMaximum() const
{
    return d_limiteMax ;
}

string QuestionNumerique::intitule() const
{
    return string{d_intitule+'\n'};
}

string QuestionNumerique::instructionsQuestion() const
{
    return string{"Saisissez la bonne reponse\n"} ;
}

string QuestionNumerique::reponse() const
{
    return string{std::to_string(d_reponse)+'\n'};
}

bool QuestionNumerique::validiteEntreeUtilisateur(const string &reponse) const
{
     if (reponse.empty())
 {
     cout<< "Veuillez donnez une réponse "<<'\n';
     return false;
 }
   try
 {
     int valeur = std::stoi(reponse);
     if (!isdigit(valeur))
     {
         std::cout << "Ceci n'est pas un nombre, veuillez entrez un nombre valide\n";
         return false;
     }
     else
         return true;
 }
 catch (const std::invalid_argument&)
 {
     std::cout << "Ceci n'est pas un nombre,Veuillez saisir un nombre valide\n";
     return false;
 }
 catch (const std::out_of_range&)
 {
     std::cout << "Nombre trop grand, veuillez saisir un nombre valide\n";
     return false;
 }
}



bool QuestionNumerique::verificationReponse(const string &reponse) const
{
    int rep=std::stoi(reponse);
    if(rep<d_limiteMin || rep>d_limiteMax)
        return false;
    else
      return true;
}


std::unique_ptr<Question> QuestionNumerique::clone() const
{
    return std::make_unique<QuestionNumerique>(*this);
}

nlohmann::json QuestionNumerique::conversionJSON() const
{
    return nlohmann::json
    {
        {"type", "numerique"},
        {"question", intitule()},
        {"reponseCorrecte", reponse()},
        {"limiteMin",limiteMinimum()},
        {"limiteMax",limiteMaximum()}
    };
}
