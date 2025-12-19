#include "gestionnaireQuestionnaires.h"

#include "gestionnaireEvaluations.h"

gestionnaireQuestionnaires::gestionnaireQuestionnaires() : d_nomQuestionnaire{}, d_gestionnaireJSON{}
{

}

gestionnaireQuestionnaires::gestionnaireQuestionnaires(const std::string &nomQuestionnaire) :
d_nomQuestionnaire{nomQuestionnaire}, d_gestionnaireJSON {nomQuestionnaire}
{

}

Questionnaire gestionnaireQuestionnaires::questionnaireCourant()
{
    Questionnaire nouveau {};
    d_gestionnaireJSON.chargerDansQuestionnaire(nouveau) ;
    return nouveau ;
}

void gestionnaireQuestionnaires::selectionneQuestionnaire(const std::string& nom)
{
    d_nomQuestionnaire = nom ;
    d_gestionnaireJSON.changerQuestionnaire(nom) ;
}

std::vector<std::string> gestionnaireQuestionnaires::nomsDesDifferentsQuestionnaires() const
{
    return  d_gestionnaireJSON.nomsDifferentsQuestionnaires();
}
