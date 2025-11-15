#include "QuestionChoixMultiple.h"

QuestionChoixMultiple::QuestionChoixMultiple(const string &question, const std::vector<string> &reponse) :
    Question{question}, d_reponse{reponse}
{
}

string QuestionChoixMultiple::reponse() const {
    string rep="Les différentes options sont entres autres :\n" ;
    for (const auto &r : d_reponse) {
        rep += r + " ";
    }
    return rep ;
}
std::vector<string> QuestionChoixMultiple::reponseQM() const {
    return d_reponse;
}

void QuestionChoixMultiple::afficherReponse() const {
    std::cout<<reponse()<<std::endl;
}

bool QuestionChoixMultiple::verificationReponse(string reponse) const {
    return true ;
}
bool QuestionChoixMultiple::verificationReponse(int reponse) const {
    int i=0 ;
    while (i<d_reponse.size() && i+1!=reponse) {
        i++ ;
    }

    return i!=d_reponse.size() ;
}

std::unique_ptr<Question> QuestionChoixMultiple::clone() const {
    // on fait un std::move ou pas ?? (je ne sais pas encore, j'ai oublié)
    // ??
    return std::make_unique<QuestionChoixMultiple>(intitule(),reponseQM()) ;
}