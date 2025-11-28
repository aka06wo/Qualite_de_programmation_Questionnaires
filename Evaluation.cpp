#include "Evaluation.h"

/*Evaluation::Evaluation(const std::string &nomQuestionnaire) : d_questionnaire{&}, d_monFichier{nomQuestionnaire}, d_nbEssai{0}
{
    //chargerQuestionnaire et chargerDansQuestionnaire sont differents?
    //d_monFichier.chargerQuestionnaire(d_questionnaire) ;
}*/
Evaluation::Evaluation(const Questionnaire &questionnaire) : d_questionnaire(&questionnaire), d_nbEssai{0}, d_score{0}
{
}

std::string Evaluation::reponseUtilisateurQuestion() const {
    std::string reponse ;
    std::cout<<"Saisissez votre reponse : "<<std::endl ;
    std::cin>>reponse;

    return reponse;
}
