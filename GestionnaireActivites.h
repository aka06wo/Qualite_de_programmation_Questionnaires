#ifndef CODE_QUESTIONNAIRE_GESTIONNAIREACTIVITES_H
#define CODE_QUESTIONNAIRE_GESTIONNAIREACTIVITES_H

#include "Questionnaire.h"
#include "Evaluation.h"
#include "Apprentissage.h"
#include "certificat.h"

enum class Evaluation_TYPE {
    EVALUATION_TEST,
    EVALUATION_SECONDE_CHANCE,
    EVALUATION_ADAPTATIVE
};

enum class Apprentissage_TYPE {
    APPRENTISSAGE_SIMPLE,
    APPRENTISSAGE_TYPE
};

enum class Certificat_TYPE { TEXTE, HTML };


class GestionnaireActivites
{
    public:
    GestionnaireActivites(const Questionnaire &q);
    void selectionneQuestionnaire(const Questionnaire &q) ;
    void lanceEvaluation(Evaluation_TYPE eval);
    void lanceApprentissage(Apprentissage_TYPE ap);
    void genererCertificat(Certificat_TYPE format, Evaluation_TYPE eval);

    private:
    const Questionnaire *d_questionnaire;
    std::map<Apprentissage_TYPE, std::unique_ptr<Apprentissage>> d_apprentissages;
    std::map<Evaluation_TYPE, std::unique_ptr<Evaluation>> d_evaluations;
    std::map<Certificat_TYPE, std::unique_ptr<certificat>> d_certificats;
};


#endif //CODE_QUESTIONNAIRE_GESTIONNAIREACTIVITES_H