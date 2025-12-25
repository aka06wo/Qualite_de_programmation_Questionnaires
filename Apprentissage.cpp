#include "Apprentissage.h"

Apprentissage::Apprentissage(const Questionnaire& questionnaire):
                                        d_questionnaire{&questionnaire}
{
}

void Apprentissage::changerQuestionnaire(const Questionnaire &questionnaire) {
    d_questionnaire = &questionnaire;
}
