#ifndef CODE_QUESTIONNAIRE_AFFICHEUR_H
#define CODE_QUESTIONNAIRE_AFFICHEUR_H

#include <string>

class Afficheur
{
    public :
    Afficheur();
    virtual ~Afficheur();
    virtual void separateur(int largeur, char symbole) const = 0 ;
    virtual void messageSelonScore(double pourcentage) const = 0 ;
    virtual void affiche(const std::string &message) const = 0 ;

    private :

};


#endif //CODE_QUESTIONNAIRE_AFFICHEUR_H
