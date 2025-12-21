#include "GestionnaireActivites.h"
#include "ApprentissageSimple.h"
#include "ApprentissageParType.h"
#include "EvaluationTest.h"
#include "EvaluationSecondeChance.h"
#include "EvaluationAdaptative.h"
#include "certificatText.h"
#include "certificatHTML.h"

GestionnaireActivites::GestionnaireActivites(const Questionnaire &q) :
            d_questionnaire(&q), d_evaluations{},d_apprentissages{}, d_certificats{}
{
    d_apprentissages[Apprentissage_TYPE::APPRENTISSAGE_SIMPLE] = std::make_unique<ApprentissageSimple>(q);
    d_apprentissages[Apprentissage_TYPE::APPRENTISSAGE_TYPE] = std::make_unique<ApprentissageParType>(q);

    d_evaluations[Evaluation_TYPE::EVALUATION_TEST] = std::make_unique<EvaluationTest>(q);
    d_evaluations[Evaluation_TYPE::EVALUATION_SECONDE_CHANCE] = std::make_unique<EvaluationSecondeChance>(q);
    d_evaluations[Evaluation_TYPE::EVALUATION_ADAPTATIVE] = std::make_unique<EvaluationAdaptative>(q);

    d_certificats[Certificat_TYPE::TEXTE] = std::make_unique<certificatText>();
    d_certificats[Certificat_TYPE::HTML] = std::make_unique<certificatHTML>();
}

void GestionnaireActivites::selectionneQuestionnaire(const Questionnaire &q)
{
    d_questionnaire = &q ;
    for (auto const& objet : d_evaluations)
    {
        // objet.first est la clé (Evaluation_TYPE)
        // objet.second est le unique_ptr vers l'évaluation
        objet.second->changerQuestionnaire(q);
    }
    for (const auto &objet : d_apprentissages)
    {
        objet.second->changerQuestionnaire(q) ;
    }
}

void GestionnaireActivites::lanceEvaluation(Evaluation_TYPE eval)
{
    d_evaluations[eval]->lanceEvaluation();
}

void GestionnaireActivites::lanceApprentissage(Apprentissage_TYPE apprentissage)
{
    d_apprentissages[apprentissage]->lanceApprentissage() ;
}

void GestionnaireActivites::genererCertificat(Certificat_TYPE certif, Evaluation_TYPE eval)
{
    d_certificats[certif]->genereCertificat(d_questionnaire->nomQuestionnaire(),
                                            d_questionnaire->descriptionQuestionnaire(),
                                            d_evaluations[eval]->scoreDernierEssai(),
                                            d_questionnaire->nombreDeQuestions()) ;
}
