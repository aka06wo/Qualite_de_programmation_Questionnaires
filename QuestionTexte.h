 //Les bibliothèques nécessaires que j'ai utilisé
#include "Question.h"
#include <memory>
#include <string>
#include <iostream>

#ifndef CODE_QUESTIONTEXTE_H
#define CODE_QUESTIONTEXTE_H
using std::string;
class QuestionTexte:public Question{
public:
    QuestionTexte(const string &intitule,const string &texte,const string &reponse);
    //Redéfinition des méthodes de la classe de base Question que je vais utiliser dans QuestionTexte
    bool verificationReponse(const string &reponse) const override;
    void afficherReponse() const override;
    string reponse() const override;
    void afficherQuestion() const override;
private:
    string d_texte;//La question posée est sous forme de texte (ex:"Quelle est la capitale de le France")
    string d_reponseCorrecte;//réponse correcte pour notre exemple:"Paris"

};


#endif //CODE_QUESTIONTEXTE_H
