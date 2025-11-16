#include "QuestionNumerique.h"
#include <iostream>


QuestionNumerique::QuestionNumerique(const string& intitule,int reponse): Question{intitule},d_reponse{reponse},d_limitemax{static_cast<int>(reponse+reponse*0.1)},d_limitemin{static_cast<int>(reponse-reponse*0.1)}
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
bool QuestionNumerique::estunentier(const string& reponse) const
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
bool QuestionNumerique::verificationReponse(string reponse) const
{
   if(!estunentier(reponse))
    return false;
   int rep=std::stoi(reponse);
   if(rep<d_limitemin || rep>d_limitemax)
    return false;

   return true;
}
