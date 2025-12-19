#include "gestionnaireApprentissage.h"

#include <memory>

#include "ApprentissageParType.h"
#include "ApprentissageSimple.h"

gestionnaireApprentissage::gestionnaireApprentissage() : d_questionnaire{}, d_apprentissage{}
{

}


gestionnaireApprentissage::gestionnaireApprentissage(const Questionnaire &q):
d_questionnaire{&q},d_apprentissage{}
{
    d_apprentissage.push_back(std::make_unique<ApprentissageSimple>(q));
    d_apprentissage.push_back(std::make_unique<ApprentissageParType>(q)) ;
}

void gestionnaireApprentissage::selectionneQuestionnaire(const Questionnaire &q)
{
    d_questionnaire = &q ;
}


void gestionnaireApprentissage::commenceApprentissage(int apprentissage)
{
    d_apprentissage[apprentissage]->executer() ;
}
