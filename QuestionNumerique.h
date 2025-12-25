#ifndef CODE_QUESTIONNUMERIQUE_H
#define CODE_QUESTIONNUMERIQUE_H

#include "Question.h"


class QuestionNumerique : public Question
{
    public:
    /**
     Constructeur de la classe QuestionNumerique
     @param intitule L'enonce de la question
     @param reponse La valeur entiere attendue comme reponse correcte
     @param limitemax La valeur maximale autorisee pour la saisie utilisateur
     @param limitemin La valeur minimale autorisee pour la saisie utilisateur
     */
    QuestionNumerique(const std::string& intitule, int reponse, int limitemax, int limitemin);

    /**
     Renvoie la borne inferieure de validite pour cette question
     @return La limite minimum autorisee (entier)
     */
    int limiteMinimum() const ;

    /**
     Renvoie la borne superieure de validite pour cette question
     @return La limite maximum autorisee (entier)
     */
    int limiteMaximum() const ;

    std::string intitule() const override ;
    std::string instructionsQuestion() const override;
    std::string reponse() const override ;
    bool validiteEntreeUtilisateur(const std::string &reponse) const override ;
    bool verificationReponse(const std::string &reponse) const override ;
    std::unique_ptr<Question> clone() const override ;
    nlohmann::json conversionJSON () const override ;
    std::string typeQuestion() const override ;

    private:
    int d_reponse;
    int d_limiteMax,d_limiteMin;
};


#endif //CODE_QUESTIONNUMERIQUE_H
