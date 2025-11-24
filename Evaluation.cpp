#include "Evaluation.h"

Evaluation::Evaluation(const Questionnaire &questionnaire) : d_questionnaire(&questionnaire), d_nbEssai{0}, d_score{0}
{
}

std::string Evaluation::reponseUtilisateurQuestion() const {
    std::string reponse ;
    std::cout<<"Saisissez votre reponse : "<<std::endl ;
    std::cin>>reponse;

    return reponse;
}