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
    /**
    Constructeur par défaut qui initialise en instanciant les certification disponibles
    */
    GestionnaireActivites ();

    /**
     Constructeur de la classe GestionnaireActivites
     Initialise le gestionnaire en instanciant l'ensemble des strategies d'apprentissage,
     d'evaluation et de certifications disponibles dans des conteneurs de pointeurs intelligents
     @param q Le questionnaire de reference utilise pour initialiser chaque activite
     */
    GestionnaireActivites(const Questionnaire &q);

    /**
     Modifie le questionnaire de reference pour les prochaines evaluations ou apprentissages
     @param q Le nouveau questionnaire à selectionner
     */
    void selectionneQuestionnaire(const Questionnaire &q) ;

    /**
     Lance une session d'evaluation correspondant au type passe en parametre
     @param eval Le type d'evaluation souhaite (enum Evaluation_TYPE)
     */
    void lanceEvaluation(Evaluation_TYPE eval);

    /**
     Lance une session d'apprentissage correspondant au type passe en parametre
     @param ap Le type d'apprentissage souhaite (ex: SIMPLE, PAR_TYPE)
     */
    void lanceApprentissage(Apprentissage_TYPE ap);

    /**
     Genere un document de certification pour une evaluation specifique dans le format demande
     @param format Le format de sortie du certificat (ex: HTML, TEXTE)
     @param eval Le type d'evaluation dont on veut certifier le score
     */
    void genererCertificat(Certificat_TYPE format, Evaluation_TYPE eval);

    private:
    const Questionnaire *d_questionnaire;
    std::map<Apprentissage_TYPE, std::unique_ptr<Apprentissage>> d_apprentissages;
    std::map<Evaluation_TYPE, std::unique_ptr<Evaluation>> d_evaluations;
    std::map<Certificat_TYPE, std::unique_ptr<certificat>> d_certificats;
};


#endif //CODE_QUESTIONNAIRE_GESTIONNAIREACTIVITES_H