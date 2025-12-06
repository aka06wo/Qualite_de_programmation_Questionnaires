#ifndef CODE_QUESTIONTEXTE_H
#define CODE_QUESTIONTEXTE_H

#include "Question.h"
#include <string>

class QuestionTexte:public Question {
    public:
    QuestionTexte(const std::string &intitule, const std::string &reponse);
    void afficherQuestion() const override ;
    void afficherReponse() const override;
    std::string reponse() const override;
    bool validiteEntreeUtilisateur(const std::string &reponse) const override ;
    bool verificationReponse(const std::string &reponse) const override;
    std::unique_ptr<Question> clone() const override ;
    // mamadou : j'en avais besoin pour la classe questionnaireJSON, je vous expliquerait
    nlohmann::json conversionJSON () const override ;

    private:
    std::string d_reponseCorrecte;
};


#endif //CODE_QUESTIONTEXTE_H
