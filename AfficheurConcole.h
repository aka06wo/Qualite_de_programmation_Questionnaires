#ifndef CODE_QUESTIONNAIRE_AFFICHEURCONCOLE_H
#define CODE_QUESTIONNAIRE_AFFICHEURCONCOLE_H
#include <string>

#include "Afficheur.h"


class AfficheurConcole : public Afficheur
{
    public:
    AfficheurConcole();
    void separateur(int largeur, char symbole) const override ;
    void messageSelonScore(double pourcentage) const override ;
    void affiche(const std::string &message) const override ;

    private:
};


#endif //CODE_QUESTIONNAIRE_AFFICHEURCONCOLE_H