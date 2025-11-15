#ifndef CODE_QUESTIONCHOIXMULTIPLE_H
#define CODE_QUESTIONCHOIXMULTIPLE_H

#include "Question.h"
#include <vector>
#include <iostream>

class QuestionChoixMultiple : public Question
{
    public:
    QuestionChoixMultiple(const string &question, const std::vector<string> &reponse);

    string reponse() const override ;
    // Problème de modélisation dans la classe abstraite
    std::vector<string> reponseQM() const ;

    void afficherReponse() const override ;

    bool verificationReponse(string reponse) const override ;
    // Problème de modélisation dans la classe abstraite
    bool verificationReponse(int reponse) const ;

    std::unique_ptr<Question> clone() const override ;

    private:
    std::vector<string> d_reponse ;
};


#endif //CODE_QUESTIONCHOIXMULTIPLE_H