#include "QuestionNumerique.h"
#include "styleAffichage.h"
#include <iostream>

using std::cout;
using std::string ;
using std::endl ;

QuestionNumerique::QuestionNumerique(const string& intitule,int reponse,int limitemax,int limitemin): Question{intitule},d_reponse{reponse},
    d_limiteMax{limitemax},d_limiteMin{limitemin}
{
}

int QuestionNumerique::limiteMinimum() const {
    return d_limiteMin;
}

int QuestionNumerique::limiteMaximum() const {
    return d_limiteMax ;
}

std::string QuestionNumerique::intitule() const {
    return string{d_intitule};
}

string QuestionNumerique::instructionsQuestion() const {
    return string{"Saisissez la bonne reponse :"} ;
}

string QuestionNumerique::reponse() const {
    return std::to_string(d_reponse);
}


bool QuestionNumerique::validiteEntreeUtilisateur(const string &reponse) const
{
    if (reponse.empty())
    {
        styleAffichage::ecritEnRouge("Veuillez donnez une réponse \n") ;
        return false;
    }
    else if (reponse.length() > 9)
    {
        styleAffichage::ecritEnRouge("  [!] Erreur : Nombre trop long ou vide.\n");
        return false;
    }

    int i=0;
    if(reponse[i]=='+' || reponse[i]=='-')
    {
        if (reponse.length()==1)
            return false ;
        else
            ++i;
    }

    while(i< reponse.length() && isdigit(reponse[i]) )
    {
        ++i;
    }
    if(i != reponse.length())
    {
        styleAffichage::ecritEnRouge("Saisie invalide : veuillez n'entrer que des chiffres.\n") ;
        return false;
    }
    return true;
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

std::string QuestionNumerique::typeQuestion() const
{
    return std::string {"numerique"} ;
}

