#include "QuestionNumerique.h"
#include <iostream>


QuestionNumerique::QuestionNumerique(const string& intitule,int reponse): Question{intitule},d_reponse{reponse},
                d_limiteMax{static_cast<int>(reponse+reponse*0.1)},d_limiteMin{static_cast<int>(reponse-reponse*0.1)}
{
}

string QuestionNumerique::reponse() const
{
    return std::to_string(d_reponse);
}

void QuestionNumerique::afficherReponse() const
{
    std::cout<<reponse()<<std::endl;
}

// Essaye de faire des if else, trop de return séparées
bool QuestionNumerique::estUnEntier(const string& reponse) const
{
  if (reponse.empty()) return false;
    int i = 0;
    if (reponse[0] == '-' || reponse[0] == '+') {
        if (reponse.size() == 1) return false;
        i = 1;
    }

    for (int j{i}; j < reponse.size(); ++j) {
        if (!isdigit(reponse[j])) return false;
    }
    return true;
}


// Aisse il ya trop de return, essaye de faire if else, au lieu de faire des if séparées
bool QuestionNumerique::verificationReponse(const string &reponse) const
{
   if(!estUnEntier(reponse))
    return false;
   int rep=std::stoi(reponse);
   if(rep<d_limiteMin || rep>d_limiteMax)
    return false;

   return true;
}
