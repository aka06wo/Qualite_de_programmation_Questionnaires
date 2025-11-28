#ifndef CODE_QUESTIONCHOIXMULTIPLE_H
#define CODE_QUESTIONCHOIXMULTIPLE_H

#include "Question.h"
#include <vector>
#include <iostream>

class QuestionChoixMultiple : public Question
{
public:
    QuestionChoixMultiple(const string &question,
                const std::vector<string> &reponsesPossibles, int numReponse);
    string reponse() const override ;
    int nombreDeChoix() const ;
    string choixNumero(int i) const ;
    void afficherQuestion() const override ;
    void afficherReponse() const override ;
    bool validiteEntreeUtilisateur(const string &reponse) const override ;
    bool verificationReponse(const string &reponse) const override ;
    std::unique_ptr<Question> clone() const override ;
    json conversionJSON () const override ;

private:
    std::vector<string> d_reponsesPossibles ;
    int d_indiceReponse ;
};


#endif //CODE_QUESTIONCHOIXMULTIPLE_H
