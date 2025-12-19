#ifndef CODE_QUESTIONNAIRE_GESTIONNAIREEVALUATIONS_H
#define CODE_QUESTIONNAIRE_GESTIONNAIREEVALUATIONS_H

#include "Questionnaire.h"
#include "Evaluation.h"
#include "certificat.h"

class gestionnaireEvaluations
{
    public :
    gestionnaireEvaluations() ;
    gestionnaireEvaluations(const Questionnaire &q) ;
    void changeQuestionnaire(const Questionnaire &q) ;
    void genereCertificat(int numCertificat,int evaluation) ;
    void commenceEvaluation(int evaluation) ;

    private :
    const Questionnaire *d_questionnaire ;
    std::vector<std::unique_ptr<Evaluation>> d_evaluations ;
    std::vector<std::unique_ptr<certificat>> d_certificats ;
};


#endif //CODE_QUESTIONNAIRE_GESTIONNAIREEVALUATIONS_H