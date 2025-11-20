#include "QuestionChoixMultiple.h"

QuestionChoixMultiple::QuestionChoixMultiple(const string &question,
                    const std::vector<string> &reponsesPossibles, int numReponse) :
    Question{question}, d_reponsesPossibles{reponsesPossibles}, d_indiceReponse{numReponse-1}
{
}

string QuestionChoixMultiple::reponse() const {
    return choixNumero(d_indiceReponse);
}

int QuestionChoixMultiple::nombreDeChoix() const 
{
    return d_reponsesPossibles.size() ;
}

// tester si i ne depasse pas les élements du tableau
string QuestionChoixMultiple::choixNumero(int i) const 
{
    return d_reponsesPossibles[i] ;
}

void QuestionChoixMultiple::afficherQuestion() const {
    std::cout<<intitule()<<std::endl ;
    if (d_reponsesPossibles.size() != 0) {
        for (int i = 0; i < d_reponsesPossibles.size(); i++) {
            std::cout<<i+1<<"- "<<d_reponsesPossibles[i]<<std::endl ;
        }
    }
}

void QuestionChoixMultiple::afficherReponse() const {
    std::cout<<reponse()<<std::endl;
}

// revoir la modélisation bool QuestionChoixMultiple::verificationReponse(STRING reponse) const
bool QuestionChoixMultiple::verificationReponse(const string &reponse) const {
    return std::stoi(reponse) == d_indiceReponse + 1 ;
}

std::unique_ptr<Question> QuestionChoixMultiple::clone() const {
    return std::make_unique<QuestionChoixMultiple>(*this) ;
}


json QuestionChoixMultiple::conversionJSON() const {
    return json {
        {"type", "choixMultiples"},
        {"question", intitule()},
        {"reponsesPossibles", d_reponsesPossibles},
        {"numReponseCorrecte", d_indiceReponse}
    } ;
}

