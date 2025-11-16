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
    // mettre dans la classe de base, reponseUtilisateur (une methode qui renvoie le string du cin utilisateur)
    void afficherReponse() const override ;

    bool verificationReponse(string reponse) const override ;
    // Problème de modélisation dans la classe abstraite
    bool verificationReponse(int reponse) const ;

    std::unique_ptr<Question> clone() const override ;

    private:
    std::vector<string> d_reponsesPossibles ;
    int d_numReponse ;
};


#endif //CODE_QUESTIONCHOIXMULTIPLE_H