#include "essai.h"

essai::essai() : d_score{0}, d_tabErreur{}
{
}

void essai::saisieErreurs(int indiceErreur)
{
    d_tabErreur.push_back(indiceErreur);
}

void essai::augmenteScore()
{
    d_score++ ;
}

int essai::score() const
{
    return d_score ;
}

int essai::nombreErreurs() const
{
    return d_tabErreur.size() ;
}

int essai::erreurNumero(int indiceErreur) const
{
   return d_tabErreur[indiceErreur] ;
}

void essai::reinitialise()
{
    d_score = 0 ;
    d_tabErreur.clear();
}


