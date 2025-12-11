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
    // Refaire avec les try cath


    if (reponse.empty())
    {
        cout<< "Veuillez donnez une réponse "<<'\n';
        return false;
    }
    else
    {
        int i = 0;
        // si il a - ou + il faut qu'on renvoie false, revoir le code
        // mamadou, j'ai egalement un warning
        if (reponse[0] == '-' || reponse[0] == '+')
        {
            if (reponse.size() == 1)
            {
                cout << " Donnez une réponse valide! " <<'\n';
                return false;
            }
            else
                ++i;
        }

        for (int j{i}; j < reponse.size(); ++j)
        {
            if (!isdigit(reponse[j]))
            {
                cout<< "Votre réponse n'est pas valide, veuillez saisir un nombre\n";
                return false;
            }
        }
        // Si tous les caractères sont des chiffres, la réponse est valide
        return true;
    }
    // Ne devrait jamais arriver ici, mais pour éviter le warning
    return false;
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
