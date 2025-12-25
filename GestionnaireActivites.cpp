#include "GestionnaireActivites.h"
#include "ApprentissageSimple.h"
#include "ApprentissageParType.h"
#include "EvaluationTest.h"
#include "EvaluationSecondeChance.h"
#include "EvaluationAdaptative.h"
#include "certificatText.h"
#include "certificatHTML.h"

#include <iostream>

#include "styleAffichage.h"

GestionnaireActivites::GestionnaireActivites() :
    d_questionnaire(nullptr), d_evaluations{}, d_apprentissages{}, d_certificats{}
{
    d_certificats[Certificat_TYPE::TEXTE] = std::make_unique<certificatText>();
    d_certificats[Certificat_TYPE::HTML] = std::make_unique<certificatHTML>();
}

GestionnaireActivites::GestionnaireActivites(const Questionnaire &q) : GestionnaireActivites{}
{
    selectionneQuestionnaire(q);
}


void GestionnaireActivites::selectionneQuestionnaire(const Questionnaire &q)
{
    d_questionnaire = &q;

    // Si les maps sont vides (cas après constructeur par défaut), on crée les objets
    if (d_evaluations.empty())
    {
        d_apprentissages[Apprentissage_TYPE::APPRENTISSAGE_SIMPLE] = std::make_unique<ApprentissageSimple>(q);
        d_apprentissages[Apprentissage_TYPE::APPRENTISSAGE_TYPE] = std::make_unique<ApprentissageParType>(q);

        d_evaluations[Evaluation_TYPE::EVALUATION_TEST] = std::make_unique<EvaluationTest>(q);
        d_evaluations[Evaluation_TYPE::EVALUATION_SECONDE_CHANCE] = std::make_unique<EvaluationSecondeChance>(q);
        d_evaluations[Evaluation_TYPE::EVALUATION_ADAPTATIVE] = std::make_unique<EvaluationAdaptative>(q);
    }
    else
    {
        // Si les objets existent déjà, on les met simplement à jour
        for (auto const& objet : d_evaluations) {
            objet.second->changerQuestionnaire(q);
        }
        for (const auto &objet : d_apprentissages) {
            objet.second->changerQuestionnaire(q);
        }
    }
}


void GestionnaireActivites::lanceEvaluation(Evaluation_TYPE eval)
{
    d_evaluations[eval]->lanceEvaluation();

    if (d_evaluations[eval] -> pourcentageReussite() >= 50.0)
    {
        genererCertificat(Certificat_TYPE::TEXTE,eval) ;
        styleAffichage::ecritEnBleu("      Souhaitez vous également imprimer un certificat HTML\n") ;
        std::cout<< "       O (oui) / N (non)"<<std::endl ;
        std::cout<< "       > " ;
        char choix ;
        std::cin>> choix ;
        if (choix == 'O')
        {
            genererCertificat(Certificat_TYPE::HTML,eval) ;
        }
    }

    styleAffichage::ecritEnBleu("      Souhaitez vous également revoir vos erreurs commises\n") ;
    std::cout<< "       O (oui) / N (non)"<<std::endl ;
    std::cout<< "       > " ;
    char choix ;
    std::cin>> choix ;
    if (choix == 'O')
    {
        d_evaluations[eval]->erreursCommisesEssais() ;
    }

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
