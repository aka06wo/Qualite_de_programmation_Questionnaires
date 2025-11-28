#include "QuestionNumerique.h"
#include <iostream>


QuestionNumerique::QuestionNumerique(const string& intitule,int reponse,int limitemax,int limitemin): Question{intitule},d_reponse{reponse},
    d_limiteMax{limitemax},d_limiteMin{limitemin}
{
}

string QuestionNumerique::reponse() const
{
    return std::to_string(d_reponse);
}

void QuestionNumerique::afficherQuestion() const
{
    std::cout<<intitule()<<std::endl ;
    std::cout<<"Saisissez la bonne reponse :\n" ;
}

void QuestionNumerique::afficherReponse() const
{
    std::cout<<"La bonne reponse est : "+reponse()<<std::endl;
}

bool QuestionNumerique::validiteEntreeUtilisateur(const string &reponse) const
{
    if (reponse.empty())
    {
        cout<< "Veuillez donnez une réponse "<<'\n';
        return false;
    }
    else
    {
        int i = 0;
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
                cout<< "Votre réponse n'est pas valide veuillez rentrer un nombre"<<'\n';
                return false;
            }
            else
                return true;
        }

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

json QuestionNumerique::conversionJSON() const
{
    return json
    {
        {"type", "numerique"},
        {"question", intitule()},
        {"reponseCorrecte", d_reponse}
    };
}
