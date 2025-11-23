#include "Evaluation.h"

Evaluation::Evaluation(const std::string &nomQuestionnaire) : d_questionnaire{}, d_monFichier{nomQuestionnaire}, d_nbEssai{0}
{
    //chargerQuestionnaire et chargerDansQuestionnaire sont differents?
    d_monFichier.chargerQuestionnaire(d_questionnaire) ;
}
