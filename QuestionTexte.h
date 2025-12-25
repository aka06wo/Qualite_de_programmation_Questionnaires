#ifndef CODE_QUESTIONTEXTE_H
#define CODE_QUESTIONTEXTE_H

#include "Question.h"
#include <string>
#include <iostream>

class QuestionTexte: public Question
{
    public:
    QuestionTexte(const std::string &intitule, const std::string &reponse);
    std::string intitule() const override ;
    std::string instructionsQuestion() const override;
    std::string reponse() const override ;
    bool validiteEntreeUtilisateur(const std::string &reponse) const override ;
    bool verificationReponse(const std::string &reponse) const override;
    std::unique_ptr<Question> clone() const override ;
    nlohmann::json conversionJSON () const override ;
    std::string typeQuestion() const override ;

    private:
    std::string d_reponseCorrecte;
};


#endif //CODE_QUESTIONTEXTE_H
