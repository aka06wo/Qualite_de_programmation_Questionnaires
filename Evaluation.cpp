#include "Evaluation.h"

Evaluation::Evaluation(const std::string &nomQuestionnaire) : d_questionnaire{}, d_monFichier{nomQuestionnaire}, d_nbEssai{0}
{
    d_monFichier.chargerDansQuestionnaire(d_questionnaire) ;
}
