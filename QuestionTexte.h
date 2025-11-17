#ifndef CODE_QUESTIONTEXTE_H
#define CODE_QUESTIONTEXTE_H

#include "Question.h"
#include <string>
#include <iostream>

using std::string;

class QuestionTexte:public Question {
    public:
    QuestionTexte(const string &intitule, const string &reponse);
    bool verificationReponse(const string &reponse) const override;
    void afficherReponse() const override;
    string reponse() const override;
    std::unique_ptr<Question> clone() const override ;
    private:
    string d_reponseCorrecte;

};


#endif //CODE_QUESTIONTEXTE_H
