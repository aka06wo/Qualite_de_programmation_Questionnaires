#ifndef CODE_QUESTIONNAIRE_ESSAI_H
#define CODE_QUESTIONNAIRE_ESSAI_H

#include <vector>

class essai
{
    public:
    essai();
    void saisieErreurs(int indiceErreur) ;
    void augmenteScore() ;
    int score() const ;
    int nombreErreurs() const ;
    int erreurNumero(int indiceErreur) const ;
    void reinitialise () ;

    private:
    int d_score ;
    std::vector<int> d_tabErreur ;
};


#endif //CODE_QUESTIONNAIRE_ESSAI_H