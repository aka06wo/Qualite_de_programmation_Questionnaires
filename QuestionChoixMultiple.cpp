#include "QuestionChoixMultiple.h"

QuestionChoixMultiple::QuestionChoixMultiple(const string &question,
                    const std::vector<string> &reponsesPossibles, int numReponse) :
    Question{question}, d_reponsesPossibles{reponsesPossibles}, d_numReponse{numReponse}
{
}

string QuestionChoixMultiple::reponse() const {
    return choixNumero(d_numReponse);
}

int QuestionChoixMultiple::nombreDeChoix() const 
{
    return d_reponsesPossibles.size() ;
}

// tester si i ne depasse pas les élements du tableau
string QuestionChoixMultiple::choixNumero(int i) const 
{
    return d_reponsesPossibles[i-1] ;
}

void QuestionChoixMultiple::afficherReponse() const {
    std::cout<<reponse()<<std::endl;
}

// revoir la modélisation bool QuestionChoixMultiple::verificationReponse(STRING reponse) const
bool QuestionChoixMultiple::verificationReponse(string reponse) const {
    return std::stoi(reponse)==d_numReponse +1 ;
}

std::unique_ptr<Question> QuestionChoixMultiple::clone() const {
    // on fait un std::move ou pas ?? (je ne sais pas encore, j'ai oublié)
    // utilisé dans le constructeur de questionnaires
    // ??
    return std::make_unique<QuestionChoixMultiple>(intitule(),d_reponsesPossibles,d_numReponse) ;
}
