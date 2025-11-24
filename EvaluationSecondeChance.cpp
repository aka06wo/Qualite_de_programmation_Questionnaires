#include "EvaluationSecondeChance.h"
#include "Question.h"
#include "certificat.h"

EvaluationSecondeChance::EvaluationSecondeChance(const Questionnaire &questionnaire) : Evaluation{questionnaire}
{
}

void EvaluationSecondeChance::lanceEvaluation()
{
    // on augmente le nombre d essais
    d_nbEssai++ ;

    for (int i=0 ; i<d_questionnaire->nombreDeQuestions())
    {
        d_questionnaire->afficherQuestionNumero(i) ;
        std::string reponseUtilisateur = reponseUtilisateurQuestion() ;

        // si la reponse est mauvaise, on offre une seconde chance
        if (!d_questionnaire->verificationReponse(i,reponseUtilisateur))
        {
            std::cout<<"Mauvaise reponse, Seconde chance : \n" ;
            // pas la peine de reaficher la question ?
            reponseUtilisateur = reponseUtilisateurQuestion() ;
            // si la reponse est encore mauvaise, on lui affiche la bonne réponse
            if (!d_questionnaire->verificationReponse(i,reponseUtilisateur))
            {
                std::cout<<"La bonne reponse est : \n" ;
                d_questionnaire->afficherQuestionNumero(i) ;
            }
        }
        else // bonne reponse
        {
            std::cout<<"Bonne reponse\n" ;
            d_score++ ;
        }
    }
    //
    resultatEvaluation() ;

}

void EvaluationSecondeChance::resultatEvaluation() const {
    // si il a reussi le test, 70% de bonne reponses, on appelle certificatReussite
    // sinon on affiche les basiques, reponses sur nbquestions, .....
    json j ;
    certificat monCertificat{j} ;

    //monCertificat.certficatHtml() ;
    //monCertificat.certficatText() ;

    // on affiche la possibili
}
